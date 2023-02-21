#include <gtest/gtest.h>
#include <vector.h>

// Should be able to initialize vectors with arrays in 3 ways and access elements using [] operator
TEST(VectorTest, ArrrayInitialization) {
	Vector<int> v1 = {1, 2, 3, 4, 5};
	Vector<int> v2 {5, 4, 3, 2, 1}; 
	Vector<int> v3({0, 1, 2, 3, 4});
	
	for (int i = 0; i < 5; i++) {
		ASSERT_EQ(v1[i], i + 1);
		ASSERT_EQ(v2[i], 5 - i);
		ASSERT_EQ(v3[i], i);
	}
}
