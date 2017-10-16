
WINRT_EXPORT namespace winrt
{
    template <typename T>
    struct agile_ref
    {
        agile_ref(std::nullptr_t = nullptr) noexcept {}

        agile_ref(T const& object)
        {
            check_hresult(RoGetAgileReference(AGILEREFERENCE_DEFAULT,
                guid_of<T>(),
                winrt::get_abi(object),
                put_abi(m_ref)));
        }

        T get() const
        {
            T result = nullptr;
            check_hresult(m_ref->Resolve(guid_of<T>(), reinterpret_cast<void**>(put_abi(result))));
            return result;
        }

        explicit operator bool() const noexcept
        {
            return static_cast<bool>(m_ref);
        }

    private:

        com_ptr<IAgileReference> m_ref;
    };

    template <typename T>
    agile_ref<T> make_agile(T const& object)
    {
        return object;
    }
}
