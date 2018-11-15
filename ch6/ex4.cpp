// ex4.cpp
#include <iostream>

struct bop 
{
    std::string fullName;
    std::string title;
    std::string bopName;
    int preferance;

};

    bop user[3] = 
    {
	{
	    "Jhonny Bravo",
	    "Cool Dude",
	    "Secret genius",
	    1

	},
	{
	    "Albert Einstein",
	    "Physicist",
	    "Cat lover",
	    0
	},
	{
	    "Bill Gates",
	    "Entrepreneur",
	    "Secret Alien",
	    1
	}
    };

char menu();
void handlePreferance(int choice, int i);

int main()
{
    char choice = menu();

    for (int i = 0; i < 3; i++) 
    {
	switch (choice) {
	    case 'a':
	    case 'A':
		std::cout << user[i].fullName << std::endl;
		break;

	    case 'b':
	    case 'B':
		std::cout << user[i].title << std::endl;
		break;

	    case 'c':
	    case 'C':
		std::cout << user[i].bopName << std::endl;
		break;

	    case 'd':
	    case 'D':
		handlePreferance(user[i].preferance, i);
		break;

	    case 'q':
	    case 'Q':
		std::cout << "Bye!" << std::endl;
		break;
	    default:
		std::cout << "That is not a option!" << std::endl;
		choice = menu();
		i--;
		break;
	}    
    }
}

char menu()
{
    std::cout << 
	"a. display by name\tb. display by title\n" 
	"c. display by BOP name\td. display by preference\n"
	"q, quit"
    << std::endl;
    char choice;
    std::cin >> choice;
    return choice;
}

void handlePreferance(int pref, int i)
{
    switch (pref) {
        case 0:
	    std::cout << user[i].fullName << std::endl;
    	break;
    	
        case 1:
	    std::cout << user[i].title << std::endl;
    	break;
    	
        case 2:
	    std::cout << user[i].bopName << std::endl;
    	break;
    	
    }
}

