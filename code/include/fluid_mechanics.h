#pragma once
#include <string> 
#include <iostream>
#include <memory>

class boundary_condition {
	private:
		enum class Enum : char {
			dirichlet, neumann
		};
	public:
		boundary_condition();

};



class fluid_variable {
	private:
		class velocity {};
		class temperature {};
		class pressure {}; 

	public:
		fluid_variable();
};

