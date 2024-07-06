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
