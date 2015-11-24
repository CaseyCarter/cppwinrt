
#pragma once

namespace Modern { namespace Windows { namespace Foundation {

inline IReference<byte> Reference(byte const value)
{
	return PropertyValue::CreateUInt8(value).As<IReference<byte>>();
}

inline IReference<short> Reference(short const value)
{
	return PropertyValue::CreateInt16(value).As<IReference<short>>();
}

//inline IReference<unsigned short> Reference(unsigned short const value)
//{
//	return PropertyValue::CreateUInt16(value).As<IReference<unsigned short>>();
//}

inline IReference<unsigned> Reference(unsigned const value)
{
	return PropertyValue::CreateUInt32(value).As<IReference<unsigned>>();
}

template <typename T>
IReference<T>::IReference(T const & value) :
	IReference(Reference(value))
{}

}}}
