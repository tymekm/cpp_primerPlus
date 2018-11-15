#include "Tv.h"
#include <iostream>

int main()
{
    using std::cout;
    Tv s42;
    cout << "Initial settings for 42\"TV:\n";
    s42.settings();
    s42.onOff();
    s42.chanUp();
    cout << "\nAdjusted settings for 42\" Tv:\n";
    s42.settings();

    Remote grey;
    
    grey.setChan(s42,10);
    grey.volUp(s42);
    grey.volUp(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();
    
    Tv s58(Tv::On);
    s58.setMode();
    grey.setChan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();

    Remote black;
    black.showMode();
    s58.setRemote(black);
    black.showMode();
    
    return 0;
}
