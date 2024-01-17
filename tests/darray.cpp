#include <gtest/gtest.h>
#include <BadLinAlg/darray.h>

// Implies operator[] works
TEST(DArrayTest, InitializerList) {
	DArray<int> d = {1, 2, 3, 4, 5};
	
	ASSERT_EQ(d.size(), 5);
	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(d[i], i + 1);
}

TEST(DArrayTest, CopyConstructor) {
	DArray<int> dBase = {1, 2, 3, 4};
	DArray<int> dCopy = dBase;

	ASSERT_EQ(dBase.size(), dCopy.size());
	for (int i = 0; i < 4; ++i)
		ASSERT_EQ(dBase[i], dCopy[i]);
}

TEST(DArrayTest, SizeConstructor) {
	DArray<int> d(4);

	ASSERT_EQ(d.size(), 4);
	for (int i = 0; i < 4; ++i)
		ASSERT_EQ(d[i], 0);
}

TEST(DArrayTest, Push) {
	DArray<int> d = {1, 2, 3, 4, 5};

	d.push(6);

	ASSERT_EQ(d.size(), 6);
	for (int i = 0; i < 6; ++i)
		ASSERT_EQ(d[i], i + 1);
}

TEST(DArrayTest, Pop) {
	DArray<int> d = {1, 2, 3, 4, 5};

	d.pop();

	ASSERT_EQ(d.size(), 4);
	for (int i = 0; i < 4; ++i)
		ASSERT_EQ(d[i], i + 1);
}

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

TEST(DArrayTest, EqualsOperator) {
	DArray<int> d = {1, 2, 3, 4, 5};
	ASSERT_EQ(d.size(), 5);
	
	d = {1, 2, 3};

	ASSERT_EQ(d.size(), 3);
	for (int i = 0; i < d.size(); ++i)
		ASSERT_EQ(d[i], i + 1);
}

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
