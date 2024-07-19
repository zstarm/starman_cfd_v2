#include <fluids_simulation.h>

sim_in_CFD_2D_cart::sim_in_CFD_2D_cart() : simulation_input("input.dat") {}

sim_in_CFD_2D_cart::sim_in_CFD_2D_cart(std::string infile) : simulation_input(infile) {}

void sim_in_CFD_2D_cart::read_input() {
   //opens file name of the input file
   std::ifstream fs(input_file_name);
   if(fs.is_open()) {
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
	   std::cout << "ERROR: Cannot open input file" << std::endl;
   }

}

/*
void sim_in_CFD_2D_cart::parse_infile_line(std::string& str, char delim) {
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

   //save grid parameters
   if(name == "num_x") {
      num_x_points = std::stoi(str);
   }
   else if(name == "num_y") {
      num_y_points = std::stoi(str);
   }
   else if(name == "del_x") {
      dx = std::stod(str);
   }
   else if(name == "del_y") {
      dy = std::stod(str);
   }

   //save time parameters
   else if(name == "del_t") {
      dt = std::stod(str);
   }
   else if(name == "num_time_iter") {
      N = std::stoi(str);
   }
   else if(name == "time_iter_skip") {
      Nskip = std::stoi(str);
   }
   
   //save pressure solver methods
   else if(name == "solver") {
      //checks for which solver and saves as an enumerated class type
      if(str == "SOR") {
         pressure_solver_method = solver_method::SOR;
      }
      else if(str == "Gauss-Seidel") {
         pressure_solver_method = solver_method::GaussSeidel;
      }
      else if(str == "LU") {
         pressure_solver_method = solver_method::LU;
      }
      else {
         cout << "ERROR: could not determine solver method" << endl;
      }
   }
   else if(name == "weight") {
      weight = std::stod(str);
   }
   else if(name == "convergence") {
      convergence = std::stod(str);
   }
   else if(name == "max_iter") {
      max_iterations = std::stoi(str);
   }

   //save nondimensional parameters
   else if(name == "heat_gen") {
      heat_generation = std::stod(str);
   }
   else if(name == "reynolds") {
      reynolds_number = std::stod(str);
   }
   else if(name == "peclet") {
      peclet_number = std::stod(str);
   }

   //save object parameters
   else if(name == "I_pos") {
      obj_I = std::stoi(str);
   }
   else if(name == "J_pos") {
      obj_J = std::stoi(str);
   }
   else if(name == "L_obj") {
      obj_L = std::stoi(str);
   }
   else if(name == "k") {
      k_ = std::stod(str);
   }
   else if(name == "alpha") {
      alpha = std::stod(str);
   }

   //save initial values
   else if(name == "Tinit") {
      T_initial = std::stod(str);
   }
   else if(name == "Pinit") {
      P_initial = std::stod(str);
   }
   else if(name == "Uinit") {
      U_initial = std::stod(str);
   }
   else if(name == "Vinit") {
      V_initial = std::stod(str);
   }

   //save boundary conditions
   else if(name == "north_type_P") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         pressure_boundary_type[0] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         pressure_boundary_type[0] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "south_type_P") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         pressure_boundary_type[1] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         pressure_boundary_type[1] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "east_type_P") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         pressure_boundary_type[2] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         pressure_boundary_type[2] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "west_type_P") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         pressure_boundary_type[3] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         pressure_boundary_type[3] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "north_val_P") {
      pressure_boundary_val[0] = std::stod(str);
   }
   else if(name == "south_val_P") {
      pressure_boundary_val[1] = std::stod(str);
   }
   else if(name == "east_val_P") {
      pressure_boundary_val[2] = std::stod(str);
   }
   else if(name == "west_val_P") {
      pressure_boundary_val[3] = std::stod(str);
   }

   else if(name == "north_type_U") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         u_vel_boundary_type[0] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         u_vel_boundary_type[0] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "south_type_U") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         u_vel_boundary_type[1] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         u_vel_boundary_type[1] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "east_type_U") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         u_vel_boundary_type[2] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         u_vel_boundary_type[2] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "west_type_U") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         u_vel_boundary_type[3] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         u_vel_boundary_type[3] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "north_val_U") {
      u_vel_boundary_val[0] = std::stod(str);
   }
   else if(name == "south_val_U") {
      u_vel_boundary_val[1] = std::stod(str);
   }
   else if(name == "east_val_U") {
      u_vel_boundary_val[2] = std::stod(str);
   }
   else if(name == "west_val_U") {
      u_vel_boundary_val[3] = std::stod(str);
   }

   else if(name == "north_type_T") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         temp_boundary_type[0] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         temp_boundary_type[0] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "south_type_T") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         temp_boundary_type[1] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         temp_boundary_type[1] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "east_type_T") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         temp_boundary_type[2] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         temp_boundary_type[2] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "west_type_T") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         temp_boundary_type[3] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         temp_boundary_type[3] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "north_val_T") {
      temp_boundary_val[0] = std::stod(str);
   }
   else if(name == "south_val_T") {
      temp_boundary_val[1] = std::stod(str);
   }
   else if(name == "east_val_T") {
      temp_boundary_val[2] = std::stod(str);
   }
   else if(name == "west_val_T") {
      temp_boundary_val[3] = std::stod(str);
   }

   else if(name == "north_type_V") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         v_vel_boundary_type[0] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         v_vel_boundary_type[0] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "south_type_V") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         v_vel_boundary_type[1] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         v_vel_boundary_type[1] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "east_type_V") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         v_vel_boundary_type[2] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         v_vel_boundary_type[2] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "west_type_V") {
      //checks for which boundary type and saves as an enumerated class type
      if(str == "dirichlet" || str == "Dirichlet") {
         v_vel_boundary_type[3] = boundary_condition::dirichlet;
      }
      else if(str == "neumann" || str == "Neumann") {
         v_vel_boundary_type[3] = boundary_condition::neumann;
      }
      else {
         cout << "ERROR: could not determine north boundary type" << endl;
      }
   }
   else if(name == "north_val_V") {
      v_vel_boundary_val[0] = std::stod(str);
   }
   else if(name == "south_val_V") {
      v_vel_boundary_val[1] = std::stod(str);
   }
   else if(name == "east_val_V") {
      v_vel_boundary_val[2] = std::stod(str);
   }
   else if(name == "west_val_V") {
      v_vel_boundary_val[3] = std::stod(str);
   }

   //return error message if name does not correspond to a object parameter
   else {
      cout << "ERROR: parameter name \"" << name << "\" does not correspond to input parameter type" << endl;
   }        

}
*/

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

	switch(std::tolower(name[0])) {
		case 'a':
			break;
		case 'b':
			break;
		case 'c':
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
				//throw
			}
			break;
		case 'e':
			break;
		case 'f':
			break;
		case 'g':
			break;
		case 'h':
			break;
		case 'i':
			break;
		case 'j':
			break;
		case 'k':
			break;
		case 'l':
			break;
		case 'm':
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
				//throw
			}
			break;
		case 'o':
			break;
		case 'p':
			if(name == "PBC") {
				//parse boundary conditions
			}
			else if(name == "PBV") {
				//parse boundary values
			}
			else if(name == "Pe") {
				Pe = std::stod(str);
			}
			else {
				//throw 
			}
			break;
		case 'q':
			if(name == "qdot") {
				qdot = std::stod(str);
			}
			break;
		case 'r':
			if(name == "Re") {
				Re = std::stod(str);
			}
			else {
				//throw 
			}
			break;
		case 's':
			if(name == "solver") {
			}
			break;
		case 't':
			if(name == "TBC") {
				//parse boundary conditions
			}
			else if(name == "TBV") {
				//parse boundary values
			}
			else {
				//throw
			}
			break;
		case 'u':
			if(name == "UBC") {
				//parse boundary conditions
			}
			else if(name == "UBV") {
				//parse boundary values
			}
			break;
		case 'v':
			if(name == "VBC") {
				//parse boundary conditions
			}
			else if(name == "VBV") {
				//parse boundary values
			}
			break;
		case 'w':
			break;
		case 'x':
			break;
		case 'y':
			break;
		case 'z':
			break;
		default:
			//throw
			std::cout << "error" << std::endl;

	}
}

void sim_in_CFD_2D_cart::print_input_parameters() {
	std::string sect_break = "------------------------------------------------------";

	std::cout << sect_break << "\nSIMULATION INPUTS\n" << sect_break << std::endl;

	//GRID 
	std::cout << "Grid Size\n" << sect_break << "\nI = " << Ni << "\nJ = " << Nj << std::endl;
	std::cout << "dx = " << dx << "\ndy = " << dy << "\n" << sect_break << std::endl;

	//TIME
	std::cout << "Time Interation\n" << sect_break << "\nNt = " << Nt << "\nNskip = " << Nskip << std::endl;
	std::cout << "dt = " << dt << "\n" << sect_break << std::endl;
	
}
