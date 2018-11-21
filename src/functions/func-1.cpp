//
// Created by krutna on 08.11.18.
//

#include "function.hpp"
#include "func-1.hpp"

func1::func1() {
    functionText = "f(x) = 6x^5 + 24x^3 + 42x";
};

std::string func1::getText() {
    return functionText;
}

double func1::execute(double x) {
    return
            6 * boost::math::pow<5>(x) +
            24 * boost::math::pow<3>(x) +
            42 * x;
}