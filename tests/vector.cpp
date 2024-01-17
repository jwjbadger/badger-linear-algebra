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

TEST(VectorTest, EqualsOperator) {
	Vector<int> v1 {1, 2, 3, 4};
	Vector<int> v2 = v1;
	
	ASSERT_EQ(v1, v2);

	v1[0] = 21;
	ASSERT_NE(v1, v2); // Ensure v1 and v2 don't point to the same thing
}

// Test the functionality of the push function (adds an element)
TEST(VectorTest, Push) {
	Vector<int> d {1, 2, 3, 4, 5};

	d.push(6);

	ASSERT_EQ(d.size(), 6);
	for (int i = 0; i < 6; ++i)
		ASSERT_EQ(d[i], i + 1);
}

// Test the functionality of the pop function (removes an element)
TEST(VectorTest, Pop) {
	Vector<int> d {1, 2, 3, 4, 5};

	d.pop();

	ASSERT_EQ(d.size(), 4);
	for (int i = 0; i < 4; ++i)
		ASSERT_EQ(d[i], i + 1);
}

// Test the == and != operators (used by ASSERT_EQ and ASSERT_NE)
TEST(VectorTest, EqualityOperator) {
	Vector<int> v1 {1, 2, 3};
	Vector<int> v2 {1, 2, 3};
	Vector<int> v3 {4, 5, 6};

	ASSERT_EQ(v1, v2);
	ASSERT_NE(v1, v3);
}

// Test the element-wise addition of two vectors
TEST(VectorTest, VectorAdd) {
	Vector<int> v1 {1, 2, 3};
	Vector<int> v2 {3, 4, 5};
	Vector<int> expect {4, 6, 8};

	ASSERT_EQ(v1 + v2, expect);
}

// Test the element-wise subtraction of two vectors
TEST(VectorTest, VectorSubtract) {
	Vector<int> v1 {1, 2, 3};
	Vector<int> v2 {3, 10, 5};
	Vector<int> expect {-2, -8, -2};

	ASSERT_EQ(v1 - v2, expect);
}

// Test the repeated addition of the same scalar on a vector
TEST(VectorTest, ScalarAdd) {
	Vector<int> v1 {1, 2, 3};
	Vector<int> expect {7, 8, 9};

	ASSERT_EQ(v1 + 6, expect);
}

// Test the repeated subtraction of the same scalar on a vector
TEST(VectorTest, ScalarSubtract) {
	Vector<int> v1 {7, 8, 9};
	Vector<int> expect {1, 2, 3};

	ASSERT_EQ(v1 - 6, expect);
}

// Test the dot product of two vectors
TEST(VectorTest, DotProduct) {
	Vector<int> v1 {1, 2, 3};
	Vector<int> v2 {3, 4, 5};
	
	ASSERT_EQ(v1.dot(v2), 26);
	ASSERT_EQ(v1.dot(v1 * 2), 28);
}

// Test the repeated multiplication of the same scalar on a vector
TEST(VectorTest, ScalarMultiply) {
	Vector<int> v1 {1, 2, 3};
	Vector<int> expect {3, 6, 9};

	ASSERT_EQ(v1 * 3, expect);
}

// Test the repeated division of the same scalar on a vector by it's property of being the inverse operation of scalar multiplication
TEST(VectorTest, ScalarDivide) {
	Vector<int> v1 {1, 2, 3};
	Vector<int> expect {3, 6, 9};

	ASSERT_EQ((v1 * 6) / 2, expect);
}

// Test the data() getter function returns the data stored in a vector
TEST(VectorTest, DataGetter) {
	Vector<int> v {1, 2, 3};
	DArray<int> d {1, 2, 3};

	ASSERT_EQ(v.data(), d);
}
