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
Matrix<T>::Matrix(const int m, const int n) {
	for (int i = 0; i < m; i++) {
		std::vector<T> row(n, 0); 
		_matrix.push_back(row);
	}

	_size.m = m;
	_size.n = n;
}

template <typename T>
std::vector<T>& Matrix<T>::operator[](const unsigned int r) {
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

template<typename T>
Matrix<T>& Matrix<T>::insert(const int m, const int n, const T value) {
	if (m >= _size.m || n >= _size.n) {
		_matrix.resize(m + 1, std::vector<T>(n + 1));

		_size.m = _size.m <= m ? m + 1 : _size.m;
		_size.n = _size.n <= n ? n + 1 : _size.n;
	}
	
	_matrix[m][n] = value;
	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::resize(const int m, const int n) {
	_matrix.resize(m, std::vector<T>(n));

	_size.m = m;
	_size.n = n;

	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> b)	{
	Matrix<T> sum(_size.m, _size.n);

	for (int i = 0; i < _size.m; i++) {
		for (int j = 0; j < _size.n; j++)
			sum[i][j] = _matrix[i][j] + b[i][j];
			
	}

	return sum;
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
