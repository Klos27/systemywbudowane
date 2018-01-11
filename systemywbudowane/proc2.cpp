#include "proc2.h"

void proc2::task() {
	// room S-3
	// CD 3,4
	int num_of_ppl = 0;
	bool light = false;
	int error = 0;  // 0 = no error , 1 = error in room , 2 = end of error
	int tmp = 1;
	bool print = false;

	while(tmp >= 0){
		//wait();
		print = false;
		// delete error
		if(error == 1){
			error = 2;
			print = true;
		}
		else if(error == 2)
			error = 0;
		
		tmp = fifo_in.read();

		switch(tmp){
			case 13:
			case 14:
				num_of_ppl++;
				print = true;
				break;
			case 23:
			case 24:
				if(num_of_ppl > 0)
					num_of_ppl--;
				else
					error = 1;
				print = true;
				break;
			// ERRORS
			case 33:
			case 34:
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
			cout << "(proc2-task) Room S3: " << num_of_ppl << " Light: ";
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