//
// Created by krutna on 08.11.18.
//

#pragma once

class integral {
    std::unique_ptr<function> func;

    void trapezes();
public:
    double result;
    integral() = default;

    double execute(
            std::unique_ptr<function>&& func,
            double topValue, double lowValue,
            char type,  char rectType = 'u', unsigned int accuracy = 6);
};