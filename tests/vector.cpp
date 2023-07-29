#include <gtest/gtest.h>
#include <BadLinAlg/vector.h>

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

TEST(VectorTest, BasicOperations) {
	Vector<int> v1 {1, 2, 3};
	Vector<int> v2 {3, 4, 5};
	Vector<int> expect {4, 6, 8};

	// Addition
	ASSERT_EQ((v1 + v2).data(), expect.data());

	// Subtraction
	expect = {-2, -2, -2};
	ASSERT_EQ((v1 - v2).data(), expect.data());

	// Multiplication
	ASSERT_EQ(v1.dot(v2), 26);
	ASSERT_EQ(v1.dot(v1 * 2), 28);

	// Division
	ASSERT_EQ(((v1 * 5) / 5).data(), v1.data());
}
