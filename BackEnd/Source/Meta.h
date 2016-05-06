#pragma once

#include "debug.h"

namespace Modern {

enum class Options
{
    None,

    Out      = 0x0001,
    NoLogo   = 0x0002,
    Time     = 0x0004,
};

DEFINE_ENUM_FLAG_OPERATORS(Options)

enum class ParameterFlags
{
    None      = 0,
    In        = 0x00001,
    Out       = 0x00002,
    Return    = 0x10000,
    Reference = 0x20000,
    Array     = 0x40000,
};

DEFINE_ENUM_FLAG_OPERATORS(ParameterFlags)

enum class TypeCategory
{
    Unknown = 0,

    Value       = 0x0001, // 1
    String      = 0x0002, // 2
    Enumeration = 0x0004, // 4
    Structure   = 0x0008, // 8
    Interface   = 0x0010, // 16
    Delegate    = 0x0020, // 32
    Class       = 0x0040, // 64
};

struct Parameter
{
    std::string Name;
    std::string Type;
    std::string ClassType;
    TypeCategory Category;
    ParameterFlags Flags;

    Parameter(char const * name,
              char const * type,
              char const * classType,
              TypeCategory category,
              ParameterFlags flags) :
        Name(name),
        Type(type),
        ClassType(classType ? classType : ""),
        Category(category),
        Flags(flags)
    {}

    std::string const & ModernType() const
    {
        if (ClassType.empty())
        {
            return Type;
        }
        else
        {
            return ClassType;
        }
    }

    bool HasFlag(ParameterFlags flag) const noexcept
    {
        return flag == (Flags & flag);
    }

    bool IsReturn() const noexcept
    {
        return HasFlag(ParameterFlags::Return);
    }

    bool IsIn() const noexcept
    {
        return HasFlag(ParameterFlags::In);
    }

    bool IsOut() const noexcept
    {
        return HasFlag(ParameterFlags::Out);
    }

    bool IsReference() const noexcept
    {
        return HasFlag(ParameterFlags::Reference);
    }

    bool IsArray() const noexcept
    {
        return HasFlag(ParameterFlags::Array);
    }

    bool IsReferenceOrReturn() const noexcept
    {
        return ParameterFlags::None != (Flags & (ParameterFlags::Reference | ParameterFlags::Return));
    }
};

struct ParameterInfo
{
    std::vector<Parameter> Parameters;
    bool HasReturnType = false;
    std::string ReturnType;

    ParameterInfo() = default;
    ParameterInfo(ParameterInfo const &) = delete;
    ParameterInfo & operator=(ParameterInfo const &) = delete;
    ParameterInfo(ParameterInfo &&) = default;
    ParameterInfo & operator=(ParameterInfo &&) = default;

    void Clear() noexcept
    {
        Parameters.clear();
        HasReturnType = false;
    }

    char const * ReturnTypeName() const noexcept
    {
        MODERN_ASSERT(HasReturnType);
        return Parameters.back().Name.c_str();
    }
};

}
