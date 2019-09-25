#pragma once

#include <FunctionQuadratic2D.hh>
#include <FunctionQuadraticND.hh>
#include <FunctionNonConvex2D.hh>

//== NAMESPACES ===================================================================

namespace AOPT {

    //== CLASS DEFINITION =========================================================

    class GridSearch {
    public:
        using Vec = FunctionBase::Vec;
        using Mat = FunctionBase::Mat;

        GridSearch(const int _n_grid = 10) : n_grid_(_n_grid){}
        ~GridSearch() {}

    public:
        int grid_search_2d(const Vec& _x_l, const Vec& _x_u, const int _func = 0) {
            std::cout<<"Grid searching the minimum of a 2d function..."<<std::endl;

            FunctionNonConvex2D fnc2d;
            FunctionQuadratic2D fq2d(-1.);

            //------------------------------------------------------//
            //Todo: implement the 2d version of the grid search
            //algorithm to find minimum value of function 0 and function 1
            //------------------------------------------------------//

            //------------------------------------------------------//
            return 0;
        }


        int grid_search_nd(const int _n, const Vec& _x_l, const Vec& _x_u) {
            if(_x_l.size() != _n || _x_u.size() != _n) {
                std::cout<<"Error: inputs are not of"<<_n<<" dimension!"<<std::endl;
                return -1;
            }
            std::cout<<"Grid searching the minimum of a "<<_n<<" d function..."<<std::endl;
            //------------------------------------------------------//
            //Todo: implement the nd version of the grid search
            //algorithm to find the minimum value of a n-dimension
            //quadratic function. Hint: use FunctionQuadratic2D class
            //to evaluate function value
            //------------------------------------------------------//

            //------------------------------------------------------//
            return 0;
        }

    private:
        int n_grid_;
    };

    //=============================================================================
}





