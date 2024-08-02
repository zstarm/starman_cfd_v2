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

//LINEAR SYSTEMS/IMPLICIT SOLVERS
class LUDecomp : public scheme {
	protected:
		double** A, L, U;
		double* y, b;
	public:
		LUDecomp();
		~LUDecomp();

		void solve_point(int ind, double* var, int Ndepend, double** dependencies) override;
};

class gauss_seidel : public scheme {
	protected:
		double* convergence;
		double* max_iters;
	public:
		gauss_seidel();
		~gauss_seidel();

		void solve_point(int ind, double* var, int Ndepend, double** dependencies) override;

		void test() override;
		void set_convergence(double* c);
		void set_max_iters(double* N);
};

class SOR : public gauss_seidel {
	protected:
		double* weight;
	public:
		SOR();
		~SOR();
	
		void test() override;
		void set_weight(double* w);
		void solve_point(int ind, double* var, int Ndepend, double** dependencies) override;
};

//UNSTEADY SOLVERS
class explicit_first_order_upwinding : public scheme {
	protected:
		double *Re, *Pe, *qdot;
	public:
		explicit_first_order_upwinding();
		~explicit_first_order_upwinding();

		void solve_point(int ind, double* var, int Ndepend, double** dependencies) override;
		void set_Re(double* R);
		void set_Pe(double* P);
		void set_q(double* q);
};
