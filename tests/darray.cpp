#include <gtest/gtest.h>
#include <BadLinAlg/darray.h>

TEST(DArrayTest, ArrrayInitialization) {
	DArray<int> d = {1, 2, 3, 4, 5};
	
	for (int i = 0; i < 5; i++)
		ASSERT_EQ(d[i], i + 1);
}
