#include "gate.h"

Gate::Gate(int inputSize, int outputSize) : Component(inputSize, outputSize) {}

void Gate::setComponent() {}

void Gate::setInputComponent() {}

BUFFERGate::BUFFERGate() : Gate(POS_IN_SIZE, POS_OUT_SIZE) {}

void BUFFERGate::set(bool in) {
	input[POS_IN] = in;
}

void BUFFERGate::setOutputComponent() {
	output[POS_OUT] = input[POS_IN];
}

NOTGate::NOTGate() : Gate(POS_IN_SIZE, POS_OUT_SIZE) {}

void NOTGate::set(bool in) {
	input[POS_IN] = in;
}

void NOTGate::setOutputComponent() {
	output[POS_OUT] = (!input[POS_IN]);
}

ANDGate::ANDGate() : Gate(POS_IN_SIZE, POS_OUT_SIZE) {}

void ANDGate::set(bool a, bool b) {
	input[POS_IN_A] = a;
	input[POS_IN_B] = b;
}

void ANDGate::setOutputComponent() {
	output[POS_OUT] = (input[POS_IN_A] && input[POS_IN_B]);
}

ORGate::ORGate() : Gate(POS_IN_SIZE, POS_OUT_SIZE) {}

void ORGate::set(bool a, bool b) {
	input[POS_IN_A] = a;
	input[POS_IN_B] = b;
}

void ORGate::setOutputComponent() {
	output[POS_OUT] = (input[POS_IN_A] || input[POS_IN_B]);
}

ORGate4Input::ORGate4Input() : Gate(POS_IN_SIZE, POS_OUT_SIZE) {}

void ORGate4Input::set(bool a, bool b, bool c, bool d) {
	input[POS_IN_A] = a;
	input[POS_IN_B] = b;
	input[POS_IN_C] = c;
	input[POS_IN_D] = d;
}

void ORGate4Input::setOutputComponent() {
	output[POS_OUT] = (input[POS_IN_A] || input[POS_IN_B] || input[POS_IN_C] || input[POS_IN_D]);
}

NANDGate::NANDGate() : Gate(POS_IN_SIZE, POS_OUT_SIZE) {}

void NANDGate::set(bool a, bool b) {
	input[POS_IN_A] = a;
	input[POS_IN_B] = b;
}

void NANDGate::setOutputComponent() {
	output[POS_OUT] = (!(input[POS_IN_A] && input[POS_IN_B]));
}

NORGate::NORGate() : Gate(POS_IN_SIZE, POS_OUT_SIZE) {}

void NORGate::set(bool a, bool b) {
	input[POS_IN_A] = a;
	input[POS_IN_B] = b;
}

void NORGate::setOutputComponent() {
	output[POS_OUT] = (!(input[POS_IN_A] || input[POS_IN_B]));
}

XORGate::XORGate() : Gate(POS_IN_SIZE, POS_OUT_SIZE) {}

void XORGate::set(bool a, bool b) {
	input[POS_IN_A] = a;
	input[POS_IN_B] = b;
}

void XORGate::setOutputComponent() {
	output[POS_OUT] = ((input[POS_IN_A] && (!input[POS_IN_B])) || ((!input[POS_IN_A]) && input[POS_IN_B]));
}

XNORGate::XNORGate() : Gate(POS_IN_SIZE, POS_OUT_SIZE) {}

void XNORGate::set(bool a, bool b) {
	input[POS_IN_A] = a;
	input[POS_IN_B] = b;
}

void XNORGate::setOutputComponent() {
	output[POS_OUT] = (((!input[POS_IN_A]) && (!input[POS_IN_B])) || (input[POS_IN_A] && input[POS_IN_B]));
}
