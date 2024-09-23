#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <iomanip>
using namespace std;

class Time{
    private:
    int hour , minute , second;
    public:
    Time(int hr , int min , int sec){
        setTime(hr , min , sec);       //use function to set time 
    }
    void setTime(int h , int m , int s){
        hour = (h >= 0 && h < 24) ? h : 0;
        minute = (m >= 0 && m < 60) ? m : 0;
        second = (s >= 0 && s < 60) ? s : 0;
    }
    void tick(){
        int nextSec=0 , nextMin=0;
        second = (second >= 0 && second < 59) ? second+1 : nextSec++;      //Make sure the time is still in range when time incremented by one second
        minute = (minute+nextSec >= 0 && minute+nextSec < 59) ? minute+nextSec : nextMin++;
        hour = (hour+nextMin >= 0 && hour+nextMin < 23) ? hour+nextMin : 0;
    }
    void printUniversal(){
        cout << "Universal-time: " << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second <<endl;
    }
    void printStandard(){
        cout << "Standard-time: " << ((hour == 0 || hour == 12) ? 12 : hour % 12)<< ":" << setfill( '0' ) << setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM") <<endl;
    }
};

#endif