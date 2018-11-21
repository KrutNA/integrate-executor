//
// Created by krutna on 08.11.18.
//

#include "function.hpp"
#include "func-5.hpp"

func5::func5() {
    functionText = "f(x) = (sin(x))^2 + (cos(x))^2";
};

std::string func5::getText() {
    return functionText;
}

double func5::execute(double x) {
    return
            boost::math::pow<2>(sin(x)) +
            boost::math::pow<2>(cos(x));
}
