// ex2.cpp
#include <iostream>
#include <string>

struct candybar
{
    std::string brand;
    double weight;
    int calories;
};

void fillStruct
(
    candybar & bar,
    std::string brand = "Millennium Munch",
    double weight = 2.85,
    int calories = 350
);

void showBar(const candybar & bar);

int main()
{
    candybar myBar;
    std::string brand;
    double weight;
    int calories;
    fillStruct(myBar);
    showBar(myBar); 
    return 0;
}

void fillStruct
(
    candybar & bar,
    std::string brand,
    double weight,
    int calories
)
{
    bar.brand = brand;
    bar.weight = weight;
    bar.calories = calories;
}

void showBar(const candybar & bar)
{
    std::cout << "Your favorite candybar is:\n";
    std::cout << bar.brand << '\n' << bar.weight << " gr\n";
    std::cout << bar.calories << " calories\n";
}
