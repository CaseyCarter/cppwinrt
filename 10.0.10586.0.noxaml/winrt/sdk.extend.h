// C++ for the Windows Runtime v1.29 - http://moderncpp.com
// Copyright (c) 2016 Microsoft Corporation

#pragma once

namespace winrt { namespace Windows { namespace ApplicationModel { namespace Core {

template <typename T>
struct IFrameworkViewSourceT : impl::implements<IFrameworkViewSource>
{
	virtual HRESULT __stdcall abi_CreateView(abi_arg_out<IFrameworkView> view) noexcept override
	{
		try
		{
			*view = detach(static_cast<T *>(this)->CreateView());
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename T>
struct IFrameworkViewT : impl::implements<IFrameworkView>
{
	void Initialize(CoreApplicationView const &) const noexcept
	{
	}

	void SetWindow(UI::Core::CoreWindow const &) const noexcept
	{
	}

	void Load(String const &) const noexcept
	{
	}

	void Run() const
	{
		UI::Core::CoreWindow window = UI::Core::CoreWindow::GetForCurrentThread();
		window.Activate();

		UI::Core::ICoreDispatcher dispatcher = window.Dispatcher();
		dispatcher.ProcessEvents(UI::Core::CoreProcessEventsOption::ProcessUntilQuit);
	}

	void Uninitialize() const noexcept
	{
	}

	HRESULT __stdcall abi_Initialize(abi_arg_in<ICoreApplicationView> view) noexcept
	{
		try
		{
			static_cast<T *>(this)->Initialize(impl::forward<CoreApplicationView>(view));
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	HRESULT __stdcall abi_SetWindow(abi_arg_in<UI::Core::ICoreWindow> window) noexcept
	{
		try
		{
			static_cast<T *>(this)->SetWindow(impl::forward<UI::Core::CoreWindow>(window));
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	HRESULT __stdcall abi_Load(HSTRING entryPoint) noexcept
	{
		try
		{
			static_cast<T *>(this)->Load(impl::forward<String>(entryPoint));
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	HRESULT __stdcall abi_Run() noexcept
	{
		try
		{
			static_cast<T *>(this)->Run();
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	HRESULT __stdcall abi_Uninitialize() noexcept
	{
		try
		{
			static_cast<T *>(this)->Uninitialize();
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

}}}}
