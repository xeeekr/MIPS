#ifndef MIPS_COMPONENT_H
#define MIPS_COMPONENT_H

#include <vector>

class Component {
public:
	Component(int inputSize, int outputSize);

	std::vector<bool> input;
	std::vector<bool> output;

	virtual bool run();

	void set(const std::vector<bool> &in);

protected:
	std::vector<Component *> components;

	virtual void setComponent() = 0;
	virtual void setInputComponent() = 0;
	virtual void setOutputComponent() = 0;

private:
	std::vector<bool> backup_output;

	void backupOutput();
	bool isChangeOutput();
	virtual bool runComponent();
};


#endif //MIPS_COMPONENT_H
