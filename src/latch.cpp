#include "latch.h"

SR_LATCH::SR_LATCH() : Component(POS_IN_SIZE, POS_OUT_SIZE) {
	input[POS_IN_S] = false;
	input[POS_IN_R] = true;
	input[POS_IN_CLOCK] = true;
	for (int i = 0 ; i < 10 ; i++) run();
	input[POS_IN_CLOCK] = false;
}

void SR_LATCH::set(bool s, bool r) {
	input[POS_IN_S] = s;
	input[POS_IN_R] = r;
}

void SR_LATCH::setClock(bool clk) {
	input[POS_IN_CLOCK] = clk;
}

void SR_LATCH::setComponent() {
	for (auto & i : nandGate) {
		components.insert(components.end(), &i);
	}
}

void SR_LATCH::setInputComponent() {
	nandGate[0].set(input[POS_IN_S], input[POS_IN_CLOCK]);
	nandGate[1].set(input[POS_IN_CLOCK], input[POS_IN_R]);

	nandGate[2].set(nandGate[0].output[NANDGate::POS_OUT], nandGate[3].output[NANDGate::POS_OUT]);
	nandGate[3].set(nandGate[2].output[NANDGate::POS_OUT], nandGate[1].output[NANDGate::POS_OUT]);
}

void SR_LATCH::setOutputComponent() {
	output[POS_OUT_Q] = nandGate[2].output[NANDGate::POS_OUT];
	output[POS_OUT_Q_BAR] = nandGate[3].output[NANDGate::POS_OUT];
}

D_LATCH::D_LATCH() : Component(POS_IN_SIZE, POS_OUT_SIZE) {}

void D_LATCH::set(bool D) {
	input[POS_IN_D] = D;
}

void D_LATCH::setClock(bool clk) {
	input[POS_IN_CLOCK] = clk;
}

void D_LATCH::setComponent() {
	components.insert(components.end(), &notGate);
	components.insert(components.end(), &srLatch);
}

void D_LATCH::setInputComponent() {
	notGate.set(input[POS_IN_D]);
	srLatch.set(input[POS_IN_D], notGate.output[NOTGate::POS_OUT]);
	srLatch.setClock(input[POS_IN_CLOCK]);
}

void D_LATCH::setOutputComponent() {
	output[POS_OUT_Q] = srLatch.output[POS_OUT_Q];
	output[POS_OUT_Q_BAR] = srLatch.output[POS_OUT_Q_BAR];
}
