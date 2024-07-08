# Computational Fluid Dynamics and Heat Transfer Solver
## Version 2.0
## Written by Z. Starman 
## Expanded upon course project for ME:7269 at the University of Iowa

### Description

This code is 2D solver for the Navier-Stokes and unsteady heat/energy equation. A large portion of this code was originally written for completion of a course project for ME:7269 at the University of Iowa.
I am now updating and maintaining this code base as a personal project.

### Major Updates 

### July 8,, 2024
Initial git commit. I am starting to add portions of the original class project code into this repository. However, I will be updating the design of the code's structure to make development and scaling easier in the future. 

The main objective will be to develop a framework for the code such that it can be easily adapted and built upon and used for a large range of CFD and other PDE simulations. 

**Planned Tasks**
- Start developing base classes to be used.
  	- SIMULATION CLASS: 
        - Members: Input Parameter, Variable(s), Output File Handler
        - Fuctionality: 
            - Add variable(s)
            - Change output file type
            - Initialize variables
            - Attach solver method to variable
            - Write variables to output file
            - Run simulation time step
