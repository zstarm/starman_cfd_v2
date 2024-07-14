#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

///////////////////////////////////
// INPUT
///////////////////////////////////

enum class simulation_mode : int  {
	normal, 
	restart
};

class simulation_input {
	protected:
		std::string input_file_name;
		simulation_mode mode_switch;
		std::string simulation_title;
		
	public:
		simulation_input();
		simulation_input(std::string infile);
		~simulation_input();

		virtual void read_input();
//		virtual void print_params();

		void set_fname(std::string name);
		void set_mode(simulation_mode mode);
		void set_title(std::string title);

		void print_fname();
		void print_mode();
		void print_title();
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
