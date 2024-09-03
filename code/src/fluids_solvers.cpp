#include <fluids_solvers.h>

///////////////////////////////////
// SOLVER SCHEMES
///////////////////////////////////

//LU DECOMPOSITION
LUDecomp::LUDecomp() {}

LUDecomp::~LUDecomp() {}

void LUDecomp::solve_point(int ind, double* var, int Ndepend, double** dependicies) {}

//GAUSS-SEIDEL
gauss_seidel::gauss_seidel() {}

gauss_seidel::~gauss_seidel() {}

void gauss_seidel::solve_point(int ind, double* var, int Ndepend, double** dependicies) {}

void gauss_seidel::test() {
	std::cout << "GS - RUN TEST" << std::endl;
	std::cout << *convergence << std::endl;
}

//SUCCESSIVE OVER-RELAXATION 
SOR::SOR() {}

SOR::~SOR() {}


void SOR::solve_point(int ind, double* var, int Ndepend, double** dependicies) {
}

void SOR::test() {
	std::cout << "SOR - RUN TEST" << std::endl;
	std::cout << *weight << std::endl;
}

//EXPLICIT UPWINDING (FIRST ORDER)
explicit_first_order_upwinding::explicit_first_order_upwinding() {}

explicit_first_order_upwinding::~explicit_first_order_upwinding() {}

void explicit_first_order_upwinding::solve_point(int ind, double* var, int Ndepend, double** dependicies) {

}
