#pragma once

#include <vector>
#include "Modern\Base.h"

namespace Modern {

enum class Command
{
    None,
    Library,
    Component,
    Console,
    Desktop,
    Store
};

enum class Options
{
    None,

    Include  = 0x0001,
    Library  = 0x0002,
    Name     = 0x0004,
    Out      = 0x0008,

    Sdk      = 0x0010,
    Database = 0x0020,
    NoLogo   = 0x0040,
    Time     = 0x0080,

    Debug    = 0x0100,
    Noexcept = 0x0200,
    Depends  = 0x0400,
    Update   = 0x0800,

	NoXaml	 = 0x1000,
};

DEFINE_ENUM_FLAG_OPERATORS(Options)

enum class ParameterDirection
{
    In     = 0,
    Out    = 1,
    Return = 2,
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
    ParameterDirection Direction;
    TypeCategory Category;

    Parameter(char const * name,
              char const * type,
              char const * classType,
              ParameterDirection direction,
              TypeCategory category) :
        Name(name),
        Type(type),
        ClassType(classType ? classType : ""),
        Direction(direction),
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
    std::swap(left.Direction, right.Direction);
    std::swap(left.Category, right.Category);
}

struct ParameterInfo
{
    std::vector<Parameter> Parameters;
    unsigned StringCount = 0;
    bool HasReturnType = false;
    bool HasDelegate = false;

    ParameterInfo() = default;
    ParameterInfo(ParameterInfo const &) = delete;
    ParameterInfo & operator=(ParameterInfo const &) = delete;
    ParameterInfo(ParameterInfo &&) = default;
    ParameterInfo & operator=(ParameterInfo &&) = default;

    void Clear() noexcept
    {
        Parameters.clear();
        StringCount = 0;
        HasReturnType = false;
        HasDelegate = false;
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
