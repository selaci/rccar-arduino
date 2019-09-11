#include <gtest/gtest.h>
#include "sequence.h"

TEST(StarTrekTest, fullSequence) {
	Sequence* sequence = new StarTrek();

	EXPECT_EQ(33153, sequence->next());
	EXPECT_EQ(16962, sequence->next());
	EXPECT_EQ(9252,  sequence->next());
	EXPECT_EQ(6168,  sequence->next());

	// And verify the circle is closed.
	EXPECT_EQ(33153, sequence->next());
}
