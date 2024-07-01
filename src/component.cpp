#include "component.h"

Component::Component(int inputSize, int outputSize) {
	input.assign(inputSize, false);
	output.assign(outputSize, false);
	backup_output.assign(outputSize, false);
}

bool Component::run() {
	if (components.empty()) {
		setComponent();
	}

	setInputComponent();
	bool bChangeOutputComponent = runComponent();

	backupOutput();
	setOutputComponent();
	bool bChangeOutput = isChangeOutput();

	return (bChangeOutputComponent || bChangeOutput);
}

void Component::set(const std::vector<bool> &in) {
	for (int i = 0 ; i < in.size() ; i++) {
		input[i] = in[i];
	}
}

bool Component::runComponent() {
	bool componentChange = false;
	for (auto & component : components) {
		componentChange = ((*component).run() || componentChange);
	}
	return componentChange;
}

void Component::backupOutput() {
	for (int i = 0 ; i < output.size() ; i++) {
		backup_output[i] = output[i];
	}
}

bool Component::isChangeOutput() {
	for (int i = 0 ; i < output.size() ; i++) {
		if (output[i] != backup_output[i]) {
			return true;
		}
	}
	return false;
}
