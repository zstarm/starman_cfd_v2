#include <iostream>
#include <fluids_simulation.h>
//#include <fluid_mechanics.h>

int main(int argc, char* argv[]) {
	
//	std::cout << "Hello World!" << std::endl;
	sim_in_CFD_2D_cart test;
	test.read_input();
	test.print_input_parameters();

	return 0; 
}
