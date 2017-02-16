
namespace Windows::Foundation
{

struct Point
{
    float X;
    float Y;

    Point() noexcept = default;

    Point(float X, float Y) noexcept
        : X(X), Y(Y)
    {}

#ifdef WINRT_NUMERICS

    Point(const Numerics::float2 & value) noexcept
        : X(value.x), Y(value.y)
    {}

    operator Numerics::float2() const noexcept
    {
        return { X, Y };
    }

#endif
};

struct Size
{
    float Width;
    float Height;

    Size() noexcept = default;

    Size(float Width, float Height) noexcept
        : Width(Width), Height(Height)
    {}

#ifdef WINRT_NUMERICS

    Size(const Numerics::float2 & value) noexcept
        : Width(value.x), Height(value.y)
    {}

    operator Numerics::float2() const noexcept
    {
        return { Width, Height };
    }

#endif
};

struct Rect
{
    float X;
    float Y;
    float Width;
    float Height;
};

}

namespace ABI::Windows::Foundation
{
    using Point = winrt::Windows::Foundation::Point;
    using Size = winrt::Windows::Foundation::Size;
    using Rect = winrt::Windows::Foundation::Rect;
}
