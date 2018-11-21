//
// Created by krutna on 08.11.18.
//

#pragma once
#include <string>
#include <boost/math/special_functions.hpp>

class function {
    std::string functionText;
public:
    virtual std::string getText() = 0;

    virtual double execute(double x) = 0;
};
