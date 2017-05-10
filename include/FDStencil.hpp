#ifndef _FDSTENCIL_H
#define _FDSTENCIL_H

#include "Stencil.hpp"


namespace fidi{


// FDStencil
template<std::size_t dim, std::size_t reach>
struct FDStencilTypedef{
	typedef Stencil<dim,reach,double> type;
};

template<std::size_t dim, std::size_t reach>
using FDStencil = typename FDStencilTypedef<dim,reach>::type;


// FDStencil1D
template<std::size_t reach>
struct FDStencil1DTypedef{
	typedef FDStencil<1,reach> type;
};

template<std::size_t reach>
using FDStencil1D = typename FDStencil1DTypedef<reach>::type;


// FDStencil2D
template<std::size_t reach>
struct FDStencil2DTypedef{
	typedef FDStencil<2,reach> type;
};

template<std::size_t reach>
using FDStencil2D = typename FDStencil2DTypedef<reach>::type;


// FDStencil3D
template<std::size_t reach>
struct FDStencil3DTypedef{
	typedef FDStencil<3,reach> type;
};

template<std::size_t reach>
using FDStencil3D = typename FDStencil3DTypedef<reach>::type;



// first derivative
static const FDStencil1D<1>	CentralStencil_D1_O2(0.0, {{-0.5}}, {{0.5}});
static const FDStencil1D<2>	CentralStencil_D1_O4(0.0, {{-2.0/3.0, 1.0/12.0}}, {{2.0/3.0, -1.0/12.0}});

// second derivative
static const FDStencil1D<1>	CentralStencil_D2_O2(-2.0, {{1.0}}, {{1.0}});
static const FDStencil1D<2>	CentralStencil_D2_O4(-5.0/2.0, {{4.0/3.0, -1.0/12.0}}, {{4.0/3.0, -1.0/12.0}});

// third derivative
static const FDStencil1D<2>	CentralStencil_D3_O2(0.0, {{1.0, -1.0/2.0}}, {{-1.0, 1.0/2.0}});

// fourth derivative
static const FDStencil1D<2>	CentralStencil_D4_O2(6.0, {{-4.0, 1.0}}, {{-4.0, 1.0}});


}// end namespace fidi
#endif