#include <iostream>
#include <iomanip>
using namespace std;

class Book{
    friend class Bookstore;
    private:
        string title;
        string author;
        float price;
        int stock;
    public:
        Book(string = "Empty", string = "Empty" , float = 0.0 ,int = 0);
        void printBook();
        void update(string,string);
};

Book::Book(string t , string a , float p , int s)
    : title( t ),
      author( a ),
      price( p ),
      stock( s )
{
    //empty body
}

//print the book detail
void Book::printBook(){
            cout << setw(8) << left << "Title:" << title <<endl;
            cout << setw(8) << left << "Author:" << author <<endl;
            cout << setw(8) << left << "Price:" << price <<endl;
            cout << setw(8) << left << "Stock:" << stock <<endl;
}

//update the book data
void Book::update(string code_in , string input1){
    if (code_in == "T"){
        title = input1;
    }
    else if (code_in == "A"){
        author = input1;
    }
    else if (code_in == "P"){
        price = stof(input1);
    }
    else if (code_in == "S"){
        stock = stoi(input1);
    }
    else
        cout << "Wrong input!!!" <<endl;
}

class Bookstore{ 
    private:
        string item[3][4];
        void validFunction(int,string,string,float,int);   
    public:
        Bookstore();
        void setBook(Book,int);
        bool addBook(string,string,float,int);
        void printBookstore();
        bool updateBook(string);
};

Bookstore::Bookstore(){
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<4 ; j++)
            item[i][j]="Empty";
    }
}


//set the book to the bookstore
void Bookstore::setBook(Book in , int sequenceNumber){
        item[sequenceNumber-1][0] = in.title;
        item[sequenceNumber-1][1] = in.author;
        item[sequenceNumber-1][2] = to_string(in.price);
        item[sequenceNumber-1][3] = to_string(in.stock);
}

//find the empty space(Title=="Empty"), if there is empty space(Title=="Empty"), call validFunction to add book in empty space and return true, not found will return false
bool Bookstore::addBook(string addTitle , string addAuthor , float addPrice ,int addStock){
    if (item[0][0]=="Empty"){
        validFunction(0 , addTitle , addAuthor , addPrice , addStock);
        return true;
    }
    else if(item[1][0]=="Empty"){
        validFunction(1 , addTitle , addAuthor , addPrice , addStock);
        return true;
    }
    else if(item[2][0]=="Empty"){
        validFunction(2 , addTitle , addAuthor , addPrice , addStock);
        return true;
    }
    else
        return false;
}

//add the book in empty space(Title=="Empty") and print the success message to notice user
void Bookstore::validFunction(int i , string vTitle , string vAuthor , float vPrice ,int vStock){
    item[i][0] = vTitle;
    item[i][1] = vAuthor;
    item[i][2] = to_string(vPrice);
    item[i][3] = to_string(vStock);
    cout << "\n!!!SUCCESS!!!" <<endl;
}

//print all book in the bookstore 
void Bookstore::printBookstore(){
    cout << "\n---Bookstore---" <<endl;
    for (int i=0 ; i<3 ; i++){
        cout << "\n[BOOKSTORE] Book " << i+1 << setw(8) << left << "\nTitle:" << item[i][0] <<endl;
        cout << setw(8) << left << "Author:" << item[i][1] <<endl;
        cout << setw(8) << left << "Price:" << item[i][2] <<endl;
        cout << setw(8) << left << "Stock:" << item[i][3] <<endl;
    }
}

//update the book detail from bookstore, have this book will return true, else will return false
bool Bookstore::updateBook(string findTitle){
    for (int i=0 ; i<3 ; i++){
        if ( item[i][0] == findTitle){
            return true;
            break;
        }   
    }
            return false;
}

int main(){
    string code,value;

//B3 will test the default value
    Book B1("ABC English" , "Jason Chen" , 18.99 , 20);
    Book B2("C++ How to program" , "Paul Deitel" , 26.99 , 5);
    Book B3;

//print three books one by one
    cout << "Book 1:" <<endl;
    B1.printBook();
    cout << "\nBook 2:" <<endl;
    B2.printBook();
    cout << "\nBook 3:" <<endl;
    B3.printBook();

//let user update B2 data with the code and the new data
    cout << "\nEnter the code and new value you want to update from Book 2(T for title, A for author, P for price, S for stock), separated by space or enter:";
    cin >> code >> value;
    B2.update(code,value);
//print the new data after user update
    cout << "\n[Update]Book 2:" <<endl;
    B2.printBook();

    Bookstore S1;
//set three book into the bookstore
    S1.setBook(B1,1);
    S1.setBook(B2,2);
    S1.setBook(B3,3);

//add two book, the first input will succeed, the latter input will fail
    if (S1.addBook("ADD1" , "Jim" , 35 , 25) == false)
        cout << "\nERROR!!!  There was no room for the book \"ADD1\"!!!" <<endl;
    if (S1.addBook("ADD2" , "Panda" , 58 , 10) == false)
        cout << "\nERROR!!!  There was no room for the book \"ADD2\"!!!" <<endl;
    S1.printBookstore();

//find if there have the book that is same title, this example will success and user can update data if user change B2 title before, this will failed and print a sorry message 
    if (S1.updateBook("C++ How to program") == true){
        cout << "\nEnter the code and new value you want to update from Book 2(T for title, A for author, P for price, S for stock), separated by space or enter:";
        cin >> code >> value;
        B2.update(code,value);
        S1.setBook(B2,2);
    }
    else
        cout << "\nSorry! The book \"C++ How to program\" was not found!"<<endl;

//find if there have the book that is same title again, but this will failed and print a sorry message
    if (S1.updateBook("Hahaha") == true){
        cout << "\nEnter the code and new value you want to update from Book 1(T for title, A for author, P for price, S for stock), separated by space or enter:";
        cin >> code >> value;
        B1.update(code,value);
        S1.setBook(B1,1);
    }
    else
        cout << "\nSorry! The book \"Hahaha\" was not found!"<<endl;

//print bookstore data
    S1.printBookstore();

    return 0;
}