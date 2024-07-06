#ifndef MIPS_LATCH_H
#define MIPS_LATCH_H

#include "component.h"
#include "gate.h"

class SR_LATCH : public Component {
public:
	enum {
		POS_OUT_Q = 0,
		POS_OUT_Q_BAR,
		POS_OUT_SIZE,
	};

	SR_LATCH();
	void set(bool s, bool r);
	void setClock(bool clk);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_S = 0,
		POS_IN_R,
		POS_IN_CLOCK,
		POS_IN_SIZE
	};

	NANDGate nandGate[4];

	void setComponent() override;
	void setInputComponent() override;
	void setOutputComponent() override;
};

class D_LATCH : public Component {
public:
	enum {
		POS_OUT_Q = 0,
		POS_OUT_Q_BAR,
		POS_OUT_SIZE,
	};

	D_LATCH();
	void set(bool D);
	void setClock(bool clk);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_D = 0,
		POS_IN_CLOCK,
		POS_IN_SIZE
	};

	NOTGate notGate;
	SR_LATCH srLatch;

	void setComponent() override;
	void setInputComponent() override;
	void setOutputComponent() override;
};

#endif //MIPS_LATCH_H
