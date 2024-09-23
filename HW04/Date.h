#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date{
    private:
    int month , day , year;
    public:
    Date(int m , int d , int y){
        setMonth(m);
        setDay(d);
        setYear(y);
    }
    void setMonth(int m_set){
        month = ( m_set >= 1 && m_set <=12 ) ? m_set : 1;
    }

    int getMonth(){        //get the month
        return month;
    }

    void setDay(int d_set){      //set the day
        day = d_set;
    }
     
    int getDay(){         //get the day
        return day;
    }

    void setYear(int y_set){     //set the year
        year = y_set;
    }

    int getYear(){         //get the year
        return year;
    }

    void displayDate(){                //display the date by mm/dd/yy
        cout << getMonth() << "/" << getDay() << "/" << getYear() <<endl;
    }
};

#endif