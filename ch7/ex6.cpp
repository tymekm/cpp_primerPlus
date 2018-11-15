// ex6.cpp
#include <iostream>

int fillArray(double arr[], int size);
void showArray(const double arr[], int size);
void reverseArray(double arr[], int size);

int main()
{
    int size;
    std::cout << "How many numbers do you wish to enter? __\b\b";
    std::cin >> size;
    double arr[size];
    size = fillArray(arr, size);
    showArray(arr, size);
    reverseArray(arr, size);
    showArray(arr, size);
    reverseArray(arr + 1, size - 2);
    showArray(arr, size);
}

int fillArray(double arr[], int size)
{
    int numbersEntered = 0;

    for (int i = 0; i < size; i++) 
    {
	std::cout << "Enter #" << i << " _\b";    
	std::cin >> arr[i];
	if (std::cin)
	{
	    numbersEntered ++;
	}
	else
	{
	    std::cout << "Illegal character entered, aborting filling array" << std::endl;
	    std::cin.clear();
	}
    }
    return numbersEntered;;
}

void showArray(const double arr[], int size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b]" << std::endl;
}

void reverseArray(double arr[], int size)
{
    double tempArr[size];    

    for (int i = size - 1, j = 0; j < size; i--, j++) 
    {
	tempArr[j] = arr[i];	    
	std::cout << i << " + "<< j << std::endl;
    }

    for (int i = 0; i < size; i++) 
    {
        arr[i] = tempArr[i];
    }
}
