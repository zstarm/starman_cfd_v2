#pragma once
#include <iostream>

class scheme {
	protected:
		int* size;
		double* solution;
		int num_const_params;
		double** const_params;

		void allocate_memory();

	public:
		scheme();
		~scheme();

		virtual void setup_scheme(int* soln_size, int Nparams, double* params[]);
		virtual void solve_point(int ind, double* var, int Ndepend, double** dependicies);
		virtual void test();
		void update_var(int ind, double* var);
};

