template <typename T>
Vector<T>::Vector(std::initializer_list<T> data) : vector(data) {
	n = vector.size();
};

template <typename T>
T Vector<T>::operator[](const unsigned int r) {
	return vector[r];
}
