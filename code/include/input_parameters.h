#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<memory>

enum class simulation_mode : char {
	normal, 
	restart
};

class input_parameters {
	private:
		std::string input_file_name;

		simulation_mode mode_switch;

	public:
		input_parameters();
		input_parameters(std::string infile);
};
