#include <fluids_simulation.h>

///////////////////////////////////
// 2D CFD SIMULATION INPUT
///////////////////////////////////

sim_in_CFD_2D_cart::sim_in_CFD_2D_cart() : simulation_input("input.dat"), u_bc(4), v_bc(4), T_bc(4), p_bc(4) {}

sim_in_CFD_2D_cart::sim_in_CFD_2D_cart(std::string infile) : simulation_input(infile), u_bc(4), v_bc(4), T_bc(4), p_bc(4) {}


void sim_in_CFD_2D_cart::parse_infile_line(std::string & str, char delim) {
	//separtes input file line into two substrings of the parameter name and parameter value
	std::size_t pos = str.find(delim, 0);
	std::string name = str.substr(0, pos - 1);
	str.erase(0, pos + 1);

	//manipulate name/value substrings to eliminate any unncessary spaces
	if(name[0] == ' ') {
		name.erase(0,1); //erase space before the parameter name
	}
	if(name[pos-1] == ' ') {
		name.erase(pos-1,1); //erase space at the end parameter name
	}
	if(str[0] == ' ') {
		str.erase(0,1); //erase space before the parameter value
	}
	if(str[str.length()-1] == ' ' || str[str.length()-1] == '\r') {
		str.erase(str.length()-1,1); //erase space at the end parameter value
	}

	//READING AND STORING INPUT PARAMETERS FROM .DAT FILE
	try {
		switch(std::tolower(name[0])) {
			case 'a':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'b':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'c':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'd':
				if(name == "dt") {
					dt = std::stod(str);
				}
				else if(name == "dx") {
					dx = std::stod(str);
				}
				else if(name == "dy") {
					dy = std::stod(str);
				}
				else {
					throw std::logic_error("Unrecognized input identifier"); }
				break;

			case 'e':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'f':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'g':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'h':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'i':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'j':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'k':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'l':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'm':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'n':
				if(name == "Nskip") {
					Nskip = std::stoi(str);
				}
				else if(name == "Nt") {
					Nt = std::stoi(str);
				}
				else if(name == "Nx") {
					Ni = std::stoi(str);
				}
				else if(name == "Ny") {
					Nj = std::stoi(str);
				}
				else {
					throw std::logic_error("Unrecognized input identifier");
				}
				break;

			case 'o':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'p':
				if(name == "PBC") {
					save_boundary_input(p_bc, str, 't');	
				}
				else if(name == "PBV") {
					save_boundary_input(p_bc, str, 'v');	
				}
				else if(name == "Pe") {
					Pe = std::stod(str);
				}
				else if(name == "Pinit") {
					pinit = std::stod(str);
				}
				else if(name == "Psolver") {
					save_solver_selections(str, 'p');
				}
				else {
					throw std::logic_error("Unrecognized input identifier");
					//throw 
				}
				break;

			case 'q':
				if(name == "qdot") {
					qdot = std::stod(str);
				}
				else {
					throw std::logic_error("Unrecognized input identifier");
				}
				break;

			case 'r':
				if(name == "Re") {
					Re = std::stod(str);
				}
				else {
					throw std::logic_error("Unrecognized input identifier");
					//throw 
				}
				break;

			case 's':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 't':
				if(name == "TBC") {
					save_boundary_input(T_bc, str, 't');	
				}
				else if(name == "TBV") {
					save_boundary_input(T_bc, str, 'v');	
				}
				else if (name == "Tinit") {
					Tinit = std::stod(str);
				}
				else if(name == "Tsolver") {
					save_solver_selections(str, 'T');
				}
				else {
					throw std::logic_error("Unrecognized input identifier");
					//throw
				}
				break;

			case 'u':
				if(name == "UBC") {
					save_boundary_input(u_bc, str, 't');	
				}
				else if(name == "UBV") {
					save_boundary_input(u_bc, str, 'v');	
				}
				else if(name == "Usolver") {
					save_solver_selections(str, 'u');
				}
				else if(name == "Uinit") {
					uinit = std::stod(str);
				}
				else {
					throw std::logic_error("Unrecognized input identifier");
				}
				break;

			case 'v':
				if(name == "VBC") {
					save_boundary_input(v_bc, str, 't');	
				}
				else if(name == "VBV") {
					save_boundary_input(v_bc, str, 'v');	
				}
				else if(name == "Vinit") {
					vinit = std::stod(str);
				}
				else {
					throw std::logic_error("Unrecognized input identifier");
				}
				break;

			case 'w':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'x':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'y':
				throw std::logic_error("Unrecognized input identifier");
				break;

			case 'z':
				throw std::logic_error("Unrecognized input identifier");
				break;

			default:
				throw std::logic_error("Unrecognized input identifier");
		}
	}
	
	catch(const std::exception& e) {
		successful_load = false; //make boolean false if an exception is thrown

		std::cout << "Exception: " << e.what() << " \"" << name << "\"" << std::endl;
	}
}

void sim_in_CFD_2D_cart::save_boundary_input(boundary_condition& var, std::string& str, char type_or_value) {

	str.erase(0, str.find('{',0) + 1);
	str = str.substr(0, str.find('}',1));
	if(str[0] == ' ') {
		str.erase(0, 1);
	}

	std::size_t pos;
	int count = 0;
	try {
		if(type_or_value == 't') {
			for(int i = 0; (i < 4) && ((pos = str.find(' ', 0)) != std::string::npos); i++) {
				std::string tmp = str.substr(0, pos);
				if(tmp == "dirichlet") {
					var.change_type(i, boundary_type::dirichlet);
				}
				else if(tmp == "neumann") {
					var.change_type(i, boundary_type::neumann);	
				}
				else {
					throw std::logic_error("Invailid boundary condition type used : \"" + tmp + "\"");
				}
				str.erase(0, pos+1);
				count = i;
			}
			if(count != 3) {
				throw count;
			}
		}
		else if(type_or_value == 'v') {
			for(int i = 0; (i < 4) && ((pos = str.find(' ', 0)) != std::string::npos); i++) {
				double tmp = std::stod(str.substr(0, pos));
				var.change_value(i, tmp);
				str.erase(0, pos+1);
				count = i;
			}
			if(count != 3) {
				throw count;
			}
		}
		else {
			std::cout << "Invalid boundary type/value identifier passed to function!" << std::endl;
		}
	}
	
	catch(const std::exception& e) {
		successful_load = false; //make boolean false if exception is thrown
		std::cout << "Exception: " << e.what() << std::endl;
	}

	catch(int) {
		successful_load = false; //make boolean false if exception is thrown
		std::cout << "Incorrect number of arguments specified for boundary condition" << std::endl;
	}
}

void sim_in_CFD_2D_cart::save_solver_selections(std::string& str, char var_type) {

	str.erase(0, str.find('{',0) + 1);
	str = str.substr(0, str.find('}',1));
	if(str[0] == ' ') {
		str.erase(0, 1);
	}

	std::size_t pos;
	std::string tmp;
	
	try {
		switch(var_type) {
			case 'p': //pressure
				pos = str.find(' ', 0);
				tmp = str.substr(0, pos);
					if(tmp ==  "LU") {
						Psolver_type = linear_system_solver_methods::LU;
					}
					else if(tmp ==  "GS") {
						Psolver_type = linear_system_solver_methods::GS;
						str.erase(0, pos + 1);
						for(int i = 0; i < 2; i++) {
							pos = str.find(' ', 0);
							if(pos != std::string::npos) {
								Psolver_opts.push_back(std::stod(str.substr(0, pos)));
							}
							else {
								throw std::logic_error("Not enough options supplied for \"Gauss-Seidel\" pressure solver algorithm");
								break;
							}
							str.erase(0, pos + 1);
						}
					}
					else if (tmp == "SOR") {
						Psolver_type = linear_system_solver_methods::SOR;
						str.erase(0, pos + 1);
						for(int i = 0; i < 3; i++) {
							pos = str.find(' ', 0);
							if(pos != std::string::npos) {
								Psolver_opts.push_back(std::stod(str.substr(0, pos)));
							}
							else {
								throw std::logic_error("Not enough options supplied for \"SOR\" pressure solver algorithm");
								break;
							}
							str.erase(0, pos + 1);
						}
					}
					else {
						Psolver_type = linear_system_solver_methods::None;
						throw std::logic_error("Unrecognized solver method for pressure");
					}
				break;

			case 'u': //velocity
				pos = str.find(' ', 0);
				tmp = str.substr(0, pos);
					if(tmp ==  "EXPLICIT") {
						Usolver_type = time_differentiation_methods::explicit_euler;
						str.erase(0, pos + 1);
						pos = str.find(' ', 0);
						if(pos != std::string::npos) {
							if(str.substr(0, pos) == "1") {
								Uadvect_acc = upwinding_accuracy::first_order;
							}
							else {
								throw std::logic_error("Unsupported velocity upwinding spatial accuracy of order " + str.substr(0, pos));
							}
						}
						else {
							throw std::logic_error("No option supplied for velocity upwinding accuracy");
						}
					}
					else {
						Usolver_type = time_differentiation_methods::None;
						throw std::logic_error("Invaild time differentiation method given for velocity");
					}
				break;
			case 'T': //energy/temperature
				pos = str.find(' ', 0);
				tmp = str.substr(0, pos);
					if(tmp ==  "EXPLICIT") {
						Tsolver_type = time_differentiation_methods::explicit_euler;
						str.erase(0, pos + 1);
						pos = str.find(' ', 0);
						if(pos != std::string::npos) {
							if(str.substr(0, pos) == "1") {
								Tadvect_acc = upwinding_accuracy::first_order;
							}
							else {
								throw std::logic_error("Unsupported temperature/energy upwinding spatial accuracy of order " + str.substr(0, pos));
							}
						}
						else {
							throw std::logic_error("No option supplied for temperature/energy upwinding accuracy");
						}
					}
					else {
						Tsolver_type = time_differentiation_methods::None;
						throw std::logic_error("Invaild time differentiation method given for temperature/energy");
					}
				break;

			default:
				std::cout << "Invalid variable solver method identifier passed to function!" << std::endl;
		}
	}
	
	catch(const std::exception& e) {
		successful_load = false; //make boolean false if exception is thrown
		std::cout << "Exception: " << e.what() << std::endl; 
	}
}

void sim_in_CFD_2D_cart::read_input() {
	//opens file name of the input file
	std::ifstream fs(input_file_name);
	try {
		if(fs.is_open()) {
			successful_load = true; //make boolean true (keep true unless exception is thrown)
			std::string line;
			while(!fs.eof()) {
				//starts reading lines from input file
			 	std::getline(fs,line);
			 	//skip empty lines or commeted lines (beginning with #)
			 	if(line[0] != '#' && line[0] != '\r' && !line.empty()) {
					parse_infile_line(line, '=');
			 	}
			}

		  /*
		  //reset the time step size based on Pe number if "-1" option is selected
		  if(dt < 0) {
			 if(dt > dx) {
				dt = dx;
			 }
			 if(dt > dy) {
				dt = dy;
			 }
			 dt = 0.5*peclet_number/(1.0/dx/dx + 1.0/dy/dy);
			 double dt_obj = 0.5/alpha*peclet_number/(1.0/dx/dx + 1.0/dy/dy);
			 if(dt > dt_obj) {
				dt = dt_obj;
			 }
		  }
		  */
		}

	   //returns error message if input file cannot be opened 

		else {
			throw std::runtime_error("Could not open file \"" + input_file_name + "\"");
		}
	}

	catch(std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

}

void sim_in_CFD_2D_cart::print_input_parameters() {
	//print out input parameters if no exceptions are thrown
	if(successful_load) {
	
		std::string sect_break = "------------------------------------------------------";

		std::cout << sect_break << "\nSIMULATION INPUTS\n" << sect_break << std::endl;

		//GRID 
		std::cout << "Grid Size\n" << sect_break << "\nI = " << Ni << "\nJ = " << Nj << std::endl;
		std::cout << "dx = " << dx << "\ndy = " << dy << "\n" << sect_break << std::endl;

		//TIME
		std::cout << "Time Interation\n" << sect_break << "\nNt = " << Nt << "\nNskip = " << Nskip << std::endl;
		std::cout << "dt = " << dt << "\n" << sect_break << std::endl;

		//BOUNDARIES
		std::cout << "Boundary Conditions\n" << sect_break;
		std::cout << "\nPressure\n"; 
		p_bc.print_conditions();
		std::cout << "\nU Velocity\n"; 
		u_bc.print_conditions();
		std::cout << "\nV Velocity\n"; 
		v_bc.print_conditions();
		std::cout << "\nTemperature\n"; 
		T_bc.print_conditions();
		std::cout << sect_break << std::endl;

		//INITIAL CONDITIONS
		std::cout << "NONDIMENSIONAL PARAMETERS\n" << sect_break;
		std::cout << "\nReynolds Number = " << Re << "\nPeclet Number = " << Pe; 
		std::cout << "\nScaled Heat Generation = " << qdot << "\n" << sect_break << std::endl;

		//TIME
		std::cout << "Time Interation\n" << sect_break << "\nNt = " << Nt << "\nNskip = " << Nskip << std::endl;
		std::cout << "dt = " << dt << "\n" << sect_break << std::endl;

		//SOLVER METHODS
		std::cout << "Solver Methods\n" << sect_break;
		std::cout << "\nPressure Poisson Equation: Fractional Step";
		std::cout << "\n\tSolver Method = ";
		switch(static_cast<char>(Psolver_type)) {
			case static_cast<char>(linear_system_solver_methods::LU):
				std::cout << "LU Decomposition";
				break;
				
			case static_cast<char>(linear_system_solver_methods::GS):
				std::cout << "Gauss-Seidel";
				std::cout << "\n\tConvergence: " << Psolver_opts[0];
				std::cout << "\n\tMax Iterations: " << static_cast<int>(Psolver_opts[1]);
				break;

			case static_cast<char>(linear_system_solver_methods::SOR):
				std::cout << "Successive Over-Relaxation";
				std::cout << "\n\tConvergence: " << Psolver_opts[0];
				std::cout << "\n\tMax Iterations: " << static_cast<int>(Psolver_opts[1]);
				std::cout << "\n\tWeight: " << Psolver_opts[2];
				break;

			default:
				std::cout << "No Selection";
		}
		std::cout << std::endl;

		std::cout << "\nVelocity Schemes";
		std::cout << "\n\tTime Differentiation = ";
		switch(static_cast<char>(Usolver_type)) {
			case static_cast<char>(time_differentiation_methods::explicit_euler):
				std::cout << "Explicit Euler";
				break;

			case static_cast<char>(time_differentiation_methods::implicit_euler):
				std::cout << "Implicit Euler";
				break;

			default:
				std::cout << "No Selection" << std::endl;
		}

		std::cout << "\n\tUpwinding Spatial Accuracy = ";
		switch(static_cast<char>(Uadvect_acc)) {
			case static_cast<char>(upwinding_accuracy::first_order):
				std::cout << "1st Order";
				break;

			case static_cast<char>(upwinding_accuracy::second_order):
				std::cout << "2nd Order";
				break;

			default:
				std::cout << "No Selection";
		}
		std::cout << std::endl;

		std::cout << "\nTemperature/Energy Schemes";
		std::cout << "\n\tTime Differentiation = ";
		switch(static_cast<char>(Tsolver_type)) {
			case static_cast<char>(time_differentiation_methods::explicit_euler):
				std::cout << "Explicit Euler";
				break;

			case static_cast<char>(time_differentiation_methods::implicit_euler):
				std::cout << "Implicit Euler";
				break;

			default:
				std::cout << "No Selection";
		}

		std::cout << "\n\tUpwinding Spatial Accuracy = ";
		switch(static_cast<char>(Tadvect_acc)) {
			case static_cast<char>(upwinding_accuracy::first_order):
				std::cout << "1st Order";
				break;

			case static_cast<char>(upwinding_accuracy::second_order):
				std::cout << "2nd Order";
				break;

			default:
				std::cout << "No Selection" << std::endl;
		}
		std::cout << std::endl;

		std::cout << sect_break << std::endl;
	}	
}

///////////////////////////////////
// 2D CFD SIMULATION VARIABLES 
///////////////////////////////////

//PRESSURE
pressure::pressure() {}

pressure::~pressure() {}

void pressure::run() {
	solver->test();
}

//VELOCITY
velocity::velocity() {}

velocity::~velocity() {}

//TEMPERATURE
temperature::temperature() {}

temperature::~temperature() {}

///////////////////////////////////
// 2D CFD SIMULATION 
///////////////////////////////////

typedef sim_in_CFD_2D_cart SIMIN;
fluid_sim_2D::fluid_sim_2D(std::string ifname, std::string ofname) : simulation(ifname, ofname) {
	INPUT = new sim_in_CFD_2D_cart(ifname);
	load_inputs();
	if(INPUT->check_load()) {
		setup_variables();
		setup_schemes();
	}
	else {
		std::cout << "Error loading inputs! Could not setup 2D fluid dynamics case" << std::endl;
	}

}

fluid_sim_2D::~fluid_sim_2D() {
	std::cout << "Simulation Deconstructed" << std::endl;
}

void fluid_sim_2D::setup_variables() {

	//get size of variables from input
	int_size = (static_cast<SIMIN*>(INPUT)->Ni - 2) * (static_cast<SIMIN*>(INPUT)->Nj - 2);
	ext_size = (static_cast<SIMIN*>(INPUT)->Ni)*(static_cast<SIMIN*>(INPUT)->Nj) - int_size;
	
	//apply size to variable container
	p.set_size(int_size);
	u.set_size(int_size);
	v.set_size(int_size);
	T.set_size(int_size);

	//attach boundary conditions to variable
	p.attach_boundary_conditions(&static_cast<SIMIN*>(INPUT)->p_bc);
	u.attach_boundary_conditions(&static_cast<SIMIN*>(INPUT)->u_bc);
	v.attach_boundary_conditions(&static_cast<SIMIN*>(INPUT)->v_bc);
	T.attach_boundary_conditions(&static_cast<SIMIN*>(INPUT)->T_bc);

	//set variable names
	p.set_name("Pressure");
	u.set_name("U Velocity");
	v.set_name("V Velocity"); 
	T.set_name("Temperature");

}

void fluid_sim_2D::setup_schemes() {
	//Constant parameters to be given to solver
	double* Re_ptr = &static_cast<SIMIN*>(INPUT)->Re;
	double* Pe_ptr = &static_cast<SIMIN*>(INPUT)->Pe;
	double* q_ptr = &static_cast<SIMIN*>(INPUT)->qdot;
	double* dx_ptr = &static_cast<SIMIN*>(INPUT)->dx;
	double* dy_ptr = &static_cast<SIMIN*>(INPUT)->dy;
	double* dt_ptr = &static_cast<SIMIN*>(INPUT)->dt;
	double* P_opts = &static_cast<SIMIN*>(INPUT)->Psolver_opts[0];

	//Pressure solver
	switch(static_cast<char>(static_cast<SIMIN*>(INPUT)->Psolver_type)) {
		case static_cast<char>(linear_system_solver_methods::LU):
			break;
			
		case static_cast<char>(linear_system_solver_methods::GS):
			p.select_solver(new gauss_seidel);
			p.solver->setup_scheme(&int_size, 2, (double* []){&P_opts[0], &P_opts[1]});
			break;

		case static_cast<char>(linear_system_solver_methods::SOR):
			p.select_solver(new SOR);
			p.solver->setup_scheme(&int_size, 3, (double* []){&P_opts[0], &P_opts[1], &P_opts[2]});
			break;

		default:;
	}

	//Velocity solvers
	switch(static_cast<char>(static_cast<SIMIN*>(INPUT)->Usolver_type)) {
		case static_cast<char>(time_differentiation_methods::explicit_euler):
			switch(static_cast<char>(static_cast<SIMIN*>(INPUT)->Uadvect_acc)) {
				case static_cast<char>(upwinding_accuracy::first_order):
					u.select_solver(new explicit_first_order_upwinding);
					u.solver->setup_scheme(&int_size, 3, (double* []){Re_ptr, Pe_ptr, q_ptr});
					v.select_solver(new explicit_first_order_upwinding);
					v.solver->setup_scheme(&int_size, 3, (double* []){Re_ptr, Pe_ptr, q_ptr});
					break;

				case static_cast<char>(upwinding_accuracy::second_order):
					break;

				default:;

			}
			break;
			
		case static_cast<char>(time_differentiation_methods::implicit_euler):
			break;
		
		default:;
	}

	//Temperature/Energy solver
	switch(static_cast<char>(static_cast<SIMIN*>(INPUT)->Tsolver_type)) {
		case static_cast<char>(time_differentiation_methods::explicit_euler):
			switch(static_cast<char>(static_cast<SIMIN*>(INPUT)->Tadvect_acc)) {
				case static_cast<char>(upwinding_accuracy::first_order):
					T.select_solver(new explicit_first_order_upwinding);
					T.solver->setup_scheme(&int_size, 3, (double* []){Re_ptr, Pe_ptr, q_ptr});
					break;

				case static_cast<char>(upwinding_accuracy::second_order):
					break;

				default:;

			}
			break;
			
		case static_cast<char>(time_differentiation_methods::implicit_euler):
			break;
		
		default:;
	}

	p.run();
}

void fluid_sim_2D::print_inputs() {
	INPUT->print_input_parameters();
}
