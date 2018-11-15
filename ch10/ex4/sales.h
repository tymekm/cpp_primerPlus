#ifndef SALES_H
#define SALES_H
namespace SALES
{
    class Sales
    {
    public:
	Sales();
        Sales(const double arr[], int n);
	void showSales();
	enum {QUARTERS = 4};
    
    private:
	double sales[QUARTERS];
	double average;
	double max;
	double min;
    };
}
#endif
