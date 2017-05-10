#ifndef _STENCIL_H
#define _STENCIL_H

#include <array>

namespace fidi{


template<std::size_t dim,
		 std::size_t reach,
		 class ValueT>
struct Stencil{
	ValueT										center;
	std::array<std::array<ValueT,reach>, dim>	neighbMin;
	std::array<std::array<ValueT,reach>, dim>	neighbMax;		


	constexpr Stencil(const ValueT & c, 
			const std::array<std::array<ValueT,reach>, dim> & nMin,
			const std::array<std::array<ValueT,reach>, dim> & nMax)
	: center(c), neighbMin(nMin), neighbMax(nMax) {};

	constexpr ValueT & getNeighborMin(std::size_t d, std::size_t r){
		return neighbMin[d][r];
	};

	constexpr ValueT & getCenter(){
		return center;
	};

	constexpr ValueT & getNeighborMax(std::size_t d, std::size_t r){
		return neighbMax[d][r];
	};


	constexpr const ValueT & getNeighborMin(std::size_t d, std::size_t r) const{
		return neighbMin[d][r];
	};

	constexpr const ValueT & getCenter() const{
		return center;
	};

	constexpr const ValueT & getNeighborMax(std::size_t d, std::size_t r) const{
		return neighbMax[d][r];
	};


	void setNeighborMin(std::size_t d, std::size_t r, const ValueT & val){
		neighbMin[d][r] = val;
	};

	void setCenter(const ValueT & val){
		center = val;
	};

	void setNeighborMax(std::size_t d, std::size_t r, const ValueT & val){
		neighbMax[d][r] = val;
	};
};




}// end namespace fidi
#endif