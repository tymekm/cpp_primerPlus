#include "Employee.h"
#include <iostream>

int main()
{
    using std::cout;

    Employee em("Trip", "Harris", "Thumper");
    cout << em << '\n';
    em.ShowAll();
    Manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << '\n';
    ma.ShowAll();

    Fink fi("Matt", "Oggs", "Oliver", "Juno Barr");
    cout << fi << '\n';
    fi.ShowAll();
    HighFink hf(ma, "Kurly Kew");
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
    std::cin.get();
    std::cin.ignore();
    HighFink hf2;
    hf2.SetAll();
    hf2.ShowAll();

    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++) 
    {
        tri[i]->ShowAll();
    }
    return 0;
}
