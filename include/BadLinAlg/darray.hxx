template <typename T>
DArray<T>::DArray(std::initializer_list<T> data) {
	_cap = _n = data.size();
	_contents = new T[_n];
	
	for (const T* it = data.begin(); it != data.end(); it++)
		_contents[it - data.begin()] = *it;
}

template <typename T>
DArray<T>::~DArray() {
	delete [] _contents;
}

template <typename T>
T& DArray<T>::operator[](const unsigned int r) {
	return _contents[r];
}

template <typename T>
DArray<T>& DArray<T>::operator=(DArray<T> b) {
	*_contents = *b._contents;
	_cap = b._cap;
	_n = b._n;

	return *this;
}

template <typename T>
unsigned int DArray<T>::size() const {
	return _n;
}

template <typename T>
DArray<T>& DArray<T>::push(const T v) {
	if (_n == _cap)
		expand();
	
	_contents[_n++] = v;
	return *this;
}

template <typename T>
DArray<T>& DArray<T>::pop() {
	_contents[_n--].~T();
	return *this;
}

template <typename T>
void DArray<T>::expand() {
	T* temp = new T[_cap * 2];

	for (int i = 0; i < _n; i++)
		temp[i] = _contents[i];
	
	delete [] _contents;
	_contents = temp;
	_cap *= 2;
}
