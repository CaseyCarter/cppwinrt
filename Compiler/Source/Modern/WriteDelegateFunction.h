
template <typename T> % %(T handler)
{
	return make<impl_%<T>>(handler);
}
