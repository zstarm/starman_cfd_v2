#pragma once
#include <lib/schemes.h>

///////////////////////////////////
// SOLVER OPTIONS ENUMERATIONS
///////////////////////////////////

enum class linear_system_solver_methods : char {
	None, //No method selected
	LU, //LU Decomposition
	GS, //Gauss-Seidel
	SOR //Sucessive Over Relaxation
};

enum class time_differentiation_methods : char {
	None, //No method select
	explicit_euler,
	implicit_euler
};

enum class upwinding_accuracy : char {
	None, //No method select
	first_order,
	second_order 
};

///////////////////////////////////
// SOLVER SCHEMES
///////////////////////////////////

class gauss_seidel : public scheme {
	public:
		gauss_seidel();
		~gauss_seidel();

		void solve_point(int ind, double* var, int Ndepend, double** dependencies) override;
};
