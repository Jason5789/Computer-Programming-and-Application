#include <iostream>
using namespace std;

class Date{
    private:
    int month , day , year;
    int judgeLeapYear();
    int judgeMonth();
    public:
    Date( int = 1 , int = 1 , int = 2000 );
    void setDate(int,int,int);
    void nextDay();
    void printDate() const;
};

//constructor
Date::Date(int m , int d , int y){
    setDate(m , d , y);
}

//set the date
void Date::setDate(int m , int d , int y){
    month = (m >= 1 && m <= 12) ? m : 1;
    year = y;
    day = (d >= 1 && d <= judgeMonth()) ? d : 1;  
}

//leap year will return 1, common year will return 0
int Date::judgeLeapYear(){
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
int Date::judgeMonth(){
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2 && judgeLeapYear() == 1)  //if this year is leap year
        return 29;
    else if (month == 2 && judgeLeapYear() == 0)  //if this year is common year
        return 28;
    else
        return 31;
}

//increment the day by one
void Date::nextDay(){
    for (int i=1 ; i<=5 ; i++){
        int nextMonth=0 , nextYear=0;
        day = (day >= 1 && day < judgeMonth()) ? day+1 : ++nextMonth;
        month = (month+nextMonth >= 1 && month+nextMonth <= 12) ? month+nextMonth : ++nextYear;
        year += nextYear;
        cout << i << " Day(s) Later: ";
        printDate();
    }
}

//print the date by mm/dd/yy
void Date::printDate() const{
    cout << month << '/' << day << '/' << year <<endl;
}

int main(){
//D1 will test the increment the day by one in a loop, from February in a common year
    cout << "[TEST1]\nInitial Date: ";
    Date D1(2,28,2021);
    D1.printDate();
    cout << "---Increment the day---" <<endl;
    D1.nextDay();

//D2 will test the increment the day by one in a loop, from February in a leap year
    cout << "\n[TEST2]\nInitial Date: ";
    Date D2(2,28,2020);
    D2.printDate();
    cout << "---Increment the day---" <<endl;
    D2.nextDay();

//D3 will test the increment the day by one in a loop, will increment into the next year
    cout << "\n[TEST3]\nInitial Date: ";
    Date D3(12,31,2022);
    D3.printDate();
    cout << "---Increment the day---" <<endl;
    D3.nextDay();

//D4 will test the error date, it will adjustment to correct numbers
    cout << "\n[TEST4]\nInitial Date: ";
    Date D4(500,500,500);
    D4.printDate();
    cout << "---Increment the day---" <<endl;
    D4.nextDay();
}