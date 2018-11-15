#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    double salesArr[Sales::QUARTERS] = {5000.12, 2131.12, 9083.09, 1235.84};

    Sales sales2017 {salesArr, Sales::QUARTERS};
    sales2017.showSales();

    Sales sales2018;
    sales2018.showSales();
}
