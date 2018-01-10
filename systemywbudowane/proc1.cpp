#include "proc1.h"

void proc1::task1() {
	int input;	// user input
	int people[5] = {0}; // num of people in room
	bool error = false;

	while (true) {
		wait();
		// get user input
		cin >> input;
		if (input < 0) {
			// stop simulation
			sc_stop();
		}
		if (input != 0) {
			system("cls");
			state.write(input);
			fifo_out.write(input);
			//TODO THIS FUNCTION
			/*switch(input){
				case 0:
				default: state.write(0); // if incorrect input write 0
			}*/
			//cout << "State task1: " << state.read()
		} 
	} 
}

void proc1::task2() {
	// room S-2
	// CD 8,9,10
	int num_of_ppl = 0;
	bool light = false;
	int error = 0;  // 0 = no error , 1 = error in room , 2 = end of error
	int tmp = 1;
	bool print = false;

	while(tmp > 0){
		wait();
		print = false;
		// delete error
		if(error == 1){
			error = 2;
			print = true;
		}
		else if(error == 2)
			error = 0;
		
		tmp = state.read();

		switch(tmp){
			case 18:
			case 19:
			case 210:
				num_of_ppl++;
				print = true;
				break;
			case 28:
			case 29:
			case 110:
				error = 0;
				if(num_of_ppl > 0)
					num_of_ppl--;
				else
					error = 1;
				print = true;
				break;
			// ERRORS
			case 38:
			case 39:
			case 310:
				//display error
				error = 1;
				print = true;
				break;
			default:
				break;
		}

		// SWITCH LIGHT
		if(num_of_ppl > 0)
			light = true;
		else
			light = false;

		// PRINT INFO
		if(print){
			cout << "proc1-task2: Room S2: " << num_of_ppl << " Light: ";
			if(light) cout << " On ";
			else cout << " Off ";
		
			if(error == 1) cout << " ERROR IN ROOM ";
			else if (error == 2){
				error = 0;
				cout << " END OF ERROR";
			}
			cout << endl;
		}
	}
}

void proc1::task3() {
	// room S-4
	// CD 6,7,10
	int num_of_ppl = 0;
	bool light = false;
	int error = 0;  // 0 = no error , 1 = error in room , 2 = end of error
	int tmp = 1;
	bool print = false;

	while(tmp > 0){
		wait();
		print = false;
		// delete error
		if(error == 1){
			error = 2;
			print = true;
		}
		else if(error == 2)
			error = 0;

		tmp = state.read();

		switch(tmp){
			case 26:
			case 17:
			case 110:
				num_of_ppl++;
				print = true;
				break;
			case 16:
			case 27:
			case 210:
				if(num_of_ppl > 0)
					num_of_ppl--;
				else
					error = 1;
				print = true;
				break;
			// ERRORS
			case 36:
			case 37:
			case 310:
				//display error
				error = 1;
				print = true;
				break;
			default:
				break;
		}

		// SWITCH LIGHT
		if(num_of_ppl > 0)
			light = true;
		else
			light = false;

		// PRINT INFO
		if(print){
			cout << "proc1-task3: Room S4: " << num_of_ppl << " Light: ";
			if(light) cout << " On ";
			else cout << " Off ";
		
			if(error == 1) cout << " ERROR IN ROOM ";
			else if (error == 2){
				error = 0;
				cout << " END OF ERROR";
			}
			cout << endl;
		}
	}
}

void proc1::task4() {
	// room S-5
	// CD 1,5,6
	int num_of_ppl = 0;
	bool light = false;
	int error = 0;  // 0 = no error , 1 = error in room , 2 = end of error
	int tmp = 1;
	bool print = false;

	while(tmp > 0){
		wait();
		print = false;
		// delete error
		if(error == 1){
			error = 2;
			print = true;
		}
		else if(error == 2)
			error = 0;

		tmp = state.read();

		switch(tmp){
			case 11:
			case 15:
			case 16:
				num_of_ppl++;
				print = true;
				break;
			case 21:
			case 25:
			case 26:
				if(num_of_ppl > 0)
					num_of_ppl--;
				else
					error = 1;
				print = true;
				break;
			// ERRORS
			case 31:
			case 35:
			case 36:
				//display error
				error = 1;
				print = true;
				break;
			default:
				break;
		}

		// SWITCH LIGHT
		if(num_of_ppl > 0)
			light = true;
		else
			light = false;

		// PRINT INFO
		if(print){
			cout << "proc1-task4: Room S5: " << num_of_ppl << " Light: ";
			if(light) cout << " On ";
			else cout << " Off ";
		
			if(error == 1) cout << " ERROR IN ROOM ";
			else if (error == 2){
				error = 0;
				cout << " END OF ERROR";
			}
			cout << endl;
		}
	}
}
