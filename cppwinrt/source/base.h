#pragma once

#pragma comment(lib, "windowsapp")
#include "base_dependencies.h"
#include "base_macros.h"

#include "base_meta.h"
#include "base_constexpr_string.h"
#include "base_handle.h"
#include "base_com_ptr.h"
#include "base_string.h"
#include "base_string_hstring.h"
#include "base_string_input.h"
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
#include "base_implements_marshal.h"
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
#include "base_collections_input_vector.h"
#include "base_collections_input_map.h"
#include "base_collections_vector.h"
#include "base_collections_map.h"

#include "base_reference.h"
#include "base_foundation.h"
#include "base_chrono.h"
#include "base_async_consume.h"
#include "base_async_produce.h"
#include "base_await_consume.h"
#include "base_await_produce.h"

#include "base_std_hash.h"

#ifdef WINRT_ASYNC

#include "base_std_fire_and_forget.h"
#include "base_std_async_action.h"
#include "base_std_async_action_with_progress.h"
#include "base_std_async_operation.h"
#include "base_std_async_operation_with_progress.h"

#endif
