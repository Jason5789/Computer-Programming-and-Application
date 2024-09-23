#include <iostream>
#include "Date.h"
using namespace std;

int main(){
//test the correct date, display by month/day/year
    Date d1(3,16,2022);
    cout << "[D1] ";
    d1.displayDate();
    
//test the date if the month is wrong, display by month/day/year
    Date d2(30,21,2035);
    cout << "[D2] ";
    d2.displayDate();

    return 0;
}