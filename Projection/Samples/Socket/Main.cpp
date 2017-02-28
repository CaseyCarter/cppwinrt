#include "pch.h"

using namespace winrt;

using namespace Windows::Foundation;
using namespace Windows::Networking;
using namespace Windows::Networking::Sockets;

concurrency::task<void> PplSample()
{
    StreamSocket socket;
    HostName hostname(L"moderncpp.com");

    auto task = ppl::create_task(socket.ConnectAsync(hostname, L"80"));

    return task.then([]
    {
        printf("Connection succeeded!\n");
    });
}

IAsyncAction CoroutineSample()
{
    StreamSocket socket;
    HostName hostname(L"moderncpp.com");

    await socket.ConnectAsync(hostname, L"80");

    printf("Connection succeeded!\n");
}

int main()
{
    init_apartment();

    try
    {
        PplSample().get();
        CoroutineSample().get();
    }
    catch (hresult_error const & e)
    {
        printf("Connection failed (0x%8X) %ls\n", e.code(), e.message().c_str());
    }
}
