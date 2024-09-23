#include <iostream>
#include <iomanip>
using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time( int = 0 , int = 0 , int = 0 );
        Time &setTime( int , int , int );
        Time &setHour( int );
        Time &setMinute( int );
        Time &setSecond( int );
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        int getFromMidnight() const;
        void printUniversal() const;       
        void printStandard() const;  
};

Time::Time( int hr , int min , int sec ){
    setTime( hr , min , sec );
}

//set values of hour, minute and hour
Time &Time::setTime( int h , int m , int s){
    setHour( h );
    setMinute( m );
    setSecond( s );
    return *this;
}

//set hour and change to seconds
Time &Time::setHour( int h ){
    hour = (( h >= 0 && h < 24 ) ? h : 0)*3600;
    return *this;
}

//set minute and change to seconds
Time &Time::setMinute( int m ){
    minute = (( m >= 0 && m < 60 ) ? m : 0)*60;
    return *this;
}

//set seconds
Time &Time::setSecond( int s ){
    second = ( s >= 0 && s < 60 ) ? s : 0;
    return *this;
}

//get hour
int Time::getHour() const{
    return hour;
}

//get minute
int Time::getMinute() const{
    return minute;
}

//get second
int Time::getSecond() const{
    return second;
}

//get seconds since midnight
int Time::getFromMidnight() const{
    return hour+minute+second;
}

//print time in universal-time format
void Time::printUniversal() const{
    cout << "Universal-time: " << setfill('0') << setw(2) << getFromMidnight()/3600 << ":" << setw(2) << getFromMidnight()%3600/60 << ":" << setw(2) << getFromMidnight()%60 <<endl;
}

//print time in standard-time format
void Time::printStandard() const{
    cout << "Standard-time: " << ((getFromMidnight()/3600 == 0 || getFromMidnight()/3600 == 12) ? 12 : getFromMidnight()/3600 % 12)<< ":";
    cout << setfill( '0' ) << setw(2) << getFromMidnight()%3600/60 << ":" << setw(2) << getFromMidnight()%60 << ( getFromMidnight()/3600 < 12 ? " AM" : " PM") <<endl;
}

int main(){
    Time t;

//no visible change in functionality to the clients but represent the time internally as the number of seconds since midnight
    t.setHour( 18 ).setMinute( 30 ).setSecond( 22 );

    t.printUniversal();
    t.printStandard();

    t.setTime(20,20,20).printStandard();

    return 0;
}