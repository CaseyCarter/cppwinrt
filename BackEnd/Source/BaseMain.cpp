#pragma comment(lib, "windowsapp")
#include "base_dependencies.h"
#include "base_macros.h"

namespace winrt {

#include "base_accessors.h"
#include "base_handle.h"
#include "base_meta.h"
#include "base_com_ptr.h"
#include "base_string.h"
#include "base_string_hstring.h"
#include "base_string_hstring_ref.h"
#include "base_string_operators.h"
#include "base_error.h"
#include "base_lock.h"
#include "base_array.h"
#include "base_windows.h"
#include "base_implements.h"
#include "base_weak.h"
#include "base_composable.h"
#include "base_event_consume.h"
#include "base_activation.h"
#include "base_delegate.h"
#include "base_reference.h"
#include "base_collections_consume.h"
#include "base_collections_produce.h"
#include "base_collections_impl.h"
#include "base_foundation.h"
#include "base_async_consume.h"
#include "base_async_produce.h"
#include "base_agile.h"
#include "base_await_consume.h"
#include "base_await_produce.h"

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

using namespace winrt;

int main()
{
}
