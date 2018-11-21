//
// Created by krutna on 21.11.18.
//

#pragma once
#include <string>
#include "main_texts.hpp"

#ifdef INTEGRAL_EXECUTOR_COLORED
std::string parsingError = "\033[31;1mError occurred while parsing arguments\033[0m";
std::string descriptions[] {
    "\033[1;36mRequired options\033[0m",
    "\033[1;36mAllowed options\033[0m",
    "\033[1;36mFor rectangle method\033[0m"
};
std::string unknownIntegralMethods[] {
    "Unknown\033[1m integral\033[0m method type.",
    "Required: '\033[1mr\033[0m'/'\033[1ms\033[0m'/'\033[1mt\033[0m'"
};
std::string unknownRectangleMethods[] {
    "Unknown\033[1m rectangle\033[0m method type.",
    "Required: '\033[1mr\033[0m'/'\033[1mm\033[0m'/'\033[1ml\033[0m'"
};
std::string inputs[] {
    "\033[0mInput number of function: \033[1;36m",
    "\033[0mInput top value: \033[1;36m",
    "\033[0mInput low value: \033[1;36m"
};
std::string results[] {
        "\033[0mResult: \033[1;36m",
        "\033[0m"
};
std::string funcThemes[] {
    "\033[32;1m",
    "\033[0m"
};
std::string accuracyThemes[] {
        "\033[0mAccuracy: \033[36;1m",
        "\033[0m"
};

#else
std::string parsingError = "Error occurred while parsing arguments";
std::string descriptions[] {
        "Required options",
        "Allowed options",
        "For rectangle method"
};
std::string unknownIntegralMethods[] {
        "Unknown integral method type.",
        "Required: 'r'/'s'/'t'"
};
std::string unknownRectangleMethods[] {
        "Unknown rectangle method type.",
        "Required: 'r'/'m'/'l'"
};
std::string inputs[] {
        "Input number of function: ",
        "Input top value: ",
        "Input low value: "
};
std::string results[] {
        "Result: ",
        ""
};
std::string funcThemes[] {
    "",
    ""
};
std::string accuracyThemes[] {
        "Accuracy: ",
        ""
};
#endif

void noColorTexts() {
    parsingError = "Error occurred while parsing arguments";
    descriptions[0] = "Required options";
    descriptions[1] = "Allowed options";
    descriptions[2] = "For rectangle method";
    unknownIntegralMethods[0] = "Unknown integral method type.";
    unknownIntegralMethods[1] = "Required: 'r'/'s'/'t'";
    unknownRectangleMethods[0] = "Unknown rectangle method type.";
    unknownRectangleMethods[1] ="Required: 'r'/'m'/'l'";
    inputs[0] = "Input number of function: ";
    inputs[1] = "Input top value: ";
    inputs[2] = "Input low value: ";
    results[0] = "Result: ";
    results[1] = "";
    funcThemes[0] = "";
    funcThemes[1] = "";
    accuracyThemes[0] = "Accuracy: ";
    accuracyThemes[1] = "";
}
