#include <gtest/gtest.h>
#include "sequence.h"

TEST(KnightRiderTest, fullSequence) {
	Sequence* sequence = new KnightRider();

	// From left to right.
	EXPECT_EQ(32769, sequence->next());
	EXPECT_EQ(16386, sequence->next());
	EXPECT_EQ(8196,  sequence->next());
	EXPECT_EQ(4104,  sequence->next());
	EXPECT_EQ(2064,  sequence->next());
	EXPECT_EQ(1056,  sequence->next());
	EXPECT_EQ(576,   sequence->next());
	EXPECT_EQ(384,   sequence->next());

	// From right to left.
	EXPECT_EQ(576,   sequence->next());
	EXPECT_EQ(1056,  sequence->next());
	EXPECT_EQ(2064,  sequence->next());
	EXPECT_EQ(4104,  sequence->next());
	EXPECT_EQ(8196,  sequence->next());
	EXPECT_EQ(16386, sequence->next());
	EXPECT_EQ(32769, sequence->next());

	// And verify the circle is closed.
	EXPECT_EQ(16386, sequence->next());
}
