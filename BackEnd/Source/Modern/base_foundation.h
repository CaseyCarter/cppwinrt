 
namespace Windows::Foundation {

struct Point
{
    float X;
    float Y;

    Point() noexcept = default;

    Point(float X, float Y) noexcept
        : X(X), Y(Y)
    {}

    Point(const Numerics::float2 & value) noexcept
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

    Size(const Numerics::float2 & value) noexcept
        : Width(value.x), Height(value.y)
    {}

    operator Numerics::float2() const noexcept
    {
        return { Width, Height };
    }
};

using TimeSpan = std::chrono::duration<int64_t, std::ratio<1, 10'000'000>>;

}

namespace ABI::Windows::Foundation {

using Point = winrt::Windows::Foundation::Point;
using Size = winrt::Windows::Foundation::Size;
using TimeSpan = winrt::Windows::Foundation::TimeSpan;

}

namespace ABI::Windows::Foundation::Numerics {

using float2 = winrt::Windows::Foundation::Numerics::float2;
using float3 = winrt::Windows::Foundation::Numerics::float3;
using float4 = winrt::Windows::Foundation::Numerics::float4;
using float3x2 = winrt::Windows::Foundation::Numerics::float3x2;
using float4x4 = winrt::Windows::Foundation::Numerics::float4x4;
using plane = winrt::Windows::Foundation::Numerics::plane;
using quaternion = winrt::Windows::Foundation::Numerics::quaternion;

}
