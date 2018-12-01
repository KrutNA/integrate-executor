//
// Created by krutna on 08.11.18.
//

#include <memory>
#include <method.hpp>
#include "function.hpp"
#include "integral.hpp"
#include "left-rectangles-method.hpp"
#include "middle-rectangles-method.hpp"
#include "right-rectangles-method.hpp"
#include "simpsons-method.hpp"
#include "trapezes-method.hpp"


double integral::execute(std::unique_ptr<function>&& func, double topValue, double lowValue, char type, char rectType, unsigned int accuracy) {

    if (topValue < lowValue)
        std::swap(lowValue, topValue);

    int dimension = static_cast<int>(std::ceil(std::max(std::log10(topValue), std::log10(lowValue))) - accuracy);

    std::unique_ptr<method> selectedMethod = nullptr;

    if (std::tolower(type) == 'r') {
        if (std::tolower(rectType) == 'l')
            selectedMethod = std::make_unique<left_rectangles_method>();
        else if (std::tolower(rectType) == 'm')
            selectedMethod = std::make_unique<middle_rectangles_method>();
        else if (std::tolower(rectType) == 'r')
            selectedMethod = std::make_unique<right_rectangles_method>();
        else {
            return NAN;
        }
    } else if (std::tolower(type) == 't') {
        selectedMethod = std::make_unique<trapezes_method>();
    } else if (std::tolower(type) == 's') {
        selectedMethod = std::make_unique<simpsons_method>();
    } else {
        return NAN;
    }
    return selectedMethod->execute(
            std::move(func), dimension,
            lowValue, topValue);
}

