#include <iostream>
using namespace std;

class Package{
    private:
        string name_send , address_send , city_send , state_send , zipCode_send , name_rec , address_rec , city_rec , state_rec , zipCode_rec;
        double weight , costPerOunce;
    public:
        Package(const string & , const string & , const string & , const string & , const string & , const string & ,
        const string & , const string & , const string & , const string & , double , double );

        void setName_send(string &);
        string getName_send() const;
        void setAddress_send(string &);
        string getAddress_send() const;
        void setCity_send(string &);
        string getCity_send() const;
        void setState_send(string &);
        string getState_send() const;
        void setZipCode_send(string &);
        string getZipCode_send() const;

        void setName_rec(string &);
        string getName_rec() const;
        void setAddress_rec(string &);
        string getAddress_rec() const;
        void setCity_rec(string &);
        string getCity_rec() const;
        void setState_rec(string &);
        string getState_rec() const;
        void setZipCode_rec(string &);
        string getZipCode_rec() const;

        void setWeight(double);
        double getWeight() const;
        void setCostPerOunce(double);
        double getCostPerOunce() const;

        double calculateCost() const;
        void printPackage() const;
};

Package::Package(const string &name_s , const string &address_s , const string &city_s , const string &state_s , const string &zipCode_s , const string &name_r ,
                const string &address_r , const string &city_r , const string &state_r , const string &zipCode_r , double weight_in , double costPerOunce_in)
    :name_send(name_s),
    address_send(address_s),
    city_send(city_s),
    state_send(state_s),
    zipCode_send(zipCode_s),
    name_rec(name_r),
    address_rec(address_r),
    city_rec(city_r),
    state_rec(state_r),
    zipCode_rec(zipCode_r)
{
    setWeight(weight_in);
    setCostPerOunce(costPerOunce_in);
}

//set sender name
void Package::setName_send(string &name_in){
    name_send = name_in;
}

//get sender name
string Package::getName_send() const{
    return name_send;
}

//set sender address
void Package::setAddress_send(string &address_in){
    address_send = address_in;
}

//get sender address
string Package::getAddress_send() const{
    return address_send;
}

//set sender city
void Package::setCity_send(string &city_in){
    city_send = city_in;
}

//get sender city
string Package::getCity_send() const{
    return city_send;
}

//set sender state
void Package::setState_send(string &state_in){
    state_send = state_in;
}

//get sender state
string Package::getState_send() const{
    return state_send;
}

//set sender ZIP code
void Package::setZipCode_send(string &zipCode_in){
    zipCode_send = zipCode_in;
}

//get sender ZIP code
string Package::getZipCode_send() const{
    return zipCode_send;
}

//set recipient name
void Package::setName_rec(string &name_in){
    name_rec = name_in;
}

//get recipient name
string Package::getName_rec() const{
    return name_rec;
}

//set recipient address
void Package::setAddress_rec(string &address_in){
    address_rec = address_in;
}

//get recipient address
string Package::getAddress_rec() const{
    return address_rec;
}

//set recipient city
void Package::setCity_rec(string &city_in){
    city_rec = city_in;
}

//get recipient city
string Package::getCity_rec() const{
    return city_rec;
}

//set recipient state
void Package::setState_rec(string &state_in){
    state_rec = state_in;
}

//get recipient state
string Package::getState_rec() const{
    return state_rec;
}

//set recipient ZIP code
void Package::setZipCode_rec(string &zipCode_in){
    zipCode_rec = zipCode_in;
}

//get recipient ZIP code
string Package::getZipCode_rec() const{
    return zipCode_rec;
}

//set weight and ensure it contain positive values, if value is negative, then set it to 0
void Package::setWeight(double weight_in){
    weight = ( weight_in > 0.0 ) ? weight_in : 0.0;
}

//get weight
double Package::getWeight() const{
    return weight;
}

//set cost per ounce and ensure it contain positive values, if value is negative, then set it to 0
void Package::setCostPerOunce(double costPerOunce_in){
    costPerOunce = ( costPerOunce_in > 0.0 ) ? costPerOunce_in : 0.0;
}

//get cost per ounce
double Package::getCostPerOunce() const{
    return costPerOunce;
}

//multiplying the weight by the cost per ounce
double Package::calculateCost() const{
    return getWeight() * getCostPerOunce();
}

//print the package detail, include name, address, city , state and ZIP code both the sender and the recipient, and package weight and cost per ounce
void Package::printPackage() const{
    cout << "-----Sendor-----\nName: " << getName_send() << "\nAddress: " << getAddress_send() << "\nCity: " << getCity_send() << "\nState: " << getState_send() << "\nZip Code: " << getZipCode_send() <<endl;
    cout << "\n-----Recipient-----\nName: " << getName_rec() << "\nAddress: " << getAddress_rec() << "\nCity: " << getCity_rec() << "\nState: " << getState_rec() << "\nZip Code: " << getZipCode_rec() <<endl;
    cout << "\nWeight: " << getWeight() <<endl;
    cout << "Cost Per Ounce: " << getCostPerOunce() <<endl;
}


//inherit directly from class Package and contain an additional data member
class TwoDayPackage : public Package{
    private:
        double twoDayFee;
    public:
        TwoDayPackage( const string & , const string & , const string & , const string & , const string & ,
        const string & , const string & , const string & , const string & , const string & , double , double , double );
        void setTwoDayFee(double);
        double getTwoDayFee() const;
        double calculateCost() const;
        void printTwoDayPackage() const;
};

TwoDayPackage::TwoDayPackage(const string &name_s , const string &address_s , const string &city_s , const string &state_s , const string &zipCode_s , const string &name_r ,
    const string &address_r , const string &city_r , const string &state_r , const string &zipCode_r , double weight_in , double costPerOunce_in , double twoDayFee_in)
    :Package(name_s , address_s , city_s , state_s , zipCode_s , name_r , address_r , city_r , state_r , zipCode_r ,  weight_in , costPerOunce_in)
{
    setTwoDayFee(twoDayFee_in);
}

//set two day fee and ensure it contain positive values, if value is negative, then set it to 0
void TwoDayPackage::setTwoDayFee(double twoDayFee_in){
    twoDayFee = ( twoDayFee_in > 0 ) ? twoDayFee_in : 0.0;
}

//get two day fee
double TwoDayPackage::getTwoDayFee() const{
    return twoDayFee;
}

//multiplying the weight by the cost per ounce, and add a flat fee that the shipping company charges for two-day delivery service
double TwoDayPackage::calculateCost() const{
    return Package::calculateCost() + getTwoDayFee() ;
}

//print the package detail and package fee
void TwoDayPackage::printTwoDayPackage() const{
    cout << "Two Day Package:" <<endl;
    Package::printPackage();
    cout << "Two Day Fee: " << getTwoDayFee() <<endl;
    cout << "Cost(Two Day Package): " << calculateCost() <<endl;
}


//inherit directly from class Package and contain an additional data member
class OvernightPackage : public Package{
    private:
        double overnightFee;
    public:
        OvernightPackage( const string & , const string & , const string & , const string & , const string & ,
        const string & , const string & , const string & , const string & , const string & , double , double , double );
        void setOvernightFee(double);
        double getOvernightFee() const;
        double calculateCost() const;
        void printOvernightPackage() const;
};

OvernightPackage::OvernightPackage(const string &name_s , const string &address_s , const string &city_s , const string &state_s , const string &zipCode_s , const string &name_r ,
    const string &address_r , const string &city_r , const string &state_r , const string &zipCode_r , double weight_in , double costPerOunce_in , double overnightFee_in)
    :Package(name_s , address_s , city_s , state_s , zipCode_s , name_r , address_r , city_r , state_r , zipCode_r ,  weight_in , costPerOunce_in)
{
    setOvernightFee(overnightFee_in);
}

//set overnight fee and ensure it contain positive values, if value is negative, then set it to 0
void OvernightPackage::setOvernightFee(double overnightFee_in){
    overnightFee = ( overnightFee_in > 0.0 ) ? overnightFee_in : 0.0;
}

//get overnight fee
double OvernightPackage::getOvernightFee() const{
    return overnightFee;
}

//adds the overnight-delivery fee per ounce to the standard cost per ounce before calculating the shipping cost, than multiply by the weight
double OvernightPackage::calculateCost() const{
    return ( Package::getCostPerOunce() + getOvernightFee() ) * Package::getWeight();
}

//print the package detail and package fee
void OvernightPackage::printOvernightPackage() const{
    cout << "Overnight Package:" <<endl;
    Package::printPackage();
    cout << "Overnight Fee: " << getOvernightFee() <<endl;
    cout << "Cost(Overnight Package): " << calculateCost() <<endl;
}

int main(){
//t1 will test the TwoDayPackage with normal value
    cout << "[Normal]";
    TwoDayPackage t1( "Jason" , "1F., No. 2, Abc Rd." , "Tainan" , "Taiwan" , "70101" , "Andy" , "3F., No. 4, Def Rd." , "Tokyo" , "Japan" , "100-0005" , 7 , 0.3 , 1.2 );
    t1.printTwoDayPackage();

//t2 will test the TwoDayPackage with negative value
    cout << "\n\n[Negative Value]";
    TwoDayPackage t2( "Ada" , "5F., No. 6, Abc Rd." , "Venice" , "Italy" , "30121" , "Mika" , "7F., No. 8, Def Rd." , "Berlin" , "Germany" , "10178" , -3.2 , -0.7 , -1.5 );
    t2.printTwoDayPackage();

//o1 will test the OvernightPackage with normal value
    cout << "\n\n\n\n[Normal]";
    OvernightPackage o1( "Jim" , "9F., No. 8, Ghi Rd." , "Paris" , "France" , "75015" , "Chen" , "7F., No. 6, Jkl Rd." , "Madrid" , "Spain" , "28071" , 1.5 , 0.8 , 0.4 );
    o1.printOvernightPackage();

//o2 will test the OvernightPackage with negative value
    cout << "\n\n[Negative Value]";
    OvernightPackage o2( "Lin" , "5F., No. 4, Ghi Rd." , "bangkok" , "Thailand" , "10200" , "Chen" , "3F., No. 2, Jkl Rd." , "Bergen" , "Norway" , "5017" , -4.2 , -0.1 , -9.6 );
    o2.printOvernightPackage();
    
    return 0;
}