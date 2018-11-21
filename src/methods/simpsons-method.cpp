//
// Created by krutna on 14.11.18.
//

#include "methods/simpsons-method.hpp"

double simpsons_method::execute(
        std::unique_ptr<function>&& function,
        const int dimension, const double lowValue, const double topValue) {
    double it = std::pow(10, dimension);
    auto cnt = static_cast<long long>( (topValue - lowValue) / it );
    double integral = 0;
    for (auto i = 1; i < cnt - 1; i += 2) {
        integral = integral +
                function->execute( lowValue + it * (i-1) ) +
                4 * function->execute( lowValue + it * i ) +
                function->execute( lowValue + it * (i+1) );
    }
    integral = integral * it / 3;
    return integral;
}