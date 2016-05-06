 
namespace Windows { namespace Foundation {

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

}}
