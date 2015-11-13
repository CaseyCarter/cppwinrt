
class %Factory : public Implements<ABI::IActivationFactory%>
{
public:

	virtual HRESULT __stdcall abi_ActivateInstance(::IInspectable ** instance) noexcept override;
%
};
