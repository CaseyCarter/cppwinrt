#include "pch.h"

using namespace winrt;

using namespace Windows::Networking;
using namespace Windows::Networking::Sockets;

int main()
{
    Initialize();

    try
    {
        StreamSocket socket;
        HostName hostname(L"moderncpp.com");

        auto task = ppl::create_task(socket.ConnectAsync(hostname, L"80"));

        task = task.then([]
        {
            printf("Connection succeeded!\n");
        });

        task.wait();
    }
    catch (hresult_error const & e)
    {
        printf("Connection failed (0x%8X) %ls\n", e.code(), e.message().c_str());
    }
}
