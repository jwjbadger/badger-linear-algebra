template <typename T>
Vector<T>::Vector(std::initializer_list<T> data) : _vector(data) {
	_n = _vector.size();
}

template <typename T>
T& Vector<T>::operator[](const unsigned int r) {
	return _vector[r];
}

template <typename T>
const T& Vector<T>::operator[](const unsigned int r) const {
	return _vector[r];
}

template <typename T>
DArray<T> Vector<T>::operator=(T data[]) {
	_vector = data;
	return _vector;
}

template <typename T>
Vector<T>& Vector<T>::pop() {
	_vector.pop();
	_n = _vector.size();
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::push(T value) {
	_vector.push(value);
	_n = _vector.size();
	return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& b) const {
	if (_n != b.size())
		return false;
	
	for (int i = 0; i < _n; i++)
		if (_vector[i] != b[i])
			return false;

	return true;
}
template <typename T>
bool Vector<T>::operator!=(const Vector<T> &b) const {
	if (_n != b.size())
		return true;
	
	for (int i = 0; i < _n; i++)
		if (_vector[i] != b[i])
			return true;

	return false;

}

template <typename T>
Vector<T> Vector<T>::operator+(Vector<T> b) {
	Vector<T> sum {};

	for (int i = 0; i < _n; i++)
		sum.push(_vector[i] + b[i]);
	
	return sum;
}

template <typename T>
Vector<T> Vector<T>::operator+(const T b) {
	Vector<T> sum {};

	for (int i = 0; i < _n; i++)
		sum.push(_vector[i] + b);

	return sum;
}

template <typename T>
Vector<T> Vector<T>::operator-(Vector<T> b) {
	Vector<T> diff {};

	for (int i = 0; i < _n; i++)
		diff.push(_vector[i] - b[i]);

	return diff;
}

template <typename T>
Vector<T> Vector<T>::operator-(const T b) {
	Vector<T> diff {};

	for (int i = 0; i < _n; i++)
		diff.push(_vector[i] - b);

	return diff;
}

template <typename T>
Vector<T> Vector<T>::operator*(const T b) {
	Vector<T> product {};

	for (int i = 0; i < _n; i++)
		product.push(_vector[i] * b);	
  
	return product;
}

template <typename T>
T Vector<T>::dot(Vector<T> b) {
	T product = 0;

	for (int i = 0; i < _n; i++) 
		product += _vector[i] * b[i];	
	
	return product;
}

template <typename T>
Vector<T> Vector<T>::operator/(const T b) {
	Vector<T> product {};

	for (int i = 0; i < _n; i++)
		product.push(_vector[i] / b);	

	return product;
}

template <typename T>
unsigned int Vector<T>::size() const {
	return _n;
}

template <typename T>
DArray<T> Vector<T>::data() {
	return _vector;
}
