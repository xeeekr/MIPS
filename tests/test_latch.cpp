#include <gtest/gtest.h>
#include "latch.h"

bool testSRLatch(SR_LATCH &latch, bool s, bool r, bool clk) {
	latch.set(s, r);
	latch.setClock(clk);
	for (int i = 0 ; i < 4 ; i++) latch.run();
	return latch.output[D_LATCH::POS_OUT_Q];
}

bool testDLatch(D_LATCH &latch, bool d, bool clk) {
	latch.set(d);
	latch.setClock(clk);
	for (int i = 0 ; i < 4 ; i++) latch.run();
	return latch.output[D_LATCH::POS_OUT_Q];
}

TEST(MipsTest_Latch, SR_LATCH) {
	SR_LATCH srLatch;

	EXPECT_EQ(false, testSRLatch(srLatch, true, false, false));
	EXPECT_EQ(true, testSRLatch(srLatch, true, false, true));
	EXPECT_EQ(true, testSRLatch(srLatch, true, false, false));

	EXPECT_EQ(true, testSRLatch(srLatch, false, true, false));
	EXPECT_EQ(false, testSRLatch(srLatch, false, true, true));
	EXPECT_EQ(false, testSRLatch(srLatch, false, true, false));
}

TEST(MipsTest_Latch, D_LATCH) {
	D_LATCH dLatch;

	EXPECT_EQ(false, testDLatch(dLatch, true, false));
	EXPECT_EQ(true, testDLatch(dLatch, true, true));
	EXPECT_EQ(true, testDLatch(dLatch, true, false));

	EXPECT_EQ(true, testDLatch(dLatch, false, false));
	EXPECT_EQ(false, testDLatch(dLatch, false, true));
	EXPECT_EQ(false, testDLatch(dLatch, false, false));
}
