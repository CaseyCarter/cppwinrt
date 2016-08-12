#include "Precompiled.h"
#include "Writers.h"
#include "Output.h"
#include "Strings.h"
#include "Version.h"
#include "Database.h"
#include "Settings.h"

namespace Modern {

using namespace Database;

template <unsigned Count>
bool StartsWith(std::string const & target, char const (&match)[Count]) noexcept
{
    return target.compare(0, Count - 1, match) == 0;
}

static void WriteEnumeratorsFlag(Output & out)
{
    GetEnumeratorsFlag([&]
    {
        Write(out,
              Strings::WriteEnumeratorFlag,
              Settings::EnumeratorName,
              Settings::EnumeratorValue);
    });
}

static void WriteEnumerators(Output & out)
{
    GetEnumerators([&]
    {
        Write(out, 
              Strings::WriteEnumerator,
              Settings::EnumeratorName,
              Settings::EnumeratorValue);
    });
}

static void WriteStructureFields(Output & out)
{
    GetFields([&]
    {
        Write(out,
              Strings::WriteStructureField,
              Settings::FieldType,
              Settings::FieldName);
    });
}

static void WriteAbiStructureFields(Output & out)
{
    GetFields([&]
    {
        if (Settings::FieldCategory == TypeCategory::Enumeration)
        {
            Write(out,
                  Strings::WriteStructureField,
                  "winrt::" + Settings::FieldType,
                  Settings::FieldName);
        }
        else if (Settings::FieldCategory == TypeCategory::Interface)
        {
            Write(out,
                  Strings::WriteStructureField,
                  Settings::FieldType + " *",
                  Settings::FieldName);
        }
        else
        {
            Write(out,
                  Strings::WriteStructureField,
                  Settings::FieldType,
                  Settings::FieldName);
        }
    });
}

static void WriteProducerForwardArgument(Output & out, Parameter const & param)
{
    if (param.IsIn())
    {
        if (param.Category == TypeCategory::Interface ||
            param.Category == TypeCategory::Delegate ||
            param.Category == TypeCategory::String ||
            param.Category == TypeCategory::Structure)
        {
            Write(out,
                  "*reinterpret_cast<const % *>(&%)",
                  param.ModernType(),
                  param.Name);
        }
        else if (param.IsArray())
        {
            Write(out,
                  "array_ref<const %>(%, % + __%Size)",
                  param.ModernType(),
                  param.Name,
                  param.Name,
                  param.Name);
        }
        else
        {
            Write(out, param.Name);
        }
    }
    else if (param.IsOut())
    {
        if (param.IsArray() &&
            param.IsReferenceOrReturn())
        {
            Write(out,
                  "detach<%>(__%Size, %)",
                  param.ModernType(),
                  param.Name,
                  param.Name);
        }
        else
        {
            Write(out,
                  "*%",
                  param.Name);
        }
    }
}

static void WriteProducerForwardArguments(Output & out)
{
    bool first = true;

    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (first)
        {
            first = false;
        }
        else if (!param.IsReturn())
        {
            Write(out, ", ");
        }

        WriteProducerForwardArgument(out, param);
    }
}

static void WriteAbiArgument(Output & out, Parameter const & param)
{
    if (param.IsArray())
    {
        if (param.IsIn() || !param.IsReferenceOrReturn())
        {
            Write(out, "%.size(), get(%)", param.Name, param.Name);
        }
        else
        {
            Write(out, "put_size(%), put(%)", param.Name, param.Name);
        }
    }
    else
    {
        if (param.Category == TypeCategory::Enumeration || param.Category == TypeCategory::Value)
        {
            if (param.IsIn())
            {
                Write(out, "%", param.Name);
            }
            else
            {
                Write(out, "&%", param.Name);
            }
        }
        else
        {
            if (param.IsIn())
            {
                Write(out, "get(%)", param.Name);
            }
            else
            {
                Write(out, "put(%)", param.Name);
            }
        }
    }
}

static void WriteAbiArguments(Output & out)
{
    bool first = true;

    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            Write(out, ", ");
        }

        WriteAbiArgument(out, param);
    }
}

static void WriteComposableConstructorArguments(Output & out)
{
    MODERN_ASSERT(Settings::ParameterInfo.Parameters.size() >= 3);

    for (size_t i = 0; i != Settings::ParameterInfo.Parameters.size() - 3; ++i)
    {
        Parameter const & param = Settings::ParameterInfo.Parameters[i];

        Write(out, "%, ", param.Name);
    }
}

static void WriteModernArguments(Output & out)
{
    bool first = true;

    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (param.IsReturn())
        {
            break;
        }

        if (first)
        {
            first = false;
        }
        else
        {
            Write(out, ", ");
        }

        Write(out, param.Name);
    }
}

static void WriteAbiProducerParameter(Output & out, Parameter const & param)
{
    std::string paramType = param.Type;

    if (param.IsIn())
    {
        if (param.IsArray())
        {
            Write(out, "uint32_t __%Size, abi_arg_in<%> * %", param.Name, param.Type, param.Name);
        }
        else if (param.Category == TypeCategory::Value || param.Category == TypeCategory::Enumeration)
        {
            Write(out, "% %", param.Type, param.Name);
        }
        else
        {
            Write(out, "abi_arg_in<%> %", param.Type, param.Name);
        }
    }
    else
    {
        if (param.IsArray())
        {
            if (param.IsReferenceOrReturn())
            {
                Write(out, "uint32_t * __%Size, abi_arg_out<%> * %", param.Name, param.Type, param.Name);
            }
            else
            {
                Write(out, "uint32_t __%Size, abi_arg_out<%> %", param.Name, param.Type, param.Name);
            }
        }
        else if (param.Category == TypeCategory::Value || param.Category == TypeCategory::Enumeration)
        {
            Write(out, "% * %", param.Type, param.Name);
        }
        else
        {
            Write(out, "abi_arg_out<%> %", param.Type, param.Name);
        }
    }
}

static void WriteAbiProducerParameters(Output & out)
{
    bool first = true;

    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            Write(out, ", ");
        }

        WriteAbiProducerParameter(out, param);
    }
}

static void WriteAbiParameter(Output & out, Parameter const & param)
{
    std::string paramType = param.Type;

    if (param.IsIn())
    {
        if (param.IsArray())
        {
            Write(out, "uint32_t __%Size, ", param.Name);

            if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate)
            {
                Write(out, "% ** %", param.Type, param.Name);
            }
            else if (param.Category == TypeCategory::Enumeration)
            {
                Write(out, "winrt::% * %", param.Type, param.Name);
            }
            else
            {
                Write(out, "% * %", paramType, param.Name);
            }
        }
        else
        {
            if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate)
            {
                Write(out, "% * %", param.Type, param.Name);
            }
            else if (param.Category == TypeCategory::Enumeration)
            {
                Write(out, "winrt::% %", param.Type, param.Name);
            }
            else
            {
                Write(out, "% %", paramType, param.Name);
            }
        }
    }
    else
    {
        if (param.IsArray())
        {
            if (param.IsReferenceOrReturn())
            {
                Write(out, "uint32_t * __%Size, ", param.Name);

                if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate)
                {
                    Write(out, "% *** %", param.Type, param.Name);
                }
                else if (param.Category == TypeCategory::Enumeration)
                {
                    Write(out, "winrt::% ** %", param.Type, param.Name);
                }
                else
                {
                    Write(out, "% ** %", paramType, param.Name);
                }
            }
            else
            {
                Write(out, "uint32_t __%Size, ", param.Name);

                if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate)
                {
                    Write(out, "% ** %", param.Type, param.Name);
                }
                else if (param.Category == TypeCategory::Enumeration)
                {
                    Write(out, "winrt::% * %", param.Type, param.Name);
                }
                else
                {
                    Write(out, "% * %", paramType, param.Name);
                }
            }
        }
        else
        {
            if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate)
            {
                Write(out, "% ** %", param.Type, param.Name);
            }
            else if (param.Category == TypeCategory::Enumeration)
            {
                Write(out, "winrt::% * %", param.Type, param.Name);
            }
            else
            {
                Write(out, "% * %", paramType, param.Name);
            }
        }
    }
}

static void WriteAbiParameters(Output & out)
{
    bool first = true;

    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            Write(out, ", ");
        }

        WriteAbiParameter(out, param);
    }
}

static void WriteParameter(Output & out, Parameter const & param)
{
    if (param.IsArray())
    {
        if (param.IsIn())
        {
            Write(out, "array_ref<const %> %", param.ModernType(), param.Name);
        }
        else if (param.IsOut())
        {
            if (param.IsReferenceOrReturn())
            {
                Write(out, "com_array<%> & %", param.ModernType(), param.Name);
            }
            else
            {
                Write(out, "array_ref<%> %", param.ModernType(), param.Name);
            }
        }
    }
    else
    {
        if (param.IsIn())
        {
            if (param.Category == TypeCategory::String)
            {
                Write(out, "hstring_ref %", param.Name);
            }
            else if (param.Category == TypeCategory::Structure || param.Category == TypeCategory::Interface)
            {
                Write(out, "const % & %", param.ModernType(), param.Name);
            }
            else if (param.Category == TypeCategory::Delegate)
            {
                Write(out, "const % & %", param.Type, param.Name);
            }
            else
            {
                Write(out, "% %", param.Type, param.Name);
            }
        }
        else if (param.IsOut())
        {
            Write(out, "% & %", param.ModernType(), param.Name);
        }
    }
}

static void WriteComposableConstructorParameters(Output & out)
{
    MODERN_ASSERT(Settings::ParameterInfo.Parameters.size() >= 3);

    for (size_t i = 0; i != Settings::ParameterInfo.Parameters.size() - 3; ++i)
    {
        Parameter const & param = Settings::ParameterInfo.Parameters[i];

        if (i != 0)
        {
            Write(out, ", ");
        }

        WriteParameter(out, param);
    }
}

static void WriteParameters(Output & out)
{
    bool first = true;

    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (first)
        {
            first = false;
        }
        else if (!param.IsReturn())
        {
            Write(out, ", ");
        }

        WriteParameter(out, param);
    }
}

static void WriteMethodBodyPreCall(Output & out)
{
    if (Settings::ParameterInfo.HasReturnType)
    {
        Parameter const & back = Settings::ParameterInfo.Parameters.back();

        if (back.Category == TypeCategory::String || (back.Category == TypeCategory::Interface && Settings::ParameterInfo.Parameters.back().ClassType.empty()))
        {
            Write(out,
                  "\r\n    % %;",
                  Settings::ParameterInfo.ReturnType,
                  Settings::ParameterInfo.ReturnTypeName());
        }
        else if (!Settings::ParameterInfo.Parameters.back().ClassType.empty())
        {
            Write(out,
                  "\r\n    % % { nullptr };",
                  Settings::ParameterInfo.ReturnType,
                  Settings::ParameterInfo.ReturnTypeName());
        }
        else
        {
            Write(out,
                  "\r\n    % % {};",
                  Settings::ParameterInfo.ReturnType,
                  Settings::ParameterInfo.ReturnTypeName());
        }
    }
}

static void WriteMethodBodyPostCall(Output & out)
{
    if (Settings::ParameterInfo.HasReturnType)
    {
        Write(out,
              "\r\n    return %;",
              Settings::ParameterInfo.ReturnTypeName());
    }
}

static void WriteMethodBody(Output & out)
{
    Write(out,
          Strings::WriteMethodBody,
          Bind(WriteMethodBodyPreCall),
          Settings::MethodShim,
          Settings::MethodAbi,
          Bind(WriteAbiArguments),
          Bind(WriteMethodBodyPostCall));
}

static void WriteInterfaceMethodDeclaration(Output & out)
{
    Write(out,
          Strings::WriteInterfaceMethodDeclaration,
          Settings::ParameterInfo.ReturnType,
          Settings::MethodName,
          Bind(WriteParameters));

    if (StartsWith(Settings::MethodAbi, "add_"))
    {
        Write(out,
              Strings::WriteInterfaceEventMethodDeclaration,
              Settings::MethodName,
              Settings::InterfaceName,
              Settings::MethodName,
              Settings::MethodName,
              Bind(WriteParameters));
    }
}

static void WriteAbiInterfaceMethods(Output & out)
{
    GetInterfaceMethods([&]
    {
        Write(out,
              Strings::WriteAbiInterfaceMethod,
              Settings::MethodAbi,
              Bind(WriteAbiParameters));
    });
}

static void WriteInterfaceMethodDeclarations(Output & out)
{
    GetInterfaceMethods([&]
    {
        WriteInterfaceMethodDeclaration(out);
    });
}

static void WriteRequiredInterfaces(Output & out)
{
    bool first = true;
    std::string requires;

    GetRequiredInterfaces([&]
    {
        if (first)
        {
            first = false;
            requires = Settings::RequiredInterfaceName;
        }
        else
        {
            requires += ", ";
            requires += Settings::RequiredInterfaceName;
        }
    });

    if (!requires.empty())
    {
        Write(out, 
              Strings::WriteRequiredInterfaces,
              Settings::InterfaceName, 
              requires);
    }
}

static void WriteClassDefaultConstructorDefinition(Output & out)
{
    Write(out,
          Strings::WriteClassDefaultConstructorDefinition,
          Settings::ClassName,
          Settings::ClassName,
          Settings::ClassName,
          Settings::ClassName);
}

static void WriteStaticMethodDefinition(Output & out)
{
    Write(out,
          Strings::WriteStaticMethodDefinition,
          Settings::ParameterInfo.ReturnType,
          Settings::ClassName,
          Settings::MethodName,
          Bind(WriteParameters),
          Settings::ParameterInfo.HasReturnType ? "return " : "",
          Settings::ClassName,
          Settings::InterfaceName,
          Settings::MethodName,
          Bind(WriteModernArguments));

    if (StartsWith(Settings::MethodAbi, "add_"))
    {
        Write(out,
              Strings::WriteStaticEventMethodDefinition,
              Settings::InterfaceName,
              Settings::ClassName,
              Settings::MethodName,
              Bind(WriteParameters),
              Settings::ClassName,
              Settings::InterfaceName,
              Settings::Namespace,
              Settings::InterfaceName,
              Settings::MethodName,
              Settings::MethodName,
              Settings::ParameterInfo.Parameters[0].Name);
    }
}

static void WriteStaticMethodDeclaration(Output & out)
{
    Write(out,
          Strings::WriteStaticMethodDeclaration,
          Settings::ParameterInfo.ReturnType,
          Settings::MethodName,
          Bind(WriteParameters));

    if (StartsWith(Settings::MethodAbi, "add_"))
    {
        Write(out,
              Strings::WriteStaticEventMethodDeclaration,
              Settings::MethodName,
              Settings::InterfaceName,
              Settings::MethodName,
              Settings::MethodName,
              Bind(WriteParameters));
    }
}

static void WriteClassConstructorDefinition(Output & out)
{
    if (Settings::InterfaceComposable)
    {
        ParameterInfo & params = Settings::ParameterInfo;

        Write(out,
              Strings::WriteClassConstructorDefinitionComposable,
              Settings::ClassName,
              Settings::ClassName,
              Bind(WriteComposableConstructorParameters),
              params.Parameters[params.Parameters.size() - 3].Name,
              params.Parameters[params.Parameters.size() - 2].Name,
              Settings::ClassName,
              Settings::InterfaceName,
              Settings::MethodName,
              Bind(WriteModernArguments));
    }
    else
    {
        Write(out,
              Strings::WriteClassConstructorDefinition,
              Settings::ClassName,
              Settings::ClassName,
              Bind(WriteParameters),
              Settings::ClassName,
              Settings::ClassName,
              Settings::InterfaceName,
              Settings::MethodName,
              Bind(WriteModernArguments));
    }
}

static void WriteClassConstructor(Output & out)
{
    if (Settings::InterfaceComposable)
    {
        Write(out,
              Strings::WriteClassConstructorDeclaration,
              Settings::ClassName,
              Bind(WriteComposableConstructorParameters));
    }
    else
    {
        Write(out,
              Strings::WriteClassConstructorDeclaration,
              Settings::ClassName,
              Bind(WriteParameters));
    }
}

static void WriteClassConstructorDeclarations(Output & out)
{
    Write(out,
          Strings::WriteClassNullptrConstructor,
          Settings::ClassName);

    if (Settings::ClassActivatable)
    {
        Write(out,
              Strings::WriteClassDefaultConstructorDeclaration,
              Settings::ClassName);
    }

    GetPublicConstructorMethods([&]
    {
        WriteClassConstructor(out);
    });
}

static void WriteComposableOverridables(Output & out)
{
    bool first = true;

    GetClassOverrides([&]
    {
        if (first)
        {
            first = false;
        }
        else
        {
            Write(out, ", ");
        }

        Write(out, "%T<D>", Settings::InterfaceName);
    });

    if (first) // no overrides
    {
        Write(out, "Windows::IInspectable");
    }
}

static void WriteComposableRequires(Output & out)
{
    bool first = true;

    GetRequiredComposableInterfaces([&]
    {
        if (first)
        {
            first = false;
            Write(out, Settings::InterfaceName);
        }
        else
        {
            Write(out, ", %", Settings::InterfaceName);
        }
    });
}

static void WriteComposableConstructors(Output & out)
{
    GetComposableConstructors([&]
    {
        Write(out,
            Strings::WriteComposableConstructor,
            Settings::ClassName,
            Bind(WriteComposableConstructorParameters),
            Settings::ClassName,
            Settings::InterfaceName,
            Settings::MethodName,
            Bind(WriteComposableConstructorArguments));
    });
}

static void WriteOverrideDefaults(Output & out)
{
    GetInterfaceMethods([&]
    {
        Write(out,
              Strings::WriteOverrideDefault,
              Settings::ParameterInfo.ReturnType,
              Settings::MethodName,
              Bind(WriteParameters),
              Settings::ParameterInfo.HasReturnType ? "return " : "",
              Settings::InterfaceName,
              Settings::MethodName,
              Bind(WriteModernArguments));
    });
}

static void WriteDelegateOverrideVirtualInternalCall(Output & out)
{
    if (Settings::ParameterInfo.HasReturnType)
    {
        Parameter const & param = Settings::ParameterInfo.Parameters.back();

        if (param.IsArray())
        {
            Write(out, "std::tie(*__%Size, *%)", param.Name, param.Name);
        }
        else
        {
            Write(out, "*%", param.Name);
        }

        Write(out,
              " = detach((*this)(%))",
              Bind(WriteProducerForwardArguments));
    }
    else
    {
        Write(out,
              "(*this)(%)",
              Bind(WriteProducerForwardArguments));
    }
}

static void WriteOverrideVirtualInternalCall(Output & out)
{
    if (Settings::ParameterInfo.HasReturnType)
    {
        Parameter const & param = Settings::ParameterInfo.Parameters.back();

        if (param.IsArray())
        {
            Write(out, "std::tie(*__%Size, *%)", param.Name, param.Name);
        }
        else
        {
            Write(out, "*%", param.Name);
        }

        Write(out,
              " = detach(this->shim().%(%))",
              Settings::MethodName,
              Bind(WriteProducerForwardArguments));
    }
    else
    {
        Write(out,
              "this->shim().%(%)",
              Settings::MethodName,
              Bind(WriteProducerForwardArguments));
    }
}

static void WriteProducerCleanup(Output & out)
{
    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (param.Flags == ParameterFlags::In)
        {
            continue;
        }

        if (param.IsArray() && param.IsReferenceOrReturn())
        {
            Write(out, "\r\n            *__%Size = 0;", param.Name);
            Write(out, "\r\n            *% = nullptr;", param.Name);
        }
        else if (param.Category == TypeCategory::String ||
                 param.Category == TypeCategory::Interface ||
                 param.Category == TypeCategory::Delegate)
        {
            Write(out, "\r\n            *% = nullptr;", param.Name);
        }

        MODERN_ASSERT(param.Category != TypeCategory::Class);
    }
}

static void WriteInterfaceProducerVirtualMethods(Output & out)
{
    GetInterfaceMethods([&]
    {
        Write(out,
              Strings::WriteInterfaceProducerVirtualMethod,
              Settings::MethodAbi,
              Bind(WriteAbiProducerParameters),
              Bind(WriteOverrideVirtualInternalCall),
              Bind(WriteProducerCleanup));
    });
}

static void WriteBases(Output & out)
{
    bool first = true;
    std::string bases;

    GetBases([&]
    {
        if (first)
        {
            first = false;
            bases = Settings::BaseName;
        }
        else
        {
            bases += ", ";
            bases += Settings::BaseName;
        }
    });

    if (!bases.empty())
    {
        Write(out,
              ",\r\n    impl::bases<%, %>",
              Settings::ClassName,
              bases);
    }
}

static void WriteRequiredClassInterfaces(Output & out)
{
    bool first = true;
    std::string requires;

    GetRequiredClassInterfaces([&]
    {
        if (first)
        {
            first = false;
            requires = Settings::RequiredInterfaceName;
        }
        else
        {
            requires += ", ";
            requires += Settings::RequiredInterfaceName;
        }
    });

    if (!requires.empty())
    {
        Write(out,
              Strings::WriteRequiredInterfaces,
              Settings::ClassName,
              requires);
    }
}

static void WriteUsingMethodsForInterface(Output & out)
{
    GetUsingMethodsForInterface([&]
    {
        Write(out,
              Strings::WriteUsingMethod,
              Settings::UsingInterface,
              Settings::UsingMethod);
    });
}

static void WriteDelegateProducer(Output & out)
{
    Write(out,
          Strings::WriteDelegateProducer,
          Settings::DelegateName,
          Settings::DelegateName,
          Settings::DelegateName,
          Settings::DelegateName,
          Bind(WriteAbiProducerParameters),
          Bind(WriteDelegateOverrideVirtualInternalCall),
          Bind(WriteProducerCleanup));
}

static void WriteUsingMethodsForClass(Output & out)
{
    GetUsingMethodsForClass([&]
    {
        Write(out,
              Strings::WriteUsingMethod,
              Settings::UsingInterfaceName,
              Settings::UsingMethodName);
    });
}

void WriteStaticMethodDeclarations(Output & out)
{
    GetStaticMethodDeclarations([&]
    {
        WriteStaticMethodDeclaration(out);
    });
}

static void WriteClassDeclaration(Output & out)
{
    Write(out,
          Strings::WriteClassDeclaration,
          Settings::ClassName,
          Settings::ClassDefaultInterface,
          Bind(WriteBases),
          Bind(WriteRequiredClassInterfaces),
          Bind(WriteClassConstructorDeclarations),
          Bind(WriteUsingMethodsForClass),
          Bind(WriteStaticMethodDeclarations));
}

static void WriteStaticClassDeclaration(Output & out)
{
    Write(out,
          Strings::WriteStaticClassDeclaration,
          Settings::ClassName,
          Settings::ClassName,
          Bind(WriteStaticMethodDeclarations));
}

void WriteEnumerations(Output & out)
{
    GetEnumerations([&]
    {
        out.WriteNamespace(Settings::Namespace);

        if (Settings::EnumerationFlag)
        {
            Write(out,
                  Strings::WriteEnumerationFlag,
                  Settings::EnumerationName,
                  Bind(WriteEnumeratorsFlag),
                  Settings::EnumerationName);
        }
        else
        {
            Write(out,
                  Strings::WriteEnumeration,
                  Settings::EnumerationName,
                  Bind(WriteEnumerators));
        }
    });
}

void WriteStructures(Output & out)
{
    GetStructures([&]
    {
        out.WriteAbiNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteStructure,
              Settings::StructureName,
              Bind(WriteAbiStructureFields));
    });

    out.WriteNamespace();

    GetNonAbiStructures([&]
    {
        if (out.WriteNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
              Strings::WriteNonAbiStructure,
              Settings::StructureName,
              Settings::Namespace,
              Settings::StructureName);
    });

    GetAbiStructures([&]
    {
        out.WriteNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteStructure,
              Settings::StructureName,
              Bind(WriteStructureFields));
    });

    GetAbiStructures([&]
    {
        out.WriteNamespace("impl");

        Write(out,
              Strings::WriteSimpleTraits,
              Settings::Namespace,
              Settings::StructureName,
              Settings::Namespace,
              Settings::StructureName);
    });

    out.WriteNamespace();
}

void WriteAbiClassDeclarations(Output & out)
{
    out.WriteNamespace("ABI");
    Write(out, "\r\n");

    GetAbiClassDeclarations([&]
    {
        Write(out,
              Strings::WriteAbiClassDefault,
              Settings::Namespace,
              Settings::ClassName,
              Settings::InterfaceName);
    });

    out.WriteNamespace();
}

void WriteInterfaceTraits(Output & out)
{
    out.WriteNamespace("impl");

    GetInterfaceTraits([&]
    {
        if (Settings::InterfaceDelegate)
        {
            Write(out,
                  Strings::WriteSimpleTraits,
                  Settings::Namespace,
                  Settings::InterfaceName,
                  Settings::Namespace,
                  Settings::InterfaceName);
        }
        else
        {
            Write(out,
                  Strings::WriteInterfaceTraits,
                  Settings::Namespace, 
                  Settings::InterfaceName,
                  Settings::Namespace,
                  Settings::InterfaceName,
                  Settings::Namespace,
                  Settings::InterfaceName);
        }
    });

    GetClassImplementations([&]
    {
        if (Settings::ClassDefaultInterface.empty()) // static, not activatable, not composable
        {
            Write(out,
                  Strings::WriteClassImplementationStatic,
                  Settings::Namespace,
                  Settings::ClassName,
                  Settings::ClassDotName);
        }
        else // activatable/composable
        {
            Write(out,
                  Strings::WriteClassImplementation,
                  Settings::Namespace,
                  Settings::ClassName,
                  Settings::Namespace,
                  Settings::ClassName,
                  Settings::ClassDefaultInterface,
                  Settings::ClassDotName);
        }
    });
}

void WriteInterfaceProducers(Output & out)
{
    out.WriteNamespace("impl");

    GetInterfaces([&]
    {
        Write(out,
              Strings::WriteInterfaceProducer,
              Settings::Namespace,
              Settings::InterfaceName,
              Settings::Namespace,
              Settings::InterfaceName,
              Bind(WriteInterfaceProducerVirtualMethods));
    });
}

void WriteGenericInterfaces(Output & out)
{
    GetGenericInterfaces([&]
    {
        if (out.WriteAbiNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
            Strings::WriteGenericInterface,
            Settings::GenericDefine,
            Settings::GenericDefine,
            Settings::InterfaceGuid,
            Settings::InterfaceName,
            Settings::InterfaceName);
    });

    out.WriteNamespace();
}

void WriteInterfaceDefinitions(Output & out)
{
    GetDelegateDefinitions([&]
    {
        out.WriteNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteDelegateDefinition,
              Settings::InterfaceName,
              Settings::InterfaceName,
              Settings::InterfaceName,
              Settings::InterfaceName,
              Settings::InterfaceName,
              Settings::InterfaceName,
              Settings::ParameterInfo.ReturnType,
              Bind(WriteParameters));
    });

    GetInterfaceDefinitions([&]
    {
        out.WriteNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteInterfaceDefinition,
              Settings::InterfaceName,
              Settings::InterfaceName,
              Bind(WriteRequiredInterfaces),
              Settings::InterfaceName,
              Settings::InterfaceName,
              Bind(WriteUsingMethodsForInterface));
    });
}

void WriteAbiInterfaces(Output & out)
{
    GetAbiInterfaces([&]
    {
        out.WriteAbiNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteAbiInterface,
              Settings::InterfaceGuid,
              Settings::InterfaceName,
              Settings::InterfaceDelegate ? "IUnknown" : "Windows::IInspectable",
              Bind(WriteAbiInterfaceMethods));
    });
}

void WriteInterfacesMethodDefinitions(Output & out)
{
    Settings::MethodShim = "shim()";

    GetInterfaceMethodDefinitions([&]
    {
        out.WriteNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteInterfacesMethodDefinition,
              Settings::ParameterInfo.ReturnType,
              Settings::InterfaceName,
              Settings::MethodName,
              Bind(WriteParameters),
              Bind(WriteMethodBody));

        if (StartsWith(Settings::MethodAbi, "add_"))
        {
            Write(out,
                  Strings::WriteInterfacesEventMethodDefinition,
                  Settings::InterfaceName,
                  Settings::InterfaceName,
                  Settings::MethodName,
                  Bind(WriteParameters),
                  Settings::InterfaceName,
                  Settings::Namespace,
                  Settings::InterfaceName,
                  Settings::MethodName,
                  Settings::MethodName,
                  Settings::ParameterInfo.Parameters[0].Name);
        }
    });
}

void WriteInterfaceConsumers(Output & out)
{
    GetInterfaces([&]
    {
        out.WriteNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteInterfaceConsumer,
              Settings::InterfaceName,
              Settings::InterfaceName,
              Bind(WriteInterfaceMethodDeclarations));
    });
}

bool WriteComposable(Output & out)
{
    return GetClassesComposable([&]
    {
        out.WriteNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteClassComposable,
              Settings::ClassName,
              Bind(WriteComposableOverridables),
              Bind(WriteComposableRequires),
              Settings::ClassName,
              Bind(WriteComposableConstructors));
    });
}

bool WriteOverrides(Output & out)
{
    return GetOverrides([&]
    {
        out.WriteNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteOverride,
              Settings::Namespace,
              Settings::InterfaceName,
              Settings::InterfaceName,
              Settings::InterfaceName,
              Settings::Namespace,
              Settings::InterfaceName,
              Bind(WriteOverrideDefaults),
              Bind(WriteInterfaceProducerVirtualMethods));
    });
}

void WriteClassDeclarations(Output & out)
{
    GetClasses([&]
    {
        out.WriteNamespace(Settings::Namespace);

        if (!Settings::ClassDefaultInterface.empty())
        {
            WriteClassDeclaration(out);
        }
        else
        {
            WriteStaticClassDeclaration(out);
        }
    });
}

void WriteClassDefinitions(Output & out)
{
    GetClasses([&]
    {
        out.WriteNamespace(Settings::Namespace);

        if (!Settings::ClassDefaultInterface.empty())
        {
            if (Settings::ClassActivatable)
            {
                WriteClassDefaultConstructorDefinition(out);
            }

            GetPublicConstructorMethods([&]
            {
                WriteClassConstructorDefinition(out);
            });
        }

        GetStaticMethodDeclarations([&]
        {
            WriteStaticMethodDefinition(out);
        });
    });
}

void WriteDelegates(Output & out)
{
    Settings::MethodShim = "(*this)";
    Settings::MethodAbi = "abi_Invoke";

    GetDelegates([&]
    {
        out.WriteNamespace(Settings::Namespace);

        WriteDelegateProducer(out);
    });

    out.WriteNamespace();
}

void WriteForwards(Output & out)
{
    GetStructures([&]
    {
        if (out.WriteAbiNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
              Strings::WriteStructureDeclaration,
              Settings::StructureName);
    });

    out.WriteNamespace();

    GetNonAbiStructures([&]
    {
        if (out.WriteNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
              Strings::WriteNonAbiStructure,
              Settings::StructureName,
              Settings::Namespace,
              Settings::StructureName);
    });

    GetAbiStructures([&]
    {
        if (out.WriteNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
              Strings::WriteStructureDeclaration,
              Settings::StructureName);
    });

    out.WriteNamespace();

    GetAbiInterfaces([&]
    {
        if (out.WriteAbiNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
              Strings::WriteStructureDeclaration,
              Settings::InterfaceName);
    });

    GetAbiClassDeclarations([&]
    {
        if (out.WriteAbiNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
              Strings::WriteStructureDeclaration,
              Settings::ClassName);
    });

    out.WriteNamespace();

    GetDelegates([&]
    {
        if (out.WriteNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
              Strings::WriteStructureDeclaration,
              Settings::DelegateName);
    });

    GetInterfaces([&]
    {
        if (out.WriteNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
            Strings::WriteStructureDeclaration,
            Settings::InterfaceName);
    });

    GetClasses([&]
    {
        if (out.WriteNamespace(Settings::Namespace))
        {
            Write(out, "\r\n");
        }

        Write(out,
              Strings::WriteStructureDeclaration,
              Settings::ClassName);
    });

    out.WriteNamespace();
}

void WriteInterfaceImplForwards(Output & out)
{
    out.WriteNamespace(Settings::Namespace);
    Write(out, "\r\n");

    GetInterfaces([&]
    {
        Write(out,
              Strings::WriteInterfaceConsumerForward,
              Settings::InterfaceName);
    });


    GetDelegates([&]
    {
        Write(out,
              Strings::WriteDelegateForward,
              Settings::DelegateName);
    });

    out.WriteNamespace();
}

void WriteRequiredAbiHeadersForAbi(Output & out)
{
    GetGenericInterfaceArguments([&]
    {
        Write(out, Strings::WriteInclude, Settings::NamespaceDotName + Settings::AbiLayerExtension);
    });
}

void WriteRequiredAbiHeadersForInterface(Output & out)
{
    GetFieldNamespaces([&]
    {
        Write(out, Strings::WriteInclude, Settings::NamespaceDotName + Settings::AbiLayerExtension);
    });
}

void WriteRequiredForwards(Output & out)
{
    Write(out, Strings::WriteInclude, "../base.h");
    Write(out, Strings::WriteInclude, Settings::FileNamespaceDotName + Settings::ForwardLayerExtension);

    GetRequiredForwards([&]
    {
        Write(out, Strings::WriteInclude, Settings::NamespaceDotName + Settings::ForwardLayerExtension);
    });
}

void WriteRequiredInterfaceIncludes(Output & out)
{
    GetRequiredInterfaceIncludes([&]
    {
        Write(out, Strings::WriteInclude, Settings::NamespaceDotName + Settings::InterfaceLayerExtension);
    });
}

void WriteRequiredClasses(Output & out)
{
    std::vector<std::string> namespacesToIgnore;

    GetRequiredParamImpls([&]
    {
        if (std::find(namespacesToIgnore.begin(), namespacesToIgnore.end(), Settings::Namespace) == namespacesToIgnore.end())
        {
            Write(out, Strings::WriteInclude, Settings::InternalPath + Settings::NamespaceDotName + Settings::ClassDeclLayerExtension);
            namespacesToIgnore.push_back(Settings::Namespace);
        }
    });
}

void WriteRequiredOverrides(Output & out)
{
    GetClassOverrideIncludes([&]
    {
        Write(out, Strings::WriteInclude, Settings::NamespaceDotName + Settings::OverrideLayerExtension);
    });
}

void WriteDelegateShims(Output & out)
{
    Settings::MethodShim = "(*this)";
    Settings::MethodAbi = "abi_Invoke";

    GetDelegates([&]
    {
        out.WriteNamespace(Settings::Namespace);

        char const * const hasReturn = Settings::ParameterInfo.HasReturnType ? "return " : "";

        Write(out,
              Strings::WriteDelegateShims,
              Settings::DelegateName,
              Settings::DelegateName,
              Settings::DelegateName,
              Settings::DelegateName,
              Settings::DelegateName,
              Settings::DelegateName,
              Settings::DelegateName,
              Settings::DelegateName,
              hasReturn,
              Settings::DelegateName,
              Settings::DelegateName,
              Settings::DelegateName,
              hasReturn,
              Settings::ParameterInfo.ReturnType,
              Settings::DelegateName,
              Bind(WriteParameters),
              Bind(WriteMethodBody));
    });
}

void WriteDefinitionsForRequiredInterfaces(Output & out)
{
    GetRequiredInterfaceHeaders([&]
    {
        if (Settings::FileNamespace.find(Settings::Namespace) == std::string::npos)
        {
            Write(out, Strings::WriteInclude, Settings::NamespaceDotName + ".h");
        }
    });
}

}
