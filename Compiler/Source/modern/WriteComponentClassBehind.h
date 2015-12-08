
template <typename T>
struct %T : impl::implements<%>
{
protected:

    %T() noexcept
    {
        lock_module();
    }
    
    ~%T() noexcept
    {
        unlock_module();
    }
%};
