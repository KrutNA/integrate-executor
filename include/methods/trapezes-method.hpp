//
// Created by krutna on 14.11.18.
//

#pragma once

#include "../method.hpp"

class trapezes_method : public method {
    virtual double execute(
            std::unique_ptr<function>&& function,
            const int dimension, const double lowValue, const double topValue);
};


