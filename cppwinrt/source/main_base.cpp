#pragma comment(lib, "windowsapp")
#include "base_dependencies.h"
#include "base_macros.h"

namespace winrt {

#include "base_meta.h"
#include "base_constexpr_string.h"
#include "base_handle.h"
#include "base_com_ptr.h"
#include "base_string.h"
#include "base_string_hstring.h"
#include "base_string_hstring_ref.h"
#include "base_string_operators.h"
#include "base_constexpr_guid.h"
#include "base_constexpr_sha1.h"
#include "base_constexpr_traits.h"
#include "base_error.h"
#include "base_lock.h"
#include "base_windows.h"
#include "base_array.h"
#include "base_weak.h"
#include "base_agile.h"
#include "base_event_consume.h"
#include "base_event_produce.h"
#include "base_implements.h"
#include "base_composable.h"
#include "base_activation.h"
#include "base_delegate.h"

#include "base_collections_consume.h"
#include "base_collections_produce.h"
#include "base_collections_input.h"
#include "base_collections_input_iterable.h"
#include "base_collections_input_vector_view.h"
#include "base_collections_input_map_view.h"
#include "base_collections_vector.h"
#include "base_collections_map.h"

#include "base_foundation.h"
#include "base_chrono.h"
#include "base_async_consume.h"
#include "base_async_produce.h"
#include "base_await_consume.h"
#include "base_await_produce.h"
#include "base_reference.h"

}

#include "base_std_hash.h"

#ifdef WINRT_ASYNC

namespace std::experimental {

#include "base_std_fire_and_forget.h"
#include "base_std_async_action.h"
#include "base_std_async_action_with_progress.h"
#include "base_std_async_operation.h"
#include "base_std_async_operation_with_progress.h"

}

#endif

//#include "..\..\projection2\sdk.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace std::chrono;

IAsyncAction Async()
{
    printf("pre\n");
    co_await 2us;
    printf("post\n");
}

struct Factory : implements<Factory, IActivationFactory>
{
    static hstring GetRuntimeClassName()
    {
        return L"Microsoft.Sample.Dog";
    }


    Windows::Foundation::IInspectable ActivateInstance()
    {
        return Async();
    }
};

int main()
{
    HRESULT hr = hresult_class_not_available().to_abi();
    hr;

    init_apartment();

    IActivationFactory factory = make<Factory>();
    factory.ActivateInstance().as<IAsyncAction>().get();

    printf("%ls\n", GetRuntimeClassName(factory).c_str());

    IAsyncAction async = Async();
    async.get();
    async.Id();
    async.Status();
    async.ErrorCode();
    async.Cancel();
    async.Close();

    //IVector<int> v = single_threaded_vector<int>({1,2,3});
    //v.GetAt(0);
    //v.Size();
    //v.GetView().Size();

    //IStringable t = make<Thing>();
    //printf("ToString: %ls\n", t.ToString().c_str());
    //IClosable c = t.as<IClosable>();
    //c.Close();

    //static_assert(std::is_same_v<::IUnknown*, impl::arg_in<IAsyncAction>>);
    //static_assert(std::is_same_v<IUriRuntimeClass, impl::default_interface<Uri>::type>);

    //com_array<IAsyncAction> a1;
    //com_array<GUID> a2;

    //TypedEventHandler<Uri, Uri> handler = [](auto&&...){};
    //handler(nullptr, nullptr);

    //DeferralCompletedHandler dh = [](auto&& ...){ printf("deferral\n"); };
    //dh();

    //IPropertyValue pv = PropertyValue::CreateInt32Array({1,2,3}).as<IPropertyValue>();

    //com_array<int32_t> values;
    //pv.GetInt32Array(values);

    //WINRT_ASSERT(values.size() == 3);
    //WINRT_ASSERT(values[0] == 1);
    //WINRT_ASSERT(values[1] == 2);
    //WINRT_ASSERT(values[2] == 3);

    //Uri uri(L"http://moderncpp.com/path");
    //IStringable s = uri;
    //uri = s.as<Uri>();
    //printf("%ls\n", uri.Domain().c_str());
    //printf("%ls\n", uri.ToString().c_str());

    //GUID a = impl::guid_v<Uri>;
    //GUID b = impl::guid_v<IUriRuntimeClass>;

    //WINRT_ASSERT(a == b);
}
