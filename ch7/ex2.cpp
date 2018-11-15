// ex2.cpp
#include <iostream>

void getScores(int arr[]);
double calcAvg(const int arr[]);
void display(const int arr[], double navg); 
int scoreArr[10];

int main()
{
    getScores(scoreArr);
    double navg = calcAvg(scoreArr);
    display(scoreArr, navg);
    return 0;
}

void getScores(int arr[])
{
    std::cout << "Enter you scores (q to exit)" << std::endl;

    for (int i = 0; i < 10; i++) 
    {
	std::cin >> arr[i];
	if (arr[i] == 'q')
	{
	    std::cout << "Exiting" << std::endl;
	    break;
	}
    }
}

double calcAvg(const int arr[])
{
    int sum = 0;
    for (int i = 0; i < 10; i++) 
    {
       sum += arr[i]; 
    }
    return (sum / 10);
}

void display(const int arr[], double avg)
{
    for (int i = 0; i < 10; i++) 
    {
	std::cout << arr[i] << " ";
    }
    std::cout << "= " << avg << "\n";
}
