#include <gtest/gtest.h>
#include "sequence.h"

TEST(DoubleKnightRiderTest, fullSequence) {
	Sequence* sequence = new NicRider();

	// From left to right.
	EXPECT_EQ(257,   sequence->next());
	EXPECT_EQ(514,   sequence->next());
	EXPECT_EQ(1028,  sequence->next());
	EXPECT_EQ(2056,  sequence->next());
	EXPECT_EQ(4112,  sequence->next());
	EXPECT_EQ(8224,  sequence->next());
	EXPECT_EQ(16448, sequence->next());
	EXPECT_EQ(32896, sequence->next());

	// From right to left.
	EXPECT_EQ(16448, sequence->next());
	EXPECT_EQ(8224,  sequence->next());
	EXPECT_EQ(4112,  sequence->next());
	EXPECT_EQ(2056,  sequence->next());
	EXPECT_EQ(1028,  sequence->next());
	EXPECT_EQ(514,   sequence->next());

	// And verify the circle is closed.
	EXPECT_EQ(257, sequence->next());
}
