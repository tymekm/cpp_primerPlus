// ex9.cpp
#include <iostream>
#include <string>

struct student
{
    std::string fullName;
    std::string hobby;
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
    std::cout << "Enter class size: __\b\b";
    int class_size;
    std::cin >> class_size;
    while (std::cin.get() != '\n')
	continue;

    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++) 
    {
	display1(ptr_stu[i]);
	display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    std::cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n)
{
    int i;
    for (i = 0; i < n; i++) 
    {
	std::cout << "Enter information for student #" << i + 1 << "\n";    
	std::cout << "Full name:__________\b\b\b\b\b\b\b\b\b\b";
	std::cin.ignore();
	std::getline(std::cin, pa[i].fullName);
	if (pa[i].fullName.empty())
	{
	    std::cout << "Entered empty line, aborting...";
	    break;
	}
	std::cout << "Hobby:__________\b\b\b\b\b\b\b\b\b\b";
	std::getline(std::cin, pa[i].hobby);
	std::cout << "OOP level:___\b\b";
	std::cin >> pa[i].ooplevel;
    }
    return i;
}

void display1(student st)
{
    std::cout << "\nFull name: " << st.fullName;
    std::cout << "\nHobby: " << st.hobby;
    std::cout << "\nOOP level: " << st.ooplevel << "\n\n";
}

void display2(const student * ps)
{
    std::cout << "\nFull name: " << ps->fullName;
    std::cout << "\nHobby: " << ps->hobby;
    std::cout << "\nOOP level: " << ps->ooplevel << "\n\n";
}

void display3(const student pa[], int n)
{
    for (int i = 0; i < n; i++) 
    {
	std::cout << "\nFull name: " << pa->fullName;
	std::cout << "\nHobby: " << pa->hobby;
	std::cout << "\nOOP level: " << pa->ooplevel << "\n\n";
    }    
}
