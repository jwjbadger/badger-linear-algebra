#include <gtest/gtest.h>
#include <BadLinAlg/matrix.h>
#include <BadLinAlg/vector.h>
#include <BadLinAlg/darray.h>

const double DOUBLE_ABS_ERR = 0.000000000001;

// Should be able to initialize matrices with initializer lists in 3 ways and access elements using [] operator (implies [] works)
TEST(MatrixTest, ArrrayInitialization) {
	Matrix<int> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Matrix<int> m2 {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Matrix<int> m3({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ASSERT_EQ(m1[i][j], (i * 3) + j + 1);
			ASSERT_EQ(m2[i][j], (i * 3) + j + 1);
			ASSERT_EQ(m3[i][j], (i * 3) + j + 1);
		}
	}
}


// Test constructor using a 2D DArray to initialize matrix
TEST(MatrixTest, DArrayInitialization) {
	DArray<DArray<int>> d = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Matrix<int> m(d); 

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ASSERT_EQ(m[i][j], (i * 3) + j + 1);
}

// Test constructor that creates a matrix from size, implies size getter works
TEST(MatrixTest, SizeInitialization) {
	Matrix<int> m(3, 4);

	ASSERT_EQ(m.size().m, 3);
	ASSERT_EQ(m.size().n, 4);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ASSERT_EQ(m[i][j], 0);
}

// Test identity constructor A) returns an identity matrix B) has the property of not mutating a matrix when the two are multiplied
TEST(MatrixTest, IdentityConstructor) {
	Matrix<int> m1 = Matrix<int>::identity(3);

	ASSERT_EQ(m1.size().m, 3);
	ASSERT_EQ(m1.size().n, 3);

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			ASSERT_EQ(m1[i][j], i == j);

	// DEPENDS ON MATRIX MULTIPLICATION WORKING PROPERLY
	Matrix<int> m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};	
	ASSERT_EQ(m2 * m1, m2);
}

// Test equality and inequality between different matrices
TEST(MatrixTest, EqualityOperator) {
	Matrix<int> m1 {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
	Matrix<int> m2 {{1, 2, 3},{4, 4, 6},{7, 8, 9}};
	Matrix<int> m3 {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

	ASSERT_EQ(m1, m3);
	ASSERT_EQ(m3, m1);

	ASSERT_NE(m1, m2);
	ASSERT_NE(m3, m2);
	ASSERT_NE(m2, m1);
}


// Test data() getter to get the 2d DArray stored inside the matrix
TEST(MatrixTest, DataGetter) {
	DArray<DArray<int>> d {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Matrix<int> m {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
}

// Test pushRow() function which adds a row to the end of a matrix
TEST(MatrixTest, Push) {
	Matrix<int> m1 {{1, 2, 3}, {4, 5, 6}};
	Matrix<int> expect {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	m1.pushRow({7, 8, 9});

	ASSERT_EQ(m1, expect);
}

// Test resize() which changes the size of a matrix
TEST(MatrixTest, Resize) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	
	ASSERT_EQ(m1.size().m, 3);
	ASSERT_EQ(m1.size().n, 2);

	m1.resize(2, 4);

	ASSERT_EQ(m1.size().m, 2);
	ASSERT_EQ(m1.size().n, 4);
}

// Should be able to add two matrices
TEST(MatrixTest, MatrixAddition) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> m2 {{2, 1}, {3, 4}, {4, 4}};
	Matrix<int> expect {{3, 3}, {7, 9}, {11, 12}};

	ASSERT_EQ(m1 + m2, expect);
}

// Should be able to add a matrix and a scalar
TEST(MatrixTest, ScalarAddition) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> expect {{3, 4}, {6, 7}, {9, 10}};
	
	ASSERT_EQ(m1 + 2, expect);
}

// Should be able to subtract two matrices
TEST(MatrixTest, MatrixSubtraction) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> m2 {{2, 1}, {3, 4}, {4, 4}};
	Matrix<int> expect {{-1, 1}, {1, 1}, {3, 4}};

	ASSERT_EQ(m1 - m2, expect);
}

// Should be able to subtract a matrix and a scalar
TEST(MatrixTest, ScalarSubtraction) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> expect {{-1, 0}, {2, 3}, {5, 6}};
	
	ASSERT_EQ(m1 - 2, expect);
	ASSERT_EQ((m1 - 6) + 4, expect);
}

// Should be able to multiply a matrix by a vector
TEST(MatrixTest, VectorMultiplication) {
	Matrix<int> m1 {{1, 3}, {4, 0}, {2, 1}};
	Vector<int> v1 {1, 5};
	Vector<int> expect {16, 4, 7};
	
	ASSERT_EQ(m1 * v1, expect);
}

// Should be able to multiply a matrix by a matrix 
TEST(MatrixTest, MatrixMultiplication) {
	Matrix<int> m1 {{1, 3}, {4, 0}, {2, 1}};
	Matrix<int> m2 {{3, 2, 4}, {1, 7, 5}};
	Matrix<int> expect {{6, 23, 19}, {12, 8, 16}, {7, 11, 13}};

	ASSERT_EQ(m1 * m2, expect);
}

// Should be able to multiply a matrix by a scalar
TEST(MatrixTest, ScalarMultiplication) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> expect {{3, 6}, {12, 15}, {21, 24}};
	
	ASSERT_EQ(m1 * 3, expect);
}

// Should be able to divide a matrix by a scalar
TEST(MatrixTest, ScalarDivision) {
	Matrix<int> m1 {{2, 4}, {4, 2}, {10, 14}};
	Matrix<int> expect {{1, 2}, {2, 1}, {5, 7}};
	
	ASSERT_EQ(m1 / 2, expect);
	ASSERT_EQ((m1 / 2) * 2, m1);
}

// Should be able to transpose a matrix 
TEST(MatrixTest, Transpose) {
	Matrix<int> m1 {{2, 4}, {4, 2}, {10, 14}};
	Matrix<int> expect {{2, 4, 10}, {4, 2, 14}};
	
	ASSERT_EQ(m1.transpose(), expect);
}

// Should be able to get the determinant of a matrix (roughly up to 4 dimensions)
TEST(MatrixTest, Determinant) {
	Matrix<int> m1 {{3}};
	Matrix<int> m2 {{3, -2}, {7, 21}};
	Matrix<int> m3 {{3, 4, 2}, {-7, 12, 0}, {1, -9, 5}};
	Matrix<float> m4 {{0.78, 0.11, 5.48, 6.08}, {3.21, 0.81, 4.87, 6.31}, {7.17, 8.39, 0.38, 3.70}, {6.28, 7.60, 3.69, 3.25}};

	ASSERT_EQ(m1.det(), 3);
	ASSERT_EQ(m2.det(), 77);
	ASSERT_EQ(m3.det(), 422);
	ASSERT_NEAR(m4.det(), -314.381, 0.001);
}

// Test ability to calculate the inverse of a matrix using Gauss-Jordan elimination on non-singular matrices
TEST(MatrixTest, GaussJordan) {
	Matrix<int> m1 {{2, 3}, {4, 7}};
	Matrix<double> expect1 {{(7.0 / 2.0), (-3.0 / 2.0)}, {-2.0, 1.0}};

	ASSERT_EQ(m1.GaussJordan(), expect1);

	Matrix<int> m2 {{4, 3, 4}, {7, 6, 8}, {8, 1, -3}};
	Matrix<double> expect2 {{2.0, -1.0, 0.0}, {(-85.0 / 13.0), (44.0 / 13.0), (4.0 / 13.0)}, {(41.0 / 13.0), (-20.0 / 13.0), (-3.0 / 13.0)}};

	Matrix<double> actual2 = m2.GaussJordan();
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			ASSERT_NEAR(actual2[i][j], expect2[i][j], DOUBLE_ABS_ERR);
}

// Test ability to calculate the pseudo-inverse of a matrix
TEST(MatrixTest, PInv) {
	// For square, invertible matrices, the pinv should equal the inv
	Matrix<int> m1 {{2, 3}, {4, 7}};
	Matrix<double> pinv = m1.pinv();
	Matrix<double> inv = m1.GaussJordan();

	ASSERT_EQ(pinv.size(), inv.size());
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			ASSERT_NEAR(pinv[i][j], inv[i][j], DOUBLE_ABS_ERR);

	// Should calculate the pinv of a non-square matrix properly
	Matrix<int> m2 {{17, 12, 0}, {-1, 0, 43}};
	Matrix<double> pinv2 = m2.pinv();
	Matrix<double> expect2 {{31433.0 / 800761.0, -144.0 / 800761.0}, {22200.0 / 800761.0, 204.0 / 800761.0}, {731.0 / 800761.0, 18619.0 / 800761.0}};

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			ASSERT_NEAR(pinv2[i][j], expect2[i][j], DOUBLE_ABS_ERR);

	// Should calculate the pinv of a square, singular matrix properly
	Matrix<int> m3 {{2, 8}, {1, 4}};
	Matrix<double> pinv3 = m3.pinv();
	std::cout << "pensi" << std::endl;
	Matrix<double> expect3 {{ 2.0 / 85.0, 1.0 / 85.0 }, { 8.0 / 85.0, 4.0 / 85.0 }};

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			ASSERT_NEAR(pinv3[i][j], expect3[i][j], DOUBLE_ABS_ERR);
}
