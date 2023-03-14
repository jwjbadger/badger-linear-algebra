#include <gtest/gtest.h>
#include <matrix.h>

// Should be able to initialize matrices with arrays in 3 ways and access elements using [] operator
TEST(MatrixTest, ArrrayInitialization) {
	Matrix<int> v1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Matrix<int> v2 {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Matrix<int> v3({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ASSERT_EQ(v1[i][j], (i * 3) + j + 1);
			ASSERT_EQ(v2[i][j], (i * 3) + j + 1);
			ASSERT_EQ(v3[i][j], (i * 3) + j + 1);
		}
	}
}
