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
template <typename castType>
Matrix<T>::operator Matrix<castType>() const {
	Matrix<double> ret(_size.m, _size.n);
	
	for (int i = 0; i < _size.m; ++i)
		for (int j = 0; j < _size.n; ++j)
			ret[i][j] = static_cast<castType>(_matrix[i][j]);

	return ret;
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
void Matrix<T>::swapRow(unsigned int a, unsigned int b) {
	if (a == b)
		return;

	DArray<T> temp = _matrix[b];
	_matrix[b] = _matrix[a];
	_matrix[a] = temp;
}

template <typename T>
Matrix<double> Matrix<T>::GaussJordan() {
	// Create a partitioned Matrix A|I
	Matrix<double> A = static_cast<Matrix<double>>(*this);
	Matrix<double> I = Matrix<double>::identity(_size.n);

	std::cout << A[0][0] << " " << A[0][1] << std::endl << A[1][0] << " " << A[1][1] << std::endl;

	// Perform Gauss-Jordan elimination to convert A to RREF, following the same steps for I
	for (int i = 0; i < A.size().n; ++i) {
		// Find the row with the largest non-zero left-most element
		unsigned int index = 0;
		double value = -9999999999.99;
		for (int j = i; j < A.size().m; ++j) {
			int k = A[j].find([](double e) -> bool { return e != 0; });
		
			if (A[j][k] > value) {
				value = A[j][k];
				index = k;
			}
		}

		// Swap either the row with the largest non-zero left-most or the next row in the sequence with the first row 
		if (i < A.size().n) {
			A.swapRow(0, index);
			I.swapRow(0, index);
		}

		// Multiply the first row by the factor needed to make the non-zero left-most number a 1
		int leading = A[0].find([](float e) -> bool { return e != 0; });
		double factor = 1 / A[0][leading];
		A[0] = A[0] * factor;
		I[0] = I[0] * factor;

		// Add the first row multiplied by a factor to the rest of the rows in order to remove any values below the array
		for (int j = 1; j < A.size().m; ++j) {
			factor = -1 * A[j][leading] / A[0][leading];
			A[j] = A[j] + (A[0] * factor);
			I[j] = I[j] + (I[0] * factor);
		}
	}

	// Sort the return Matrix so the topmost row has the leftmost non-zero number and so on
	Matrix<double> ret(_size.n, _size.n); 
	for (int i = 0; i < A.size().m; ++i)
		ret[A[i].find([](float e) -> bool { return e != 0; })] = I[i];

	return ret;
}

template <typename T>
Matrix<double> Matrix<T>::pinv() {
	return static_cast<Matrix<double>>(this->transpose()) * (*this * this->transpose()).GaussJordan();
}
