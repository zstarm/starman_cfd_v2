#pragma once
#include <string> 
#include <iostream>
#include <memory>
#include "input_parameters.h"

class simulation {
	protected:
		input_parameters in_pars;
		//std::shared_ptr<fluid_variable[]> sim_vars;
		//outputer_file_handler out_handle;

	public:
		simulation(); //default constructor
		simulation(std::string input_file); //constructor specifying path of input file
		~simulation();		
};
