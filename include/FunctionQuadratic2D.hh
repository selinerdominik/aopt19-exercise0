#pragma once

#include <iostream>
#include "FunctionBase.hh"

//== NAMESPACES ===================================================================

namespace AOPT {

    //== CLASS DEFINITION =========================================================

    class FunctionQuadratic2D : public FunctionBase {
    public:
        // f(x,y) = 0.5(x^2 + gamma *y^2)

        // constructor
        FunctionQuadratic2D(const double _gamma = 1)
                : FunctionBase(), gamma_(_gamma) {}

        // number of unknowns
        inline virtual int n_unknowns() { return 2; }

        // funcion evaluation
        inline virtual double f(const Vec &_x) {
            //------------------------------------------------------//
            //Todo: implement the function f(x,y) = 0.5(x^2 + gamma *y^2)
            //------------------------------------------------------//
			double f;
			double x1 = _x[0];
			double x2 = _x[1];
			f = 0.5 * (x1 * x1 + gamma_ * x2 * x2);
			return f;
            //------------------------------------------------------//
        }

        // gradient evaluation
        inline virtual void grad_f(const Vec &_x, Vec &_g) {
        }

        // hessian matrix evaluation
        inline virtual void hess_f(const Vec &_x, Mat &_H) {
        }

        // initial point for optimization
        inline virtual void initial_x(Vec &_x) {
        }

        // callback that is called after optimization finished
        inline virtual void handle_result(const Vec &_x) {
            std::cerr << "solution converged to x = " << std::endl << _x << std::endl;
        }

    private:
        double gamma_;
    };

//=============================================================================
}
