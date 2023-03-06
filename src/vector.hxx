template <typename T>
Vector<T>::Vector(std::initializer_list<T> data) : vector(data) {
	n = vector.size();
};

template <typename T>
T Vector<T>::operator[](const unsigned int r) {
	return vector[r];
}

template <typename T>
std::vector<T> Vector<T>::operator=(T data[]) {
	vector = data;
	return vector;
}

template <typename T>
Vector<T>& Vector<T>::pop() {
	vector.pop_back();
	n = vector.size();
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::push(T value) {
	vector.push_back(value);
	n = vector.size();
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(Vector<T> b) {
	Vector<T> sum {};

	for (int i = 0; i < n; i++)
		sum.push(vector[i] + b[i]);

	return sum;
}

template <typename T>
Vector<T> Vector<T>::operator+(const T b) {
	Vector<T> sum {};

	for (int i = 0; i < n; i++)
		sum.push(vector[i] + b);

	return sum;
}

template <typename T>
Vector<T> Vector<T>::operator-(Vector<T> b) {
	Vector<T> diff {};

	for (int i = 0; i < n; i++)
		diff.push(vector[i] - b[i]);

	return diff;
}

template <typename T>
Vector<T> Vector<T>::operator-(const T b) {
	Vector<T> diff {};

	for (int i = 0; i < n; i++)
		diff.push(vector[i] - b);

	return diff;
}

template <typename T>
Vector<T> Vector<T>::operator*(const T b) {
	Vector<T> product {};

	for (int i = 0; i < n; i++)
		product.push(vector[i] * b);	

	return product;
}

template <typename T>
T Vector<T>::dot(Vector<T> b) {
	T product = 0;

	for (int i = 0; i < n; i++) 
		product += vector[i] * b[i];	
	
	return product;
}

template <typename T>
Vector<T> Vector<T>::operator/(const T b) {
	Vector<T> product {};

	for (int i = 0; i < n; i++)
		product.push(vector[i] / b);	

	return product;
}

template <typename T>
unsigned int Vector<T>::size() {
	return n;
}

template <typename T>
std::vector<T> Vector<T>::data() {
	return vector;
}
