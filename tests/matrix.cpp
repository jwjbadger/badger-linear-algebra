#include <gtest/gtest.h>
#include <BadLinAlg/matrix.h>
#include <BadLinAlg/vector.h>
#include <BadLinAlg/darray.h>
#include <iostream>

// Should be able to initialize matrices with arrays in 3 ways and access elements using [] operator
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

TEST(MatrixTest, SizeEquality) {
	Matrix<int> m1 {{1, 2},{4, 5},{7, 8}};

	MSize msize;
	msize.m = 3;
	msize.n = 2;
	
	unsigned int size[2] = {3, 2};
	
	ASSERT_EQ(m1.size(), msize);
	ASSERT_EQ(m1.size(), size);
}

// Should be able to get the size and data of the matrix
TEST(MatrixTest, Getters) {
	DArray<DArray<int>> m1_v {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	DArray<DArray<int>> m2_v {{1, 2}, {3, 4}, {5, 6}};
	
	Matrix<int> m1(m1_v);
	Matrix<int> m2(m2_v); 

	ASSERT_EQ(m1.size().m, 3);
	ASSERT_EQ(m1.size().n, 3);

	ASSERT_EQ(m2.size().m, 3);
	ASSERT_EQ(m2.size().n, 2);

	ASSERT_EQ(m1.data(), m1_v);
	ASSERT_EQ(m2.data(), m2_v);
}

TEST(MatrixTest, Insert) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};

	m1.insert(3, 2, 5);
	m1.insert(4, 1, 6);
	
	ASSERT_EQ(m1[3][2], 5);
	ASSERT_EQ(m1[4][1], 6);

	ASSERT_EQ(m1.size().m, 5);
	ASSERT_EQ(m1.size().n, 3);
}

TEST(MatrixTest, Push) {
	Matrix<int> m1 {{1, 2, 3}, {4, 5, 6}};
	Matrix<int> expect {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	m1.pushRow({7, 8, 9});

	ASSERT_EQ(m1, expect);
}

TEST(MatrixTest, Resize) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	
	ASSERT_EQ(m1.size().m, 3);
	ASSERT_EQ(m1.size().n, 2);

	m1.resize(2, 4);

	ASSERT_EQ(m1.size().m, 2);
	ASSERT_EQ(m1.size().n, 4);
}

// Should be able to add two matrices
TEST(MatrixTest, MMAddition) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> m2 {{2, 1}, {3, 4}, {4, 4}};
	Matrix<int> expect {{3, 3}, {7, 9}, {11, 12}};

	ASSERT_EQ(m1 + m2, expect);
}

// Should be able to add a matrix and a scalar
TEST(MatrixTest, MSAddition) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> expect {{3, 4}, {6, 7}, {9, 10}};
	
	ASSERT_EQ(m1 + 2, expect);
}

// Should be able to subtract two matrices
TEST(MatrixTest, MMSubtraction) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> m2 {{2, 1}, {3, 4}, {4, 4}};
	Matrix<int> expect {{-1, 1}, {1, 1}, {3, 4}};

	ASSERT_EQ(m1 - m2, expect);
}

// Should be able to subtract a matrix and a scalar
TEST(MatrixTest, MSSubtraction) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> expect {{-1, 0}, {2, 3}, {5, 6}};
	
	ASSERT_EQ(m1 - 2, expect);
}

// Should be able to multiply a matrix by a vector
TEST(MatrixTest, MVMultiplication) {
	Matrix<int> m1 {{1, 3}, {4, 0}, {2, 1}};
	Vector<int> v1 {1, 5};
	Vector<int> expect {16, 4, 7};
	
	ASSERT_EQ(m1 * v1, expect);
}

// Should be able to multiply a matrix by a matrix 
TEST(MatrixTest, MMMultiplication) {
	Matrix<int> m1 {{1, 3}, {4, 0}, {2, 1}};
	Matrix<int> m2 {{3, 2, 4}, {1, 7, 5}};
	Matrix<int> expect {{6, 23, 19}, {12, 8, 16}, {7, 11, 13}};

	ASSERT_EQ(m1 * m2, expect);
}

// Should be able to multiply a matrix by a scalar
TEST(MatrixTest, MSMultiplication) {
	Matrix<int> m1 {{1, 2}, {4, 5}, {7, 8}};
	Matrix<int> expect {{3, 6}, {12, 15}, {21, 24}};
	
	ASSERT_EQ(m1 * 3, expect);
}

// Should be able to divide a matrix by a scalar
TEST(MatrixTest, MSDivision) {
	Matrix<int> m1 {{2, 4}, {4, 2}, {10, 14}};
	Matrix<int> expect {{1, 2}, {2, 1}, {5, 7}};
	
	ASSERT_EQ(m1 / 2, expect);
}

// Should be able to transpose a matrix 
TEST(MatrixTest, Transpose) {
	Matrix<int> m1 {{2, 4}, {4, 2}, {10, 14}};
	Matrix<int> expect {{2, 4, 10}, {4, 2, 14}};
	
	ASSERT_EQ(m1.transpose(), expect);
}

// Should be able to get the determinant of a matrix
TEST(MatrixTest, Determinant) {
	Matrix<int> m1 {{3}};
	Matrix<int> m2 {{3, -2}, {7, 21}};
	Matrix<int> m3 {{3, 4, 2}, {-7, 12, 0}, {1, -9, 5}};
	Matrix<float> m4 {{0.78, 0.11, 5.48, 6.08}, {3.21, 0.81, 4.87, 6.31}, {7.17, 8.39, 0.38, 3.70}, {6.28, 7.60, 3.69, 3.25}};

	ASSERT_EQ(m1.det(), 3);
	ASSERT_EQ(m2.det(), 77);
	ASSERT_EQ(m3.det(), 422);
	ASSERT_LT(m4.det(), -314.380);
	ASSERT_GT(m4.det(), -314.382);
}
