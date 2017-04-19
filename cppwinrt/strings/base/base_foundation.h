
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

        Point(Numerics::float2 const& value) noexcept
            : X(value.x), Y(value.y)
        {}

        operator Numerics::float2() const noexcept
        {
            return { X, Y };
        }
    };

    struct Size
    {
        float Width;
        float Height;

        Size() noexcept = default;

        Size(float Width, float Height) noexcept
            : Width(Width), Height(Height)
        {}

        Size(Numerics::float2 const& value) noexcept
            : Width(value.x), Height(value.y)
        {}

        operator Numerics::float2() const noexcept
        {
            return { Width, Height };
        }
    };

    struct Rect
    {
        float X;
        float Y;
        float Width;
        float Height;
    };
}

namespace impl
{
    template <> struct name<Windows::Foundation::Point>
    {
        static constexpr auto & value{ L"Windows.Foundation.Point" };
    };

    template <> struct category<Windows::Foundation::Point>
    {
        using type = struct_category<float, float>;
    };

    template <> struct name<Windows::Foundation::Size>
    {
        static constexpr auto & value{ L"Windows.Foundation.Size" };
    };

    template <> struct category<Windows::Foundation::Size>
    {
        using type = struct_category<float, float>;
    };
}
