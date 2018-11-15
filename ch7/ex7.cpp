// ex7.cpp
#include <iostream>
const int Max = 5;

double * fillArray(double * begin, const double * end);
void showArray(double * begin, const double * end);
void revalue(double r, double * begin, const double * end);

int main()
{
    double properties[Max];

    double * size = fillArray(properties, properties + Max);
    if (size > properties)
    {
	std::cout << "Enter revaluation factor: ";
	double factor;
	while (!(std::cin >> factor))
	{
	    std::cin.clear();
	    while (std::cin.get() != '\n')
	    {
		continue;
	    }
	    std::cout << "Bad input, please enter a number:";
	}
	std::cout << size << std::endl;
	revalue(factor, properties, size);
	showArray(properties, size);
    }
    std::cout << "Done\n";
    std::cin.get();
    std::cin.get();
    return 0;
}

double * fillArray(double * begin, const double * end)
{
    double temp;
    double * pt;
    int i = 0;
    for (pt = begin; pt != end; pt++, i++) 
    {
	std::cout << "Enter value #" << (i + 1) << ": ";
	std::cin >> temp;
       if (!std::cin)
       {
	    std::cin.clear();
	    while (std::cin.get() != '\n')
	    {
		continue;
	    }
	    std::cout << "Bad input, input process terminated.";
	    break;
       }
       else if (temp < 0)
       {
	   break;
       }
       *pt = temp;
    }
    return pt;
}

void showArray(double * begin, const double * end)
{
    const double * pt;
    for (pt = begin; pt != end; pt++) 
    {
	std::cout << "Property #" << (pt + 1) << ": $";
	std::cout << *pt << std::endl;
    }
}

void revalue(double r, double * begin, const double * end)
{
    double * pt;
    for (pt = begin; pt != end; pt++) 
    {
        *pt *= r;
    }
}

