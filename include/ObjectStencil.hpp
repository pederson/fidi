#ifndef _OBJECTSTENCIL_H
#define _OBJECTSTENCIL_H

#include <array>

namespace fidi{


template<std::size_t dim,
		 std::size_t reach,
		 class ValueT>
struct ObjectStencil : public ValueT{
	// ValueT										center;
	std::array<std::array<const ValueT *,reach>, dim>	neighbMin;
	std::array<std::array<const ValueT *,reach>, dim>	neighbMax;		

	ObjectStencil() : ValueT(){};

	ObjectStencil(const ValueT & c) : ValueT(c){};

	ObjectStencil & operator=(const ValueT & c){
		ObjectStencil s(c);
		std::swap(s.neighbMin, neighbMin);
		std::swap(s.neighbMax, neighbMax);
		return *this;
	}

	constexpr ObjectStencil(const ValueT & c, 
			const std::array<std::array<const ValueT *,reach>, dim> & nMin,
			const std::array<std::array<const ValueT *,reach>, dim> & nMax)
	: ValueT(c), neighbMin(nMin), neighbMax(nMax) {};

	// runtime set and get
	constexpr const ValueT & getNeighborMin(std::size_t d, std::size_t r=reach-1) const{
		return *neighbMin[d][r];
	};
	constexpr const ValueT & getNeighborMax(std::size_t d, std::size_t r=reach-1) const{
		return *neighbMax[d][r];
	};
	void setNeighborMin(const ValueT & val, std::size_t d, std::size_t r=reach-1){
		neighbMin[d][r] = &val;
	};
	void setNeighborMax(const ValueT & val, std::size_t d, std::size_t r=reach-1){
		neighbMax[d][r] = &val;
	};


	// compile-time set and get
	template <std::size_t d, std::size_t r=reach-1>
	constexpr const ValueT & getNeighborMin() const {return *std::get<r>(std::get<d>(neighbMin));};
	template <std::size_t d, std::size_t r=reach-1>
	constexpr const ValueT & getNeighborMax() const {return *std::get<r>(std::get<d>(neighbMax));};
	template <std::size_t d, std::size_t r=reach-1>
	constexpr void setNeighborMin(const ValueT & val){std::get<r>(std::get<d>(neighbMin)) = &val;};
	template <std::size_t d, std::size_t r=reach-1>
	constexpr void setNeighborMax(const ValueT & val){std::get<r>(std::get<d>(neighbMax)) = &val;};
};


}// end namespace fidi
#endif