#include "Precompiled.h"
#include "Idl.h"
#include "FileView.h"
#include "Database.h"
#include "Meta.h"
#include "Output.h"

namespace Modern { namespace Idl {

enum class Token
{
    Invalid          = 0,
    EndOfFile        = 1,
    String           = 2,

    Colon            = 3,
    Assign           = 4,
    Comma            = 5,
    Semicolon        = 6,

    LeftBrace        = 7,
    RightBrace       = 8,
    LeftBracket      = 9,
    RightBracket     = 10,
    LeftParenthesis  = 11,
    RightParenthesis = 12,

    Interface        = 13,
    Typedef          = 14,
    Declare          = 15,
    Delegate         = 16,
    Requires         = 17,
    Import           = 18,

    Namespace        = 19,
    Enumeration      = 20,
    RuntimeClass     = 21,
    Structure        = 22,
};

enum class Attribute
{
    Invalid,
    In,
    Out,
    ReturnValue,
    EventAdd,
    EventRemove,
    PropertyGet,
    PropertyPut,
    Overload,
    Deprecated,
    Default,
    Activatable,
    Static,
    Composable,
    SizeIs,
    LengthIs,
    Flags,
    Overridable,
    Protected,
    Uuid,
};

struct Character
{
    Token Token;
    char Value;
};

struct Keyword
{
    Token Token;
    std::string Value;
};

struct Fundamental
{
    std::string Name;
    TypeCategory Category;
};

struct TokenResult
{
    Token Token;
    Result Result;
};

static TokenResult const TokenResults [] =
{
    { Token::String           , Result::StringExpected           },
    { Token::Colon            , Result::ColonExpected            },
    { Token::Assign           , Result::AssignExpected           },
    { Token::Comma            , Result::CommaExpected            },
    { Token::Semicolon        , Result::SemicolonExpected        },
    { Token::LeftBrace        , Result::LeftBraceExpected        },
    { Token::RightBrace       , Result::RightBraceExpected       },
    { Token::LeftBracket      , Result::LeftBracketExpected      },
    { Token::RightBracket     , Result::RightBracketExpected     },
    { Token::LeftParenthesis  , Result::LeftParenthesisExpected  },
    { Token::RightParenthesis , Result::RightParenthesisExpected },
};

static Character const Characters [] =
{
    { Token::LeftBrace,         '{' },
    { Token::RightBrace,        '}' },
    { Token::LeftBracket,       '[' },
    { Token::RightBracket,      ']' },
    { Token::LeftParenthesis,   '(' },
    { Token::RightParenthesis,  ')' },
    { Token::Comma,             ',' },
    { Token::Semicolon,         ';' },
    { Token::Colon,             ':' },
    { Token::Assign,            '=' },
};

static Keyword const Keywords [] =
{
    { Token::Namespace,     "namespace"    },
    { Token::Interface,     "interface"    },
    { Token::RuntimeClass,  "runtimeclass" },
    { Token::Enumeration,   "enum"         },
    { Token::Typedef,       "typedef"      },
    { Token::Structure,     "struct"       },
    { Token::Declare,       "declare"      },
    { Token::Delegate,      "delegate"     },
    { Token::Requires,      "requires"     },
    { Token::Import,        "import"       },
};

static Fundamental const Fundamentals [] =
{
    { "String",                 TypeCategory::String    },
    { "bool",                   TypeCategory::Boolean   },
    { "EventRegistrationToken", TypeCategory::Value     },
    { "IInspectable",           TypeCategory::Interface },

    { "int",                    TypeCategory::Value     },
    { "unsigned",               TypeCategory::Value     },

    { "double",                 TypeCategory::Value     },
    { "float",                  TypeCategory::Value     },

    { "short",                  TypeCategory::Value     },
    { "unsigned short",         TypeCategory::Value     },

    { "byte",                   TypeCategory::Value     },
    { "GUID",                   TypeCategory::Value     },

    { "long long",              TypeCategory::Value     },
    { "unsigned long long",     TypeCategory::Value     },

    { "wchar_t",                TypeCategory::Value     },
    { "HRESULT",                TypeCategory::Value     },
    { "AsyncStatus",            TypeCategory::Value     },
};

using Attributes = std::vector<std::pair<Attribute, std::string>>;

static std::string s_namespace;
static std::vector<size_t> s_namespaceBreaks;

static Attributes s_attributes;


template <unsigned Count>
bool StartsWithNoCase(std::string const & target, char const (&match)[Count]) noexcept
{
    if (target.size() < Count - 1)
    {
        return false;
    }

    return 0 == _strnicmp(target.c_str(), match, Count - 1);
}

template <unsigned Count>
bool StartsWith(std::string const & target, char const (&match)[Count]) noexcept
{
    if (target.size() < Count - 1)
    {
        return false;
    }

    return 0 == strncmp(target.c_str(), match, Count - 1);
}

template <unsigned Count>
bool EndsWith(std::string const & target, char const (&match)[Count]) noexcept
{
    if (target.size() < Count - 1)
    {
        return false;
    }

    return 0 == strncmp(target.c_str() + target.size() - (Count - 1), match, Count - 1);
}

template <unsigned Count>
bool EndsWithNoCase(std::string const & target, char const (&match)[Count]) noexcept
{
    if (target.size() < Count - 1)
    {
        return false;
    }

    return 0 == _strnicmp(target.c_str() + target.size() - (Count - 1), match, Count - 1);
}

template <unsigned MatchCount, unsigned ReplaceCount>
bool ReplaceEndsWith(std::string & target, char const (&match)[MatchCount], char const (&replace)[ReplaceCount])
{
    if (!EndsWith(target, match))
    {
        return false;
    }

    target.replace(end(target) - (MatchCount - 1), end(target), replace);
    return true;
}

static void QualifyString(std::string & type)
{
    if (std::string::npos == type.find("::"))
    {
        type = s_namespace + "::" + type;
    }
}

template <unsigned Count>
bool StartsWith(char const * begin, char const * end, char const (&match)[Count]) noexcept
{
    if (end - begin < Count - 1)
    {
        return false;
    }

    return 0 == strncmp(begin, match, Count - 1);
}

class Scanner
{
    char  const * const m_end = nullptr;
    char  const *       m_next = nullptr;
    Token               m_token = Token::Invalid;
    unsigned            m_line = 1;
    char const *        m_filename = nullptr;
    std::string         m_string;
    TypeCategory        m_category = TypeCategory::Unknown;

    void EatLine() noexcept
    {
        for (; m_next != m_end; ++m_next)
        {
            if ('\n' == *m_next)
            {
                break;
            }
        }
    }

    template <unsigned Count>
    bool Peek(char const (&match)[Count]) noexcept
    {
        // TODO: replace with StartsWith() -- test performance
        return match[0] == *m_next && m_next + Count - 1 != m_end && 0 == strncmp(match, m_next, Count - 1);
    }

    bool SkipWhitespace() noexcept
    {
        while (m_next != m_end)
        {
            if ('\n' == *m_next)
            {
                ++m_next;
                ++m_line;
            }
            else if (isspace(*m_next) || '*' == *m_next)
            {
                ++m_next;
            }
            else if (Peek("//") || Peek("cpp_quote") || Peek("#"))
            {
                EatLine();
            }
            else
            {
                return true;
            }
        }

        m_token = Token::EndOfFile;
        return false;
    }

    static TypeCategory GetCategory(std::string const & type)
    {
        for (Fundamental const & f : Fundamentals)
        {
            if (f.Name == type)
            {
                return f.Category;
            }
        }

        return TypeCategory::Unknown;
    }

    static void NormalizeType(std::string & type)
    {
        // This list has been ordered by frequency

        if (type == "HSTRING")
        {
            type = "String";
        }
        else if (type == "boolean")
        {
            type = "bool";
        }
        else if (type == "UINT32" || type == "UINT" || type == "TrackId")
        {
            type = "unsigned";
        }
        else if (type == "DOUBLE")
        {
            type = "double";
        }
        else if (type == "INT32")
        {
            type = "int";
        }
        else if (type == "FLOAT")
        {
            type = "float";
        }
        else if (type == "UINT16")
        {
            type = "unsigned short";
        }
        else if (type == "UINT64" || type == "UINT64" || type == "ULONG64")
        {
            type = "unsigned long long";
        }
        else if (type == "INT16")
        {
            type = "short";
        }
        else if (type == "INT64")
        {
            type = "long long";
        }
        else if (type == "WCHAR")
        {
            type = "wchar_t";
        }
        else if (type == "BYTE")
        {
            type = "byte";
        }
        else if (type == "EventRegistrationToken")
        {
            type = "long long";
        }
    }

    void ReadRestOfString()
    {
        unsigned t = 0;
        std::string part;

        for (; m_next != m_end; ++m_next)
        {
            if (isspace(*m_next) || '*' == *m_next)
            {
                if (0 == t)
                {
                    ++m_next;
                    break;
                }
            }
            else if ('.' == *m_next)
            {
                part += "::";
            }
            else if (isalnum(*m_next) || '_' == *m_next)
            {
                part += *m_next;
            }
            else if ('<' == *m_next)
            {
                if (ReplaceEndsWith(m_string, "TypedEventHandler", "ITypedEventHandler<") ||
                    ReplaceEndsWith(m_string, "EventHandler", "IEventHandler<"))
                {
                    MODERN_ASSERT(part.empty());
                    m_category = TypeCategory::Delegate;
                }
                else if (m_string == "IVector")
                {
                    MODERN_ASSERT(part.empty());
                    m_string = "Windows::Foundation::Collections::IVector<";
                    m_category = TypeCategory::Interface;
                }
                else
                {
                    m_string += part;
                    m_string += '<';
                    m_category = TypeCategory::Interface;
                }

                part.clear();
                ++t;
            }
            else if ('>' == *m_next)
            {
                if (!part.empty())
                {
                    NormalizeType(part);

                    if (GetCategory(part) == TypeCategory::Unknown)
                    {
                        QualifyString(part);

                        TypeCategory const category = Database::GetCategory(part);

                        if (category == TypeCategory::Structure || category == TypeCategory::Enumeration)
                        {
                            m_string += "winrt::";
                        }
                    }

                    m_string += part;
                    part.clear();
                }

                --t;
                m_string += '>';
            }
            else if (',' == *m_next)
            {
                if (0 == t)
                {
                    break;
                }

                if (!part.empty())
                {
                    NormalizeType(part);

                    if (GetCategory(part) == TypeCategory::Unknown)
                    {
                        QualifyString(part);

                        TypeCategory const category = Database::GetCategory(part);

                        if (category == TypeCategory::Structure || category == TypeCategory::Enumeration)
                        {
                            m_string += "winrt::";
                        }
                    }

                    m_string += part;
                    part.clear();
                }

                m_string += ", ";
            }
            else
            {
                break;
            }
        }

        m_string += part;
        MODERN_ASSERT(0 == t);
    }

    void ReadName()
    {
        for (; m_next != m_end; ++m_next)
        {
            if (isalnum(*m_next) || '_' == *m_next || '-' == *m_next)
            {
                m_string += *m_next;
            }
            else if ('.' == *m_next)
            {
                m_string += "::";
            }
            else
            {
                break;
            }
        }
    }

public:

    Scanner(Scanner const &) = delete;
    Scanner & operator=(Scanner const &) = delete;

    Scanner(FileView const & file, char const * const filename) noexcept :
        m_end(end(file)),
        m_next(begin(file)),
        m_filename(filename)
    {}

    void Throw(Result const result) const
    {
        throw Exception(result, m_line, m_filename);
    }

    Token Current() const noexcept
    {
        return m_token;
    }

    TypeCategory GetCategory() const noexcept
    {
        return m_category;
    }

    std::string const & String() const noexcept
    {
        MODERN_ASSERT(m_token == Token::String);
        return m_string;
    }

    void Expect(Token const token) const
    {
        if (m_token != token)
        {
            for (TokenResult const & tr : TokenResults)
            {
                if (token == tr.Token)
                {
                    Throw(tr.Result);
                }
            }

            MODERN_ASSERT(false);
        }
    }

    void Next()
    {
        if (!SkipWhitespace()) return;

        for (Character const & c : Characters)
        {
            if (*m_next == c.Value)
            {
                ++m_next;
                m_token = c.Token;
                return;
            }
        }

        m_string.clear();

        if ('"' == *m_next)
        {
            while (++m_next != m_end && '"' != *m_next)
            {
                m_string += *m_next;
            }

            if ('"' != *m_next)
            {
                Throw(Result::InvalidToken);
            }

            ++m_next;
            m_token = Token::String;
            return;
        }

        if (isalnum(*m_next) || '-' == *m_next || '_' == *m_next)
        {
            ReadName();

            for (Keyword const & k : Keywords)
            {
                if (m_string == k.Value)
                {
                    m_token = k.Token;
                    return;
                }
            }

            NormalizeType(m_string);
            m_category = GetCategory(m_string);

            if (m_category == TypeCategory::Unknown)
            {
                ReadRestOfString();
            }

            m_token = Token::String;
            return;
        }

        Throw(Result::InvalidToken);
    }

    void NextSimpleName()
    {
        if (!SkipWhitespace()) return;

        if (!isalnum(*m_next) && '_' != *m_next)
        {
            Throw(Result::StringExpected);
        }

        m_string.clear();
        ReadName();
        m_token = Token::String;
    }

    void NextQuotedString()
    {
        if (!SkipWhitespace()) return;

        if ('"' != *m_next)
        {
            Throw(Result::StringExpected);
        }

        char const * begin = ++m_next;

        for (; m_next != m_end && '"' != *m_next; ++m_next);

        m_string.assign(begin, m_next);
        m_token = Token::String;

        if ('"' != *m_next)
        {
            Throw(Result::InvalidToken);
        }

        ++m_next;
    }
};

static void Scan(Scanner & scanner);

static void ParseImport(Scanner & scanner);
static void ParseOpenNamespace(Scanner & scanner);
static void ParseRuntimeClass(Scanner & scanner);
static void ParseCloseNamespace(Scanner & scanner);
static void ParseTypedef(Scanner & scanner);
static void ParseInterface(Scanner & scanner);
static void ParseDeclare(Scanner & scanner);
static void ParseAttribute(Scanner & scanner);
static void ParseEnumeration(Scanner & scanner);
static void ParseDelegate(Scanner & scanner);
static void ParseStructure(Scanner & scanner);

static int s_indent;

static bool EatLine(char const * & begin, char const * const end) noexcept
{
    for (; begin != end; ++begin)
    {
        if ('\n' == *begin)
        {
            ++begin;
            return true;
        }
    }

    return false;
}

//static bool Find(char const * & begin, char const * const end, char const match) noexcept
//{
//    for (; begin != end; ++begin)
//    {
//        if (match == *begin)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}

static void NormalizeMetadataType(std::string & type)
{
    if (type == "Object")
    {
        type = "IInspectable";
    }
    else if (type == "Double")
    {
        type = "double";
    }
    else if (type == "Guid")
    {
        type = "GUID";
    }
    else if (type == "Int32")
    {
        type = "int";
    }
    else if (type == "Single")
    {
        type = "float";
    }
    else if (type == "UInt32")
    {
        type = "unsigned";
    }
    else if (type == "UInt8")
    {
        type = "byte";
    }
    else if (type == "UInt64")
    {
        type = "unsigned long long";
    }
    else if (type == "Int64")
    {
        type = "long long";
    }
    else if (type == "Boolean")
    {
        type = "bool";
    }
    else if (type == "Int16")
    {
        type = "short";
    }
    else
    {
        if (type != "String")
        {
            MODERN_ASSERT(std::string::npos != type.find(':'));
        }
    }
}

static bool ReadName(char const * & begin, char const * const end, std::string & name, std::string & ns)
{
    std::string part;

    for (; begin < end; ++begin)
    {
        if ('"' == *begin)
        {
            return true;
        }

        if ('`' == *begin)
        {
            ++begin; // skip parameter count
        }
        else if ('.' == *begin)
        {
            if (name.empty())
            {
                if (!ns.empty())
                {
                    ns += "::";
                }

                ns += part;
                part.clear();
            }
            else
            {
                part += "::";
            }
        }
        else if ('<' == *begin)
        {
            if (name.empty())
            {
                if (part[0] != 'I')
                {
                    name = 'I';
                }
            }

            name += part;
            name += '<';
            part.clear();
        }
        else if ('>' == *begin || ',' == *begin)
        {
            if (!part.empty())
            {
                // TODO: check category and prepend "winrt::"

                NormalizeMetadataType(part);

                TypeCategory const category = Database::GetCategory(part);

                if (category == TypeCategory::Structure || category == TypeCategory::Enumeration)
                {
                    name += "winrt::";
                }
                else if (category == TypeCategory::Deprecated)
                {
                    return false;
                }

                name += part;
                part.clear();
            }

            name += *begin;
        }
        else if (' ' == *begin)
        {
            MODERN_ASSERT(part.empty());
            name += ' ';
        }
        else
        {
            part += *begin;
        }
    }

    return false;
}

void ParseHeader(char const * filename)
{
    FileView file(filename);

    char const * next = file.Begin();
    char const * const end = file.End();

    for (; next != end; ++next)
    {
        if (StartsWith(next, end, "uuid(\""))
        {
            char const * const guidBegin = next + 6;
            char const * const guidEnd = guidBegin + 36;

            if (guidEnd > end)
            {
                MODERN_ASSERT(false);
                return;
            }

            next = guidEnd;

            if (!EatLine(next, end)) return;
            if (!EatLine(next, end)) return;
            if (!EatLine(next, end)) return;

            if (!StartsWith(next, end, "return L\""))
            {
                MODERN_ASSERT(false);
                return;
            }

            next += 9;

            std::string name, ns;

            if (!ReadName(next, end, name, ns))
            {
                continue;
            }           

            Database::AddGenericInterface(name, ns, guidBegin, guidEnd);
        }
    }
}

void Parse(int const headerId, char const * filename)
{
	++s_indent;

	if (Options::Depends == (Settings::Options & Options::Depends))
	{
		for (int i = 0; i != s_indent; ++i)
		{
			printf(" ");
		}

		std::string name = filename;
		name.resize(name.size() - 4);
		std::transform(begin(name), end(name), begin(name), tolower);

		Write(printf, "%\n", name);
	}

    FileView file(filename);
    Scanner scanner(file, filename);
    Scan(scanner);
    Database::SetSourceParsed(headerId);

	--s_indent;
}

static Attributes ConsumeAttributes()
{
    return std::move(s_attributes);
}

static void AddAttribute(Attribute const & attribute)
{
    s_attributes.emplace_back(attribute, std::string());
}

static void AddAttribute(Attribute const & attribute, std::string const & value)
{
    s_attributes.emplace_back(attribute, value);
}

static bool FindAttribute(Attributes const & attributes, Attribute const attribute)
{
    for (std::pair<Attribute, std::string> const & p : attributes)
    {
        if (p.first == attribute)
        {
            return true;
        }
    }

    return false;
}

static bool FindAttribute(Attributes const & attributes, Attribute const attribute, std::string & value)
{
    for (std::pair<Attribute, std::string> const & p : attributes)
    {
        if (p.first == attribute)
        {
            value = p.second;
            return true;
        }
    }

    return false;
}

static void AddMethodPreamble(Attributes const & attributes, std::string & method)
{
    for (std::pair<Attribute, std::string> const & p : attributes)
    {
        switch (p.first)
        {
            case Attribute::EventAdd:    method = "add_"    + method; return;
            case Attribute::EventRemove: method = "remove_" + method; return;
            case Attribute::PropertyGet: method = "get_"    + method; return;
            case Attribute::PropertyPut: method = "put_"    + method; return;
        }
    }

    method = "abi_" + method;
}

static ParameterDirection GetParameterDirection(Attributes const & attributes)
{
    ParameterDirection direction = ParameterDirection::In;

    for (std::pair<Attribute, std::string> const & p : attributes)
    {
        switch (p.first)
        {
            case Attribute::ReturnValue: return ParameterDirection::Return;
            case Attribute::Out:         direction = ParameterDirection::Out;
        }
    }

    return direction;
}

static void Scan(Scanner & scanner)
{
    scanner.Next();

    for (;;)
    {
        Token const token = scanner.Current();

        switch (token)
        {
            case Token::Import:         ParseImport(scanner);         break;
            case Token::Namespace:      ParseOpenNamespace(scanner);            break;
            case Token::RuntimeClass:   ParseRuntimeClass(scanner);   break;
            case Token::RightBrace:     ParseCloseNamespace(scanner);           break;
            case Token::Typedef:        ParseTypedef(scanner);        break;
            case Token::Interface:      ParseInterface(scanner);      break;
            case Token::Declare:        ParseDeclare(scanner);                  break;
            case Token::LeftBracket:    ParseAttribute(scanner);                break;
            case Token::Enumeration:    ParseEnumeration(scanner);    break;
            case Token::Delegate:       ParseDelegate(scanner);       break;
            case Token::Structure:      ParseStructure(scanner);      break;

            case Token::EndOfFile:      return;

            default: scanner.Throw(Result::UnexpectedToken);
        }
    }
}

static void ParseImport(Scanner & scanner)
{
    scanner.NextQuotedString();

    if (StartsWithNoCase(scanner.String(), "windows."))
    {
        MODERN_ASSERT(EndsWithNoCase(scanner.String(), ".idl"));

        if (int const sourceId = Database::AddSource(scanner.String().c_str(), false))
        {
            Parse(sourceId, scanner.String().c_str());
        }
    }

    scanner.Next();
    scanner.Expect(Token::Semicolon);
    scanner.Next();
}

static void ParseOpenNamespace(Scanner & scanner)
{
    scanner.NextSimpleName();

    s_namespaceBreaks.push_back(s_namespace.size());
    if (!s_namespace.empty()) s_namespace += "::";
    s_namespace += scanner.String();

    scanner.Next();
    scanner.Expect(Token::LeftBrace);
    scanner.Next();
}

static void ParseAttributes(Scanner & scanner)
{
    while (scanner.Current() == Token::LeftBracket)
    {
        ParseAttribute(scanner);
    }
}

static void ParseClassInterfaces(Scanner & scanner, int const classId, bool const deprecated)
{
    while (scanner.Current() != Token::RightBrace)
    {
        ParseAttributes(scanner);
        scanner.Expect(Token::Interface);
        scanner.Next();
        scanner.Expect(Token::String);

        Attributes const attributes = ConsumeAttributes();
        MODERN_ASSERT(!FindAttribute(attributes, Attribute::Deprecated));

        if (!deprecated)
        {
            std::string name = scanner.String();

            QualifyString(name);

            bool isDefault = false;
            bool isOverridable = false;
            bool isProtected = false;

            for (std::pair<Attribute, std::string> const & p : attributes)
            {
                if (p.first == Attribute::Default)
                {
                    isDefault = true;
                }
                else if (p.first == Attribute::Overridable)
                {
                    isOverridable = true;
                }
                else if (p.first == Attribute::Protected)
                {
                    isProtected = true;
                }
            }

            if (isDefault)
            {
                MODERN_ASSERT(!isOverridable);
                MODERN_ASSERT(!isProtected);

                Database::AddClassDefaultInterface(classId, name);
            }

			if (!EndsWith(name, "IClosable"))
			{
				Database::AddClassInterface(classId, name, isDefault, isOverridable, isProtected);
			}
        }

        scanner.Next();
        scanner.Expect(Token::Semicolon);
        scanner.Next();
    }
}

static void ParseRuntimeClass(Scanner & scanner)
{
    scanner.NextSimpleName();
    std::string const name = scanner.String();
    scanner.Next();

    if (scanner.Current() == Token::Semicolon)
    {
        Database::AddClassDeclaration(name, s_namespace);

        scanner.Next();
        return;
    }

    std::string base;

    if (scanner.Current() == Token::Colon)
    {
        scanner.NextSimpleName();
        base = scanner.String();
        scanner.Next();
    }

    Attributes const attributes = ConsumeAttributes();
    bool const deprecated = FindAttribute(attributes, Attribute::Deprecated);
    int classId = 0;

    if (!deprecated)
    {
        classId = Database::AddClass(name, s_namespace, base);

        for (std::pair<Attribute, std::string> const & p : attributes)
        {
            if (p.first == Attribute::Activatable)
            {
                if (p.second.empty())
                {
                    Database::AddClassDefaultConstructor(classId);
                }
                else
                {
                    Database::AddClassConstructor(classId, p.second);
                }
            }
            else if (p.first == Attribute::Static)
            {
                Database::AddClassStatic(classId, p.second);
            }
            else if (p.first == Attribute::Composable)
            {
				bool const isProtected = '+' != p.second[0];

                Database::AddClassComposable(classId, &p.second[1], isProtected);
            }
        }
    }
    else
    {
        Database::RemoveClass(name, s_namespace);
        Database::AddDeprecated(name, s_namespace);
    }

    scanner.Expect(Token::LeftBrace);
    scanner.Next();
    ParseClassInterfaces(scanner, classId, deprecated);
    scanner.Expect(Token::RightBrace);
    scanner.Next();

    if (scanner.Current() == Token::Semicolon)
    {
        scanner.Next();
    }
}

static void ParseCloseNamespace(Scanner & scanner)
{
    scanner.Next();
    size_t length = s_namespaceBreaks.back();
    s_namespace.resize(length);
    s_namespaceBreaks.pop_back();
}

static void ParseEnumerators(Scanner & scanner, int const enumerationId, bool const deprecated)
{
    long long last = -1;

    for (;;)
    {
        ParseAttributes(scanner);
        scanner.Expect(Token::String);
        std::string const name = scanner.String();
        scanner.Next();

        if (scanner.Current() == Token::Assign)
        {
            scanner.Next();
            scanner.Expect(Token::String);

            if (StartsWithNoCase(scanner.String(), "0x"))
            {
                last = stoll(scanner.String(), 0, 16);
            }
            else
            {
                last = stoll(scanner.String());
            }

            scanner.Next();
        }
        else
        {
            ++last;
        }

        Attributes const attributes = ConsumeAttributes();

        if (!deprecated && !FindAttribute(attributes, Attribute::Deprecated))
        {
            Database::AddEnumerator(enumerationId, name, last);
        }

        if (scanner.Current() != Token::Comma)
        {
            break;
        }

        scanner.Next();

        if (scanner.Current() == Token::RightBrace)
        {
            break;
        }
    }
}

static void ParseInnerEnumeration(Scanner & scanner, std::string const & name)
{
    Attributes const attributes = ConsumeAttributes();
    bool const deprecated = FindAttribute(attributes, Attribute::Deprecated);

    int id = 0;

    if (!deprecated)
    {
        bool const flags = FindAttribute(attributes, Attribute::Flags);
        id = Database::AddEnumeration(name, s_namespace, flags);
    }
    else
    {
        Database::RemoveEnumeration(name, s_namespace);
        Database::AddDeprecated(name, s_namespace);
    }

    scanner.Expect(Token::LeftBrace);
    scanner.Next();
    ParseEnumerators(scanner, id, deprecated);
    scanner.Expect(Token::RightBrace);
    scanner.Next();
}

static int ParseFields(Scanner & scanner, int const structureId)
{
    int depends = 0;

    while (scanner.Current() != Token::RightBrace)
    {
        scanner.Expect(Token::String);
        std::string const type = scanner.String();
        scanner.NextSimpleName();
        Database::AddField(structureId, scanner.String(), type);
        scanner.Next();
        scanner.Expect(Token::Semicolon);
        scanner.Next();

        if (std::string::npos != type.find(':'))
        {
            ++depends;
        }
    }

    return depends;
}

static void ParseInnerStructure(Scanner & scanner, std::string const & name)
{
    Attributes const attributes = ConsumeAttributes();
    MODERN_ASSERT(!FindAttribute(attributes, Attribute::Deprecated));

    int const id = Database::AddStructure(name, s_namespace);
    scanner.Expect(Token::LeftBrace);
    scanner.Next();
    
    if (int const depends = ParseFields(scanner, id))
    {
        Database::StructureDepends(id, depends);
    }
    
    scanner.Expect(Token::RightBrace);
    scanner.Next();
}

static void ParseTypedef(Scanner & scanner)
{
    scanner.Next();

    if (scanner.Current() == Token::Enumeration)
    {
        scanner.NextSimpleName();
        std::string const name = scanner.String();
        scanner.Next();

        if (scanner.Current() == Token::LeftBrace)
        {
            ParseInnerEnumeration(scanner, name);
        }
        else
        {
            Database::AddEnumerationDeclaration(name, s_namespace);
        }

        scanner.Expect(Token::String);
        scanner.Next();
        scanner.Expect(Token::Semicolon);
        scanner.Next();
    }
    else if (scanner.Current() == Token::Structure)
    {
        scanner.NextSimpleName();
        std::string const name = scanner.String();
        scanner.Next();

        if (scanner.Current() == Token::LeftBrace)
        {
            ParseInnerStructure(scanner, name);
        }
        else
        {
            Database::AddStructureDeclaration(name, s_namespace);
        }

        scanner.Expect(Token::String);
        scanner.Next();
        scanner.Expect(Token::Semicolon);
        scanner.Next();
    }
    else
    {
        scanner.Expect(Token::String);
        scanner.NextSimpleName();
        scanner.Next();
        scanner.Expect(Token::Semicolon);
        scanner.Next();
    }
}

static void ParseParameters(Scanner & scanner, int const methodId, bool const deprecated)
{
    while (scanner.Current() != Token::RightParenthesis)
    {
        ParseAttributes(scanner);
        scanner.Expect(Token::String);
        std::string type = scanner.String();
        TypeCategory category = scanner.GetCategory();

        scanner.NextSimpleName();
        Attributes const attributes = ConsumeAttributes();

        if (!deprecated)
        {
            if (category == TypeCategory::Unknown)
            {
                QualifyString(type);

                category = Database::GetCategory(type);

                if (category == TypeCategory::Delegate)
                {
                    type.insert(type.find_last_of(":") + 1, 1, 'I');
                }

                MODERN_ASSERT(category != TypeCategory::Unknown);
            }

            ParameterDirection const direction = GetParameterDirection(attributes);

            std::string sizeIs;
            FindAttribute(attributes, Attribute::SizeIs, sizeIs);

            std::string lengthIs;
            FindAttribute(attributes, Attribute::LengthIs, lengthIs);

            Database::AddParameter(methodId, scanner.String(), type, direction, category, sizeIs, lengthIs);
        }

        scanner.Next();

        if (scanner.Current() == Token::Comma)
        {
            scanner.Next();
        }
    }
}

static void ParseMethods(Scanner & scanner, int const interfaceId, bool const interfaceDeprecated)
{
    while (scanner.Current() != Token::RightBrace)
    {
        ParseAttributes(scanner);
        scanner.Expect(Token::String);
        
        if ("HRESULT" != scanner.String())
        {
            scanner.Throw(Result::HresultExpected);
        }
        
        scanner.NextSimpleName();
        Attributes const attributes = ConsumeAttributes();
        bool const methodDeprecated = FindAttribute(attributes, Attribute::Deprecated);
        int methodId = 0;

        if (!interfaceDeprecated)
        {
            std::string abiName = scanner.String();
            std::string name;

            if (!FindAttribute(attributes, Attribute::Overload, name))
            {
                name = abiName;
            }

            AddMethodPreamble(attributes, abiName);
            methodId = Database::AddMethod(interfaceId, name, abiName, methodDeprecated);
        }

        scanner.Next();
        scanner.Expect(Token::LeftParenthesis);
        scanner.Next();
        ParseParameters(scanner, methodId, interfaceDeprecated);
        scanner.Expect(Token::RightParenthesis);
        scanner.Next();
        scanner.Expect(Token::Semicolon);
        scanner.Next();
    }
}

static void ParseInterface(Scanner & scanner)
{
    scanner.NextSimpleName();
    std::string const name = scanner.String();
    scanner.Next();

    if (scanner.Current() == Token::Semicolon)
    {
        if (name != "IVectorChangedEventArgs")
        {
            Database::AddInterfaceDeclaration(name, s_namespace);
        }

        scanner.Next();
        return;
    }

    scanner.Expect(Token::Colon);
    scanner.NextSimpleName();

    Attributes const attributes = ConsumeAttributes();
    bool const deprecated = FindAttribute(attributes, Attribute::Deprecated);

    int interfaceId = 0;

    if (!deprecated)
    {
        std::string uuid;
        MODERN_VERIFY(FindAttribute(attributes, Attribute::Uuid, uuid));

        interfaceId = Database::AddInterface(name, s_namespace, uuid);
    }
    else
    {
        Database::RemoveInterface(name, s_namespace);
        Database::AddDeprecated(name, s_namespace);
    }

    scanner.Next();

    if (scanner.Current() == Token::Requires)
    {
        scanner.Next();

        while (scanner.Current() == Token::String)
        {
            if (!deprecated && !EndsWith(scanner.String(), "IClosable"))
            {
                Database::AddRequiredInterface(interfaceId, scanner.String());
            }

            scanner.Next();

            if (scanner.Current() == Token::Comma)
            {
                scanner.Next();
            }
        }
    }

    scanner.Expect(Token::LeftBrace);
    scanner.Next();
    ParseMethods(scanner, interfaceId, deprecated);
    scanner.Expect(Token::RightBrace);
    scanner.Next();

    if (scanner.Current() == Token::Semicolon)
    {
        scanner.Next();
    }
}

static void ParseDeclare(Scanner & scanner)
{
    scanner.Next();
    scanner.Expect(Token::LeftBrace);
    scanner.Next();

    while (scanner.Current() == Token::Interface)
    {
        scanner.Next();
        scanner.Expect(Token::String);
        scanner.Next();
        scanner.Expect(Token::Semicolon);
        scanner.Next();
    }

    scanner.Expect(Token::RightBrace);
    scanner.Next();
}

static void ParseIgnoredNameValueAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.NextSimpleName();
    scanner.Next();
    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseUuidAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.NextSimpleName();
    AddAttribute(Attribute::Uuid, scanner.String());
    scanner.Next();
    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseOverloadAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.NextQuotedString();
    AddAttribute(Attribute::Overload, scanner.String());
    scanner.Next();
    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseSizeIsAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.Next();

    if (scanner.Current() == Token::Comma)
    {
        scanner.Next();
    }

    scanner.Expect(Token::String);
    AddAttribute(Attribute::SizeIs, scanner.String());
    scanner.Next();
    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseLengthIsAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.Next();

    if (scanner.Current() == Token::Comma)
    {
        scanner.Next();
    }

    scanner.Expect(Token::String);
    AddAttribute(Attribute::LengthIs, scanner.String());
    scanner.Next();
    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseContractAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.NextSimpleName();
    scanner.Next();

    if (scanner.Current() != Token::Comma)
    {
        AddAttribute(Attribute::Activatable);
    }
    else
    {
        scanner.NextSimpleName();
        scanner.Next();
    }

    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseActivatableAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.NextSimpleName();
    std::string const name = scanner.String();
    scanner.Next();

    if (scanner.Current() != Token::Comma)
    {
        AddAttribute(Attribute::Activatable);
    }
    else
    {
        scanner.NextSimpleName();
        AddAttribute(Attribute::Activatable, name);
        scanner.Next();
    }

    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseStaticAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.NextSimpleName();
    AddAttribute(Attribute::Static, scanner.String());
    scanner.Next();
    scanner.Expect(Token::Comma);
    scanner.NextSimpleName();
    scanner.Next();

    if (scanner.Current() == Token::Comma)
    {
        scanner.NextSimpleName();
        scanner.Next();
    }

    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseDeprecatedAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.NextQuotedString();
    scanner.Next();
    scanner.Expect(Token::Comma);
    scanner.NextSimpleName();
    scanner.Next();
    scanner.Expect(Token::Comma);
    scanner.NextSimpleName();
    scanner.Next();
    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseRangeAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.NextSimpleName();
    scanner.Next();
    scanner.Expect(Token::Comma);
    scanner.NextSimpleName();
    scanner.Next();
    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseComposableAttribute(Scanner & scanner)
{
    scanner.Expect(Token::LeftParenthesis);
    scanner.NextSimpleName();
    std::string value = scanner.String();
    scanner.Next();
    scanner.Expect(Token::Comma);
    scanner.NextSimpleName();

    if ("public" == scanner.String())
    {
        value = '+' + value;
    }
    else
    {
        MODERN_ASSERT("protected" == scanner.String());

        value = '-' + value;
    }

    AddAttribute(Attribute::Composable, value);
    scanner.Next();
    scanner.Expect(Token::Comma);
    scanner.NextSimpleName();
    scanner.Next();
    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
}

static void ParseAttribute(Scanner & scanner)
{
    scanner.Next();

    for (;;)
    {
        scanner.Expect(Token::String);
        std::string const name = scanner.String();
        scanner.Next();

        if (name == "version" ||
            name == "exclusiveto" ||
            name == "threading")
        {
            ParseIgnoredNameValueAttribute(scanner);
        }
        else if (name == "propget")
        {
            AddAttribute(Attribute::PropertyGet);
        }
        else if (name == "propput")
        {
            AddAttribute(Attribute::PropertyPut);
        }
        else if (name == "eventadd")
        {
            AddAttribute(Attribute::EventAdd);
        }
        else if (name == "eventremove")
        {
            AddAttribute(Attribute::EventRemove);
        }
        else if (name == "out")
        {
            AddAttribute(Attribute::Out);
        }
        else if (name == "retval")
        {
            AddAttribute(Attribute::ReturnValue);
        }
        else if (name == "in")
        {
            AddAttribute(Attribute::In);
        }
        else if (name == "default")
        {
            AddAttribute(Attribute::Default);
        }
        else if (name == "overridable")
        {
            AddAttribute(Attribute::Overridable);
        }
        else if (name == "protected")
        {
            AddAttribute(Attribute::Protected);
        }
        else if (name == "uuid")
        {
            ParseUuidAttribute(scanner);
        }
        else if (name == "overload")
        {
            ParseOverloadAttribute(scanner);
        }
        else if (name == "marshaling_behavior")
        {
            ParseIgnoredNameValueAttribute(scanner);
        }
        else if (name == "contract")
        {
            ParseContractAttribute(scanner);
        }
        else if (name == "size_is")
        {
            ParseSizeIsAttribute(scanner);
        }
        else if (name == "length_is")
        {
            ParseLengthIsAttribute(scanner);
        }
        else if (name == "activatable")
        {
            ParseActivatableAttribute(scanner);
        }
        else if (name == "static")
        {
            ParseStaticAttribute(scanner);
        }
        else if (name == "deprecated")
        {
            AddAttribute(Attribute::Deprecated);
            ParseDeprecatedAttribute(scanner);
        }
        else if (name == "default_overload")
        {
            // Not needed for C++
        }
        else if (name == "flags")
        {
            AddAttribute(Attribute::Flags);
        }
        else if (name == "range")
        {
            ParseRangeAttribute(scanner);
        }
        else if (name == "object")
        {
            // Ignored
        }
        else if (name == "v1_enum")
        {
            // Ignored
        }
        else if (name == "composable")
        {
            ParseComposableAttribute(scanner);
        }
        else
        {
            scanner.Throw(Result::UnexpectedAttribute);
        }

        if (scanner.Current() == Token::Comma)
        {
            scanner.Next();
            continue;
        }

        scanner.Expect(Token::RightBracket);
        scanner.Next();
        break;
    }
}

static void ParseEnumeration(Scanner & scanner)
{
    scanner.NextSimpleName();
    std::string const name = scanner.String();
    scanner.Next();
    ParseInnerEnumeration(scanner, name);
    scanner.Expect(Token::Semicolon);
    scanner.Next();
}

static void ParseDelegate(Scanner & scanner)
{
    scanner.NextSimpleName();

    if ("HRESULT" != scanner.String())
    {
        Database::AddDelegateDeclaration(scanner.String(), s_namespace);

        scanner.Next();
        scanner.Expect(Token::Semicolon);
        scanner.Next();
        return;
    }
    
    scanner.NextSimpleName();

    Attributes const attributes = ConsumeAttributes();
    bool const deprecated = FindAttribute(attributes, Attribute::Deprecated);
    int methodId = 0;

    if (!deprecated)
    {
        std::string uuid;
        MODERN_VERIFY(FindAttribute(attributes, Attribute::Uuid, uuid));

        int const interfaceId = Database::AddDelegate(scanner.String(), s_namespace, uuid);

        methodId = Database::AddMethod(interfaceId, "Invoke", "abi_Invoke", false);
    }
    else
    {
        Database::RemoveDelegate(scanner.String(), s_namespace);
        Database::AddDeprecated(scanner.String(), s_namespace);
    }

    scanner.Next();
    scanner.Expect(Token::LeftParenthesis);
    scanner.Next();
    ParseParameters(scanner, methodId, deprecated);
    scanner.Expect(Token::RightParenthesis);
    scanner.Next();
    scanner.Expect(Token::Semicolon);
    scanner.Next();
}

static void ParseStructure(Scanner & scanner)
{
    scanner.NextSimpleName();
    std::string const name = scanner.String();
    scanner.Next();
    ParseInnerStructure(scanner, name);
    scanner.Expect(Token::Semicolon);
    scanner.Next();
}

}}
