#include "Tv.h"
#include <iostream>

bool Tv::volUp()
{
    if (volume < MaxVal)
    {
	volume ++;
	return true;
    }
    else
	return false;
}

bool Tv::volDown()
{
    if (volume > MaxVal)
    {
	volume --;
	return true;
    }
    else
	return false;
}

bool Tv::chanUp()
{
    if (channel < maxChannel)
    {
	volume ++;
	return true;
    }
    else
	return false;
    
}

bool Tv::chanDown()
{
    if (channel > maxChannel)
    {
	volume --;
	return true;
    }
    else
	return false;

}

void Tv::settings() const
{
    using std::cout;
    cout << "TV is " << (state == Off ? "Off" : "On") << '\n';
    if (state == On)
    {
	cout << "Volume settings = " << volume << '\n';
	cout << "Channel settings = " << channel << '\n';
	cout << "Mode = " << (mode == Antenna? "antenna" : "cable") << '\n';
	cout << "Input = " << (input == TV? "TV" : "DVD") << '\n';
    }
}

void Tv::setRemote(Remote & r)
{
    if (state == On)
	r.state = (r.state == r.Normal) ? r.Interactive : r.Normal;
}

void Remote::showMode() const
{
    std::cout << "Remote in state: " << 
	(state == Normal? "Normal" : "Interactive") << '\n';
}
