
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    enum class AsyncStatus
    {
        Started,
        Completed,
        Canceled,
        Error,
    };

    struct AsyncActionCompletedHandler;
    template <typename TResult> struct AsyncOperationCompletedHandler;
    template <typename TProgress> struct AsyncActionProgressHandler;
    template <typename TProgress> struct AsyncActionWithProgressCompletedHandler;
    template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler;
    template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler;

    struct IAsyncInfo;
    struct IAsyncAction;
    template <typename TResult> struct IAsyncOperation;
    template <typename TProgress> struct IAsyncActionWithProgress;
    template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
}

namespace winrt::impl
{
    inline bool is_sta() noexcept
    {
        APTTYPE aptType;
        APTTYPEQUALIFIER aptTypeQualifier;
        return (S_OK == CoGetApartmentType(&aptType, &aptTypeQualifier)) && ((aptType == APTTYPE_STA) || (aptType == APTTYPE_MAINSTA));
    }

    template <typename Async>
    void blocking_suspend(Async const& async) noexcept
    {
        WINRT_ASSERT(!is_sta());

        if (async.Status() == Windows::Foundation::AsyncStatus::Completed)
        {
            return;
        }

        lock x;
        condition_variable cv;
        bool completed = false;

        async.Completed([&](Async const&, Windows::Foundation::AsyncStatus)
        {
            lock_guard const guard(x);
            completed = true;
            cv.wake_one();
        });

        lock_guard const guard(x);
        cv.wait_while(x, [&] { return !completed; });
    }

    template <typename D>
    struct consume_IAsyncInfo
    {
        uint32_t Id() const noexcept;
        Windows::Foundation::AsyncStatus Status() const noexcept;
        HRESULT ErrorCode() const noexcept;
        void Cancel() const;
        void Close() const;
    };


    template <typename D>
    struct consume_IAsyncAction
    {
        void Completed(Windows::Foundation::AsyncActionCompletedHandler const& handler) const noexcept;
        Windows::Foundation::AsyncActionCompletedHandler Completed() const noexcept;
        void GetResults() const;
        void get() const;
    };

    template <typename D, typename TResult>
    struct consume_IAsyncOperation
    {
        void Completed(Windows::Foundation::AsyncOperationCompletedHandler<TResult> const& handler) const noexcept;
        Windows::Foundation::AsyncOperationCompletedHandler<TResult> Completed() const noexcept;
        TResult GetResults() const;
        TResult get() const;
    };

    template <typename D, typename TProgress>
    struct consume_IAsyncActionWithProgress
    {
        void Progress(Windows::Foundation::AsyncActionProgressHandler<TProgress> const& handler) const noexcept;
        Windows::Foundation::AsyncActionProgressHandler<TProgress> Progress() const noexcept;
        void Completed(Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> const& handler) const noexcept;
        Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> Completed() const noexcept;
        void GetResults() const;
        void get() const;
    };

    template <typename D, typename TResult, typename TProgress>
    struct consume_IAsyncOperationWithProgress
    {
        void Progress(Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress> const& handler) const noexcept;
        Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress> Progress() const noexcept;
        void Completed(Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> const& handler) const noexcept;
        Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const noexcept;
        TResult GetResults() const;
        TResult get() const;
    };

    template <>
    struct abi<Windows::Foundation::AsyncActionCompletedHandler>
    {
        struct type : ::IUnknown
        {
            virtual HRESULT __stdcall Invoke(::IUnknown* asyncInfo, Windows::Foundation::AsyncStatus asyncStatus) = 0;
        };
    };

    template <typename TResult>
    struct abi<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
    {
        struct type : ::IUnknown
        {
            virtual HRESULT __stdcall Invoke(::IUnknown* asyncInfo, Windows::Foundation::AsyncStatus status) = 0;
        };
    };

    template <typename TProgress>
    struct abi<Windows::Foundation::AsyncActionProgressHandler<TProgress>>
    {
        struct type : ::IUnknown
        {
            virtual HRESULT __stdcall Invoke(::IUnknown* asyncInfo, arg_in<TProgress> progressInfo) = 0;
        };
    };

    template <typename TProgress>
    struct abi<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        struct type : ::IUnknown
        {
            virtual HRESULT __stdcall Invoke(::IUnknown* asyncInfo, Windows::Foundation::AsyncStatus status) = 0;
        };
    };

    template <typename TResult, typename TProgress>
    struct abi<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
    {
        struct type : ::IUnknown
        {
            virtual HRESULT __stdcall Invoke(::IUnknown* asyncInfo, arg_in<TProgress> progressInfo) = 0;
        };
    };

    template <typename TResult, typename TProgress>
    struct abi<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
    {
        struct type : ::IUnknown
        {
            virtual HRESULT __stdcall Invoke(::IUnknown* asyncInfo, Windows::Foundation::AsyncStatus status) = 0;
        };
    };

    template <>
    struct abi<Windows::Foundation::IAsyncInfo>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall get_Id(uint32_t* id) = 0;
            virtual HRESULT __stdcall get_Status(Windows::Foundation::AsyncStatus* status) = 0;
            virtual HRESULT __stdcall get_ErrorCode(HRESULT* errorCode) = 0;
            virtual HRESULT __stdcall Cancel() = 0;
            virtual HRESULT __stdcall Close() = 0;
        };
    };

    template <>
    struct consume<Windows::Foundation::IAsyncInfo>
    {
        template <typename D> using type = consume_IAsyncInfo<D>;
    };

    template <>
    struct abi<Windows::Foundation::IAsyncAction>
    {
        struct type : ::IInspectable
        {
            virtual HRESULT __stdcall put_Completed(::IUnknown* handler) = 0;
            virtual HRESULT __stdcall get_Completed(::IUnknown** handler) = 0;
            virtual HRESULT __stdcall GetResults() = 0;
        };
    };

    template <>
    struct consume<Windows::Foundation::IAsyncAction>
    {
        template <typename D> using type = consume_IAsyncAction<D>;
    };

    template <>
    struct delegate<Windows::Foundation::AsyncActionCompletedHandler>
    {
        template <typename H>
        struct type : implements_delegate<Windows::Foundation::AsyncActionCompletedHandler, H>
        {
            type(H&& handler) : implements_delegate<Windows::Foundation::AsyncActionCompletedHandler, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(::IUnknown* asyncInfo, Windows::Foundation::AsyncStatus asyncStatus) noexcept override
            {
                try
                {
                    (*this)(*reinterpret_cast<Windows::Foundation::IAsyncAction const*>(&asyncInfo), asyncStatus);
                    return S_OK;
                }
                catch (...)
                {
                    return to_hresult();
                }
            }
        };
    };

    template <typename TResult>
    struct delegate<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
    {
        template <typename H>
        struct type : implements_delegate<Windows::Foundation::AsyncOperationCompletedHandler<TResult>, H>
        {
            type(H&& handler) : implements_delegate<Windows::Foundation::AsyncOperationCompletedHandler<TResult>, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(::IUnknown* sender, Windows::Foundation::AsyncStatus args) noexcept override
            {
                try
                {
                    (*this)(*reinterpret_cast<Windows::Foundation::IAsyncOperation<TResult> const*>(&sender), args);
                    return S_OK;
                }
                catch (...) { return to_hresult(); }
            }
        };
    };

    template <typename TProgress>
    struct delegate<Windows::Foundation::AsyncActionProgressHandler<TProgress>>
    {
        template <typename H>
        struct type : implements_delegate<Windows::Foundation::AsyncActionProgressHandler<TProgress>, H>
        {
            type(H&& handler) : implements_delegate<Windows::Foundation::AsyncActionProgressHandler<TProgress>, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(::IUnknown* sender, arg_in<TProgress> args) noexcept override
            {
                try
                {
                    (*this)(*reinterpret_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const*>(&sender), *reinterpret_cast<TProgress const*>(&args));
                    return S_OK;
                }
                catch (...) { return to_hresult(); }
            }
        };
    };

    template <typename TProgress>
    struct delegate<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        template <typename H>
        struct type : implements_delegate<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>, H>
        {
            type(H&& handler) : implements_delegate<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(::IUnknown* sender, Windows::Foundation::AsyncStatus args) noexcept override
            {
                try
                {
                    (*this)(*reinterpret_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const*>(&sender), args);
                    return S_OK;
                }
                catch (...) { return to_hresult(); }
            }
        };
    };

    template <typename TResult, typename TProgress>
    struct delegate<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
    {
        template <typename H>
        struct type : implements_delegate<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>, H>
        {
            type(H&& handler) : implements_delegate<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(::IUnknown* sender, arg_in<TProgress> args) noexcept override
            {
                try
                {
                    (*this)(*reinterpret_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const*>(&sender), *reinterpret_cast<TProgress const*>(&args));
                    return S_OK;
                }
                catch (...) { return to_hresult(); }
            }
        };
    };

    template <typename TResult, typename TProgress>
    struct delegate<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
    {
        template <typename H>
        struct type : implements_delegate<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>, H>
        {
            type(H&& handler) : implements_delegate<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(::IUnknown* sender, Windows::Foundation::AsyncStatus args) noexcept override
            {
                try
                {
                    (*this)(*reinterpret_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const*>(&sender), args);
                    return S_OK;
                }
                catch (...) { return to_hresult(); }
            }
        };
    };

    template <typename TResult>
    struct abi<Windows::Foundation::IAsyncOperation<TResult>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall put_Completed(::IUnknown* handler) = 0;
            virtual HRESULT __stdcall get_Completed(::IUnknown** handler) = 0;
            virtual HRESULT __stdcall GetResults(arg_out<TResult> results) = 0;
        };
    };

    template <typename TResult>
    struct consume<Windows::Foundation::IAsyncOperation<TResult>>
    {
        template <typename D> using type = consume_IAsyncOperation<D, TResult>;
    };

    template <typename TProgress>
    struct abi<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall put_Progress(::IUnknown* handler) = 0;
            virtual HRESULT __stdcall get_Progress(::IUnknown** handler) = 0;
            virtual HRESULT __stdcall put_Completed(::IUnknown* handler) = 0;
            virtual HRESULT __stdcall get_Completed(::IUnknown** handler) = 0;
            virtual HRESULT __stdcall GetResults() = 0;
        };
    };

    template <typename TProgress>
    struct consume<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        template <typename D> using type = consume_IAsyncActionWithProgress<D, TProgress>;
    };

    template <typename TResult, typename TProgress>
    struct abi<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall put_Progress(::IUnknown* handler) = 0;
            virtual HRESULT __stdcall get_Progress(::IUnknown** handler) = 0;
            virtual HRESULT __stdcall put_Completed(::IUnknown* handler) = 0;
            virtual HRESULT __stdcall get_Completed(::IUnknown** handler) = 0;
            virtual HRESULT __stdcall GetResults(arg_out<TResult> results) = 0;
        };
    };

    template <typename TResult, typename TProgress>
    struct consume<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        template <typename D> using type = consume_IAsyncOperationWithProgress<D, TResult, TProgress>;
    };

    template <>
    struct guid<Windows::Foundation::AsyncActionCompletedHandler>
    {
        static constexpr GUID value{ 0xA4ED5C81,0x76C9,0x40BD,{ 0x8B,0xE6,0xB1,0xD9,0x0F,0xB2,0x0A,0xE7 } };
    };
    
    template <> 
    struct name<Windows::Foundation::AsyncActionCompletedHandler>
    {
        static constexpr auto & value{ L"Windows.Foundation.AsyncActionCompletedHandler" };
    };

    template <>
    struct category<Windows::Foundation::AsyncActionCompletedHandler>
    {
        using type = delegate_category;
    };

    template <typename TResult>
    struct guid<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>::value };
    };

    template <typename TResult>
    struct name<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
    {
        static constexpr auto value{ L"Windows.Foundation.AsyncOperationCompletedHandler`1<" + make_constexpr_string(name_v<TResult>) + L">" };
    };

    template <typename TResult>
    struct category<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
    {
        using type = pinterface_category<TResult>;
        static constexpr GUID value{ 0xfcdcf02c, 0xe5d8, 0x4478,{ 0x91, 0x5a, 0x4d, 0x90, 0xb7, 0x4b, 0x83, 0xa5 } };
    };

    template <typename TProgress>
    struct guid<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>::value };
    };

    template <typename TProgress>
    struct name<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        static constexpr auto value{ L"Windows.Foundation.AsyncActionWithProgressCompletedHandler`1<" + make_constexpr_string(name_v<TProgress>) + L">" };
    };

    template <typename TProgress>
    struct category<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        using type = pinterface_category<TProgress>;
        static constexpr GUID value{ 0x9c029f91, 0xcc84, 0x44fd,{ 0xac, 0x26, 0x0a, 0x6c, 0x4e, 0x55, 0x52, 0x81 } };
    };

    template <typename TProgress>
    struct guid<Windows::Foundation::AsyncActionProgressHandler<TProgress>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::AsyncActionProgressHandler<TProgress>>::value };
    };

    template <typename TProgress>
    struct name<Windows::Foundation::AsyncActionProgressHandler<TProgress>>
    {
        static constexpr auto value{ L"Windows.Foundation.AsyncActionProgressHandler`1<" + make_constexpr_string(name_v<TProgress>) + L">" };
    };

    template <typename TProgress>
    struct category<Windows::Foundation::AsyncActionProgressHandler<TProgress>>
    {
        using type = pinterface_category<TProgress>;
        static constexpr GUID value{ 0x6d844858, 0x0cff, 0x4590,{ 0xae, 0x89, 0x95, 0xa5, 0xa5, 0xc8, 0xb4, 0xb8 } };
    };

    template <typename TResult, typename TProgress>
    struct guid<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>::value };
    };

    template <typename TResult, typename TProgress>
    struct name<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
    {
        static constexpr auto value{ L"Windows.Foundation.AsyncOperationProgressHandler`2<" + make_constexpr_string(name_v<TResult>) + L"," + make_constexpr_string(name_v<TProgress>) + L">" };
    };

    template <typename TResult, typename TProgress>
    struct category<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
    {
        using type = pinterface_category<TResult, TProgress>;
        static constexpr GUID value{ 0x55690902, 0x0aab, 0x421a,{ 0x87, 0x78, 0xf8, 0xce, 0x50, 0x26, 0xd7, 0x58 } };
    };

    template <typename TResult, typename TProgress>
    struct guid<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>::value };
    };

    template <typename TResult, typename TProgress>
    struct name<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
    {
        static constexpr auto value{ L"Windows.Foundation.AsyncOperationWithProgressCompletedHandler`2<" + make_constexpr_string(name_v<TResult>) + L"," + make_constexpr_string(name_v<TProgress>) + L">" };
    };

    template <typename TResult, typename TProgress>
    struct category<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
    {
        using type = pinterface_category<TResult, TProgress>;
        static constexpr GUID value{ 0xe85df41d, 0x6aa7, 0x46e3,{ 0xa8, 0xe2, 0xf0, 0x09, 0xd8, 0x40, 0xc6, 0x27 } };
    };

    template <>
    struct guid<Windows::Foundation::IAsyncInfo>
    {
        static constexpr GUID value{ 0x00000036,0x0000,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
    };

    template <>
    struct name<Windows::Foundation::IAsyncInfo>
    {
        static constexpr auto & value{ L"Windows.Foundation.IAsyncInfo" };
    };

    template <>
    struct category<Windows::Foundation::IAsyncInfo>
    {
        using type = interface_category;
    };

    template <>
    struct guid<Windows::Foundation::IAsyncAction>
    {
        static constexpr GUID value{ 0x5A648006,0x843A,0x4DA9,{ 0x86,0x5B,0x9D,0x26,0xE5,0xDF,0xAD,0x7B } };
    };

    template <>
    struct name<Windows::Foundation::IAsyncAction>
    {
        static constexpr auto & value{ L"Windows.Foundation.IAsyncAction" };
    };

    template <>
    struct category<Windows::Foundation::IAsyncAction>
    {
        using type = interface_category;
    };

    template <typename TResult>
    struct guid<Windows::Foundation::IAsyncOperation<TResult>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::IAsyncOperation<TResult>>::value };
    };

    template <typename TResult>
    struct name<Windows::Foundation::IAsyncOperation<TResult>>
    {
        static constexpr auto value{ L"Windows.Foundation.IAsyncOperation`1<" + make_constexpr_string(name_v<TResult>) + L">" };
    };

    template <typename TResult>
    struct category<Windows::Foundation::IAsyncOperation<TResult>>
    {
        using type = pinterface_category<TResult>;
        static constexpr GUID value{ 0x9fc2b0bb, 0xe446, 0x44e2,{ 0xaa, 0x61, 0x9c, 0xab, 0x8f, 0x63, 0x6a, 0xf2 } };
    };

    template <typename TProgress>
    struct guid<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::IAsyncActionWithProgress<TProgress>>::value };
    };

    template <typename TProgress>
    struct name<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        static constexpr auto value{ L"Windows.Foundation.IAsyncActionWithProgress`1<" + make_constexpr_string(name_v<TProgress>) + L">" };
    };

    template <typename TProgress>
    struct category<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        using type = pinterface_category<TProgress>;
        static constexpr GUID value{ 0x1f6db258, 0xe803, 0x48a1,{ 0x95, 0x46, 0xeb, 0x73, 0x53, 0x39, 0x88, 0x84 } };
    };

    template <typename TResult, typename TProgress>
    struct guid<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>::value };
    };

    template <typename TResult, typename TProgress>
    struct name<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        static constexpr auto value{ L"Windows.Foundation.IAsyncOperationWithProgress`2<" + make_constexpr_string(name_v<TResult>) + L"," + make_constexpr_string(name_v<TProgress>) + L">" };
    };

    template <typename TResult, typename TProgress>
    struct category<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        using type = pinterface_category<TResult, TProgress>;
        static constexpr GUID value{ 0xb5d036d7, 0xe297, 0x498f,{ 0xba, 0x60, 0x02, 0x89, 0xe7, 0x6e, 0x23, 0xdd } };
    };
}

WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct IAsyncInfo :
        IInspectable,
        impl::consume_t<IAsyncInfo>
    {
        IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
    };

    struct IAsyncAction :
        IInspectable,
        impl::consume_t<IAsyncAction>,
        impl::require<IAsyncAction, IAsyncInfo>
    {
        IAsyncAction(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename TProgress>
    struct WINRT_EBO IAsyncActionWithProgress :
        IInspectable,
        impl::consume_t<IAsyncActionWithProgress<TProgress>>,
        impl::require<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
    {
        IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename TResult>
    struct WINRT_EBO IAsyncOperation :
        IInspectable,
        impl::consume_t<IAsyncOperation<TResult>>,
        impl::require<IAsyncOperation<TResult>, IAsyncInfo>
    {
        IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename TResult, typename TProgress>
    struct WINRT_EBO IAsyncOperationWithProgress :
        IInspectable,
        impl::consume_t<IAsyncOperationWithProgress<TResult, TProgress>>,
        impl::require<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
    {
        IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
    };

    struct AsyncActionCompletedHandler : IUnknown
    {
        AsyncActionCompletedHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        AsyncActionCompletedHandler(L handler) :
            AsyncActionCompletedHandler(impl::make_delegate<AsyncActionCompletedHandler>(std::forward<L>(handler)))
        {}

        template <typename F> AsyncActionCompletedHandler(F* handler) :
            AsyncActionCompletedHandler([=](auto&& ... args) { handler(args ...); })
        {}

        template <typename O, typename M> AsyncActionCompletedHandler(O* object, M method) :
            AsyncActionCompletedHandler([=](auto&& ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(IAsyncAction const& sender, AsyncStatus args) const
        {
            check_hresult((*(abi_t<AsyncActionCompletedHandler>**)this)->Invoke(get_abi(sender), args));
        }
    };

    template <typename TProgress>
    struct WINRT_EBO AsyncActionProgressHandler : IUnknown
    {
        AsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        AsyncActionProgressHandler(L handler) :
            AsyncActionProgressHandler(impl::make_delegate<AsyncActionProgressHandler<TProgress>>(std::forward<L>(handler)))
        {}

        template <typename F> AsyncActionProgressHandler(F* handler) :
            AsyncActionProgressHandler([=](auto&& ... args) { handler(args ...); })
        {}

        template <typename O, typename M> AsyncActionProgressHandler(O* object, M method) :
            AsyncActionProgressHandler([=](auto&& ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(IAsyncActionWithProgress<TProgress> const& sender, TProgress const& args) const
        {
            check_hresult((*(abi_t<AsyncActionProgressHandler<TProgress>>**)this)->Invoke(get_abi(sender), get_abi(args)));
        }
    };

    template <typename TProgress>
    struct WINRT_EBO AsyncActionWithProgressCompletedHandler : IUnknown
    {
        AsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        AsyncActionWithProgressCompletedHandler(L handler) :
            AsyncActionWithProgressCompletedHandler(impl::make_delegate<AsyncActionWithProgressCompletedHandler<TProgress>>(std::forward<L>(handler)))
        {}

        template <typename F> AsyncActionWithProgressCompletedHandler(F* handler) :
            AsyncActionWithProgressCompletedHandler([=](auto&& ... args) { handler(args ...); })
        {}

        template <typename O, typename M> AsyncActionWithProgressCompletedHandler(O* object, M method) :
            AsyncActionWithProgressCompletedHandler([=](auto&& ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(IAsyncActionWithProgress<TProgress> const& sender, AsyncStatus const args) const
        {
            check_hresult((*(abi_t<AsyncActionWithProgressCompletedHandler<TProgress>>**)this)->Invoke(get_abi(sender), args));
        }
    };

    template <typename TResult, typename TProgress>
    struct WINRT_EBO AsyncOperationProgressHandler : IUnknown
    {
        AsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        AsyncOperationProgressHandler(L handler) :
            AsyncOperationProgressHandler(impl::make_delegate<AsyncOperationProgressHandler<TResult, TProgress>>(std::forward<L>(handler)))
        {}

        template <typename F> AsyncOperationProgressHandler(F* handler) :
            AsyncOperationProgressHandler([=](auto&& ... args) { handler(args ...); })
        {}

        template <typename O, typename M> AsyncOperationProgressHandler(O* object, M method) :
            AsyncOperationProgressHandler([=](auto&& ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(IAsyncOperationWithProgress<TResult, TProgress> const& sender, TProgress const& args) const
        {
            check_hresult((*(abi_t<AsyncOperationProgressHandler<TResult, TProgress>>**)this)->Invoke(get_abi(sender), get_abi(args)));
        }
    };

    template <typename TResult, typename TProgress>
    struct WINRT_EBO AsyncOperationWithProgressCompletedHandler : IUnknown
    {
        AsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        AsyncOperationWithProgressCompletedHandler(L handler) :
            AsyncOperationWithProgressCompletedHandler(impl::make_delegate<AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(std::forward<L>(handler)))
        {}

        template <typename F> AsyncOperationWithProgressCompletedHandler(F* handler) :
            AsyncOperationWithProgressCompletedHandler([=](auto&& ... args) { handler(args ...); })
        {}

        template <typename O, typename M> AsyncOperationWithProgressCompletedHandler(O* object, M method) :
            AsyncOperationWithProgressCompletedHandler([=](auto&& ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(IAsyncOperationWithProgress<TResult, TProgress> const& sender, AsyncStatus const args) const
        {
            check_hresult((*(abi_t<AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>**)this)->Invoke(get_abi(sender), args));
        }
    };

    template <typename TResult>
    struct WINRT_EBO AsyncOperationCompletedHandler : IUnknown
    {
        AsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        AsyncOperationCompletedHandler(L handler) :
            AsyncOperationCompletedHandler(impl::make_delegate<AsyncOperationCompletedHandler<TResult>>(std::forward<L>(handler)))
        {}

        template <typename F> AsyncOperationCompletedHandler(F* handler) :
            AsyncOperationCompletedHandler([=](auto&& ... args) { handler(args ...); })
        {}

        template <typename O, typename M> AsyncOperationCompletedHandler(O* object, M method) :
            AsyncOperationCompletedHandler([=](auto&& ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(IAsyncOperation<TResult> const& sender, AsyncStatus args) const
        {
            check_hresult((*(abi_t<AsyncOperationCompletedHandler<TResult>>**)this)->Invoke(get_abi(sender), args));
        }
    };
}

namespace winrt::impl
{
    template <typename D>
    uint32_t consume_IAsyncInfo<D>::Id() const noexcept
    {
        uint32_t id{};
        check_terminate((*(abi_t<Windows::Foundation::IAsyncInfo>**)&static_cast<Windows::Foundation::IAsyncInfo const&>(static_cast<D const&>(*this)))->get_Id(&id));
        return id;
    }

    template <typename D>
    Windows::Foundation::AsyncStatus consume_IAsyncInfo<D>::Status() const noexcept
    {
        Windows::Foundation::AsyncStatus status{};
        check_terminate((*(abi_t<Windows::Foundation::IAsyncInfo>**)&static_cast<Windows::Foundation::IAsyncInfo const&>(static_cast<D const&>(*this)))->get_Status(&status));
        return status;
    }

    template <typename D>
    HRESULT consume_IAsyncInfo<D>::ErrorCode() const noexcept
    {
        HRESULT code = S_OK;
        check_terminate((*(abi_t<Windows::Foundation::IAsyncInfo>**)&static_cast<Windows::Foundation::IAsyncInfo const&>(static_cast<D const&>(*this)))->get_ErrorCode(&code));
        return code;
    }

    template <typename D>
    void consume_IAsyncInfo<D>::Cancel() const
    {
        check_hresult((*(abi_t<Windows::Foundation::IAsyncInfo>**)&static_cast<Windows::Foundation::IAsyncInfo const&>(static_cast<D const&>(*this)))->Cancel());
    }

    template <typename D>
    void consume_IAsyncInfo<D>::Close() const
    {
        check_hresult((*(abi_t<Windows::Foundation::IAsyncInfo>**)&static_cast<Windows::Foundation::IAsyncInfo const&>(static_cast<D const&>(*this)))->Close());
    }


    template <typename D>
    void consume_IAsyncAction<D>::Completed(const Windows::Foundation::AsyncActionCompletedHandler& handler) const noexcept
    {
        check_terminate((*(abi_t<Windows::Foundation::IAsyncAction>**)&static_cast<Windows::Foundation::IAsyncAction const&>(static_cast<D const&>(*this)))->put_Completed(get_abi(handler)));
    }

    template <typename D>
    Windows::Foundation::AsyncActionCompletedHandler consume_IAsyncAction<D>::Completed() const noexcept
    {
        Windows::Foundation::AsyncActionCompletedHandler handler{};
        check_terminate((*(abi_t<Windows::Foundation::IAsyncAction>**)&static_cast<Windows::Foundation::IAsyncAction const&>(static_cast<D const&>(*this)))->get_Completed(put_abi(handler)));
        return handler;
    }

    template <typename D>
    void consume_IAsyncAction<D>::GetResults() const
    {
        check_hresult((*(abi_t<Windows::Foundation::IAsyncAction>**)&static_cast<Windows::Foundation::IAsyncAction const&>(static_cast<D const&>(*this)))->GetResults());
    }

    template <typename D>
    void consume_IAsyncAction<D>::get() const
    {
        blocking_suspend(static_cast<Windows::Foundation::IAsyncAction const&>(static_cast<D const&>(*this)));
        GetResults();
    }

    template <typename D, typename TResult>
    void consume_IAsyncOperation<D, TResult>::Completed(Windows::Foundation::AsyncOperationCompletedHandler<TResult> const& handler) const noexcept
    {
        check_terminate((*(abi_t<Windows::Foundation::IAsyncOperation<TResult>>**)&static_cast<Windows::Foundation::IAsyncOperation<TResult> const&>(static_cast<D const&>(*this)))->put_Completed(get_abi(handler)));
    }

    template <typename D, typename TResult>
    Windows::Foundation::AsyncOperationCompletedHandler<TResult> consume_IAsyncOperation<D, TResult>::Completed() const noexcept
    {
        Windows::Foundation::AsyncOperationCompletedHandler<TResult> temp;
        check_terminate((*(abi_t<Windows::Foundation::IAsyncOperation<TResult>>**)&static_cast<Windows::Foundation::IAsyncOperation<TResult> const&>(static_cast<D const&>(*this)))->get_Completed(put_abi(temp)));
        return temp;
    }

    template <typename D, typename TResult>
    TResult consume_IAsyncOperation<D, TResult>::GetResults() const
    {
        TResult result = empty_value<TResult>();
        check_hresult((*(abi_t<Windows::Foundation::IAsyncOperation<TResult>>**)&static_cast<Windows::Foundation::IAsyncOperation<TResult> const&>(static_cast<D const&>(*this)))->GetResults(put_abi(result)));
        return result;
    }

    template <typename D, typename TResult>
    TResult consume_IAsyncOperation<D, TResult>::get() const
    {
        blocking_suspend(static_cast<Windows::Foundation::IAsyncOperation<TResult> const&>(static_cast<D const&>(*this)));
        return GetResults();
    }

    template <typename D, typename TProgress>
    void consume_IAsyncActionWithProgress<D, TProgress>::Progress(Windows::Foundation::AsyncActionProgressHandler<TProgress> const& handler) const noexcept
    {
        check_terminate((*(abi_t<Windows::Foundation::IAsyncActionWithProgress<TProgress>>**)&static_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const&>(static_cast<D const&>(*this)))->put_Progress(get_abi(handler)));
    }

    template <typename D, typename TProgress>
    Windows::Foundation::AsyncActionProgressHandler<TProgress> consume_IAsyncActionWithProgress<D, TProgress>::Progress() const noexcept
    {
        Windows::Foundation::AsyncActionProgressHandler<TProgress> handler;
        check_terminate((*(abi_t<Windows::Foundation::IAsyncActionWithProgress<TProgress>>**)&static_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const&>(static_cast<D const&>(*this)))->get_Progress(put_abi(handler)));
        return handler;
    }

    template <typename D, typename TProgress>
    void consume_IAsyncActionWithProgress<D, TProgress>::Completed(Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> const& handler) const noexcept
    {
        check_terminate((*(abi_t<Windows::Foundation::IAsyncActionWithProgress<TProgress>>**)&static_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const&>(static_cast<D const&>(*this)))->put_Completed(get_abi(handler)));
    }

    template <typename D, typename TProgress>
    Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> consume_IAsyncActionWithProgress<D, TProgress>::Completed() const noexcept
    {
        Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> handler;
        check_terminate((*(abi_t<Windows::Foundation::IAsyncActionWithProgress<TProgress>>**)&static_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const&>(static_cast<D const&>(*this)))->get_Completed(put_abi(handler)));
        return handler;
    }

    template <typename D, typename TProgress>
    void consume_IAsyncActionWithProgress<D, TProgress>::GetResults() const
    {
        check_hresult((*(abi_t<Windows::Foundation::IAsyncActionWithProgress<TProgress>>**)&static_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const&>(static_cast<D const&>(*this)))->GetResults());
    }

    template <typename D, typename TProgress>
    void consume_IAsyncActionWithProgress<D, TProgress>::get() const
    {
        blocking_suspend(static_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const&>(static_cast<D const&>(*this)));
        GetResults();
    }

    template <typename D, typename TResult, typename TProgress>
    void consume_IAsyncOperationWithProgress<D, TResult, TProgress>::Progress(Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress> const& handler) const noexcept
    {
        check_terminate((*(abi_t<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>**)&static_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const&>(static_cast<D const&>(*this)))->put_Progress(get_abi(handler)));
    }

    template <typename D, typename TResult, typename TProgress>
    Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress> consume_IAsyncOperationWithProgress<D, TResult, TProgress>::Progress() const noexcept
    {
        Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress> handler;
        check_terminate((*(abi_t<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>**)&static_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const&>(static_cast<D const&>(*this)))->get_Progress(put_abi(handler)));
        return handler;
    }

    template <typename D, typename TResult, typename TProgress>
    void consume_IAsyncOperationWithProgress<D, TResult, TProgress>::Completed(Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> const& handler) const noexcept
    {
        check_terminate((*(abi_t<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>**)&static_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const&>(static_cast<D const&>(*this)))->put_Completed(get_abi(handler)));
    }

    template <typename D, typename TResult, typename TProgress>
    Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> consume_IAsyncOperationWithProgress<D, TResult, TProgress>::Completed() const noexcept
    {
        Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
        check_terminate((*(abi_t<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>**)&static_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const&>(static_cast<D const&>(*this)))->get_Completed(put_abi(handler)));
        return handler;
    }

    template <typename D, typename TResult, typename TProgress>
    TResult consume_IAsyncOperationWithProgress<D, TResult, TProgress>::GetResults() const
    {
        TResult result = empty_value<TResult>();
        check_hresult((*(abi_t<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>**)&static_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const&>(static_cast<D const&>(*this)))->GetResults(put_abi(result)));
        return result;
    }

    template <typename D, typename TResult, typename TProgress>
    TResult consume_IAsyncOperationWithProgress<D, TResult, TProgress>::get() const
    {
        blocking_suspend(static_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const&>(static_cast<D const&>(*this)));
        return GetResults();
    }
}
