#include <fluids_simulation.h>

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
				save_boundary_input(p_bc, str, 't');	
			}
			else if(name == "PBV") {
				save_boundary_input(p_bc, str, 'v');	
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
				save_boundary_input(T_bc, str, 't');	
			}
			else if(name == "TBV") {
				save_boundary_input(T_bc, str, 'v');	
			}
			else {
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
			break;
		case 'v':
			if(name == "VBC") {
				save_boundary_input(v_bc, str, 't');	
			}
			else if(name == "VBV") {
				save_boundary_input(v_bc, str, 'v');	
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

void sim_in_CFD_2D_cart::save_boundary_input(boundary_condition& var, std::string& str, char type_or_value) {

	str.erase(0, str.find('{',0) + 1);
	str = str.substr(0, str.find('}',1));
	if(str[0] == ' ') {
		str.erase(0, 1);
	}

	std::size_t pos;
	int count = 0;
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
				//throw;
			}
			str.erase(0, pos+1);
			count = i;
		}
		if(count != 3) {
			//throw
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
			//throw
		}
	}
	else {
		//throw
	}
}

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

void sim_in_CFD_2D_cart::print_input_parameters() {
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
	std::cout << "\nU Velocity\n"; 
	u_bc.print_conditions();
	std::cout << "\nV Velocity\n"; 
	v_bc.print_conditions();
	std::cout << "\nTemperature\n"; 
	T_bc.print_conditions();
	std::cout << "\nPressure\n"; 
	p_bc.print_conditions();
	std::cout << sect_break << std::endl;
	
}
