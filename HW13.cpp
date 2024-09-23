#include <iostream>
#include <iomanip>
#include <exception>
using namespace std;

class bmiexception : public exception{
    public:
        virtual const char * ans( double bmiValue ){
            if ( bmiValue <= 18.5 )                          //bmi<=18.5
                return "you're in the underweight range";
            else if ( bmiValue < 25 )                        //18.5<bmi<=25
                return "you're in the healthy weight range";
            else if ( bmiValue < 30 )                        //25<bmi<=30
                return "you're in the overweight range";
            else if ( bmiValue < 40 )                        //30<bmi<=40
                return "you're in the obese range";
            else                                             //bmi>40
                return "you're BMI above 40";
        }
}myex;

int main(){
    double mass=0 , height=0 , bmi;

//let user enter mass value in kilogram, if user enter negative value or 0 will let user enter again
    do{
    cout << "Mass(kilogram): ";
    cin >> mass;
    }while(mass<=0);

//let user enter height value in meter, if user enter negative value or 0 will let user enter again
    do{
    cout << "Height(meter): ";
    cin >> height;
    }while(mass<=0);

    bmi = mass/(height*height);     //calculate BMI

//try and catch
    try{
        throw myex;    //throw
    }
    catch(bmiexception &m){
        cout << m.ans(bmi) <<endl;    //print the result
    }
    
    return 0;
}