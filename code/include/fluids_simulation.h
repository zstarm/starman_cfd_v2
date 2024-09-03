#ifndef FLUIDS_SIM_H
#define FLUIDS_SIM_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "fluids_solvers.h"
#include "lib/simulation.h"

///////////////////////////////////
// INPUT
///////////////////////////////////

class sim_in_CFD_2D_cart : public simulation_input {
	friend class fluid_sim_2D;
	private:
		double dt, dx, dy; //delta time, x, and y;
		int Nt, Nskip, Ni, Nj; //number of time steps, time steps to skip, x points, and y points
		
		double Re, Pe, qdot; //Reynolds number, Peclet number, and scaled heat generation

		double pinit, uinit, vinit, Tinit; //initial values for variables

		boundary_condition u_bc, v_bc, T_bc, p_bc; //boundary conditions for variables

		linear_system_solver_methods Psolver_type;
		std::vector<double> Psolver_opts;

		time_differentiation_methods Usolver_type;
		upwinding_accuracy Uadvect_acc; 

		time_differentiation_methods Tsolver_type;
		upwinding_accuracy Tadvect_acc;

		void parse_infile_line(std::string& str, char delim);
		void save_boundary_input(boundary_condition& var, std::string& str, char type_or_value);
		void save_solver_selections(std::string& str, char var_type);
			
	public:
		sim_in_CFD_2D_cart();
		sim_in_CFD_2D_cart(std::string infile);

		void read_input() override;
		void print_input_parameters() override;

		std::vector<double>* get_pressure_solver_opts();
		double* get_reynolds_num();
		double* get_peclet_num();
		double* get_heat_gen();
};

///////////////////////////////////
// 2D CFD SIMULATION VARIABLES
///////////////////////////////////

class pressure : sim_variable {
	friend class fluid_sim_2D;
	
	private:

	public:
		pressure();
		~pressure();

		void run();
}; 

class velocity : sim_variable {
	friend class fluid_sim_2D;

	private:

	public:
		velocity();
		~velocity();

};

class temperature : sim_variable {
	friend class fluid_sim_2D;

	private:

	public:
		temperature();
		~temperature();
};
///////////////////////////////////
// 2D CFD SIMULATION
///////////////////////////////////

class fluid_sim_2D : public simulation {
	private:
		int int_size, ext_size;

		pressure p;
		velocity u, v;
		temperature T;

		void setup_variables();
		void setup_schemes();

	public:
		fluid_sim_2D(std::string ifname = "input.dat", std::string ofname = "output.dat");
		~fluid_sim_2D();

		void print_inputs();

};

#endif
