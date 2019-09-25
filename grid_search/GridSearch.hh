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
			double a1 = std::numeric_limits<double>::infinity();

			double xl = _x_l[0];
			double xu = _x_u[0];
			double nu = n_grid_;
			double step_size = (xu - xl)/ nu;
			
			for (double i = xl; i <= xu; i = i+step_size) {
				for (double j = xl; j <= xu; j = j+step_size) {
					Vec x(2);
					x << i, j;
					double b;
					if (_func == 0) {
						b = fnc2d.f(x);
					} else {
						b = fq2d.f(x);
					}
					if (b < a1) {
						a1 = b;
					}
				}
			}
			
			std::cout << "minimum:" << a1 << std::endl;
			return a1;
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

			double xl = _x_l[0];
			double xu = _x_u[0];
			double nu = n_grid_;
			double step_size = (xu - xl) / nu;
			
			FunctionQuadraticND fqnd(_n);
			//FunctionNonConvex2D fqnd;
			double a = std::numeric_limits<double>::infinity();

			Vec x;
			x = {};
			min_function(_n, xu, xl, step_size, x, fqnd, a);
			std::cout << "minimum:" << a << std::endl;
			return a;
        }

    private:
        int n_grid_;

		void min_function(int d, double xu, double xl, double step_size, Vec x, FunctionQuadraticND fqnd, double& a) {

			if (d > 2){
				for (double i = xl; i <= xu; i = i + step_size) {
					Vec y(x.size() + 1);
					y << x, i;
					min_function(d - 1, xu, xl, step_size, y, fqnd, a);
				}
			}
			else{
				for (double i = xl; i <= xu; i = i + step_size) 
					for (double j = xl; j <= xu; j = j + step_size) {
						Vec y(x.size() + 2);
						y << x, i, j;
						double b = fqnd.f(y);
						if (b < a) {
							//std::cout << "b:" << b << std::endl;
							a = b;
						}
					}
				}
			return;
		}
    };

    //=============================================================================
}
