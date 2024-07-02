#include <gtest/gtest.h>
#include "gate.h"

bool testBUFFERGate(bool in) {
	BUFFERGate gate;
	gate.set(in);
	gate.run();
	return gate.output[BUFFERGate::POS_OUT];
}

bool testNOTGate(bool in) {
	NOTGate gate;
	gate.set(in);
	gate.run();
	return gate.output[NOTGate::POS_OUT];
}

bool testANDGate(bool a, bool b) {
	ANDGate gate;
	gate.set(a, b);
	gate.run();
	return gate.output[ANDGate::POS_OUT];
}

bool testORGate(bool a, bool b) {
	ORGate gate;
	gate.set(a, b);
	gate.run();
	return gate.output[ORGate::POS_OUT];
}

bool testORGate4Input(bool a, bool b, bool c, bool d) {
	ORGate4Input gate;
	gate.set(a, b, c, d);
	gate.run();
	return gate.output[ORGate::POS_OUT];
}

bool testNANDGate(bool a, bool b) {
	NANDGate gate;
	gate.set(a, b);
	gate.run();
	return gate.output[NANDGate::POS_OUT];
}

bool testNORGate(bool a, bool b) {
	NORGate gate;
	gate.set(a, b);
	gate.run();
	return gate.output[NORGate::POS_OUT];
}

bool testXORGate(bool a, bool b) {
	XORGate gate;
	gate.set(a, b);
	gate.run();
	return gate.output[XORGate::POS_OUT];
}

bool testXNORGate(bool a, bool b) {
	XNORGate gate;
	gate.set(a, b);
	gate.run();
	return gate.output[XNORGate::POS_OUT];
}


TEST(MipsTest_Gate, BUFFERGate) {
EXPECT_EQ(false, testBUFFERGate(false));
EXPECT_EQ(true, testBUFFERGate(true));
}

TEST(MipsTest_Gate, NOTGate) {
EXPECT_EQ(true, testNOTGate(false));
EXPECT_EQ(false, testNOTGate(true));
}

TEST(MipsTest_Gate, ANDGate) {
EXPECT_EQ(false, testANDGate(false, false));
EXPECT_EQ(false, testANDGate(false, true));
EXPECT_EQ(false, testANDGate(true, false));
EXPECT_EQ(true, testANDGate(true, true));
}

TEST(MipsTest_Gate, ORGate) {
EXPECT_EQ(false, testORGate(false, false));
EXPECT_EQ(true, testORGate(false, true));
EXPECT_EQ(true, testORGate(true, false));
EXPECT_EQ(true, testORGate(true, true));
}

TEST(MipsTest_Gate, ORGate4Input) {
EXPECT_EQ(false, testORGate4Input(false, false, false, false));
EXPECT_EQ(true, testORGate4Input(false, false, false, true));
EXPECT_EQ(true, testORGate4Input(false, false, true, false));
EXPECT_EQ(true, testORGate4Input(false, false, true, true));
EXPECT_EQ(true, testORGate4Input(false, true, false, false));
EXPECT_EQ(true, testORGate4Input(false, true, false, true));
EXPECT_EQ(true, testORGate4Input(false, true, true, false));
EXPECT_EQ(true, testORGate4Input(false, true, true, true));
EXPECT_EQ(true, testORGate4Input(true, false, false, false));
EXPECT_EQ(true, testORGate4Input(true, false, false, true));
EXPECT_EQ(true, testORGate4Input(true, false, true, false));
EXPECT_EQ(true, testORGate4Input(true, false, true, true));
EXPECT_EQ(true, testORGate4Input(true, true, false, false));
EXPECT_EQ(true, testORGate4Input(true, true, false, true));
EXPECT_EQ(true, testORGate4Input(true, true, true, false));
EXPECT_EQ(true, testORGate4Input(true, true, true, true));
}

TEST(MipsTest_Gate, NANDGate) {
EXPECT_EQ(true, testNANDGate(false, false));
EXPECT_EQ(true, testNANDGate(false, true));
EXPECT_EQ(true, testNANDGate(true, false));
EXPECT_EQ(false, testNANDGate(true, true));
}

TEST(MipsTest_Gate, NORGate) {
EXPECT_EQ(true, testNORGate(false, false));
EXPECT_EQ(false, testNORGate(false, true));
EXPECT_EQ(false, testNORGate(true, false));
EXPECT_EQ(false, testNORGate(true, true));
}

TEST(MipsTest_Gate, XORGate) {
EXPECT_EQ(false, testXORGate(false, false));
EXPECT_EQ(true, testXORGate(false, true));
EXPECT_EQ(true, testXORGate(true, false));
EXPECT_EQ(false, testXORGate(true, true));
}

TEST(MipsTest_Gate, XNORGate) {
EXPECT_EQ(true, testXNORGate(false, false));
EXPECT_EQ(false, testXNORGate(false, true));
EXPECT_EQ(false, testXNORGate(true, false));
EXPECT_EQ(true, testXNORGate(true, true));
}
