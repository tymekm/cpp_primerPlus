// ex7.cpp
#include <iostream>
#include <cctype>

int main()
{
    int consonant = 0;
    int vowel = 0;
    int other = 0;
    char temp[20];


    std::cout << "Enter words (q to quit):" << std::endl;
    std::cin >> temp;

    while (temp[0] != 'q' && temp[1] != '\n')
    {
	if (isalpha(temp[0]))
	{
	    switch (temp[0])
	    {
		case 'a': 
		case 'A': 
		case 'e': 
		case 'E': 
		case 'y': 
		case 'Y': 
		case 'u': 
		case 'U': 
		case 'i': 
		case 'I': 
		case 'o': 
		case 'O': 
		    vowel++;
		default:
		    consonant++;
	    }
	}
	else
	{
	    other++;
	}
	std::cin >> temp;
    }

    std::cout << vowel << " words beggining with vowels" << std::endl;
    std::cout << consonant << " words beggining with consonants" << std::endl;
    std::cout << other << " others" << std::endl;
}

