template <typename T>
DArray<T>::DArray(const std::initializer_list<T>& data) {
	_cap = _n = data.size();
	_contents = new T[_n];
	for (const T* it = data.begin(); it != data.end(); it++)
		_contents[it - data.begin()] = *it;
}

template<typename T>
DArray<T>::DArray(const DArray<T>& src) : _n(src._n), _cap(src._cap),
    _contents(new T[_cap]) {
    for(int i = 0; i < _n; ++i)
        _contents[i] = src._contents[i];
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
const T& DArray<T>::operator[](const unsigned int r) const {
	return _contents[r];
}

template <typename T>
DArray<T>& DArray<T>::operator=(DArray<T> b) {
	delete[] _contents;
	_contents = new T[b._n];
	for (int i = 0; i < b._n; i++)
		_contents[i] = b[i];

	_cap = b._cap;
	_n = b._n;
	
	return *this;
}

template <typename T>
bool DArray<T>::operator==(const DArray<T>& b) const {
	if (_n != b.size())
		return false;

	for (int i = 0; i < _n; i++)
		if (_contents[i] != b[i])
			return false;

	return true;
}

template <typename T>
bool DArray<T>::operator!=(const DArray<T>& b) const {
	if (_n != b.size())
		return true;

	for (int i = 0; i < _n; i++)
		if (_contents[i] != b[i])
			return true;

	return false;
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
	_cap = _cap > 0 ? _cap * 2 : _cap + 1;
	T* temp = new T[_cap];

	for (int i = 0; i < _n; i++)
		temp[i] = _contents[i];
	
	delete [] _contents;
	_contents = temp;
}
