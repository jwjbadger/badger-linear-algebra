template <typename T>
DArray<T>::DArray(std::initializer_list<T> data) {
	_cap, _n = data.size();
	_contents = new T[_n];
	
	for (const T* it = data.begin(); it != data.end(); ++it)
		_contents[std::distance(data.begin(), it)] = *it;
}

template <typename T>
T& DArray<T>::operator[](const unsigned int r) {
	return _contents[r];
}
