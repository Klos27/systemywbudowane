#pragma once
#include <systemc.h>
#include "submodule.h"

SC_MODULE(proc1) {
	sc_in_clk clock;
	sc_fifo_out<int> fifo_out;

	submodule submod;
	sc_signal<sc_int<16>> state;

	void task1();
	void task2();
	void task3();
	void task4();

	SC_CTOR(proc1)
		: submod("submod")
	{
		state.write(0);
		submod.clock(clock);
		submod.state(state);

		SC_THREAD(task1);
		sensitive << clock.pos();

		SC_CTHREAD(task2, clock.pos());

		SC_CTHREAD(task3, clock.pos());

		SC_CTHREAD(task4, clock.pos());
	}
};