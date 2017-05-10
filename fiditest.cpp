#include "include/FDStencil.hpp"

#include <iostream>

using namespace fidi;

int main(int argc, char * argv[]){

	std::cout << CentralStencil_D4_O2.getCenter() << std::endl;

	return 0;
}