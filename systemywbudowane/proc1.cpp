#include "proc1.h"

void proc1::write_info(int info){
	state.write(info);
	fifo_out.write(info);
}

void proc1::task1() {
	int input;	// user input
	int people[5] = {0}; // num of people in room -> 0 = S1 ; 1 = S2 ...
	//bool error = false;
	
	while (true) {
		wait();
		// get user input
		cin >> input;
		if (input < 0) {
			// stop simulation
			sc_stop();
		}
		else {
			system("cls");
			switch(input){
				case 11:
					write_info(11);
					people[4]++;
					break;
				case 21:
					if(people[4] > 0){
						write_info(21);
						people[4]--;
					}
					else
						write_info(31); // error
					break;
				case 12:
					write_info(12);
					people[0]++;
					break;
				case 22:
					if(people[0] > 0){
						write_info(22);
						people[0]--;
					}
					else
						write_info(32); // error
					break;
				case 13:
					write_info(13);
					people[2]++;
					break;
				case 23:
					if(people[2] > 0){
						write_info(23);
						people[2]--;
					}
					else
						write_info(33); // error
					break;
				case 14:
					if(people[0] > 0){
						write_info(14);
						people[0]--;
						people[2]++;
					}
					else
						write_info(34); // error
					break;
				case 24:
					if(people[2] > 0){
						write_info(24);
						people[2]--;
						people[0]++;
					}
					else
						write_info(34); // error
					break;
				case 15:
					if(people[0] > 0){
						write_info(15);
						people[0]--;
						people[4]++;
					}
					else
						write_info(35); // error
					break;
				case 25:
					if(people[4] > 0){
						write_info(25);
						people[4]--;
						people[0]++;
					}
					else
						write_info(35); // error
					break;
				case 16:
					if(people[3] > 0){
						write_info(16);
						people[3]--;
						people[4]++;
					}
					else
						write_info(36); // error
					break;
				case 26:
					if(people[4] > 0){
						write_info(26);
						people[4]--;
						people[3]++;
					}
					else
						write_info(36); // error
					break;
				case 17:
					write_info(17);
					people[3]++;
					break;
				case 27:
					if(people[3] > 0){
						write_info(27);
						people[3]--;
					}
					else
						write_info(37); // error
					break;
				case 18:
					write_info(18);
					people[1]++;
					break;
				case 28:
					if(people[1] > 0){
						write_info(28);
						people[1]--;
					}
					else
						write_info(38); // error
					break;
				case 19:
					write_info(19);
					people[1]++;
					break;
				case 29:
					if(people[1] > 0){
						write_info(29);
						people[1]--;
					}
					else
						write_info(39); // error
					break;
				case 110:
					if(people[1] > 0){
						write_info(110);
						people[1]--;
						people[3]++;
					}
					else
						write_info(310); // error
					break;
				case 210:
					if(people[3] > 0){
						write_info(210);
						people[3]--;
						people[1]++;
					}
					else
						write_info(310); // error
					break;
				default: 
					write_info(1); // if incorrect input write 0
					break;
			}
			cout << "(proc1-task1) Rooms: ";
			for(int i=0; i<5; i++)
				cout << " S" << i+1 << ": " << people[i];
			cout << endl;
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

	while(tmp >= 0){
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
			cout << "(proc1-task2) Room S2: " << num_of_ppl << " Light: ";
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

	while(tmp >= 0){
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
			cout << "(proc1-task3) Room S4: " << num_of_ppl << " Light: ";
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

	while(tmp >= 0){
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
			cout << "(proc1-task4) Room S5: " << num_of_ppl << " Light: ";
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
