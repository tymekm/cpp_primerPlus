#include <iostream>
#include <cstring>

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter characters closing with a \"$\"\n";
    char input[30];
    cin.getline(input, 30, '$');

    cout << "Characters entered: " << strlen(input);
}

