#include <iostream>
#include <iomanip>
using namespace std;

class DateAndTime{
    private:
    int hour , minute , second , month , day , year;
    int judgeLeapYear();
    int judgeMonth();
    public:
    DateAndTime(int = 1 , int = 1 , int = 2000 , int = 0 , int = 0 , int =0);
    void setDateAndTime(int , int , int , int , int , int);
    void tick();
    void nextDay();
    void printUniversal() const;
    void printStandard() const;
};

//constructor
DateAndTime::DateAndTime(int month_in , int day_in , int year_in , int hr , int min , int sec){
    setDateAndTime(month_in , day_in , year_in , hr , min , sec);       //use function to set time 
}

//set the date and time
void DateAndTime::setDateAndTime(int m_date , int d , int y , int h , int m_time , int s){
    month = (m_date >= 1 && m_date <= 12) ? m_date : 1;
    year = y;
    day = (d >= 1 && d <= judgeMonth()) ? d : 1;
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m_time >= 0 && m_time < 60) ? m_time : 0;
    second = (s >= 0 && s < 60) ? s : 0;
    
}

//leap year will return 1, common year will return 0
int DateAndTime::judgeLeapYear(){
    if(year%400 == 0)
        return 1;
    else if(year%100 == 0)
        return 0;
    else if(year%4 == 0)
        return 1;
    else
        return 0;
}

//return the days of the month
int DateAndTime::judgeMonth(){
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2 && judgeLeapYear() == 1)  //if this year is leap year
        return 29;
    else if (month == 2 && judgeLeapYear() == 0)  //if this year is common year
        return 28;
    else
        return 31;
}

void DateAndTime::nextDay(){
    int nextMonth=0 , nextYear=0;
    day = (day >= 1 && day < judgeMonth()) ? day+1 : ++nextMonth;
    month = (month+nextMonth >= 1 && month+nextMonth <= 12) ? month+nextMonth : ++nextYear;
    year += nextYear;
}

void DateAndTime::tick(){
    int nextSec=0 , nextMin=0 ,newDay=0;
    second = (second >= 0 && second < 59) ? second+1 : nextSec++;      //Make sure the time is still in range when time incremented by one second
    minute = (minute+nextSec >= 0 && minute+nextSec < 59) ? minute+nextSec : nextMin++;
    hour = (hour+nextMin >= 0 && hour+nextMin < 23) ? hour+nextMin : newDay++;

    if (newDay == 1)    //increments into next day
        nextDay();      //call the nextDay function
}

//print time in standard-time format and then print date
void DateAndTime::printStandard() const{
    cout << month << '/' << day << '/' << year <<"   ";
    cout << "Standard-time: " << ((hour == 0 || hour == 12) ? 12 : hour % 12)<< ":" << setfill( '0' ) << setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM") <<endl;
    
}

//print time in universal-time format and then print date
void DateAndTime::printUniversal() const{
    cout << month << '/' << day << '/' << year << "   ";
    cout << "Universal-time: " << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second <<endl;
    
}

int main(){
//T1 will test into next day after incrementing one second in the leap year in February(2/28/2020 to 2/29/2020), print in standard-time and universal-time, print before and after
    DateAndTime T1(02,28,2020,23,59,59);
    cout << "[TEST1]" <<endl;
    T1.printStandard();
    T1.printUniversal();
    T1.tick();
    cout << "----------After 1 tick----------" <<endl;
    T1.printStandard();
    T1.printUniversal();

//T2 will test into next month after incrementing one second in the common year in February(2/28/2021 to 3/1/2021), print in standard-time and universal-time, print before and after
    DateAndTime T2(02,28,2021,23,59,59);
    cout << "\n[TEST2]" <<endl;
    T2.printStandard();
    T2.printUniversal();
    T2.tick();
    cout << "----------After 1 tick----------" <<endl;
    T2.printStandard();
    T2.printUniversal();

//T3 will test into next year after incrementing one second(12/31/2022 to 1/1/2023), print in standard-time and universal-time, print before and after
    DateAndTime T3(12,31,2022,23,59,59);
    cout << "\n[TEST3]" <<endl;
    T3.printStandard();
    T3.printUniversal();
    T3.tick();
    cout << "----------After 1 tick----------" <<endl;
    T3.printStandard();
    T3.printUniversal();

//T4 will test the error date and time, it will adjustment to correct numbers, and then print in standard-time and universal-time, print before and after
    DateAndTime T4(100,100,100,100,100,100);
    cout << "\n[TEST4]" <<endl;
    T4.printStandard();
    T4.printUniversal();
    T4.tick();
    cout << "----------After 1 tick----------" <<endl;
    T4.printStandard();
    T4.printUniversal();
}