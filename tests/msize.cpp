#include <gtest/gtest.h>
#include <BadLinAlg/matrix.h>

TEST(MSizeTest, MSizeEquality) {
	MSize a;
	a.m = 3;
	a.n = 2;
	
	MSize b;
	b.m = 3;
	b.n = 2;
	
	ASSERT_EQ(a, b);

	b.n = 3;
	ASSERT_NE(a, b);
}

TEST(MSizeTest, ArrayEquality) {
	MSize a;
	a.m = 3;
	a.n = 2;
	
	unsigned int b[2] = {3, 2};
	
	ASSERT_EQ(a, b);

	a.n = 3;
	ASSERT_NE(a, b);
}
