#include <fluids_solvers.h>

///////////////////////////////////
// SOLVER SCHEMES
///////////////////////////////////

//LU DECOMPOSITION
LUDecomp::LUDecomp() {}

LUDecomp::~LUDecomp() {}

void LUDecomp::solve_point(int ind, double* var, int Ndepend, double** dependicies) {}

void LUDecomp::setup_scheme(int* soln_size, int Nparams, double* params[]) {
//	A = params[0];
//	L = params[1];
//	U = params[2];
//	y = params[3];
//	b = params[4];
}

//GAUSS-SEIDEL
gauss_seidel::gauss_seidel() {}

gauss_seidel::~gauss_seidel() {}

void gauss_seidel::solve_point(int ind, double* var, int Ndepend, double** dependicies) {}

void gauss_seidel::setup_scheme(int* soln_size, int Nparams, double* params[]) {
	if(Nparams == 2) {
		convergence = params[0];
		max_iters = params[1];
	}
	else {
		std::cout << "Error: Incorrect number of parameters used" << std::endl;
	}
}

void gauss_seidel::test() {
	std::cout << "GS - RUN TEST" << std::endl;
	std::cout << *convergence << std::endl;
}

//SUCCESSIVE OVER-RELAXATION 
SOR::SOR() {}

SOR::~SOR() {}

void SOR::setup_scheme(int* soln_size, int Nparams, double* params[]) {
	if(Nparams == 3) {
		convergence = params[0];
		max_iters = params[1];
		weight = params[2];
	}
	else {
		std::cout << "Error: Incorrect number of parameters used" << std::endl;
	}
}

void SOR::solve_point(int ind, double* var, int Ndepend, double** dependicies) {
}

void SOR::test() {
	std::cout << "SOR - RUN TEST" << std::endl;
	std::cout << *weight << std::endl;
}

//EXPLICIT UPWINDING (FIRST ORDER)
explicit_first_order_upwinding::explicit_first_order_upwinding() {}

explicit_first_order_upwinding::~explicit_first_order_upwinding() {}

void explicit_first_order_upwinding::setup_scheme(int* soln_size, int Nparams, double* params[]) {
	if(Nparams == 3) {
		Re = params[0];
		Pe = params[1];
		qdot = params[2];
	}
	else {
		std::cout << "Error: Incorrect number of parameters used" << std::endl;
	}
}

void explicit_first_order_upwinding::solve_point(int ind, double* var, int Ndepend, double** dependicies) {

}
