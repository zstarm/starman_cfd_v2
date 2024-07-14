#include <fluids_simulation.h>

sim_in_CFD_2D_cart::sim_in_CFD_2D_cart() : simulation_input("input.dat") {}

sim_in_CFD_2D_cart::sim_in_CFD_2D_cart(std::string infile) : simulation_input(infile) {}

void sim_in_CFD_2D_cart::read_input() {}
