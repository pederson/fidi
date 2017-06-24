#ifndef _OBJECTSTENCIL_H
#define _OBJECTSTENCIL_H

#include <array>

namespace fidi{


template<std::size_t dim,
		 std::size_t reach,
		 class ValueT>
struct ObjectStencil : public ValueT{
	typedef ObjectStencil<dim, reach, ValueT>			NeighborType;

	// ValueT										center;
	std::array<std::array<const NeighborType *,reach>, dim>	neighbMin;
	std::array<std::array<const NeighborType *,reach>, dim>	neighbMax;		

	ObjectStencil() : ValueT(){};

	ObjectStencil(const ObjectStencil & o) = default;

	ObjectStencil(const ValueT & c) : ValueT(c){};

	ObjectStencil & operator=(const ValueT & c){
		ObjectStencil s(c);
		// std::swap(s.neighbMin, neighbMin);
		// std::swap(s.neighbMax, neighbMax);
		std::swap(static_cast<ValueT &>(*this), static_cast<ValueT &>(s));
		return *this;
	}

	constexpr ObjectStencil(const ValueT & c, 
			const std::array<std::array<const NeighborType *,reach>, dim> & nMin,
			const std::array<std::array<const NeighborType *,reach>, dim> & nMax)
	: ValueT(c), neighbMin(nMin), neighbMax(nMax) {};

	// runtime set and get
	constexpr const NeighborType & getNeighborMin(std::size_t d, std::size_t r=reach-1) const{
		return *neighbMin[d][r];
	};
	constexpr const NeighborType & getNeighborMax(std::size_t d, std::size_t r=reach-1) const{
		return *neighbMax[d][r];
	};
	void setNeighborMin(const NeighborType & val, std::size_t d, std::size_t r=reach-1){
		neighbMin[d][r] = &val;
	};
	void setNeighborMax(const NeighborType & val, std::size_t d, std::size_t r=reach-1){
		neighbMax[d][r] = &val;
	};


	// compile-time set and get
	template <std::size_t d, std::size_t r=reach-1>
	constexpr const NeighborType & getNeighborMin() const {return *std::get<r>(std::get<d>(neighbMin));};
	template <std::size_t d, std::size_t r=reach-1>
	constexpr const NeighborType & getNeighborMax() const {return *std::get<r>(std::get<d>(neighbMax));};
	template <std::size_t d, std::size_t r=reach-1>
	constexpr void setNeighborMin(const NeighborType & val){std::get<r>(std::get<d>(neighbMin)) = &val;};
	template <std::size_t d, std::size_t r=reach-1>
	constexpr void setNeighborMax(const NeighborType & val){std::get<r>(std::get<d>(neighbMax)) = &val;};
};


}// end namespace fidi
#endif