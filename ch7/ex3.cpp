// ex3.cpp
#include <iostream>

struct box
{
    char maker[40];
    float height;
    float width;
    float lenght;
    float volume;
};

void getVolume(box * pf);
void display(box box1);

int main()
{
    box box1 = 
    {
	"FedEx",
	10,
	20,
	50
    };
    getVolume(&box1);
    display(box1) ;
    return 0;
}

void getVolume(box * pf)
{
    pf->volume = pf->height * pf->lenght * pf->width ;
}

void display(box box1)
{
   std::cout << "Maker: " << box1.maker << "\nHeight: " << box1.height <<
    "\nWidth: " << box1.width << "\nLenght: " << box1.lenght << "\nVolume: " << box1.volume
   << std::endl; 
}
