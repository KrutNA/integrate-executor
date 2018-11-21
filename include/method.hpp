//
// Created by krutna on 14.11.18.
//

#pragma once

#include <function.hpp>

class method {
public:
    virtual double execute(std::unique_ptr<function>&& function,
                   const int dimension, const double lowValue, const double topValue) = 0;
    std::string name;
};
