#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    Sales sales2017, sales2018;

    double salesArr[QUARTERS] = {5000.12, 2131.12, 9083.09, 1235.84};
    setSales(sales2017 , salesArr, QUARTERS);
    showSales(sales2017);

    setSales(sales2018);
    showSales(sales2018);
}
