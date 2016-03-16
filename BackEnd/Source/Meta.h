#pragma once

#include <vector>
#include "debug.h"

namespace Modern {

enum class Options
{
    None,

    Out = 0x0001,
    NoLogo = 0x0002,
    Time = 0x0004,
    Debug = 0x0008,
    Module = 0x0010
};

DEFINE_ENUM_FLAG_OPERATORS(Options)

enum ParameterAttribute
{
    // None, In and Out should match the corresponding values:
    // None = System.Reflection.ParameterAttributes.None
    // In = System.Reflection.ParameterAttributes.In
    // Out = System.Reflection.ParameterAttributes.Out

    None = 0,
    In = 1,
    Out = 2,
    Return = 65536,
    ByRef = 131072,
    Array = 262144,
    Const = 524288
};

enum class TypeCategory
{
    Unknown = 0,

	// TODO: why are these bit flags? I don't think they need to be.
	
    Value       = 0x0001, // 1
    String      = 0x0002, // 2
    Enumeration = 0x0004, // 4
    Structure   = 0x0008, // 8
    Interface   = 0x0010, // 16
    Delegate    = 0x0020, // 32
    Class       = 0x0040, // 64
    Boolean     = 0x0080, // 128
    Deprecated  = 0x0100, // 256
};

enum class CompositionType
{
    Protected = 1,
    Public = 2
};

struct Parameter
{
    std::string Name;
    std::string Type;
    std::string ClassType;
    ParameterAttribute Attribute;
    TypeCategory Category;

    Parameter(char const * name,
              char const * type,
              char const * classType,
              ParameterAttribute attribute,
              TypeCategory category) :
        Name(name),
        Type(type),
        ClassType(classType ? classType : ""),
        Attribute(attribute),
        Category(category)
    {}

    char const * ModernType() const
    {
        if (ClassType.empty())
        {
            return Type.c_str();
        }
        else
        {
            return ClassType.c_str();
        }
    }
};

inline void swap(Parameter & left, Parameter & right)
{
    swap(left.Name, right.Name);
    swap(left.Type, right.Type);
    std::swap(left.Attribute, right.Attribute);
    std::swap(left.Category, right.Category);
}

struct ParameterInfo
{
    std::vector<Parameter> Parameters;
    int HasReturnType = false;
    bool HasDelegate = false;
    // TODO: Remove once support for arrays is added
    bool HasArrayParam = false;

    ParameterInfo() = default;
    ParameterInfo(ParameterInfo const &) = delete;
    ParameterInfo & operator=(ParameterInfo const &) = delete;
    ParameterInfo(ParameterInfo &&) = default;
    ParameterInfo & operator=(ParameterInfo &&) = default;

    void Clear() noexcept
    {
        Parameters.clear();
        HasReturnType = false;
        HasDelegate = false;
        // TODO: Remove once support for arrays is added
        HasArrayParam = false;
    }

    char const * ReturnType() const noexcept
    {
        if (HasReturnType)
        {
            return Parameters.back().ModernType();
        }
        else
        {
            return "void";
        }
    }

    char const * ReturnTypeName() const noexcept
    {
        MODERN_ASSERT(HasReturnType);
        return Parameters.back().Name.c_str();
    }
};

}
