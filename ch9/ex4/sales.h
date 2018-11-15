#ifndef SALES_H
#define SALES_H
namespace SALES
{
    const int QUARTERS = 4;
    struct Sales
    {
	double sales[QUARTERS];
	double average;
	double max;
	double min;
    };

//void setSales(Sales& s, const array<double> ar, int n);
void setSales(Sales& s, const double arr[], int n);

void setSales(Sales& s);

void showSales(const Sales& s);
}
#endif
