#ifndef MIPS_MUX_H
#define MIPS_MUX_H

#include "component.h"
#include "gate.h"

class MUX_2_TO_1 : public Component {
public:
	enum {
		POS_OUT_Y = 0,
		POS_OUT_SIZE,
	};

	MUX_2_TO_1();
	void set(bool s, bool in_0, bool in_1);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_S = 0,
		POS_IN_I_1,
		POS_IN_I_0,
		POS_IN_SIZE
	};

	NOTGate notGate;
	NANDGate nandGate[3];

	void setComponent() override;
	void setInputComponent() override;
	void setOutputComponent() override;
};

#endif //MIPS_MUX_H
