
template <typename T>
struct %FactoryT : impl::implements<Windows::IActivationFactory%>
{
protected:

    %FactoryT() noexcept
    {
        lock_module();
    }
    
    ~%FactoryT() noexcept
    {
        unlock_module();
    }
%};
