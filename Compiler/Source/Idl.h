#pragma once

namespace Modern { namespace Idl {

enum class Result
{
    Success,
    InvalidToken,
    UnexpectedToken,
    StringExpected,
    SemicolonExpected,
    LeftBraceExpected,
    RightBraceExpected,
    LeftParenthesisExpected,
    RightParenthesisExpected,
    RightBracketExpected,
    ColonExpected,
    HresultExpected,
    InterfaceExpected,
    CommaExpected,
    AssignExpected,
    LeftBracketExpected,
    UnexpectedAttribute,
};

struct Exception
{
    Result Reason;
    unsigned Line;
    std::string File;

    Exception(Result const result,
              unsigned const line,
              char const * filename):
        Reason(result),
        Line(line),
        File(filename)
    {
    }
};

void Parse(int headerId, char const * filename);
void ParseHeader(char const * filename);

}}
