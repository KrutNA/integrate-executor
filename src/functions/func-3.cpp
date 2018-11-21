//
// Created by krutna on 08.11.18.
//

#include "../../include/function.hpp"
#include "functions/func-3.hpp"

func3::func3() {
    functionText = "f(x) = sin(x) - cos(x)";
};

std::string func3::getText() {
    return functionText;
}

double func3::execute(double x) {
    return
            sin(x) -
            cos(x);
}
