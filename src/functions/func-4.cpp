//
// Created by krutna on 08.11.18.
//

#include "function.hpp"
#include "func-4.hpp"

func4::func4() {
    functionText = "f(x) = x^2 + 8x + 16";
};

std::string func4::getText() {
    return functionText;
}

double func4::execute(double x) {
    return
            boost::math::pow<2>(x) +
            8 * x +
            16;
}
