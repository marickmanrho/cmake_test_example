// A simple program that computes the square root of a number
#include <iostream>
#include <string>

#include "MathFunctions.h"

int main(int argc, char *argv[])
{
    // convert input to double
    const double inputValue = std::stod(argv[1]);

    // which square root function should we use?
    const double outputValue = mysqrt(inputValue);

    std::cout << "The square root of " << inputValue << " is " << outputValue
              << std::endl;
    return 0;
}
