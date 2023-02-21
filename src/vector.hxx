template <typename T>
Vector<T>::Vector(std::initializer_list<T> data) : vector(data) {
	n = vector.size();
};

template <typename T>
T Vector<T>::operator[](const unsigned int r) {
	return vector[r];
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
unsigned int Vector<T>::size() {
	return n;
}

template <typename T>
std::vector<T> Vector<T>::data() {
	return vector;
}

