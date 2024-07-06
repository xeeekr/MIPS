#ifndef MIPS_FLIPFLOP_H
#define MIPS_FLIPFLOP_H

#include "component.h"
#include "gate.h"
#include "latch.h"

class D_FLIP_FLOP : public Component {
public:
	enum {
		POS_OUT_Q = 0,
		POS_OUT_Q_BAR,
		POS_OUT_SIZE,
	};

	D_FLIP_FLOP();
	void set(bool d);
	void setClock(bool clk);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_D = 0,
		POS_IN_CLOCK,
		POS_IN_SIZE
	};

	NOTGate notGate;
	D_LATCH dLatch;
	SR_LATCH srLatch;

	void setComponent() override;
	void setInputComponent() override;
	void setOutputComponent() override;
};

#endif //MIPS_FLIPFLOP_H
