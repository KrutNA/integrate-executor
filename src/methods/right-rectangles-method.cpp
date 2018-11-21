//
// Created by krutna on 14.11.18.
//

#include "methods/right-rectangles-method.hpp"

double right_rectangles_method::execute(
        std::unique_ptr<function>&& function,
        const int dimension, const double lowValue, const double topValue) {
    double it = std::pow(10, dimension);
    auto cnt = static_cast<long long>( (topValue - lowValue) / it );
    double integral = 0;
    for (auto i = 0; i <= cnt - 1; ++i) {
        integral += function->execute( lowValue + it * ( i + 0.5 ) );
    }
    integral *= it;
    return integral;
}