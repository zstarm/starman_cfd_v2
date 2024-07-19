#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <fluids_solvers.h>
#include <lib/simulation.h>

///////////////////////////////////
// INPUT
///////////////////////////////////

class sim_in_CFD_2D_cart : public simulation_input {
	private:
		double dt, dx, dy; //delta time, x, and y;
		int Nt, Nskip, Ni, Nj; //number of time steps, time steps to skip, x points, and y points
		
		double Re, Pe, qdot; //Reynolds number, Peclet number, and scaled heat generation

		boundary_condition u_bc, v_bc, T_bc, p_bc;

		void parse_infile_line(std::string& str, char delim);
			
	public:
		sim_in_CFD_2D_cart();
		sim_in_CFD_2D_cart(std::string infile);

		void read_input() override;
		void print_input_parameters() override;
};

///////////////////////////////////
// VARIABLES
///////////////////////////////////

class velocity : sim_variable  {};

class temperature : sim_variable {};

class pressure : sim_variable {}; 

///////////////////////////////////
// SIMULATION
///////////////////////////////////
/*
class fluid_sim_2D : public simulation {
	private:

	public:
		fluid_sim_2D();
		fluid_sim_2D(std::string input_file);
		~fluid_sim_2D();


};
*/
