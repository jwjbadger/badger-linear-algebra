// MSize
bool MSize::operator==(const MSize& b) const {
	return n == b.n && m == b.m;
}
bool MSize::operator!=(const MSize& b) const {
	return !(n == b.n && m == b.m);
}
	
bool MSize::operator==(const unsigned int arr[2]) const {
	return n == arr[1] && m == arr[0];
}
bool MSize::operator!=(const unsigned int arr[2]) const {
	return !(n == arr[1] && m == arr[0]);
}

// Matrix
template <typename T>
Matrix<T>::Matrix(std::initializer_list<DArray<T>> data) : _matrix(data) {
	_size.m = _matrix.size();
	_size.n = _matrix[0].size();
}

template <typename T>
Matrix<T>::Matrix(DArray<DArray<T>> data) : _matrix(data) {
	_size.m = _matrix.size();
	_size.n = _matrix[0].size();
}

template <typename T>
Matrix<T>::Matrix(const int m, const int n) {
	for (int i = 0; i < m; i++)
		_matrix.push(DArray<T>(n));

	_size.m = m;
	_size.n = n;
}

template <typename T>
Matrix<T> Matrix<T>::identity(unsigned int n) {
	Matrix<T> ret(n, n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ret[i][j] = (i == j);

	return ret;
}

template <typename T>
DArray<T>& Matrix<T>::operator[](const unsigned int r) {
	return _matrix[r];
}

template <typename T>
const DArray<T>& Matrix<T>::operator[](const unsigned int r) const {
	return _matrix[r];
}

template <typename T>
MSize Matrix<T>::size() const {
	return _size;
}

template <typename T>
DArray<DArray<T>> Matrix<T>::data() {
	return _matrix;
}

template <typename T>
T Matrix<T>::det() {
	switch (_size.m) {
		case 1:
			return _matrix[0][0];
			break;
		case 2:
			return (_matrix[0][0] * _matrix[1][1]) - (_matrix[0][1] * _matrix[1][0]);
			break;
		default:
			T determ = 0;

			// Loop through first row of matrix
			for (int i = 0; i < _size.m; ++i) {
				Matrix<T> subArray(_size.m - 1, _size.m - 1); // Find determinate of subarray found by crossing out the row and column of the given element of the first row
				
				// Looping through to cross out the row and column
				for (int j = 1; j < _size.m; ++j)
					for (int k = 0; k < _size.m; ++k)
						if (k != i)
							subArray[j - 1][k > i ? k - 1 : k] = _matrix[j][k];

				// Multiply by the element we crossed out then add if the element's position was even and subtract if odd (part of formula)
				determ += (i % 2 == 0) ? (_matrix[0][i] * subArray.det()) : (-1 * _matrix[0][i] * subArray.det());
			}

			return determ;
	}
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& b) const {
	if (_size != b.size())
		return false;

	for (int i = 0; i < _size.m; i++)
		for (int j = 0; j < _size.n; j++)
			if (_matrix[i][j] != b[i][j])
				return false;

	return true;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix<T>& b) const {
	if (_size != b.size())
		return true;

	for (int i = 0; i < _size.m; i++)
		for (int j = 0; j < _size.n; j++)
			if (_matrix[i][j] != b[i][j])
				return true;

	return false;
}

template<typename T>
Matrix<T>& Matrix<T>::pushRow(DArray<T> b) {
	_size.m++;
	_matrix.push(b);

	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::resize(const int m, const int n) {
	_matrix.resize(m, DArray<T>(n));

	_size.m = m;
	_size.n = n;

	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> b)	{
	Matrix<T> sum(_size.m, _size.n);

	for (int i = 0; i < _size.m; i++) 
		for (int j = 0; j < _size.n; j++)
			sum[i][j] = _matrix[i][j] + b[i][j];

	return sum;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T b) {
	Matrix<T> sum(_size.m, _size.n);

	for (int i = 0; i < _size.m; i++)
		for (int j = 0; j < _size.n; j++)
			sum[i][j] = _matrix[i][j] + b;

	return sum;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> b)	{
	Matrix<T> diff(_size.m, _size.n);

	for (int i = 0; i < _size.m; i++)
		for (int j = 0; j < _size.n; j++)
			diff[i][j] = _matrix[i][j] - b[i][j];

	return diff;
}


template <typename T>
Matrix<T> Matrix<T>::operator-(const T b) {
	Matrix<T> diff(_size.m, _size.n);

	for (int i = 0; i < _size.m; i++)
		for (int j = 0; j < _size.n; j++)
			diff[i][j] = _matrix[i][j] - b;

	return diff;
}

template <typename T>
Vector<T> Matrix<T>::operator*(Vector<T> b) {
	Vector<T> product {};

	for (int i = 0; i < _size.m; i++) {
		product.push(0);

		for (int j = 0; j < _size.n; j++)
			product[i] += _matrix[i][j] * b[j];
	}
	
	return product;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T b) {
	Matrix<T> product(_size.m, _size.n);

	for (int i = 0; i < _size.m; i++)
		for (int j = 0; j < _size.n; j++)
			product[i][j] = _matrix[i][j] * b;

	return product;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> b) {
	MSize bsize = b.size(); // n x p	
	Matrix<T> product(_size.m, bsize.n); // m x p

	for (int i = 0; i < bsize.n; i++)
		for (int j = 0; j < _size.m; j++)
			for (int k = 0; k < _size.n; k++) 
				product[j][i] += _matrix[j][k] * b[k][i];	

	return product;
}


template <typename T>
Matrix<T> Matrix<T>::operator/(const T b) {
	Matrix<T> quotiant(_size.m, _size.n);

	for (int i = 0; i < _size.m; i++)
		for (int j = 0; j < _size.n; j++)
			quotiant[i][j] = _matrix[i][j] / b;

	return quotiant;
}


template <typename T>
Matrix<T> Matrix<T>::transpose() {
	Matrix<T> transposed(_size.n, _size.m);
for (int i = 0; i < _size.m; i++)
		for (int j = 0; j < _size.n; j++)
			transposed[j][i] = _matrix[i][j];

	return transposed;
}

template <typename T>
DArray<T> Matrix<T>::swapRow(unsigned int a, unsigned int b) {
	DArray<T> temp = _matrix[b];
	_matrix[b] = _matrix[a];
	_matrix[a] = temp;

	return _matrix[a];
}

template <typename T>
DArray<T> Matrix<T>::multiplyRow(unsigned int a, T b) {
	for (int i = 0; i < _size.n; ++i)
		_matrix[a][i] *= b;

	return _matrix[a];
}

template <typename T>
DArray<T> Matrix<T>::addRow(unsigned int a, unsigned int b, T factor) {
	for (int i = 0; i < _size.n; ++i)
		_matrix[a][i] += _matrix[b][i] * factor;

	return _matrix[a];
}

template <typename T>
Matrix<double> Matrix<T>::GaussJordan() {
	Matrix<double> A(_size.m, _size.n);
	for (int i = 0; i < _matrix.size(); ++i) {
		for (int j = 0; j < _matrix[0].size(); ++j) {
			A[i][j] = static_cast<double>(_matrix[i][j]);
		}
	}
	
	Matrix<double> I = Matrix<double>::identity(_size.n);

	unsigned int index = 0;
	T value = 0;
	for (int i = 0; i < A.size().m; ++i) {
		unsigned int j = A[i].find([](T e) -> bool { return e != 0; });

	  	if (A[i][j] > value) {
	  		value = A[i][j];
			index = i;
		}
	}

	if (index != 0) {
		A.swapRow(0, index);
		I.swapRow(0, index);
	}

	for (int i = 1; i <= A.size().n; ++i) {
		int leading = A[0].find([](float e) -> bool { return e != 0; });
		double factor = 1 / A[0][leading];
		A.multiplyRow(0, factor);
		I.multiplyRow(0, factor);

		for (int j = 1; j < A.size().m; ++j) {
			factor = -1 * A[j][leading] / A[0][leading];
			A.addRow(j, 0, factor);
			I.addRow(j, 0, factor);
		}
		
		if (i < A.size().n) {
			A.swapRow(0, i);
			I.swapRow(0, i);
		}
	}

	Matrix<double> ret(_size.n, _size.n); 
	for (int i = 0; i < A.size().m; ++i) {
		ret[A[i].find([](float e) -> bool { return e != 0; })] = I[i];
	}

	return ret;
}
