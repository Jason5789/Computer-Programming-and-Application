#include <iostream>
using namespace std;

class DegreeAngle{
    friend ostream &operator<<( ostream & , const DegreeAngle & );
    friend istream &operator>>( istream & , DegreeAngle & );
    private:
        int angle;
    public:
        DegreeAngle(int=0);
        DegreeAngle operator+( const DegreeAngle & );
        DegreeAngle operator-( const DegreeAngle & );
};

//make sure the range of value is 0-359
DegreeAngle::DegreeAngle(int angle_in){
    angle = angle_in % 360;
}

//overload + operator, and make sure the range of value is 0-359
DegreeAngle DegreeAngle::operator+( const DegreeAngle &a ){
    DegreeAngle DegreeAngle;
    DegreeAngle.angle = this->angle + a.angle;
    DegreeAngle.angle = DegreeAngle.angle%360;
    return DegreeAngle;
}

//overload - operator, and make sure the range of value is 0-359
DegreeAngle DegreeAngle::operator-( const DegreeAngle &b ){
    DegreeAngle DegreeAngle;
    DegreeAngle.angle = this->angle - b.angle;
    DegreeAngle.angle = (DegreeAngle.angle%360 >= 0) ? DegreeAngle.angle%360 : -DegreeAngle.angle%360;
    return DegreeAngle;
}

//overload stream insertion operator
ostream &operator<<( ostream &output , const DegreeAngle &x ){
    output << x.angle;
    return output;
}

//overload stream extraction operator, and make sure the range of value is 0-359
istream &operator>>( istream &input , DegreeAngle &y ){
    input >> y.angle;
    y.angle = y.angle%360;
    return input;
}



int main(){
    DegreeAngle d1(500);    //angle 1
    DegreeAngle d2;         //angle 2


//let user enter second angle
    cout << "Enter second angle: ";
    cin >> d2;

//print 2 angle
    cout << "\nAngle 1: " << d1 <<endl;
    cout << "Angle 2: " << d2 <<endl;

//test the overload operator+ function, and print
    cout << "\nAngle 1 + Angle 2 = " << d1+d2 <<endl;

//test the overload operator- function, and print
    cout << "Angle 1 - Angle 2 = " << d1-d2 <<endl;

    return 0;
}