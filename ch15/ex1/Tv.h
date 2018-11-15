#ifndef TV_H
#define TV_H

class Remote;
class Tv 
{
protected:
public:
    friend class Remote;
    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125)
	:state(s), volume(5), maxChannel(mc),
	 channel(2), mode(Cable), input(TV) {}
    void onOff() {state = (state == On) ? Off : On; }
    bool isOn() const { return state == On; }
    bool volUp();
    bool volDown();
    bool chanUp();
    bool chanDown();
    void setMode() { mode = (mode == Antenna) ? Cable : Antenna; }
    void setInput() { input = (input == TV) ? DVD : TV; }
    void settings() const;
    void setRemote(Remote & r);
private:
    int state;
    int volume;
    int maxChannel;
    int channel;
    int mode;
    int input;
};

class Remote 
{
public:
    friend class Tv;
    enum {Normal, Interactive};
    Remote(int m = Tv::TV)
	:mode(m), state(Normal) {}
    bool volUp(Tv & t) { return t.volUp(); }
    bool volDown(Tv & t) { return t.volDown(); }
    bool chanUp(Tv & t) { return t.chanUp(); }
    bool chanDown(Tv & t) { return t.chanDown(); }
    void setMode(Tv & t) { return t.setMode(); }
    void setInput(Tv & t) { return t.setInput(); }
    void setChan(Tv & t, const int c) { t.channel = c; }
    void showMode() const;
private:
    int mode;
    int state;
};

#endif
