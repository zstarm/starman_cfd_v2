#include <sstream>
#include <iostream>
#include "fluids_simulation.h"

int main(int argc, char* argv[]) {
	bool verbose = false;

	for(int i = 0; i < argc; i++) {
		char* cmd = argv[i];
		if(cmd[0] == '-') {
			std::stringstream ss;
			switch(cmd[1]) {
				case 'v':
					ss << argv[++i];
					if(!(ss >> std::boolalpha >> verbose)) {
						std::cout << "Incorrect argument" << std::endl;
					}
					break;

				default:;
			}
		}
	}
	fluid_sim_2D test;
	if(verbose) {
		test.print_inputs();
	}

	return 0; 
}
