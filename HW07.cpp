#include <iostream>
#include <iomanip>
using namespace std;

class SavingAccount{
    private:
        static double annualInterestRate;
        double savingsBalance;
    public:
        SavingAccount(const double &);
        double calculateMonthlyInterest();
        void setSavingsBalance();
        double getSavingsBalance() const;
        static void modifyInterestRate();
};

double SavingAccount::annualInterestRate = 0.03;

SavingAccount::SavingAccount(const double &balance)
    : savingsBalance( balance )
{

}

//calculates the monthly interest by multiplying the balance by annualInterestRate divided by 12
double SavingAccount::calculateMonthlyInterest(){
    return savingsBalance * annualInterestRate / 12;
}

//set the amount the saver currently has on deposit
void SavingAccount::setSavingsBalance(){
    savingsBalance += calculateMonthlyInterest();
}

//get the amount the saver currently has on deposit
double SavingAccount::getSavingsBalance() const{
    return savingsBalance;
}

//sets the static annualInterestRate to a new value
void SavingAccount::modifyInterestRate(){
    annualInterestRate = 0.04;
}

int main(){
//set saver1 and saver2
    SavingAccount saver1(2000.00);
    SavingAccount saver2(3000.00);

//print the initial value
    cout <<  "[Initial]" <<  "   ";
    cout << "Saver1: " << saver1.getSavingsBalance() << "    " << "Saver2: " << saver2.getSavingsBalance() <<endl;

//print the one month later value when Annual Interest=3%
    saver1.setSavingsBalance();
    saver2.setSavingsBalance();
    cout <<  "\n[Annual Interest=3%]" <<  "   ";
    cout << "Saver1: " << saver1.getSavingsBalance() << "    " << "Saver2: " << saver2.getSavingsBalance() <<endl;

//sets the static annualInterestRate to 4%(0.04)
    SavingAccount::modifyInterestRate();

//print the one month later value when Annual Interest=4%
    saver1.setSavingsBalance();
    saver2.setSavingsBalance();
    cout <<  "\n[Annual Interest=4%]" <<  "   ";
    cout << "Saver1: " << saver1.getSavingsBalance() << "    " << "Saver2: " << saver2.getSavingsBalance() <<endl;
    
    return 0;
}