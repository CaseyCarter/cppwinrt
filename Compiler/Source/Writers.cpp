#include "Precompiled.h"
#include "Writers.h"
#include "Output.h"
#include "Strings.h"
#include "Version.h"
#include "Year.h"
#include "Database.h"
#include "Settings.h"

namespace Modern {

using namespace Database;

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

static void WriteTemplatePreamble(Output & output, unsigned const stringCount, bool const hasDelegate)
{
    MODERN_ASSERT(hasDelegate || 0 != stringCount);

    Write(output, "template <");

    bool first = true;

    for (unsigned s = 0; s != stringCount; ++s)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            Write(output, ", ");
        }

        Write(output, "unsigned S%", s);
    }

    if (hasDelegate)
    {
        if (!first)
        {
            Write(output, ", ");
        }

        Write(output, "typename F");
    }

    Write(output, "> ");
}

static void WriteDelegateForwardArgunents(Output & output)
{
    bool first = true;

    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (first)
        {
            first = false;
        }
        else if (param.Direction != ParameterDirection::Return)
        {
            Write(output, ", ");
        }

        if (param.Direction == ParameterDirection::In)
        {
            if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate || param.Category == TypeCategory::String)
            {
                Write(output, Strings::LibraryForwardArgument, param.ModernType(), param.Name);
            }
            else
            {
                Write(output, param.Name);
            }
        }

        // TODO: deal with out and return parameters
    }
}

static void WriteAbiArguments(Output & output, unsigned const stringCount)
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
            Write(output, ", ");
        }

        if (param.Direction == ParameterDirection::In)
        {
            if (param.Category == TypeCategory::String && 0 != stringCount)
            {
                Write(output, "StringReference(%)", param.Name);
            }
            else if (param.Category == TypeCategory::Enumeration || param.Category == TypeCategory::Structure || param.Category == TypeCategory::Value || param.Category == TypeCategory::Boolean)
            {
                Write(output, "%", param.Name);
            }
            else
            {
                Write(output, "get(%)", param.Name);
            }
        }
        else
        {
            if (param.Category == TypeCategory::Enumeration || param.Category == TypeCategory::Structure || param.Category == TypeCategory::Value || param.Category == TypeCategory::Boolean)
            {
                Write(output, "&%", param.Name);
            }
            else
            {
                Write(output, "put(%)", param.Name);
            }
        }
    }
}

static void WriteComposableConstructorArguments(Output & output)
{
    MODERN_ASSERT(Settings::ParameterInfo.Parameters.size() >= 3);

    for (size_t i = 0; i != Settings::ParameterInfo.Parameters.size() - 3; ++i)
    {
        Parameter const & param = Settings::ParameterInfo.Parameters[i];

        Write(output, "%, ", param.Name);
    }
}

static void WriteModernArguments(Output & output, bool const hasDelegate)
{
    bool first = true;

    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (param.Direction == ParameterDirection::Return)
        {
            break;
        }

        if (first)
        {
            first = false;
        }
        else
        {
            Write(output, ", ");
        }

        if (hasDelegate && param.Category == TypeCategory::Delegate)
        {
            size_t pos = param.Type.find('<');

            if (std::string::npos == pos)
            {
                pos = param.Type.size();
            }

            pos = param.Type.find_last_of(':', pos);

            Write(output, "%%(%)", Substring(param.Type, pos + 1), &param.Type[pos + 2], param.Name);
        }
        else
        {
            Write(output, param.Name);
        }
    }
}

static void WriteDelegateAbiParameters(Output & output)
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
            Write(output, ", ");
        }

        if (param.Direction == ParameterDirection::In)
        {
            if (param.Category == TypeCategory::String)
            {
                Write(output, "HSTRING %", param.Name);
            }
            else if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate)
            {
                Write(output, "abi_arg_in<%> %", param.Type, param.Name);
            }
            else
            {
                Write(output, "% %", param.Type, param.Name);
            }
        }
        else
        {
            MODERN_ASSERT(param.Direction == ParameterDirection::Return || param.Direction == ParameterDirection::Out);

            if (param.Category == TypeCategory::String)
            {
                Write(output, "HSTRING * %", param.Name);
            }
            else if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate)
            {
                Write(output, "abi_arg_out<%> %", param.Type, param.Name);
            }
            else
            {
                Write(output, "% * %", param.Type, param.Name);
            }
        }
    }
}

static void WriteAbiParameters(Output & output)
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
            Write(output, ", ");
        }

        if (param.Direction == ParameterDirection::In)
        {
            if (param.Category == TypeCategory::String)
            {
                Write(output, "HSTRING %", param.Name);
            }
            else if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate)
            {
                Write(output, "% * %", param.Type, param.Name);
            }
            else if (param.Category == TypeCategory::Enumeration || param.Category == TypeCategory::Structure)
            {
                Write(output, "winrt::% %", param.Type, param.Name);
            }
            else
            {
                Write(output, "% %", param.Type, param.Name);
            }
        }
        else if (param.Direction == ParameterDirection::Out || param.Direction == ParameterDirection::Return)
        {
            if (param.Category == TypeCategory::String)
            {
                Write(output, "HSTRING * %", param.Name);
            }
            else if (param.Category == TypeCategory::Interface || param.Category == TypeCategory::Delegate)
            {
                Write(output, "% ** %", param.Type, param.Name);
            }
            else if (param.Category == TypeCategory::Enumeration || param.Category == TypeCategory::Structure)
            {
                Write(output, "winrt::% * %", param.Type, param.Name);
            }
            else
            {
                Write(output, "% * %", param.Type, param.Name);
            }
        }
    }
}

static void WriteParameter(Output & output, Parameter const & param, unsigned const stringCount, bool const hasDelegate, bool const definition, unsigned & s)
{
    if (param.Direction == ParameterDirection::In)
    {
        if (param.Category == TypeCategory::String)
        {
            if (0 != stringCount)
            {
                Write(output, "wchar_t const (&%)[S%]", param.Name, s++);
            }
            else
            {
                Write(output, "StringReference const & %", param.Name);
            }
        }
        else if (param.Category == TypeCategory::Structure || param.Category == TypeCategory::Interface)
        {
            Write(output, "% const & %", param.ModernType(), param.Name);
        }
        else if (param.Category == TypeCategory::Delegate)
        {
            if (hasDelegate)
            {
                Write(output, "F %", param.Name);
            }
            else
            {
                Write(output, "% const & %", param.Type, param.Name);
            }
        }
        else if (definition)
        {
            Write(output, "% const %", param.Type, param.Name);
        }
        else
        {
            Write(output, "% %", param.Type, param.Name);
        }
    }
    else if (param.Direction == ParameterDirection::Out)
    {
        Write(output, "% & %", param.ModernType(), param.Name);
    }
}

static void WriteComposableConstructorParameters(Output & output, unsigned const stringCount, bool const hasDelegate, bool const definition)
{
    MODERN_ASSERT(Settings::ParameterInfo.Parameters.size() >= 3);
    unsigned s = 0;

    for (size_t i = 0; i != Settings::ParameterInfo.Parameters.size() - 3; ++i)
    {
        Parameter const & param = Settings::ParameterInfo.Parameters[i];

        if (i != 0)
        {
            Write(output, ", ");
        }

        WriteParameter(output, param, stringCount, hasDelegate, definition, s);
    }
}

static void WriteParameters(Output & output, unsigned const stringCount, bool const hasDelegate, bool const definition)
{
    bool first = true;
    unsigned s = 0;

    for (Parameter const & param : Settings::ParameterInfo.Parameters)
    {
        if (first)
        {
            first = false;
        }
        else if (param.Direction != ParameterDirection::Return)
        {
            Write(output, ", ");
        }

        WriteParameter(output, param, stringCount, hasDelegate, definition, s);
    }
}

static void WriteInterfaceMethod(Output & h, Output & methods, unsigned const stringCount, bool const hasDelegate)
{
    Write(h, "\t");
    Write(methods, "\ntemplate <typename T> ");

    if (hasDelegate || 0 != stringCount)
    {
        WriteTemplatePreamble(h, stringCount, hasDelegate);
        WriteTemplatePreamble(methods, stringCount, hasDelegate);
    }

    Write(h, 
          Strings::LibraryNonStaticMethodDeclarationOpen, 
          Settings::ParameterInfo.ReturnType(),
          Settings::MethodName);

    WriteParameters(h, stringCount, hasDelegate, false);

    Write(h, 
          Strings::LibraryNonStaticMethodDeclarationClose);

    Write(methods, 
          Strings::LibraryMethodDefinitionOpen, 
          Settings::ParameterInfo.ReturnType(),
          Settings::InterfaceName, 
          Settings::MethodName);

    WriteParameters(methods, 
                    stringCount, 
                    hasDelegate, 
                    true);

    if (hasDelegate)
    {
        if (Settings::ParameterInfo.HasReturnType)
        {
            Write(methods, 
                  Strings::LibraryDelegateMethodDefinitionBodyReturnTypeOpen, 
                  Settings::MethodName);
        }
        else
        {
            Write(methods, 
                  Strings::LibraryDelegateMethodDefinitionBodyNoReturnTypeOpen, 
                  Settings::MethodName);
        }

        WriteModernArguments(methods, hasDelegate);

        Write(methods, 
              Strings::LibraryDelegateMethodDefinitionClose);
    }
    else if (Settings::ParameterInfo.HasReturnType)
    {
        Parameter const & back = Settings::ParameterInfo.Parameters.back();

        if (back.Category == TypeCategory::String || (back.Category == TypeCategory::Interface && Settings::ParameterInfo.Parameters.back().ClassType.empty()))
        {
            Write(methods,
                  Strings::LibraryNonStaticMethodDefinitionBodyReturnTypeOpenDefault,
                  Settings::ParameterInfo.ReturnType(),
                  Settings::ParameterInfo.ReturnTypeName(),
                  Settings::MethodAbi);
        }
        else if (!Settings::ParameterInfo.Parameters.back().ClassType.empty())
        {
            Write(methods, 
                  Strings::LibraryNonStaticMethodDefinitionBodyReturnTypeOpenClass,
                  Settings::ParameterInfo.ReturnType(),
                  Settings::ParameterInfo.ReturnTypeName(),
                  Settings::MethodAbi);
        }
        else
        {
            Write(methods, 
                  Strings::LibraryNonStaticMethodDefinitionBodyReturnTypeOpen, 
                  Settings::ParameterInfo.ReturnType(),
                  Settings::ParameterInfo.ReturnTypeName(),
                  Settings::MethodAbi);
        }

        WriteAbiArguments(methods, stringCount);

        Write(methods, 
              Strings::LibraryNonStaticMethodDefinitionReturnTypeClose, 
              Settings::ParameterInfo.ReturnTypeName());
    }
    else
    {
        Write(methods, 
              Strings::LibraryNonStaticMethodDefinitionBodyNoReturnTypeOpen, 
              Settings::MethodAbi);

        WriteAbiArguments(methods, stringCount);

        Write(methods, 
              Strings::LibraryNonStaticMethodDefinitionNoReturnTypeClose);
    }
}

static void WriteInterfaceMethods(Output & h, Output & methods, Output & abi)
{
    unsigned deprecated = 0;

    GetInterfaceMethods([&]
    {
        if (!Settings::MethodDeprecated)
        {
            Write(abi,
                  Strings::WriteAbiInterfaceMethod,
                  Settings::MethodAbi,
                  Bind(WriteAbiParameters));

            ParameterInfo & params = Settings::ParameterInfo;

            WriteInterfaceMethod(h, methods, 0, false);

            if (0 != params.StringCount)
            {
                WriteInterfaceMethod(h, methods, params.StringCount, false);
            }

            if (params.HasDelegate)
            {
                WriteInterfaceMethod(h, methods, 0, true);
            }

            if (params.HasDelegate && 0 != params.StringCount)
            {
                WriteInterfaceMethod(h, methods, params.StringCount, true);
            }
        }
        else
        {
            Write(abi,
                  Strings::WriteAbiInterfaceMethodDeprecated,
                  ++deprecated);
        }
    });
}

static void WriteRequiredInterfaces(Output & output)
{
    bool first = true;
    std::string requires;

    GetRequiredInterfaces([&](char const * const interfaceName)
    {
        if (first)
        {
            first = false;
            requires = interfaceName;
        }
        else
        {
            requires += ", ";
            requires += interfaceName;
        }
    });

    if (!requires.empty())
    {
        Write(output, 
              Strings::LibraryInterfaceRequires, 
              Settings::InterfaceName, 
              requires);
    }
}

static void WriteClassDefaultConstructor(Output & h, Output & methods)
{
    Write(h,
          Strings::LibraryClassDefaultConstructorDeclaration,
          Settings::ClassName);

    Write(methods,
          Strings::LibraryClassDefaultConstructorDefinition,
          Settings::ClassName,
          Settings::ClassName,
          Settings::ClassName,
          Settings::ClassName);
}

static void WriteStaticMethod(Output & h, Output & methods, unsigned const stringCount, bool const hasDelegate)
{
    Write(h, "\t");
    Write(methods, "\n");

    if (hasDelegate || 0 != stringCount)
    {
        WriteTemplatePreamble(h, stringCount, hasDelegate);
        WriteTemplatePreamble(methods, stringCount, hasDelegate);
    }
    else
    {
        Write(methods, "inline ");
    }

    Write(h,
          Strings::LibraryStaticMethodDeclarationOpen,
          Settings::ParameterInfo.ReturnType(),
          Settings::MethodName);

    WriteParameters(h, stringCount, hasDelegate, false);

    Write(h, Strings::LibraryStaticMethodDeclarationClose);

    Write(methods, Strings::LibraryStaticMethodDefinitionOpen, Settings::ParameterInfo.ReturnType(), Settings::ClassName, Settings::MethodName);

    WriteParameters(methods, stringCount, hasDelegate, true);

    if (Settings::ParameterInfo.HasReturnType)
    {
        Write(methods, Strings::LibraryStaticMethodDefinitionBodyReturnTypeOpen, Settings::ClassName, Settings::InterfaceName, Settings::MethodName);
    }
    else
    {
        Write(methods, Strings::LibraryStaticMethodDefinitionBodyNoReturnTypeOpen, Settings::ClassName, Settings::InterfaceName, Settings::MethodName);
    }

    WriteModernArguments(methods, hasDelegate);
    Write(methods, Strings::LibraryRequiredMethodDefinitionClose);
}

static void WriteClassConstructor(Output & h, Output & methods, unsigned const stringCount, bool const hasDelegate)
{
    Write(h, "\t");
    Write(methods, "\n");

    if (hasDelegate || 0 != stringCount)
    {
        WriteTemplatePreamble(h, stringCount, hasDelegate);
        WriteTemplatePreamble(methods, stringCount, hasDelegate);
    }
    else
    {
        Write(methods, "inline ");
    }

    ParameterInfo & params = Settings::ParameterInfo;

    if (Settings::InterfaceComposable)
    {
        Write(h,
              Strings::WriteClassConstructorDeclaration,
              Settings::ClassName,
              Bind(WriteComposableConstructorParameters, stringCount, hasDelegate, false));

        Write(methods,
              Strings::WriteClassConstructorDefinitionComposable,
              Settings::ClassName,
              Settings::ClassName,
              Bind(WriteComposableConstructorParameters, stringCount, hasDelegate, true),
              params.Parameters[params.Parameters.size() - 3].Name,
              params.Parameters[params.Parameters.size() - 2].Name,
              Settings::ClassName,
              Settings::InterfaceName,
              Settings::MethodName,
              Bind(WriteModernArguments, hasDelegate));
    }
    else
    {
        Write(h,
              Strings::WriteClassConstructorDeclaration,
              Settings::ClassName,
              Bind(WriteParameters, stringCount, hasDelegate, false));

        Write(methods,
              Strings::WriteClassConstructorDefinition,
              Settings::ClassName,
              Settings::ClassName,
              Bind(WriteParameters, stringCount, hasDelegate, true),
              Settings::ClassName,
              Settings::ClassName,
              Settings::InterfaceName,
              Settings::MethodName,
              Bind(WriteModernArguments, hasDelegate));
    }
}

static void WriteStaticMethods(Output & h, Output & methods)
{
    GetStaticInterfaces([&]
    {
        GetInterfaceMethods([&]
        {
            if (Settings::MethodDeprecated)
            {
                return;
            }

            ParameterInfo & params = Settings::ParameterInfo;

            WriteStaticMethod(h, methods, 0, false);

            if (0 != params.StringCount)
            {
                WriteStaticMethod(h, methods, params.StringCount, false);
            }

            if (params.HasDelegate)
            {
                WriteStaticMethod(h, methods, 0, true);
            }

            if (params.HasDelegate && 0 != params.StringCount)
            {
                WriteStaticMethod(h, methods, params.StringCount, true);
            }
        });
    });
}

static void WriteClassConstructors(Output & h, Output & methods)
{
    Write(h, "\t%(std::nullptr_t) noexcept {}\n", Settings::ClassName);

    if (Settings::ClassActivatable)
    {
        WriteClassDefaultConstructor(h, methods);
    }

    GetClassConstructorsPublic([&]
    {
        GetConstructorMethods([&]
        {
            ParameterInfo & params = Settings::ParameterInfo;

            WriteClassConstructor(h, methods, 0, false);

            if (0 != params.StringCount)
            {
                WriteClassConstructor(h, methods, params.StringCount, false);
            }

            if (params.HasDelegate)
            {
                WriteClassConstructor(h, methods, 0, true);
            }

            if (params.HasDelegate && 0 != params.StringCount)
            {
                WriteClassConstructor(h, methods, params.StringCount, true);
            }
        });
    });
}

static void WriteComposableOverridables(Output & output)
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
            Write(output, ", ");
        }

        Write(output, "%T<T>", Settings::InterfaceName);
    });

    if (first) // no overrides
    {
        Write(output, "::IInspectable");
    }
}

static void WriteComposableRequires(Output & output)
{
    bool first = true;

    GetRequiredComposableInterfaces([&]
    {
        if (first)
        {
            first = false;
            Write(output, Settings::InterfaceName);
        }
        else
        {
            Write(output, ", %", Settings::InterfaceName);
        }
    });
}

static void WriteComposableConstructors(Output & output)
{
    GetComposableConstructors([&]
    {
        GetConstructorMethods([&]
        {
            Write(output,
                  Strings::WriteComposableConstructor,
                  Settings::ClassName,
                  Bind(WriteComposableConstructorParameters, 0, false, true),
                  Settings::ClassName,
                  Settings::InterfaceName,
                  Settings::MethodName,
                  Bind(WriteComposableConstructorArguments));
        });
    });
}

static void WriteOverrideDefaults(Output & output, int const interfaceId, char const * const interfaceName, char const * const interfaceNamespace)
{
    auto returnType = []
    {
        if (0 == strcmp(Settings::ParameterInfo.ReturnType(), "IInspectable"))
        {
            return "Windows::IInspectable";
        }
        else
        {
            return Settings::ParameterInfo.ReturnType();
        }
    };

    Settings::InterfaceId = interfaceId;

    GetInterfaceMethods([&]
    {
        if (Settings::MethodDeprecated)
        {
            return;
        }

        Write(output,
              Strings::WriteOverrideDefault,
              returnType(),
              Settings::MethodName,
              Bind(WriteParameters, 0, false, true),
              Settings::ParameterInfo.HasReturnType ? "return " : "",
              interfaceNamespace,
              interfaceName,
              Settings::MethodName,
              Bind(WriteModernArguments, false));
    });
}

static void WriteOverrideVirtuals(Output & output, int const interfaceId)
{
    Settings::InterfaceId = interfaceId;

    GetInterfaceMethods([&]
    {
        if (Settings::MethodDeprecated)
        {
            return;
        }

        Write(output,
              Strings::WriteOverrideVirtual,
              Settings::MethodAbi,
              Bind(WriteDelegateAbiParameters),
              "",
              Settings::MethodName,
              Bind(WriteDelegateForwardArgunents));
    });
}

static void WriteBases(Output & output)
{
    bool first = true;
    std::string bases;

    GetBases([&](char const * const base)
    {
        if (first)
        {
            first = false;
            bases = base;
        }
        else
        {
            bases += ", ";
            bases += base;
        }
    });

    if (!bases.empty())
    {
        Write(output,
              ",\n\tbases<%, %>",
              Settings::ClassName,
              bases);
    }
}

static void WriteRequiredClassInterfaces(Output & output)
{
    bool first = true;
    std::string requires;

    GetRequiredClassInterfaces([&](char const * const interfaceName)
    {
        if (first)
        {
            first = false;
            requires = interfaceName;
        }
        else
        {
            requires += ", ";
            requires += interfaceName;
        }
    });

    if (!requires.empty())
    {
        Write(output,
              Strings::LibraryInterfaceRequires,
              Settings::ClassName,
              requires);
    }
}

static void WriteIncludePrecompiled(Output & out)
{
    Write(out,
          "#include \"pch.h\"\n");
}

static void WriteIncludeComponentClass(Output & out, std::string const & name)
{
    Write(out,
          "#include \"%.h\"\n",
          name);
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

    out.WriteNamespace();
}

void WriteStructures(Output & out)
{
    GetStructures([&]
    {
        out.WriteNamespace(Settings::Namespace);

        Write(out,
              Strings::WriteStructure,
              Settings::StructureName,
              Bind(WriteStructureFields));
    });

    out.WriteNamespace();
}

//void WriteAbiClassDeclarations(Output & out)
//{
//    out.OpenModernNamespace();
//
//    GetClassDeclarations([&]
//    {
//        if (!Settings::ClassDefaultInterface.empty())
//        {
//            Write(out, 
//                  Strings::WriteAbiClassDeclaration, 
//                  Settings::Namespace,
//                  Settings::ClassName, 
//                  Settings::ClassDefaultInterface);
//        }
//        //else
//        //{
//        //    Write(out, 
//        //          Strings::WriteAbiClassDeclarationStatic, 
//        //          Settings::ClassName,
//        //          Settings::ClassDotName,
//        //          Settings::ClassDotNameLength);
//        //}
//    });
//
//    out.CloseModernNamespace();
//}

void WriteAbiInterfaceDeclarations(Output & out)
{
    GetInterfaceDeclarations([&]
    {
        if (out.WriteAbiNamespace(Settings::Namespace))
        {
            Write(out, "\n");
        }

        Write(out, 
              Strings::WriteStructureDeclaration, 
              Settings::InterfaceName);
    });

    out.WriteNamespace();
}

void WriteAbiClassDeclarations(Output & out)
{
    out.WriteNamespace("ABI");
    Write(out, "\n");

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

void WriteDeclarations(Output & out)
{
    GetDeclarations([&]
    {
        if (out.WriteNamespace(Settings::Namespace))
        {
            Write(out, "\n");
        }

        Write(out, 
              Strings::WriteClassDeclaration, 
              Settings::ClassName);
    });

    out.WriteNamespace();
}

void WriteImplementation(Output & out)
{
    out.WriteNamespace("impl");

    GetInterfaceNames([&]
    {
        Write(out,
              Strings::WriteImplementationInterface,
              Settings::Namespace, 
              Settings::InterfaceName,
              Settings::Namespace,
              Settings::InterfaceName,
              Settings::Namespace,
              Settings::InterfaceName);
    });

    GetClassImplementations([&]
    {
        if (Settings::ClassDefaultInterface.empty()) // static, not activatable, not composable
        {
            Write(out,
                  Strings::WriteClassImplementationStatic,
                  Settings::Namespace,
                  Settings::ClassName,
                  Settings::ClassDotName,
                  Settings::ClassDotNameLength);
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
                  Settings::ClassDotName,
                  Settings::ClassDotNameLength);
        }
    });

    out.WriteNamespace();
}

void WriteGenericInterfaces(Output & out)
{
    GetGenericInterfaces([&]
    {
        if (out.WriteAbiNamespace(Settings::Namespace))
        {
            Write(out, "\n");
        }

        Write(out,
              Strings::LibraryGenericInterface, 
              Settings::InterfaceGuid, 
              Settings::InterfaceName, 
              Settings::InterfaceName);
    });

    out.WriteNamespace();
}

void WriteInterfaceDefinitions(Output & out)
{
    GetInterfaceDefinitions([&]
    {
        out.WriteNamespace(Settings::Namespace);

        if (Settings::InterfaceDelegate)
        {
            Write(out,
                  Strings::LibraryInterfaceUnknownOpen, 
                  Settings::InterfaceName, 
                  Settings::InterfaceName,
                  Settings::InterfaceName);
        }
        else
        {
            Write(out,
                  Strings::LibraryInterfaceInspectableOpen, 
                  Settings::InterfaceName,
                  Settings::InterfaceName,
                  Settings::InterfaceName);
        }

        WriteRequiredInterfaces(out);

        Write(out,
              Strings::LibraryInterfaceDefinitionMacro,
              Settings::InterfaceName,
              Settings::InterfaceName);

        GetUsingMethodsForInterface([&]
        {
            Write(out,
                  Strings::LibraryClassUsingMethod, 
                  Settings::UsingInterface, 
                  Settings::UsingMethod);
        });

        Write(out,
              Strings::LibraryInterfaceDefinitionClose);
    });

    out.WriteNamespace();
}

void WriteInterfaces(Output & h, Output & methods, Output & abi)
{
    GetInterfaces([&]
    {
        h.WriteNamespace(Settings::Namespace);
        methods.WriteNamespace(Settings::Namespace);
        abi.WriteAbiNamespace(Settings::Namespace);

        Write(h, 
              Strings::LibraryInterfaceImplOpen, 
              Settings::InterfaceName,
              Settings::InterfaceName);

        if (Settings::InterfaceDelegate)
        {
            Write(abi, 
                  Strings::LibraryAbiInterfaceUnknownOpen, 
                  Settings::InterfaceGuid, 
                  Settings::InterfaceName);
        }
        else
        {
            Write(abi, 
                  Strings::LibraryAbiInterfaceInspectableOpen, 
                  Settings::InterfaceGuid, 
                  Settings::InterfaceName);
        }

        WriteInterfaceMethods(h, methods, abi);

        Write(h, 
              Strings::LibraryInterfaceClose);

        Write(abi, 
              Strings::LibraryInterfaceClose);
    });

    h.WriteNamespace();
    methods.WriteNamespace();
    abi.WriteNamespace();
}

void WriteComposable(Output & output)
{
    GetClassesComposable([&]
    {
        output.WriteNamespace(Settings::Namespace);

        Write(output,
              Strings::WriteClassComposable,
              Settings::ClassName,
              Bind(WriteComposableOverridables),
              Bind(WriteComposableRequires),
              Settings::ClassDefaultInterface,
              Bind(WriteComposableConstructors));
    });

    output.WriteNamespace();
}

void WriteOverrides(Output & output)
{
    GetOverrides([&](int const id, char const * const name, char const * const ns)
    {
        output.WriteNamespace(ns);

        Write(output,
              Strings::WriteOverrideTemplate,
              ns,
              name,
              name,
              Bind(WriteOverrideDefaults, id, name, ns),
              Bind(WriteOverrideVirtuals, id));
    });

    output.WriteNamespace();
}

void WriteClasses(Output & h, Output & methods)
{
    GetClasses([&]
    {
        h.WriteNamespace(Settings::Namespace);
        methods.WriteNamespace(Settings::Namespace);

        if (!Settings::ClassDefaultInterface.empty())
        {
            Write(h, 
                  Strings::LibraryClassOpen, 
                  Settings::ClassName, 
                  Settings::ClassDefaultInterface);

            WriteBases(h);

            WriteRequiredClassInterfaces(h);

            Write(h, 
                  Strings::LibraryClassOpenType);

            WriteClassConstructors(h, methods);

            GetUsingMethodsForClass([&](char const * const usingInterface, char const * const usingMethod)
            {
                Write(h, Strings::LibraryClassUsingMethod, usingInterface, usingMethod);
            });
        }
        else
        {
            Write(h, 
                  Strings::LibraryClassStaticOpen, 
                  Settings::ClassName,
                  Settings::ClassName);
        }

        WriteStaticMethods(h, methods);
        
        Write(h, Strings::LibraryClassClose);
    });

    h.WriteNamespace();
    methods.WriteNamespace();
}

void WriteDelegates(Output & out)
{
    GetDelegates([&]
    {
        out.WriteNamespace(Settings::Namespace);

        char const * const name = static_cast<char const *>(&Settings::DelegateName[1]);

        Write(out,
              Strings::WriteDelegateInternal,
              name,
              Settings::DelegateName, 
              name,
              Bind(WriteDelegateAbiParameters),
              Bind(WriteDelegateForwardArgunents));

        Write(out,
              Strings::WriteDelegateFunction, 
              Settings::DelegateName,
              name,
              name);
    });

    out.WriteNamespace();
}

static void WriteComponentClassInterfaces(Output & out)
{
    bool first = true;

    GetRequiredComponentClassInterfaces([&]
    {
        if (first)
        {
            first = false;
        }
        else
        {
            Write(out, ", ");
        }

        Write(out, Settings::InterfaceName);
    });
}

static void WriteComponentClassFactoryInterfaces(Output & out)
{
    GetClassConstructorsPublic([&]
    {
        Write(out, ", %", Settings::InterfaceName);
    });

    GetStaticInterfaces([&]
    {
        Write(out, ", %", Settings::InterfaceName);
    });
}

static void WriteComponentClassFactoryInterfaceMethods(Output & out)
{
    if (!Settings::ClassDefaultInterface.empty())
    {
        Write(out,
              Strings::WriteComponentClassFactoryActivateInstance_Yes,
              Settings::ClassName);
    }
    else
    {
        Write(out, Strings::WriteComponentClassFactoryActivateInstance_No);
    }
}

static void WriteComponentClassInterfaceMethods(Output & out)
{
    GetRequiredComponentClassInterfaces([&]
    {
        GetInterfaceMethods([&]
        {
            Write(out,
                  Strings::WriteComponentClassBehindOverrideVirtual,
                  Settings::MethodAbi,
                  Bind(WriteDelegateAbiParameters),
                  "",
                  Settings::MethodName,
                  Bind(WriteDelegateForwardArgunents));
        });
    });
}

void WriteComponentHeader(Output & out)
{
    Write(out, "#pragma once\n\n#include \"%.h\"\n", Database::Name());
    out.WriteImplementationNamespace(Settings::Namespace);
    Write(out, Strings::WriteComponentLockHeader);

    GetComponentClasses([&]
    {
        if (!Settings::ClassDefaultInterface.empty())
        {
            Write(out,
                  Strings::WriteComponentClassBehind,
                  Settings::ClassName,
                  Bind(WriteComponentClassInterfaces),
                  Settings::ClassName,
                  Settings::ClassName,
                  Bind(WriteComponentClassInterfaceMethods));
        }

        Write(out,
              Strings::WriteComponentClassFactoryBehind,
              Settings::ClassName,
              Bind(WriteComponentClassFactoryInterfaces),
              Settings::ClassName,
              Settings::ClassName,
              Bind(WriteComponentClassFactoryInterfaceMethods));
    });

    out.WriteNamespace();
}

static void WriteComponentMakeFactories(Output & out)
{
    GetComponentClasses([&]
    {
        Write(out,
              Strings::WriteComponentMakeFactory,
              Settings::Namespace,
              Settings::ClassName,
              Settings::ClassName);
    });
}

void WriteComponentSource(Output & out)
{
    Write(out, "#include \"pch.h\"\n");

    GetComponentClasses([&]
    {
        Write(out,
              "#include \"%.h\"\n",
              Settings::ClassDotName);
    });

    out.WriteImplementationNamespace(Settings::Namespace);
    Write(out, Strings::WriteComponentLockSource);

    Write(out,
          Strings::WriteComponent_DllGetActivationFactory,
          Bind(WriteComponentMakeFactories));

    out.WriteNamespace();
}

static void WriteComponentClassDefaultConstructorDeclaration(Output & out)
{
    if (Settings::ClassActivatable)
    {
        Write(out,
              "    %();",
              Settings::ClassName);
    }
}

static void WriteComponentClassMethodDeclarations(Output & out)
{
    GetRequiredComponentClassInterfaces([&]
    {
        GetInterfaceMethods([&]
        {
            Write(out,
                  Strings::WriteComponentClassMethodDeclaration,
                  Settings::ParameterInfo.ReturnType(),
                  Settings::MethodName,
                  Bind(WriteParameters, 0, false, false));
        });
    });
}

void WriteComponentClassHeader(Output & out)
{
    Write(out, "#pragma once\n\n#include \"component.h\"\n");
    out.WriteImplementationNamespace(Settings::Namespace);

    if (!Settings::ClassDefaultInterface.empty())
    {
        Write(out,
              Strings::WriteComponentClassDeclaration,
              Settings::ClassName,
              Settings::ClassName,
              Settings::ClassName,
              Bind(WriteComponentClassDefaultConstructorDeclaration),
              Bind(WriteComponentClassMethodDeclarations));
    }

    Write(out,
          Strings::WriteComponentClassFactoryDeclaration,
          Settings::ClassName,
          Settings::ClassName,
          Settings::ClassName);

    out.WriteNamespace();
}

static void WriteComponentClassDefinitions(Output & out)
{
    if (Settings::ClassActivatable)
    {
        Write(out,
              Strings::WriteComponentClassDefaultConstructorDefinition,
              Settings::ClassName,
              Settings::ClassName);
    }

    GetRequiredComponentClassInterfaces([&]
    {
        GetInterfaceMethods([&]
        {
            Write(out,
                  Strings::WriteComponentClassMethodDefinition,
                  Settings::ParameterInfo.ReturnType(),
                  Settings::ClassName,
                  Settings::MethodName,
                  Bind(WriteParameters, 0, false, true));
        });
    });
}

void WriteComponentClassSource(Output & out)
{
    WriteIncludePrecompiled(out);
    WriteIncludeComponentClass(out, Settings::ClassDotName);
    out.WriteImplementationNamespace(Settings::Namespace);

    if (!Settings::ClassDefaultInterface.empty())
    {
        WriteComponentClassDefinitions(out);
    }

    out.WriteNamespace();
}

}
