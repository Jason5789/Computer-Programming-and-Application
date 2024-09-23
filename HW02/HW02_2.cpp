#include <iostream>
using namespace std;

class Invoice{
private:
	string number;        //item number
	string description;   //item description
	int quantity;         //user buy how much quantity
	int price;            //how much the item cost
public:
	Invoice();
	void setNumber(string);        //set item number
	string getNumber();            //get item number
	void setDescription(string);   //set item description
	string getDescription();       //get item description
	void setQuantity(int);         //set item quantity
	int getQuantity();             //get item quantity
	void setPrice(int);            //set item price
	int getPrice();                //get item price
	int getInvoiceAmount();        //quantity * price
};  //end class Invoice

Invoice::Invoice(){
	quantity = price = 0;
}   //end Invoice constructor

void Invoice::setNumber(string enterNumber){
	number = enterNumber;
}  //end function setNumber

string Invoice::getNumber(){
	return number;               //return the number
}  //end function getNumber

void Invoice::setDescription(string enterDescription){
	description = enterDescription;
}  //end function setDescription

string Invoice::getDescription(){
	return description;         //return the description
}  //end function getDescription

void Invoice::setQuantity(int enterQuantity){
	if (enterQuantity < 0)       //if the quantity is not positive
		enterQuantity = 0;
	quantity = enterQuantity;
}  //end function setQuantity

int Invoice::getQuantity(){
	return quantity;           //return the quantity
}  //end function getQuantity

void Invoice::setPrice(int enterPrice){
	if (enterPrice < 0)          //if the price is not positive
		enterPrice = 0;
	price = enterPrice;
}  //end function setPrice

int Invoice::getPrice(){
	return price;               //return the price
}  //end function getPrice

int Invoice::getInvoiceAmount(){
	return price * quantity;           //return the amount
}  //end function getInvoiceAmount

int main() {
	Invoice invoice1,invoice2,invoice3;

	invoice1.setNumber("PP13");               //invoice 1 number
	invoice1.setDescription("iPhone 13pro");  //invoice 1 description
	invoice1.setQuantity(3);                  //invoice 1 quantity
	invoice1.setPrice(33900);                 //invoice 1 price
	cout << "Invoice 1\nNumber: "<< invoice1.getNumber() <<endl;
	cout << "Description: " << invoice1.getDescription() <<endl;
	cout << "Quantity: " << invoice1.getQuantity() <<endl;
	cout << "Price: " << invoice1.getPrice() <<endl;
	cout << "Invoice 1 Amount: " << invoice1.getInvoiceAmount() <<endl;

	invoice2.setNumber("PA06");               //invoice 2 number
	invoice2.setDescription("iPad Air");      //invoice 2 description
	invoice2.setQuantity(6);                  //invoice 2 quantity
	invoice2.setPrice(-18900);                //invoice 2 price
	cout << "\nInvoice 2\nNumber: "<< invoice2.getNumber() <<endl;
	cout << "Description: " << invoice2.getDescription() <<endl;
	cout << "Quantity: " << invoice2.getQuantity() <<endl;
	cout << "Price: " << invoice2.getPrice() <<endl;
	cout << "Invoice 2 Amount: " << invoice2.getInvoiceAmount() <<endl;

	invoice3.setNumber("WS07");                                //invoice 3 number
	invoice3.setDescription("Apple watch Series 7");           //invoice 3 description
	invoice3.setQuantity(-9);                                  //invoice 3 quantity
	invoice3.setPrice(11900);                                  //invoice 3 price
	cout << "\nInvoice 3\nNumber: "<< invoice3.getNumber() <<endl;
	cout << "Description: " << invoice3.getDescription() <<endl;
	cout << "Quantity: " << invoice3.getQuantity() <<endl;
	cout << "Price: " << invoice3.getPrice() <<endl;
	cout << "Invoice 3 Amount: " << invoice3.getInvoiceAmount() <<endl;

	return 0;
}
