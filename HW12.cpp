#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Account{
    private:
        double balance;
    public:
        Account(double);
        void setBalance(double);
        virtual double getBalance() const;
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
    //set floating-point output formatting
    cout << fixed << setprecision(2);

    //create vector of three base-class pointers
    vector < Account * > account(4);

    //initialize vector with various kinds of Account
    account[0] = new SavingAccount(20.00,0.06);        //normal SavingAccount
    account[1] = new CheckingAccount(30.88,2.5);       //normal CheckingAccount
    account[2] = new SavingAccount(-18.00,0.17);      //this SavingAccount will test the negative value, and it will print "ERROR!!! Balance was invalid!!!"
    account[3] = new CheckingAccount(-10.88,3.5);     //this CheckingAccount will test the negative value, and it will print "ERROR!!! Balance was invalid!!!"

    //polymorphically process each element in vector account
    for ( size_t i = 0 ; i < account.size() ; i++ ){
        //downcast pointer
        SavingAccount *derivedPtr = dynamic_cast < SavingAccount * > ( account[i] );

        //print initial balance
        cout << "\n[Account " << i+1 << "] Initial balance:" << account[i]->getBalance() <<endl;

        //determine whether account is a SavingAccount
        if ( derivedPtr != 0 ){
            double withdraw,deposit;

            //allow the user to specify an amount of money to withdraw from the Account using member function debit
            cout << "Withdraw money: ";
            cin >> withdraw;
            cout << "After withdraw " << withdraw <<endl;
            derivedPtr->debit(withdraw);
            cout << "Current balance: " << derivedPtr->getBalance() <<endl;


            //allow the user to specify an amount of money to deposit into the Account using member function credit
            cout << "Deposit money: ";
            cin >> deposit;
            cout << "After Credit " << deposit <<endl;
            derivedPtr->credit(deposit);
            cout << "Current balance: " << derivedPtr->getBalance() <<endl;


            //calculate the amount of interest owed to the Account using member function calculateInterest,  then add the interest to the account balance using member function credit
            cout << "Adding " << derivedPtr->calculateInterest() << " interest to account" <<endl;;
            derivedPtr->credit( derivedPtr->calculateInterest() );
            cout << "Current balance: " << derivedPtr->getBalance() <<endl;
        }

        //Final Output
        cout << "[Account " << i+1 << "] balance: " << account[i]->getBalance() << "\n[END Account " << i+1 << "]" <<endl;
    }
    return 0;
}