//============================================================================
// Name        : HW01.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Homework Week 1
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string enterPhoneNumber(){           //user enter the phone number
	string yourEnter;
	cout << "Enter the phone number:";
	cin >> yourEnter;

	return yourEnter;
}

int analyzeTheNumber(char num){       //analyze the phone number
	switch ( num ){
	case '2':                         //if the number is 2
		return 0;
		break;

	case '3':                         //if the number is 3
		return 1;
		break;

	case '4':                         //if the number is 4
		return 2;
		break;

	case '5':                         //if the number is 5
		return 3;
		break;

	case '6':                         //if the number is 6
		return 4;
		break;

	case '7':                         //if the number is 7
		return 5;
		break;

	case '8':                         //if the number is 8
		return 6;
		break;

	case '9':                         //if the number is 9
		return 7;
		break;
	}
}

int main() {
	ofstream wordFile( "word_generator.txt" , ios::in );   //opens the file

	if ( !wordFile ){                            //if could not open
		cerr << "File could not opened" << endl;
		exit(1);
	}

	string phoneNumber;
	int num0 , num1 , num2 , num3 , num4 , num5 , num6;
	string digitToLetter("ABCDEFGHIJKLMNOPRSTUVWXY");   //digit to letter

	phoneNumber=enterPhoneNumber();   //let user enter the number

	if ( phoneNumber.length()==7 ){
		num0=analyzeTheNumber(phoneNumber[0]);   //analyze the first number
		num1=analyzeTheNumber(phoneNumber[1]);   //analyze the second number
		num2=analyzeTheNumber(phoneNumber[2]);   //analyze the third number
		num3=analyzeTheNumber(phoneNumber[3]);   //analyze the fourth number
		num4=analyzeTheNumber(phoneNumber[4]);   //analyze the fifth number
		num5=analyzeTheNumber(phoneNumber[5]);   //analyze the sixth number
		num6=analyzeTheNumber(phoneNumber[6]);   //analyze the seventh number

		for ( int a=0 ; a<3 ; a++ ){
			for ( int b=0 ; b<3 ; b++ ){
				for ( int c=0 ; c<3 ; c++ ){
					for ( int d=0 ; d<3 ; d++ ){
						for ( int e=0 ; e<3 ; e++ ){
							for ( int f=0 ; f<3 ; f++ ){
								for ( int g=0 ;  g<3 ; g++ ){
									wordFile << digitToLetter[a+3*num0] << digitToLetter[b+3*num1] << digitToLetter[c+3*num2]
									<< digitToLetter[d+3*num3] << digitToLetter[e+3*num4] << digitToLetter[f+3*num5]
									<< digitToLetter[g+3*num6] << endl;      //put result in the file
								}
							}
						}
					}
				}
			}
		}
	}
	else
		cout << "Wrong input!!!" << endl;   //show when user input less or more than 7 number

	return 0;
}
