#include <gtest/gtest.h>
#include <matrix.h>
#include <vector.h>

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

TEST(MatrixTest, Getters) {
	std::vector<std::vector<int>> m1_v {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	std::vector<std::vector<int>> m2_v {{1, 2}, {3, 4}, {5, 6}};
	
	Matrix<int> m1(m1_v);
	Matrix<int> m2(m2_v); 

	ASSERT_EQ(m1.size().m, 3);
	ASSERT_EQ(m1.size().n, 3);

	ASSERT_EQ(m2.size().m, 3);
	ASSERT_EQ(m2.size().n, 2);

	ASSERT_EQ(m1.data(), m1_v);
	ASSERT_EQ(m2.data(), m2_v);
}

// Should be able to multiply a matrix by a vector
TEST(MatrixTest, MVMultiplication) {
	Matrix<int> m1 {{1, 3}, {4, 0}, {2, 1}};
	Vector<int> v1 {1, 5};
	Vector<int> expect {16, 4, 7};

	ASSERT_EQ((m1 * v1).data(), expect.data());
}
