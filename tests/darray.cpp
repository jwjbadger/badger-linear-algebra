#include <gtest/gtest.h>
#include <BadLinAlg/darray.h>

TEST(DArrayTest, ArrrayInitialization) {
	DArray<int> d = {1, 2, 3, 4, 5};
	
	for (int i = 0; i < 5; i++)
		ASSERT_EQ(d[i], i + 1);
	
	ASSERT_EQ(d.size(), 5);
}

TEST(DArrayTest, PushAndPop) {
	DArray<int> d = {1, 2, 3, 4, 5};

	d.push(6);
	for (int i = 0; i < 6; i++)
		ASSERT_EQ(d[i], i + 1);
	ASSERT_EQ(d.size(), 6);

	d.pop();
	for (int i = 0; i < 5; i++)
		ASSERT_EQ(d[i], i + 1);
	ASSERT_EQ(d.size(), 5);
}

TEST(DArrayTest, EqualsOperator) {
	DArray<int> d = {1, 2, 3, 4, 5};
	ASSERT_EQ(d.size(), 5);
	
	d = {1, 2, 3};
	ASSERT_EQ(d.size(), 3);
	for (int i = 0; i < d.size(); i++)
		ASSERT_EQ(d[i], i + 1);
}
