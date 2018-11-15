// ex3.cpp
#include <iostream>
char menu();

int main()
{
    switch(menu())
    {
	    case 'c':
    case 'C':
	std::cout << "a Carnivore eats meat\nThe more you know!" << std::endl;
	break;

    case 't':
    case 'T':
	std::cout << "Trees grow\nThe more you know!" << std::endl;
	break;

    case 'p':
    case 'P':
	std::cout << "A piano is a instrument\nThe more you know!" << std::endl;
	break;

    case 'g':
    case 'G':
	std::cout << "Life is just a game\nThe more you know!" << std::endl;
	break;
    default:
	std::cout << "That is not a option!\n" << std::endl;
	main();
    }
}

char menu()
{
    std::cout << 
	"Please choose one of the below choices\n" <<
	"c) carnivore		p) pianist\n" <<
	"t) tree 		g) game\n" <<
	"Choose c, p ,t or g: _\b"
    << std::endl;
    char choice;
    std::cin >> choice;
    return choice;
}
