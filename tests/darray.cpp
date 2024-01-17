#include <gtest/gtest.h>
#include <BadLinAlg/darray.h>

// Test the functionality of the initializer list function; implies operator[] works
TEST(DArrayTest, InitializerList) {
	DArray<int> d1 = {1, 2, 3, 4, 5};
	DArray<int> d2 {1, 2, 3, 4, 5};
	DArray<int> d3({1, 2, 3, 4, 5});
	
	ASSERT_EQ(d1.size(), 5);
	ASSERT_EQ(d2.size(), 5);
	ASSERT_EQ(d3.size(), 5);

	for (int i = 0; i < 5; ++i) {
		ASSERT_EQ(d1[i], i + 1);
		ASSERT_EQ(d2[i], i + 1);
		ASSERT_EQ(d3[i], i + 1);
	}
}

// Test the functionality of the copy constructor; if not working properly, may error after going out of scope
TEST(DArrayTest, CopyConstructor) {
	DArray<int> dBase = {1, 2, 3, 4};
	DArray<int> dCopy = dBase;

	ASSERT_EQ(dBase.size(), dCopy.size());
	for (int i = 0; i < 4; ++i)
		ASSERT_EQ(dBase[i], dCopy[i]);
}

// Test the functionality of the constructor that uses the size of the array to create it
TEST(DArrayTest, SizeConstructor) {
	DArray<int> d(4);

	ASSERT_EQ(d.size(), 4);
	for (int i = 0; i < 4; ++i)
		ASSERT_EQ(d[i], 0);
}

// Test the functionality of the push function (adds an element)
TEST(DArrayTest, Push) {
	DArray<int> d = {1, 2, 3, 4, 5};

	d.push(6);

	ASSERT_EQ(d.size(), 6);
	for (int i = 0; i < 6; ++i)
		ASSERT_EQ(d[i], i + 1);
}

// Test the functionality of the pop function (removes an element)
TEST(DArrayTest, Pop) {
	DArray<int> d = {1, 2, 3, 4, 5};

	d.pop();

	ASSERT_EQ(d.size(), 4);
	for (int i = 0; i < 4; ++i)
		ASSERT_EQ(d[i], i + 1);
}

// Test the functionality of the default constructor and the size constructor with parameter 0; creates an empty array with size 0; ensure you can add elements to an empty array 
TEST(DArrayTest, BlankInitializer) {
	DArray<int> d1;
	DArray<int> d2(0);

	ASSERT_EQ(d1, d2);

	ASSERT_EQ(d1.size(), 0);
	ASSERT_EQ(d2.size(), 0);

	d1.push(1);
	d2.push(13);

	ASSERT_EQ(d1[0], 1);
	ASSERT_EQ(d2[0], 13);
}

// Test the functionality of == and != (used within ASSERT_EQ and ASSERT_NE)
TEST(DArrayTest, EqualityOperators) {
	DArray<int> d1 = {1, 2, 3, 4, 5};
	DArray<int> d2 = {1, 2, 3, 4, 5};
	
	ASSERT_EQ(d1, d2);

	d1.push(6);
	ASSERT_NE(d1, d2);

	d1.pop();
	ASSERT_EQ(d1, d2);

	d1[3] = 2;
	ASSERT_NE(d1, d2);
}

// Test the ability to set one DArray equal to another
TEST(DArrayTest, EqualsOperator) {
	DArray<int> d = {1, 2, 3, 4, 5};
	ASSERT_EQ(d.size(), 5);
	
	d = {1, 2, 3};

	ASSERT_EQ(d.size(), 3);
	for (int i = 0; i < d.size(); ++i)
		ASSERT_EQ(d[i], i + 1);
}

// Test the functionality of the resize function to resize an array and fill new elements with 0 or a provided value
TEST(DArrayTest, Resize) {
	DArray<int> d = {1, 2, 3};

	d.resize(5);
	ASSERT_EQ(d.size(), 5);
	ASSERT_EQ(d[3], 0);
	ASSERT_EQ(d[4], 0);

	d.resize(2);
	ASSERT_EQ(d.size(), 2);
	ASSERT_EQ(d[0], 1);
	ASSERT_EQ(d[1], 2);

	d.resize(5, 14);
	ASSERT_EQ(d.size(), 5);
	ASSERT_EQ(d[0], 1);
	ASSERT_EQ(d[3], 14);
	ASSERT_EQ(d[4], 14);
}

// Test ability to find the first instance of a value
TEST(DArrayTest, IndexOf) {
	DArray<int> d = {1, 2, 3, 4, 5, -88};

	ASSERT_EQ(d.indexOf(-88), 5);
	ASSERT_EQ(d.indexOf(1), 0);
	ASSERT_EQ(d.indexOf(3), 2);
	ASSERT_EQ(d.indexOf(9), -1);
}

// Test ability to find the first instance of an element which satisfies a callback function
TEST(DArrayTest, Find) {
	DArray<int> d = {0, 0, 1, 2, 3, -2, 14};
	
	ASSERT_EQ(d.find([](int e) -> bool { return e != 0; }), 2);
	ASSERT_EQ(d.find([](int e) -> bool { return e < 0; }), 5);
	ASSERT_EQ(d.find([](int e) -> bool { return e > 15; }), -1);
}
