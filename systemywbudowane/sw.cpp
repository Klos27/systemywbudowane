#include <systemc.h>

#include "proc1.h"
#include "proc2.h"

int sc_main(int argc, char* argv[]) {
	sc_clock clock("my_clock", 1, 0.5);	// period of 1 time unit, a duty cycle of 50%
	/*	
	sc_clock clock("my_clock", 10, 0.5, 1, false)
	This declaration will create a clock object named clock with a period of 10 time units,
	a duty cycle of 50%, the first edge will occur at 1 time units, and the first value will be false.
	All of these arguments have default values except for the clock name.
	The period defaults to 1, the duty cycle to 0.5, the first edge to 0, and the first value to true.
	*/
	
	sc_fifo<int> fifo(10);

	proc1 p1("p1");
	p1.clock(clock);
	p1.fifo_out(fifo);

	proc2 p2("p2");
	p2.clock(clock);
	p2.fifo_in(fifo);

	sc_start();

	system("pause");
	return 0;
}