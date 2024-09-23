#include <iostream>
#include "Time.h"
using namespace std;

int main(){
//T1 will test incrementing into the next minute, print in standard-time and universal-time, print before and after
    Time T1(8,07,59);
    cout << "[TEST1]" <<endl;
    T1.printStandard();
    T1.printUniversal();
    T1.tick();
    cout << "----------Increments one second----------" <<endl;
    T1.printStandard();
    T1.printUniversal();
    
//T2 will test incrementing into the next hour, print in standard-time and universal-time, print before and after
    Time T2(16,59,59);
    cout << "\n[TEST2]" <<endl;
    T2.printStandard();
    T2.printUniversal();
    T2.tick();
    cout << "----------Increments one second----------" <<endl;
    T2.printStandard();
    T2.printUniversal();

//T3 will test incrementing into the next day, print in standard-time and universal-time, print before and after
    Time T3(23,59,59);
    cout << "\n[TEST3]" <<endl;
    T3.printStandard();
    T3.printUniversal();
    T3.tick();
    cout << "----------Increments one second----------" <<endl;
    T3.printStandard();
    T3.printUniversal();

    return 0;
}