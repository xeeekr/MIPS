#include "mux.h"


MUX_2_TO_1::MUX_2_TO_1() : Component(POS_IN_SIZE, POS_OUT_SIZE) {}

void MUX_2_TO_1::set(bool s, bool in_1, bool in_0) {
	input[POS_IN_S] = s;
	input[POS_IN_I_1] = in_1;
	input[POS_IN_I_0] = in_0;
}

void MUX_2_TO_1::setComponent() {
	components.insert(components.end(), &notGate);
	for (auto & i : nandGate) {
		components.insert(components.end(), &i);
	}
}

void MUX_2_TO_1::setInputComponent() {
	notGate.set(input[POS_IN_S]);
	nandGate[0].set(notGate.output[NOTGate::POS_OUT], input[POS_IN_I_0]);
	nandGate[1].set(input[POS_IN_S], input[POS_IN_I_1]);
	nandGate[2].set(nandGate[0].output[NANDGate::POS_OUT], nandGate[1].output[NANDGate::POS_OUT]);
}

void MUX_2_TO_1::	setOutputComponent() {
	output[POS_OUT_Y] = nandGate[2].output[NANDGate::POS_OUT];
}
