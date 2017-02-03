# fidi
Finite Difference toolbox
* rectangular grid mesh object
* mesh creation
* boundary conditions
* loop over a subset of the mesh 
	* useful for explicit updates
	* efficient (i,j,k)-> z ordering
	* group operations (multiply, add, etc...)
* FD operations (divergence, curl, etc...)