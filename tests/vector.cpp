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

// Should be able to modify data using simple methods (e.g. push, pop, etc.)
TEST(VectorTest, DataModification) {
	Vector<int> v1 {1, 2, 3, 4, 5};

	// Size should be 5
	ASSERT_EQ(v1.size(), 5);
	
	// Pushing + popping data should work
	ASSERT_EQ(v1.pop().size(), 4);
	ASSERT_EQ(v1[0], 1);
	ASSERT_EQ(v1.push(5).size(), 5);
	ASSERT_EQ(v1[4], 5);
}
