#include <fluids_solvers.h>

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
	for(int i = 0; i < num_params; i++) {
		std::cout << *param_ptrs[i] << std::endl;
	}
}

//SUCCESSIVE OVER-RELAXATION 
SOR::SOR() {}

SOR::~SOR() {}

void SOR::solve_point(int ind, double* var, int Ndepend, double** dependicies) {
}

void SOR::test() {
	std::cout << "SOR - RUN TEST" << std::endl;
	for(int i = 0; i < num_params; i++) {
		std::cout << *param_ptrs[i] << std::endl;
	}
}

//EXPLICIT UPWINDING (FIRST ORDER)
explicit_first_order_upwinding::explicit_first_order_upwinding() {}

explicit_first_order_upwinding::~explicit_first_order_upwinding() {}

void explicit_first_order_upwinding::solve_point(int ind, double* var, int Ndepend, double** dependicies) {

}
