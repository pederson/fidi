#ifndef _OBJECTSTENCIL_H
#define _OBJECTSTENCIL_H

#include <array>

namespace fidi{


// template<std::size_t dim,
// 		 std::size_t reach,
// 		 class ValueT>
// struct ObjectStencil : public ValueT{
// 	typedef ObjectStencil<dim, reach, ValueT>			NeighborType;

// 	// ValueT										center;
// 	std::array<std::array<const NeighborType *,reach>, dim>	neighbMin;
// 	std::array<std::array<const NeighborType *,reach>, dim>	neighbMax;		

// 	ObjectStencil() : ValueT(){
// 		for (auto i=0; i<dim; i++){
// 			for (auto j=0; j<reach; j++){
// 				neighbMin[i][j] = nullptr;
// 				neighbMax[i][j] = nullptr;
// 			}
// 	}};

// 	ObjectStencil(const ObjectStencil & o) = default;

// 	ObjectStencil(const ValueT & c) : ValueT(c){};

// 	ObjectStencil & operator=(const ValueT & c){
// 		ObjectStencil s(c);
// 		// std::swap(s.neighbMin, neighbMin);
// 		// std::swap(s.neighbMax, neighbMax);
// 		std::swap(static_cast<ValueT &>(*this), static_cast<ValueT &>(s));
// 		return *this;
// 	}

// 	constexpr ObjectStencil(const ValueT & c, 
// 			const std::array<std::array<const NeighborType *,reach>, dim> & nMin,
// 			const std::array<std::array<const NeighborType *,reach>, dim> & nMax)
// 	: ValueT(c), neighbMin(nMin), neighbMax(nMax) {};

// 	// runtime set and get
// 	constexpr const NeighborType & getNeighborMin(std::size_t d, std::size_t r=reach-1) const{
// 		return *neighbMin[d][r];
// 	};
// 	constexpr const NeighborType & getNeighborMax(std::size_t d, std::size_t r=reach-1) const{
// 		return *neighbMax[d][r];
// 	};
// 	void setNeighborMin(const NeighborType & val, std::size_t d, std::size_t r=reach-1){
// 		neighbMin[d][r] = &val;
// 	};
// 	void setNeighborMax(const NeighborType & val, std::size_t d, std::size_t r=reach-1){
// 		neighbMax[d][r] = &val;
// 	};


// 	// compile-time set and get
// 	template <std::size_t d, std::size_t r=reach-1>
// 	constexpr const NeighborType & getNeighborMin() const {return *std::get<r>(std::get<d>(neighbMin));};
// 	template <std::size_t d, std::size_t r=reach-1>
// 	constexpr const NeighborType & getNeighborMax() const {return *std::get<r>(std::get<d>(neighbMax));};
// 	template <std::size_t d, std::size_t r=reach-1>
// 	constexpr void setNeighborMin(const NeighborType & val){std::get<r>(std::get<d>(neighbMin)) = &val;};
// 	template <std::size_t d, std::size_t r=reach-1>
// 	constexpr void setNeighborMax(const NeighborType & val){std::get<r>(std::get<d>(neighbMax)) = &val;};


// 	// runtime get pointer
// 	constexpr const NeighborType * getNeighborMinPtr(std::size_t d, std::size_t r=reach-1) const{
// 		return neighbMin[d][r];
// 	};
// 	constexpr const NeighborType * getNeighborMaxPtr(std::size_t d, std::size_t r=reach-1) const{
// 		return neighbMax[d][r];
// 	};
// };








template<std::size_t dim,
		 std::size_t reach,
		 class ValueT>
struct ObjectStencil : public ValueT{
	typedef ObjectStencil<dim, reach, ValueT>			NeighborType;

	// ValueT										center;
	std::array<std::array<NeighborType *,reach>, dim>	neighbMin;
	std::array<std::array<NeighborType *,reach>, dim>	neighbMax;		

	ObjectStencil() : ValueT(){
		for (auto i=0; i<dim; i++){
			for (auto j=0; j<reach; j++){
				neighbMin[i][j] = nullptr;
				neighbMax[i][j] = nullptr;
			}
	}};

	ObjectStencil(const ObjectStencil & o) = default;

	ObjectStencil(const ValueT & c) : ValueT(c){};

	ObjectStencil & operator=(ValueT & c){
		ObjectStencil s(c);
		// std::swap(s.neighbMin, neighbMin);
		// std::swap(s.neighbMax, neighbMax);
		std::swap(static_cast<ValueT &>(*this), static_cast<ValueT &>(s));
		return *this;
	}

	constexpr ObjectStencil(ValueT & c, 
			std::array<std::array<NeighborType *,reach>, dim> & nMin,
			std::array<std::array<NeighborType *,reach>, dim> & nMax)
	: ValueT(c), neighbMin(nMin), neighbMax(nMax) {};

	// runtime set and get
	constexpr NeighborType & getNeighborMin(std::size_t d, std::size_t r=reach-1) const{
		return *neighbMin[d][r];
	};
	constexpr NeighborType & getNeighborMax(std::size_t d, std::size_t r=reach-1) const{
		return *neighbMax[d][r];
	};
	void setNeighborMin(NeighborType & val, std::size_t d, std::size_t r=reach-1){
		neighbMin[d][r] = &val;
	};
	void setNeighborMax(NeighborType & val, std::size_t d, std::size_t r=reach-1){
		neighbMax[d][r] = &val;
	};


	// compile-time set and get
	template <std::size_t d, std::size_t r=reach-1>
	constexpr NeighborType & getNeighborMin() const {return *std::get<r>(std::get<d>(neighbMin));};
	template <std::size_t d, std::size_t r=reach-1>
	constexpr NeighborType & getNeighborMax() const {return *std::get<r>(std::get<d>(neighbMax));};
	template <std::size_t d, std::size_t r=reach-1>
	constexpr void setNeighborMin(NeighborType & val){std::get<r>(std::get<d>(neighbMin)) = &val;};
	template <std::size_t d, std::size_t r=reach-1>
	constexpr void setNeighborMax(NeighborType & val){std::get<r>(std::get<d>(neighbMax)) = &val;};


	// runtime get pointer
	constexpr NeighborType * getNeighborMinPtr(std::size_t d, std::size_t r=reach-1) const{
		return neighbMin[d][r];
	};
	constexpr NeighborType * getNeighborMaxPtr(std::size_t d, std::size_t r=reach-1) const{
		return neighbMax[d][r];
	};
};


}// end namespace fidi
#endif