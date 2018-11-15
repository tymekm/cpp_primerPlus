#include <iostream>
#include "time.h"

int main()
{

    Time aida(3,35);
    Time tosca(2, 48);
    Time temp;

    std::cout << "Aida and Tosca:\n";
    std::cout << aida << "; " << tosca;;
    temp = aida + tosca;
    std::cout << "Aida + Tosca = " << temp;
    temp = aida * 1.17;
    std::cout << "Aida * 1.17 = " << temp;
    std::cout << "10.0 * Tosca = " << 10.0 * tosca;

    return 0;
}
