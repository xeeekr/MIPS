#include <gtest/gtest.h>
#include "flipflop.h"

bool testDFlipFlop(D_FLIP_FLOP &ff, bool d, bool clk) {
	ff.set(d);
	ff.setClock(clk);
	for (int i = 0 ; i < 5 ; i++) ff.run();
	return ff.output[D_FLIP_FLOP::POS_OUT_Q];
}

TEST(MipsTest_flipflop, D_FLIP_FLOP) {
	D_FLIP_FLOP ff;

	EXPECT_EQ(false, testDFlipFlop(ff, false, false));
	EXPECT_EQ(false, testDFlipFlop(ff, false, true));
	EXPECT_EQ(false, testDFlipFlop(ff, false, false));

	EXPECT_EQ(false, testDFlipFlop(ff, true, false));
	EXPECT_EQ(true, testDFlipFlop(ff, true, true));
	EXPECT_EQ(true, testDFlipFlop(ff, true, false));

	EXPECT_EQ(true, testDFlipFlop(ff, false, false));
	EXPECT_EQ(false, testDFlipFlop(ff, false, true));
	EXPECT_EQ(false, testDFlipFlop(ff, true, true));
	EXPECT_EQ(false, testDFlipFlop(ff, true, false));
}

bool testDFlipFlop_write_en(D_FLIP_FLOP_WRITE_EN &ff, bool d, bool we, bool clk) {
	ff.set(d, we);
	ff.setClock(clk);
	for (int i = 0 ; i < 5 ; i++) ff.run();
	return ff.output[D_FLIP_FLOP_WRITE_EN::POS_OUT_Q];
}

TEST(MipsTest_flipflop, D_FLIP_FLOP_WRITE_EN) {
	D_FLIP_FLOP_WRITE_EN ff;

	EXPECT_EQ(false, testDFlipFlop_write_en(ff, false, true, false));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, false, true, true));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, false, true, false));

	EXPECT_EQ(false, testDFlipFlop_write_en(ff, true, true, false));
	EXPECT_EQ(true, testDFlipFlop_write_en(ff, true, true, true));
	EXPECT_EQ(true, testDFlipFlop_write_en(ff, true, true, false));

	EXPECT_EQ(true, testDFlipFlop_write_en(ff, false, true, false));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, false, true, true));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, true, true, true));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, true, true, false));


	EXPECT_EQ(false, testDFlipFlop_write_en(ff, false, false, false));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, false, false, true));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, false, false, false));

	EXPECT_EQ(false, testDFlipFlop_write_en(ff, true, false, false));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, true, false, true));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, true, false, false));

	EXPECT_EQ(false, testDFlipFlop_write_en(ff, false, false, false));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, false, false, true));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, true, false, true));
	EXPECT_EQ(false, testDFlipFlop_write_en(ff, true, false, false));




}
