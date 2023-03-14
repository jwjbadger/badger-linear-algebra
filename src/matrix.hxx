template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::vector<T>> data) : matrix(data) {
	m = matrix.size();
	n = matrix[0].size();
}

template <typename T>
std::vector<T> Matrix<T>::operator[](const unsigned int r) {
	return matrix[r];
}
