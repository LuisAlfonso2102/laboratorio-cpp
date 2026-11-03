#include <iostream>
#include "geometria.h"

int main()
{
    double base{5.0};
    double altura{3.0};

    std::cout << "Area: "
              << calcularAreaRectangulo(base, altura)
              << '\n';

    return 0;
}
