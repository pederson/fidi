#include "include/FDStencil.hpp"
#include "include/ObjectStencil.hpp"

#include <iostream>


struct DoubleObj{
	DoubleObj(): val(0){};
	DoubleObj(double v): val(v){};
	double val;
};

using namespace fidi;

int main(int argc, char * argv[]){

	std::cout << CentralStencil_D4_O2.getCenter() << std::endl;

	ObjectStencil<1,1,DoubleObj> dos(2);
	ObjectStencil<1,1,DoubleObj> dos_right(3);
	ObjectStencil<1,1,DoubleObj> dos_left(1);
	dos.setNeighborMin<0>(dos_left);
	dos.setNeighborMax<0>(dos_right);


	std::cout << dos.getNeighborMin<0>().val << ", " << dos.val << ", " << dos.getNeighborMax<0>().val << std::endl;

	return 0;
}