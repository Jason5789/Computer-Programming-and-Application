#include <iostream>
using namespace std;

class Account{
private:
	int balance;   //user balance
public:
	Account(int);            //constructor
	void credit(int);     //set user credit how much money
	void debit(int);      //set user debit how much money
	int getBalance();    //print account current balance
};  //end class Account

Account::Account(int x){
		balance = x;
		cout << balance <<endl;
		if (balance<0){                 //initial balance less than 0
			cout << "!!!Error!!!   !!!Balance was invalid!!!   Set To 0" <<endl;
			balance = 0;
			cout << "This account initial balance after reset is: " << balance <<endl;     //reset the balance
		}
}     //end Account constructor

void Account::credit(int moneyIn){             //credit
	balance += moneyIn;                        //add money to the balance
} //end function credit

void Account::debit(int moneyOut){    //debit
	if (balance > moneyOut)     //user wants to debit more than the account balance
		balance -= moneyOut;
	else                       //print when user wants to debit less than the account balance
		cout << "  Debit amount exceeded account balance.\nThis account current balance is: ";
} //end function debit

int Account::getBalance(){       //print account balance
	return balance;
} //end function getBalance

int main() {
	cout << "Account 1 initial balance: ";
	Account account1(10);     //account 1 initial balance is 10 dollars
	cout << "Account 1 after credit 90: ";
	account1.credit(90);     //account 1 credit 90 dollars
	cout << account1.getBalance() <<endl;
	cout << "Account 1 after debit 20: ";
	account1.debit(20);     //account 1 debit 20 dollars
	cout << account1.getBalance() <<endl;

	cout << "\nAccount 2 initial balance: ";
	Account account2(-20);     //account 2 initial balance is -20 dollars
	cout << "Account 2 after credit 50: ";
	account2.credit(50);     //account 2 credit 50 dollars
	cout << account2.getBalance() <<endl;
	cout << "Account 2 after debit 200: ";
	account2.debit(200);    //account 2 debit 200 dollars
	cout << account2.getBalance() <<endl;

	return 0;
}
