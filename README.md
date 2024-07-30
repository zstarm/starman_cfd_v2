# Computational Fluid Dynamics and Heat Transfer Solver
## Version 2.0
## Written by Z. Starman 
## Expanded upon course project for ME:7269 at the University of Iowa

### Description

This code is 2D solver for the Navier-Stokes and unsteady heat/energy equation. A large portion of this code was originally written for completion of a course project for ME:7269 at the University of Iowa.
I am now updating and maintaining this code base as a personal project.

### Latest Updates 

### July 23, 2024
Established a static library that includes base simulation classes that are used here to make an simulation input for 2D cartesian CFD simulations. An instance of the simulation input can so far read/parse the uniform grid info, desired number of time steps, selected solver methods, and specified boundary conditions. Additionally, the inputs can be printed to the console in a formatted way. Exceptions are used to handle any erroreous lines in the input file. 

**Future Tasks**
- Add ability to read in initial values for the 2D CFD simulation variables (P, U, V, and T)
- Develop simulation variable class (base and child classes) to be used when running the simulation
- TEST
