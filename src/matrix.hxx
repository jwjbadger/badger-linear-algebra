template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::vector<T>> data) : _matrix(data) {
	_size.m = _matrix.size();
	_size.n = _matrix[0].size();
}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> data) {
	_matrix = data;	

	_size.m = _matrix.size();
	_size.n = _matrix[0].size();
}

template <typename T>
std::vector<T> Matrix<T>::operator[](const unsigned int r) {
	return _matrix[r];
}

template <typename T>
MSize Matrix<T>::size() {
	return _size;
}

template <typename T>
std::vector<std::vector<T>> Matrix<T>::data() {
	return _matrix;
}

template <typename T>
Vector<T> Matrix<T>::operator*(Vector<T> b) {
	Vector<T> product {};

	for (int i = 0; i < _size.m; i++) {
		T temp = 0;
		
		for (int j = 0; j < _size.n; j++)
			temp += _matrix[i][j] * b[j];
		
		product.push(temp);
	}

	return product;
}
