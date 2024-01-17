template<typename T>
DArray<T>::DArray() {
    _n = 0;
    _cap= 0;
    _contents = nullptr;
}

template <typename T>
DArray<T>::DArray(const std::initializer_list<T>& data) {
	_cap = _n = data.size();
	_contents = new T[_n];
	for (const T* it = data.begin(); it != data.end(); it++)
		_contents[it - data.begin()] = *it;
}

template<typename T>
DArray<T>::DArray(const DArray<T>& copy) : _n(copy._n), _cap(copy._cap), _contents(new T[_cap]) {
    for(int i = 0; i < _n; ++i)
        _contents[i] = copy._contents[i];
}

template<typename T>
DArray<T>::DArray(unsigned int n) {
	_n = _cap = n;
    _contents = new T[_cap];

    for(int i = 0; i < _n; i++)
        _contents[i] = T();
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
int DArray<T>::indexOf(T val) const {
	for (int i = 0; i < _n; ++i)
		if (_contents[i] == val)
			return i;

	return -1;
}

template <typename T>
int DArray<T>::find(std::function<bool(T)> func) const {
	for (int i = 0; i < _n; ++i)
		if (func(_contents[i]))
			return i;

	return -1;
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
void DArray<T>::resize(unsigned int n) {
	_cap = n;
	T* temp = new T[_cap];

	for (int i = 0; i < n; i++)
		temp[i] = i < _n ? _contents[i] : T();
	
	delete [] _contents;
	_contents = temp;
	_n = n;
}
	
template <typename T>
void DArray<T>::resize(unsigned int n, const T& v) {
	_cap = n;
	T* temp = new T[_cap];

	for (int i = 0; i < n; i++)
		temp[i] = i < _n ? _contents[i] : v;
	
	delete [] _contents;
	_contents = temp;
	_n = n;
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
