#include <gtest/gtest.h>
#include "sequence.h"

TEST(FillUpTest, partialSequence) {
	Sequence* sequence = new FillUp();

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

    EXPECT_EQ(32769, sequence->next());
    EXPECT_EQ(32770, sequence->next());
    EXPECT_EQ(32772, sequence->next());
    EXPECT_EQ(32776, sequence->next());
    EXPECT_EQ(32784, sequence->next());
    EXPECT_EQ(32800, sequence->next());
    EXPECT_EQ(32832, sequence->next());
    EXPECT_EQ(32896, sequence->next());
    EXPECT_EQ(33024, sequence->next());
    EXPECT_EQ(33280, sequence->next());
    EXPECT_EQ(33792, sequence->next());
    EXPECT_EQ(34816, sequence->next());
    EXPECT_EQ(36864, sequence->next());
    EXPECT_EQ(40960, sequence->next());
    EXPECT_EQ(49152, sequence->next());

    EXPECT_EQ(49153, sequence->next());
}

TEST(FillUpTest, eightIterations) {
	Sequence* sequence = new FillUp();

	for (int i = 0; i < 100; i++) {
		sequence->next();
	}

    EXPECT_EQ(65281, sequence->next());
}

TEST(FillUpTest, cycle) {
	Sequence* sequence = new FillUp();

	for (int i = 0; i < 135; i++) {
		sequence->next(); // 65534
	}

    EXPECT_EQ(65535, sequence->next());
    EXPECT_EQ(1,     sequence->next());
    EXPECT_EQ(2,     sequence->next());
}
