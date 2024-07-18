#include <gtest/gtest.h>
#include "mux.h"

bool testMux2_to_1(MUX_2_TO_1 &mux, bool s, bool in0, bool in1) {
	mux.set(s, in0, in1);
	for (int i = 0 ; i < 5 ; i++) mux.run();
	return mux.output[MUX_2_TO_1::POS_OUT_Y];
}

TEST(MipsTest_mux, MUX_2_TO_1) {
	MUX_2_TO_1 mux;

	EXPECT_EQ(false, testMux2_to_1(mux, false, false, false));
	EXPECT_EQ(true, testMux2_to_1(mux, false, false, true));
	EXPECT_EQ(false, testMux2_to_1(mux, false, true, false));
	EXPECT_EQ(true, testMux2_to_1(mux, false, true, true));
	EXPECT_EQ(false, testMux2_to_1(mux, true, false, false));
	EXPECT_EQ(false, testMux2_to_1(mux, true, false, true));
	EXPECT_EQ(true, testMux2_to_1(mux, true, true, false));
	EXPECT_EQ(true, testMux2_to_1(mux, true, true, true));
}
