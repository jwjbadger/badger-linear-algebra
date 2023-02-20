template <typename T, unsigned short n>
Vector<T, n>::Vector(std::initializer_list<T> data) : vector(data) {};

template <typename T, unsigned short n>
T Vector<T, n>::operator[](const unsigned short r) {
	return vector[r];
}
