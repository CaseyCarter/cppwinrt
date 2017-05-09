#include "pch.h"

using namespace winrt;

using namespace Windows::Foundation;
using namespace Windows::Networking;
using namespace Windows::Networking::Sockets;

IAsyncAction CoroutineSample()
{
    StreamSocket socket;
    HostName hostname(L"moderncpp.com");

    co_await socket.ConnectAsync(hostname, L"80");

    printf("Connection succeeded!\n");
}

int main()
{
    init_apartment();

    try
    {
        CoroutineSample().get();
    }
    catch (hresult_error const & e)
    {
        printf("Connection failed (0x%8X) %ls\n", e.code(), e.message().c_str());
    }
}
