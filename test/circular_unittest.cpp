#include <gtest/gtest.h>
#include "sequence.h"

TEST(CircularTest, fullSequence) {
	Sequence* sequence = new Circular();

	EXPECT_EQ(1,     sequence->next());
	EXPECT_EQ(2,     sequence->next());
	EXPECT_EQ(4,     sequence->next());
	EXPECT_EQ(8,     sequence->next());
	EXPECT_EQ(16,    sequence->next());
	EXPECT_EQ(32,    sequence->next());
	EXPECT_EQ(64,    sequence->next());
	EXPECT_EQ(128,   sequence->next());
	EXPECT_EQ(256,   sequence->next());
	EXPECT_EQ(512,   sequence->next());
	EXPECT_EQ(1024,  sequence->next());
	EXPECT_EQ(2048,  sequence->next());
	EXPECT_EQ(4096,  sequence->next());
	EXPECT_EQ(8192,  sequence->next());
	EXPECT_EQ(16384, sequence->next());
	EXPECT_EQ(32768, sequence->next());

	// And verify the circle is closed.
	EXPECT_EQ(1,     sequence->next());
}
