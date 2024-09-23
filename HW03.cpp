#include <iostream>
using namespace std;

class Rational{
    private:
    int numerator;
    int denominator;
    int calGcd(int,int);      //using euclidean algorithm to calculate greatest common divisor between two numbers
    public:
    Rational(int = 0 , int = 1);    //default, test in Multiplying(Fraction3)
    void printResult();             //print the answers in fraction(a/b) and floating-point format
    void addingFraction(int,int);         //Adding Two Fractions Together
    void subtractingFraction(int,int);    //Subtracting Two Fractions Together
    void multiplyingFraction(int,int);    //Multiplying Two Fractions Together
    void dividingFraction(int,int);       //Dividinging Two Fractions Together
    int getNumerator();               //get fraction numerator
    int getDenominator();             //get fraction denominator
};

Rational::Rational(int x , int y){       //constructor
    int gcd;
    gcd = calGcd(x , y);
    numerator = x/gcd;
    denominator = y/gcd;
}

int Rational::calGcd(int num1,int num2){      //using euclidean algorithm to calculate greatest common divisor between two numbers
    if (num1 < 0)              //if num1 is negative, change it to positive
        num1 = num1 - num1*2;
    if (num2 < 0)              //if num2 is negative, change it to positive
        num2 = num2 - num2*2;
    if (num1 % num2 == 0)      //euclidean algorithm
        return num2;
    else
        return calGcd(num2 , num1 % num2);
}

void Rational::printResult(){          //print the answers in fraction(a/b) and floating-point format
    int gcd;
    gcd = calGcd(numerator , denominator);     //calculate the GCD to make sure that we can get the irreducible fraction
    cout << "Fractions: " << numerator/gcd << "/" << denominator/gcd <<endl;
    cout << "Floating-point: " << (double)numerator/denominator <<endl;
}

void Rational::addingFraction(int upFra , int downFra){       //Adding Two Fractions Together
    numerator = numerator * downFra  + denominator * upFra;
    denominator *= downFra;
}

void Rational::subtractingFraction(int upFra , int downFra){       //Subtracting Two Fractions Together
    numerator = numerator * downFra - denominator * upFra;
    denominator *= downFra;
}

void Rational::multiplyingFraction(int upFra , int downFra){       //Multiplying Two Fractions Together
    numerator = numerator * upFra;
    denominator *= downFra;
}

void Rational::dividingFraction(int upFra , int downFra){       //Dividinging Two Fractions Together
    numerator = numerator * downFra;
    denominator *= upFra;
}

int Rational::getNumerator(){         //get fraction numerator
    return numerator;
}

int Rational::getDenominator(){         //get fraction denominator
    return denominator;
}

int main(){
    Rational fraction1(10,4);     //test the addingFraction
    Rational fraction2(10,4);     //test the subtractingFraction
    Rational fraction3;           //test the multiplyingFraction and the default values in constructor
    Rational fraction4(10,4);     //test the dividingFraction
    Rational fractionFixed(3,8);      //another fraction, calculate with fraction1~4
    
    cout << "10/4 =" <<endl;
    fraction1.printResult();
    cout << "\n3/8 ="<<endl;
    fractionFixed.printResult();

    fraction1.addingFraction(fractionFixed.getNumerator() , fractionFixed.getDenominator());  //test the addFraction function with different denominators (5/2)+(3/8)
    cout << "\nAdding:\n10/4 + 3/8 =" <<endl;
    fraction1.printResult();

    fraction2.subtractingFraction(fractionFixed.getNumerator() , fractionFixed.getDenominator());  //test the subtractingFraction function with different denominators (4/10)-(3/8)
    cout << "\nSubtracting:\n10/4 - 3/8 =" <<endl;
    fraction2.printResult();

    fraction3.multiplyingFraction(fractionFixed.getNumerator() , fractionFixed.getDenominator());  //test the multiplyingFraction function with different denominators (0/1)*(3/8)
    cout << "\nMultiplying:\n0/1 * 3/8 =" <<endl;
    fraction3.printResult();

    fraction4.dividingFraction(fractionFixed.getNumerator() , fractionFixed.getDenominator());  //test the dividingFraction function with different denominators (10/4) / (3/8)
    cout << "\nDividing:\n(10/4) / (3/8) =" <<endl;
    fraction4.printResult();

    return 0;
}