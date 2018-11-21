#define INTEGRAL_EXECUTOR_COLORED
#include <iostream>
#include <array>
#include <boost/program_options.hpp>

#include "function.hpp"
#include "func-1.hpp"
#include "func-2.hpp"
#include "func-3.hpp"
#include "func-4.hpp"
#include "func-5.hpp"
#include "integral.hpp"
#include "function.hpp"
#include "main_texts.hpp"

namespace po = boost::program_options;

struct nonnegative {
    unsigned value;
};

void validate(boost::any& v, const std::vector<std::string>& values, nonnegative*, int)
{
    using namespace boost::program_options;
    validators::check_first_occurrence(v);

    std::string const& s = validators::get_single_string(values);
    if (s[0] == '-') {
        throw validation_error(validation_error::invalid_option_value);
    }

    v = boost::lexical_cast<unsigned>(s);
}

// Defining program options
std::unique_ptr< po::variables_map > initOptions(int argc, char *argv[], std::vector<po::options_description>* opts) {
    std::unique_ptr< po::variables_map > vm (new po::variables_map);

    opts->at(0).add_options()
            ("method,m", po::value<char>(), "using method:\nr - for rectangle\nt - for trapeze\ns - for Simpson's method");
    opts->at(1).add_options()
            ("help,h", "produce help message")
            ("funcs,f", "produce functions list")
            ("func,F", po::value<nonnegative>(), "number of function");
    opts->at(2).add_options()
            ("type,t", po::value<char>(), "type of rectangle method:\nl - for left\nt - for middle\nr - for right")
            ("accuracy,a", po::value<nonnegative>(), "accuracy of calculating integral, default: 6")
            ("no-color", "disabling color for current execution");

    auto new_opts = new po::options_description("\033[1;36mOptions:");
    new_opts->add(opts->at(0)).add(opts->at(1)).add(opts->at(2));

    try {
        po::store(po::parse_command_line(argc, argv, *new_opts), *vm);
        po::notify(*vm);
    } catch (boost::program_options::unknown_option& e) {
        std::cout << parsingError << std::endl;
        std::cout << "\twhat(): " << e.what() << std::endl;
        delete new_opts;
        vm.release();
        return nullptr;
    } catch (boost::program_options::error& e) {

        std::cout << opts->at(0) << opts->at(1) << opts->at(2) <<
                  parsingError << std::endl <<
                  "\twhat(): " << e.what() << std::endl;
        delete new_opts;
        vm.release();
        return nullptr;
    }
    delete new_opts;
    return vm;
}

// Defining functions
std::vector< std::unique_ptr< function > > initFunctions () {
    std::vector< std::unique_ptr< function > > functions;
    functions.push_back(std::unique_ptr<function> (new func1));
    functions.push_back(std::unique_ptr<function> (new func2));
    functions.push_back(std::unique_ptr<function> (new func3));
    functions.push_back(std::unique_ptr<function> (new func4));
    functions.push_back(std::unique_ptr<function> (new func5));
    return functions;
};

int main(int argc, char *argv[]) {

    double topValue, lowValue;
    char methods[] { 'r', 't', 's' };
    char rectTypes[] { 'l', 'm', 'r' };
    char usingMethod = '?';
    char rectType = '?';
    unsigned int accuracy = 6;
    unsigned int numberOfFunction = 0;

    std::vector< po::options_description > opts = {
            po::options_description(descriptions[0]),
            po::options_description(descriptions[1]),
            po::options_description(descriptions[2])
    };
    double integralResult;
    auto vm = initOptions(argc, argv, &opts);
    auto funcs = initFunctions();
    auto currentIntegral = integral();

    if (vm != nullptr && vm->count("no-color")) {
        noColorTexts();
        opts.clear();
        opts.emplace_back(po::options_description(descriptions[0]));
        opts.emplace_back(po::options_description(descriptions[1]));
        opts.emplace_back(po::options_description(descriptions[2]));
        vm = initOptions(argc, argv, &opts);
    }
    if (vm == nullptr || argc == 1) {
        std::cout << opts[0] << opts[1] << opts[2];
        return 1;
    }
    if (argc == 2 && (vm->count("no-color") || vm->count("help")) ||
        argc == 3 && (vm->count("no-color") || vm->count("help"))) {
        std::cout << opts[0] << opts[1] << opts[2];
        return 0;
    }
    if (vm->count("help")) {
        std::cout << opts[0] << opts[1] << opts[2];
    }
    if (vm->count("funcs")) {
        for ( unsigned long i = 0; i < funcs.size(); ++i ) {
            std::cout << "   " << i << ")\t" << funcThemes[0] << funcs.at(i)->getText() << funcThemes[1] << std::endl;
        }
    }
    if (vm->count("accuracy"))
        accuracy = (*vm)["accuracy"].as<unsigned int>();
    if (vm->count("method") &&
        std::find(std::begin(methods), std::end(methods), (*vm)["method"].as<char>())) {

        usingMethod = (*vm)["method"].as<char>();
        if (usingMethod == 'r' && vm->count("type") &&
            std::find(std::begin(rectTypes), std::end(rectTypes), (*vm)["type"].as<char>())) {

            rectType = (*vm)["type"].as<char>();
        } else if (usingMethod == 'r') {
            std::cout <<
                      parsingError << std::endl <<
                      unknownRectangleMethods[0] << std::endl <<
                      unknownRectangleMethods[1] << std::endl;
            return 1;
        }
    } else {
        std::cout <<
                  parsingError << std::endl <<
                  unknownIntegralMethods[0] << std::endl <<
                  unknownIntegralMethods[1] << std::endl;
        return 1;
    }
    // Reading count of functions
    if (vm->count("func") && (*vm)["func"].as<unsigned int>() < funcs.size())
        numberOfFunction = (*vm)["func"].as<unsigned int>();
    else {
        std::cout << inputs[0];
        std::cin >> numberOfFunction;
        while (std::cin.fail() || numberOfFunction > funcs.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << inputs[0];
            std::cin >> numberOfFunction;
        }
    }
    std::cout <<
              funcThemes[0] << funcs.at(numberOfFunction)->getText() << funcThemes[1] << std::endl <<
              accuracyThemes[0] << accuracy << accuracyThemes[1] << std::endl;

    // Reading top value
    std::cout << inputs[1];
    std::cin >> topValue;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << inputs[1];
        std::cin >> topValue;
    }

    // Reading low value
    std::cout << inputs[2];
    std::cin >> lowValue;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << inputs[2];
        std::cin >> lowValue;
    }


    integralResult = currentIntegral.execute(std::move(funcs.at(numberOfFunction)), topValue, lowValue, usingMethod, rectType, accuracy);
    if (integralResult == NAN) {
        return 1;
    }
    std::cout << results[0] << integralResult << results[1] <<std::endl;
    vm.release();
    return 0;
}