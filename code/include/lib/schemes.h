#ifndef SCHEMES_H
#define SCHEMES_H

#include <iostream>
#include <vector>

class scheme {
	protected:
		const int* size;
		double* solution;

		int num_params;
		double** param_ptrs;

		void allocate_memory(); 

	public:
		scheme();
		~scheme();

		void set_soln_size(int *s);
		void set_scheme_params(std::vector<double*> &ptr_2_params);
		virtual void solve_point(int ind, double* var, int Ndepend, double** dependicies);
		virtual void test();
		void update_var(int ind, double* var);
};

#endif
