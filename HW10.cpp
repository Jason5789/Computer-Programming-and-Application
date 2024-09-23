#include <iostream>
#include <iomanip>
using namespace std;

class Account{
    private:
        double balance;
    public:
        Account(double);
        void setBalance(double);
        double getBalance() const;
        void credit(double);
        bool debit(double);
};

//Account constructor, function setBalance will validate the initaial balance to ensure that it is greater than or equal to 0
Account::Account(double initial){
    if (initial < 0.0)
        cout << "ERROR!!! Balance was invalid!!!" <<endl;
    setBalance(initial);
}

//set balance, and validate the initaial balance to ensure that it is greater than or equal to 0
void Account::setBalance(double set){
    balance = ( set >= 0.0 ) ? set : 0.0;
}

//get balance
double Account::getBalance() const{
    return balance;
}

//add an amount to the current balance
void Account::credit(double in){
    if ( in < 0.0 ){
        cout << "ERROR!  ";
        in = 0.0;
    }
    setBalance(getBalance() + in);
}

//withdraw money from the account and ensure that the debit amount does not exceed the account's balance
bool Account::debit(double out){
    if ( out < 0.0 ){
        cout << "ERROR!  ";
        out = 0.0;
    }
    if (getBalance() >= out){
        setBalance( getBalance() - out );
        return true;
    }
    else{
        cout <<  "Debit amount exceeded account balance.";
        return false;
    }
}

class SavingAccount : public Account{
    private:
        double interest;
    public:
        SavingAccount(double,double);
        void setInterest(double);
        double getInterest() const;
        double calculateInterest();
};

//SavingAccount constructor, function setInterest will validate the interest to ensure that it is greater than or equal to 0
SavingAccount::SavingAccount( double initial , double interest_in)
    :Account(initial)
{
    setInterest(interest_in);
}

//set interest, and validate the interest to ensure that it is greater than or equal to 0
void SavingAccount::setInterest(double interest_in){
    interest = ( interest_in >= 0.0 ) ? interest_in : 0.0;
}

//get interest
double SavingAccount::getInterest() const{
    return interest;
}

//calculate the interest
double SavingAccount::calculateInterest(){
    return Account::getBalance() * getInterest();
}

class CheckingAccount : public Account{
    private:
        double transactionFee;
    public:
        CheckingAccount(double,double);
        void setTransactionFee(double);
        double getTransactionFee() const;
        void credit(double);
        bool debit(double);
};

//CheckingAccount constructor
CheckingAccount::CheckingAccount( double initial , double fee_in)
    :Account(initial)
{
    setTransactionFee(fee_in);
}

//set transaction fee, and validate the transaction fee to ensure that it is greater than or equal to 0
void CheckingAccount::setTransactionFee(double fee_in){
    transactionFee = ( fee_in >= 0.0 ) ? fee_in : 0.0;
}

//get transaction fee
double CheckingAccount::getTransactionFee() const{
    return transactionFee;
}

//credit the money and charge a fee per transaction when the transaction fee
void CheckingAccount::credit(double money_in){
    Account::credit( money_in - getTransactionFee() );
}

//debit the money and charge a fee per transaction
bool CheckingAccount::debit(double money_out){
    if ( Account::debit( money_out + getTransactionFee() ) )
        return true;
    else
        return false;
}

int main(){
//Account 1 will test the base class Account, and it will input wrong credit to test the function
    cout << fixed << setprecision(2) << "[Account 1]" <<endl;
    Account a1(10.10);
    cout << "Initial balance: " << a1.getBalance() <<endl;
    cout << "After Credit -20.31, ";
    a1.credit(-20.31);
    cout << "Current balance: " << a1.getBalance() <<endl;
    cout << "After Debit 5.5, ";
    a1.debit(5.5);
    cout << "Current balance: " << a1.getBalance() <<endl;      //10.10-5.5=4.60

//Account 2 will test the base class Account, and it will input wrong initial balance, debit to test the function
    cout << "\n[Account 2]" <<endl;
    Account a2(-10.00);
    cout << "Initial balance: " << a2.getBalance() <<endl;
    cout << "After Credit 15.15, ";
    a2.credit(15.15);
    cout << "current balance: " << a2.getBalance() <<endl;
    cout << "After Debit -3.35, ";
    a2.debit(-3.35);
    cout << "current balance: " << a2.getBalance() <<endl;

//SavingAccount 1 will test the class SavingAccount, and it will input wrong credit to test the function
    cout << "\n[SavingAccount 1]" <<endl;
    SavingAccount s1(20.00,0.06);
    cout << "Initial balance: " << s1.getBalance() << "\nInterest: " << s1.getInterest() <<endl;   //20+20*0.06=21.20
    cout << "Add interest: " << s1.calculateInterest();
    s1.credit( s1.calculateInterest() );
    cout << ", Current balance: " << s1.getBalance() <<endl;
    cout << "After Credit -30.31, ";
    s1.credit(-30.31);
    cout << "Current balance: " << s1.getBalance() <<endl;
    cout << "After Debit 5.5, ";
    s1.debit(5.5);
    cout << "Current balance: " << s1.getBalance() <<endl;      //21.20-5.5=15.70
    

//SavingAccount 2 will test the class SavingAccount, and it will input wrong initial balance, interest, debit to test the function
    cout << "\n[SavingAccount 2]" <<endl;
    SavingAccount s2(-20.00,-0.5);
    cout << "Initial balance: " << s2.getBalance() << "\nInterest: " << s2.getInterest() <<endl;
    cout << "Add interest: " << s2.calculateInterest();
    s2.credit( s2.calculateInterest() );
    cout << ", Current balance: " << s2.getBalance() <<endl;
    cout << "After Credit 10.19, ";
    s2.credit(10.19);
    cout << "Current balance: " << s2.getBalance() <<endl;
    cout << "After Debit -8.1, ";
    s2.debit(-8.1);
    cout << "Current balance: " << s2.getBalance() <<endl;
    

//CheckingAccount 1 will test the class CheckingAccount, and it will input wrong credit to test the function
    cout << "\n[CheckingAccount 1]" <<endl;
    CheckingAccount c1(30.88,2.5);
    cout << "Initial balance: " << c1.getBalance() << "\nTransaction Fee: " << c1.getTransactionFee() <<endl;
    cout << "After Credit -12.18, ";
    c1.credit(-12.18);
    cout << "Current balance: " << c1.getBalance() <<endl;
    cout << "After Debit 4.3, ";
    c1.debit(4.3);
    cout << "Current balance: " << c1.getBalance() <<endl;    //30.88-4.3-2.5=24.08


//CheckingAccount 2 will test the class CheckingAccount, and it will input wrong initial balance, transaction fee, debit to test the function
    cout << "\n[CheckingAccount 2]" <<endl;
    CheckingAccount c2(-30.07,-1.45);
    cout << "Initial balance: " << c2.getBalance() << "\nTransaction Fee: " << c2.getTransactionFee() <<endl;
    cout << "After Credit 56.21, ";
    c2.credit(56.21);
    cout << "Current balance: " << c2.getBalance() <<endl;
    cout << "After Debit -4.9, ";
    c2.debit(-4.9);
    cout << "Current balance: " << c2.getBalance() <<endl;

    return 0;
}