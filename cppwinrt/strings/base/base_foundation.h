
WINRT_EXPORT namespace winrt::Windows::Foundation
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

namespace winrt::impl
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
    
    template <> struct name<Windows::Foundation::Rect>
    {
        static constexpr auto & value{ L"Windows.Foundation.Rect" };
    };

    template <> struct category<Windows::Foundation::Rect>
    {
        using type = struct_category<float, float, float, float>;
    };

    template <> struct name<Windows::Foundation::Numerics::float2>
    {
        static constexpr auto & value{ L"Windows.Foundation.Numerics.Vector2" };
    };

    template <> struct category<Windows::Foundation::Numerics::float2>
    {
        using type = struct_category<float, float>;
    };

    template <> struct name<Windows::Foundation::Numerics::float3>
    {
        static constexpr auto & value{ L"Windows.Foundation.Numerics.Vector3" };
    };

    template <> struct category<Windows::Foundation::Numerics::float3>
    {
        using type = struct_category<float, float, float>;
    };

    template <> struct name<Windows::Foundation::Numerics::float4>
    {
        static constexpr auto & value{ L"Windows.Foundation.Numerics.Vector4" };
    };

    template <> struct category<Windows::Foundation::Numerics::float4>
    {
        using type = struct_category<float, float, float, float>;
    };

    template <> struct name<Windows::Foundation::Numerics::float3x2>
    {
        static constexpr auto & value{ L"Windows.Foundation.Numerics.Matrix3x2" };
    };

    template <> struct category<Windows::Foundation::Numerics::float3x2>
    {
        using type = struct_category<float, float, float, float, float, float>;
    };

    template <> struct name<Windows::Foundation::Numerics::float4x4>
    {
        static constexpr auto & value{ L"Windows.Foundation.Numerics.Matrix4x4" };
    };

    template <> struct category<Windows::Foundation::Numerics::float4x4>
    {
        using type = struct_category<
            float, float, float, float,
            float, float, float, float,
            float, float, float, float,
            float, float, float, float
        >;
    };

    template <> struct name<Windows::Foundation::Numerics::quaternion>
    {
        static constexpr auto & value{ L"Windows.Foundation.Numerics.Quaternion" };
    };

    template <> struct category<Windows::Foundation::Numerics::quaternion>
    {
        using type = struct_category<float, float, float, float>;
    };

    template <> struct name<Windows::Foundation::Numerics::plane>
    {
        static constexpr auto & value{ L"Windows.Foundation.Numerics.Plane" };
    };

    template <> struct category<Windows::Foundation::Numerics::plane>
    {
        using type = struct_category<Windows::Foundation::Numerics::float3, float>;
    };
}
