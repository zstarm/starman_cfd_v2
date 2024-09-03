#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <memory>
#include "schemes.h"

///////////////////////////////////
// INPUT
///////////////////////////////////

enum class simulation_mode : int  {
	normal, 
	restart
};

class simulation_input {
	friend class simulation;
	protected:
		std::string input_file_name;
		simulation_mode mode_switch;
		std::string simulation_title;

		bool successful_load;
		
	public:
		simulation_input();
		simulation_input(std::string infile);
		~simulation_input();

		virtual void read_input();
		virtual void print_input_parameters();

		void set_fname(std::string name);
		void set_mode(simulation_mode mode);
		void set_title(std::string title);

		void print_fname();
		void print_mode();
		void print_title();

		bool check_load();
};
/*
///////////////////////////////////
// OUTPUT 
///////////////////////////////////

class output_file {

	public:
		output_file();

};

///////////////////////////////////
// SIMULATION
///////////////////////////////////

class simulation {
	protected:
		simulation_input* INP;
		//std::shared_ptr<fluid_variable[]> sim_vars;
		//outputer_file_handler out_handle;

	public:
		simulation(); //default constructor
		simulation(std::string input_file); //constructor specifying path of input file
		~simulation();

		void add_input(std::string input_file);
};
*/

//////////////////////////////////
// BOUNDARY CONDITION
///////////////////////////////////

enum class boundary_type : char {
	dirichlet, neumann
};

class boundary_condition {
	private:
		int N;
		boundary_type* type; 
		double* val;

	public:
		boundary_condition();
		boundary_condition(int num_of_boundaries);
		boundary_condition(int num_of_boundaries, boundary_type t, double v);
		~boundary_condition();

		void set_size(int size);
		void change_type(int ind, boundary_type t);
		void change_value(int ind, double v);
		void print_conditions();
};

///////////////////////////////////
// SIMULATION VARIABLES
///////////////////////////////////
//
class scheme;
class sim_variable {
	private:

	protected:
		int size;
		std::string var_name;
		double* content;
		boundary_condition* BCs;
		scheme* solver;

		void allocate_memory();

	public:
		sim_variable();
		sim_variable(std::string name, int size);
		~sim_variable();

		void set_name(std::string name);
		void set_size(int s);

		void initialize(double value);
		void attach_boundary_conditions(boundary_condition* boundaries);
		void select_solver(scheme* s);

};

///////////////////////////////////
// SIMULATION 
///////////////////////////////////

class simulation {
	protected:
		simulation_input* INPUT;
		//simulation_output* OUTPUT;

		void load_inputs();

	public:
		simulation(std::string ifname = "input.dat", std::string ofname = "output.dat");
		~simulation();
};

#endif
