#include "pch.h"
#include "Hen.h"
#include "Egg.h"

using namespace std::chrono;

namespace winrt::Farm::Animals::implementation
{
    hstring Hen::Français()
    {
        return L"Une poule française"; // A french hen
    }

    Windows::Foundation::IAsyncOperationWithProgress<Farm::Animals::Egg, uint32_t> Hen::LayEggAsync()
    {
        auto progress = co_await get_progress_token;

        for (uint32_t percent = 10; percent <= 100; percent += 10)
        {
            co_await 500ms;
            progress(percent);
        }

        co_return make<Egg>(*this);
    }

    Windows::Foundation::Rect Hen::StructByValue(Windows::Foundation::Rect const& byValue)
    {
        return byValue;
    }

    Windows::Foundation::Rect Hen::StructByRef(Windows::Foundation::Rect const& byRef)
    {
        return byRef;
    }
}
