#include "pch.h"
#include "Hen.h"

using namespace std::chrono;

namespace winrt::Farm::Animals::implementation
{
    hstring Hen::Français()
    {
        return L"Une poule française"; // A french hen
    }

    Windows::Foundation::IAsyncOperationWithProgress<hstring, uint32_t> Hen::LayEggAsync()
    {
        auto progress = co_await get_progress_token;

        for (uint32_t percent = 10; percent <= 100; percent += 10)
        {
            co_await 1s;
            progress(percent);
        }

        co_return hstring(L"Un œuf!"); // An egg!
    }
}
