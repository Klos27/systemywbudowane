
#include "submodule.h"

void submodule::task() {
	// room S-1
	// CD 2,4,5
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
			case 12:
			case 24:
			case 25:
				num_of_ppl++;
				print = true;
				break;
			case 22:
			case 14:
			case 15:
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
			cout << "proc1-submodule: Room S1: " << num_of_ppl << " Light: ";
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