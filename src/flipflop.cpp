#include "flipflop.h"

D_FLIP_FLOP::D_FLIP_FLOP() : Component(POS_IN_SIZE, POS_OUT_SIZE) {}

void D_FLIP_FLOP::set(bool d) {
	input[POS_IN_D] = d;
}

void D_FLIP_FLOP::setClock(bool clk) {
	input[POS_IN_CLOCK] = clk;
}

void D_FLIP_FLOP::setComponent() {
	components.insert(components.end(), &notGate);
	components.insert(components.end(), &dLatch);
	components.insert(components.end(), &srLatch);
}

void D_FLIP_FLOP::setInputComponent() {
	notGate.set(input[POS_IN_CLOCK]);

	dLatch.set(input[POS_IN_D]);
	dLatch.setClock(notGate.output[NOTGate::POS_OUT]);

	srLatch.set(dLatch.output[D_LATCH::POS_OUT_Q], dLatch.output[D_LATCH::POS_OUT_Q_BAR]);
	srLatch.setClock(input[POS_IN_CLOCK]);
}

void D_FLIP_FLOP::setOutputComponent() {
	output[POS_OUT_Q] = srLatch.output[SR_LATCH::POS_OUT_Q];
	output[POS_OUT_Q_BAR] = srLatch.output[SR_LATCH::POS_OUT_Q_BAR];
}

D_FLIP_FLOP_WRITE_EN::D_FLIP_FLOP_WRITE_EN() : Component(POS_IN_SIZE, POS_OUT_SIZE) {}

void D_FLIP_FLOP_WRITE_EN::set(bool d, bool write_en) {
	input[POS_IN_D] = d;
	input[POS_IN_WRITE_EN] = write_en;
}

void D_FLIP_FLOP_WRITE_EN::setClock(bool clk) {
	input[POS_IN_CLOCK] = clk;
}

void D_FLIP_FLOP_WRITE_EN::setComponent() {
	components.insert(components.end(), &mux2To1);
	components.insert(components.end(), &dFlipFlop);
}

void D_FLIP_FLOP_WRITE_EN::setInputComponent() {
	mux2To1.set(input[POS_IN_WRITE_EN], input[POS_IN_D], dFlipFlop.output[D_FLIP_FLOP::POS_OUT_Q]);
	dFlipFlop.set(mux2To1.output[MUX_2_TO_1::POS_OUT_Y]);
	dFlipFlop.setClock(input[POS_IN_CLOCK]);
}

void D_FLIP_FLOP_WRITE_EN::setOutputComponent() {
	output[POS_OUT_Q] = dFlipFlop.output[D_FLIP_FLOP::POS_OUT_Q];
	output[POS_OUT_Q_BAR] = dFlipFlop.output[D_FLIP_FLOP::POS_OUT_Q_BAR];
}
