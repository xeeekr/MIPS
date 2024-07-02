#ifndef MIPS_GATE_H
#define MIPS_GATE_H

#include "component.h"

class Gate : public Component {
protected:
	Gate(int inputSize, int outputSize);
	void setComponent() override;
	void setInputComponent() override;
};

class BUFFERGate : public Gate {
public:
	enum {
		POS_OUT = 0,
		POS_OUT_SIZE,
	};

	BUFFERGate();
	void set(bool in);

protected:
	using Component::set;	// disable
	enum {
		POS_IN = 0,
		POS_IN_SIZE,
	};

	void setOutputComponent() override;
};

class NOTGate : public Gate {
public:
	enum {
		POS_OUT = 0,
		POS_OUT_SIZE,
	};

	NOTGate();
	void set(bool in);

protected:
	using Component::set;	// disable
	enum {
		POS_IN = 0,
		POS_IN_SIZE,
	};

	void setOutputComponent() override;
};

class ANDGate : public Gate {
public:
	enum {
		POS_OUT = 0,
		POS_OUT_SIZE,
	};

	ANDGate();
	void set(bool a, bool b);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_A = 0,
		POS_IN_B,
		POS_IN_SIZE,
	};

	void setOutputComponent() override;
};

class ORGate : public Gate {
public:
	enum {
		POS_OUT = 0,
		POS_OUT_SIZE,
	};

	ORGate();
	void set(bool a, bool b);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_A = 0,
		POS_IN_B,
		POS_IN_SIZE,
	};

	void setOutputComponent() override;
};

class ORGate4Input : public Gate {
public:
	enum {
		POS_OUT = 0,
		POS_OUT_SIZE,
	};

	ORGate4Input();
	void set(bool a, bool b, bool c, bool d);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_A = 0,
		POS_IN_B,
		POS_IN_C,
		POS_IN_D,
		POS_IN_SIZE,
	};

	void setOutputComponent() override;
};

class NANDGate : public Gate {
public:
	enum {
		POS_OUT = 0,
		POS_OUT_SIZE,
	};

	NANDGate();
	void set(bool a, bool b);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_A = 0,
		POS_IN_B,
		POS_IN_SIZE,
	};

	void setOutputComponent() override;
};

class NORGate : public Gate {
public:
	enum {
		POS_OUT = 0,
		POS_OUT_SIZE,
	};

	NORGate();
	void set(bool a, bool b);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_A = 0,
		POS_IN_B,
		POS_IN_SIZE,
	};

	void setOutputComponent() override;
};

class XORGate : public Gate {
public:
	enum {
		POS_OUT = 0,
		POS_OUT_SIZE,
	};

	XORGate();
	void set(bool a, bool b);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_A = 0,
		POS_IN_B,
		POS_IN_SIZE,
	};

	void setOutputComponent() override;
};

class XNORGate : public Gate {
public:
	enum {
		POS_OUT = 0,
		POS_OUT_SIZE,
	};

	XNORGate();
	void set(bool a, bool b);

protected:
	using Component::set;	// disable
	enum {
		POS_IN_A = 0,
		POS_IN_B,
		POS_IN_SIZE,
	};

	void setOutputComponent() override;
};

#endif //MIPS_GATE_H
