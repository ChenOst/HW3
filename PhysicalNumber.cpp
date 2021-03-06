#include <iostream>
#include <sstream>
#include <stdexcept>
#include "string"
#include "PhysicalNumber.h"
#include "Unit.h"
using namespace std;
using namespace ariel;

PhysicalNumber::PhysicalNumber(double number, Unit unit){
    this->number=number;
    this->unit=unit;
}//end - PhysicalNumber::PhysicalNumber

//Checks if the units belong to the same category and if the unit data is valid
bool PhysicalNumber::isValid(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2) const{
    //Checks if both physical numbers belong to CM, M, KM category
    if(physicalNumber1.unit == Unit::CM || physicalNumber1.unit == Unit::M || physicalNumber1.unit == Unit::KM){
        if(physicalNumber2.unit == Unit::CM || physicalNumber2.unit == Unit::M || physicalNumber2.unit == Unit::KM){
            return true;
        }
        else if(physicalNumber2.unit == Unit::SEC || physicalNumber2.unit == Unit::MIN || physicalNumber2.unit == Unit::HOUR || physicalNumber2.unit == Unit::G || physicalNumber2.unit == Unit::KG || physicalNumber2.unit == Unit::TON){
            return false;
        }
        else{
            throw std::invalid_argument( "physicalNumber2 : Invalid unit data\n" );
        }
    }
    //Checks if both physical numbers belong to SEC, MIN, HOUR category
    else if(physicalNumber1.unit == Unit::SEC || physicalNumber1.unit == Unit::MIN || physicalNumber1.unit == Unit::HOUR){
        if(physicalNumber2.unit == Unit::SEC || physicalNumber2.unit == Unit::MIN || physicalNumber2.unit == Unit::HOUR){
            return true;
        }
        else if(physicalNumber2.unit == Unit::CM || physicalNumber2.unit == Unit::M || physicalNumber2.unit == Unit::KM || physicalNumber2.unit == Unit::G || physicalNumber2.unit == Unit::KG || physicalNumber2.unit == Unit::TON){
            return false;
        }
        else{
            throw std::invalid_argument( "physicalNumber2 : Invalid unit data\n" );
        }
    }
    //Checks if both physical numbers belong to G, KG, TON category
    else if(physicalNumber1.unit == Unit::G || physicalNumber1.unit == Unit::KG || physicalNumber1.unit == Unit::TON){
        if(physicalNumber2.unit == Unit::G || physicalNumber2.unit == Unit::KG || physicalNumber2.unit == Unit::TON){
            return true;
        }
        else if(physicalNumber2.unit == Unit::CM || physicalNumber2.unit == Unit::M || physicalNumber2.unit == Unit::KM || physicalNumber2.unit == Unit::SEC || physicalNumber2.unit == Unit::MIN || physicalNumber2.unit == Unit::HOUR){
            return false;
        }
        else{
            throw std::invalid_argument( "physicalNumber2 : Invalid unit data\n" );
        }
    }
    else{
        throw std::invalid_argument( "physicalNumber1 : Invalid unit data\n" );
    }
}//end - bool PhysicalNumber::isValid

//Convert the number depending on the unit type
double PhysicalNumber::convertUnit(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2) const{
    if(isValid(physicalNumber1, physicalNumber2)){
        if(physicalNumber1.unit == Unit::CM){
            if(physicalNumber2.unit == Unit::CM){
                return physicalNumber2.number;
            }
            else if(physicalNumber2.unit == Unit::M){
                return (physicalNumber2.number*100);
            }
            else if(physicalNumber2.unit == Unit::KM){
                return (physicalNumber2.number*100000);
            }
        }
        else if(physicalNumber1.unit == Unit::M){
            if(physicalNumber2.unit == Unit::M){
                return physicalNumber2.number;
            }
            else if(physicalNumber2.unit == Unit::CM){
                return (physicalNumber2.number/100);
            }
            else if(physicalNumber2.unit == Unit::KM){
                return (physicalNumber2.number*1000);
            }
        }
        else if(physicalNumber1.unit == Unit::KM){
            if(physicalNumber2.unit == Unit::KM){
                return physicalNumber2.number;
            }
            else if(physicalNumber2.unit == Unit::CM){
                return (physicalNumber2.number/100000);
            }
            else if(physicalNumber2.unit == Unit::M){
                return (physicalNumber2.number/1000);
            }
        }
        else if(physicalNumber1.unit == Unit::SEC){
            if(physicalNumber2.unit == Unit::SEC){
                return physicalNumber2.number;
            }
            else if(physicalNumber2.unit == Unit::MIN){
                return (physicalNumber2.number*60);
            }
            else if(physicalNumber2.unit == Unit::HOUR){
                return (physicalNumber2.number*3600);
            }
        }
        else if(physicalNumber1.unit == Unit::MIN){
            if(physicalNumber2.unit == Unit::MIN){
                return physicalNumber2.number;
            }
            else if(physicalNumber2.unit == Unit::SEC){
                return (physicalNumber2.number/60);
            }
            else if(physicalNumber2.unit == Unit::HOUR){
                return (physicalNumber2.number*60);
            }
        }
        else if(physicalNumber1.unit == Unit::HOUR){
            if(physicalNumber2.unit == Unit::HOUR){
                return physicalNumber2.number;
            }
            else if(physicalNumber2.unit == Unit::SEC){
                return (physicalNumber2.number/3600);
            }
            else if(physicalNumber2.unit == Unit::MIN){
                return (physicalNumber2.number/60);
            }
        }
        else if(physicalNumber1.unit == Unit::G){
            if(physicalNumber2.unit == Unit::G){
                return physicalNumber2.number;
            }
            else if(physicalNumber2.unit == Unit::KG){
                return (physicalNumber2.number*1000);
            }
            else if(physicalNumber2.unit == Unit::TON){
                return (physicalNumber2.number*1000000);
            }
        }
        else if(physicalNumber1.unit == Unit::KG){
            if(physicalNumber2.unit == Unit::KG){
                return physicalNumber2.number;
            }
            else if(physicalNumber2.unit == Unit::G){
                return (physicalNumber2.number/1000);
            }
            else if(physicalNumber2.unit == Unit::TON){
                return (physicalNumber2.number*1000);
            }
            
        }
        else if(physicalNumber1.unit == Unit::TON){
            if(physicalNumber2.unit == Unit::TON){
                return physicalNumber2.number;
            }
            else if(physicalNumber2.unit == Unit::G){
                return (physicalNumber2.number/1000000);
            }
            else if(physicalNumber2.unit == Unit::KG){
                return (physicalNumber2.number/1000);
            }
        }
        else{
            throw std::invalid_argument( "Invalid unit data\n" );
        }
    }
    else{
        throw std::invalid_argument( "The data is from different categorys(units)\n" );
    }
    return physicalNumber2.number;
}//end - double PhysicalNumber::convertUnit

//
//Add Functions
//

//Add two numbers
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        return PhysicalNumber(this->number + converted, this->unit);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}

//Change this number by adding the physicalNumber->number to it
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& physicalNumber){
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        this->number = this->number + converted;
        return *this;
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Change the sign of physicalNumber->number
PhysicalNumber PhysicalNumber::operator+() const{
    return PhysicalNumber(this->number, this->unit);
}
//end - Add Functions

//
//Subtract Functions
//

//Subtract two numbers
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        return PhysicalNumber(this->number - converted, this->unit);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Change this number by subtract the physicalNumber->number from it
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& physicalNumber){
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        this->number = this->number - converted;
        return *this;
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
    
}
//Change the sign of physicalNumber->number
PhysicalNumber PhysicalNumber::operator-() const{
    return PhysicalNumber(-1*this->number, this->unit);
}
//end - Subtract Functions

//
//Boolean Functions
//
//Operator <
bool PhysicalNumber::operator<(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        return(this->number < converted);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator >
bool PhysicalNumber::operator>(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        return(this->number > converted);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator <=
bool PhysicalNumber::operator<=(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        return(this->number <= converted);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator >=
bool PhysicalNumber::operator>=(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        return(this->number >= converted);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator ==
bool PhysicalNumber::operator==(const PhysicalNumber& physicalNumber) const{

    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        return(this->number == converted);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator !=
bool PhysicalNumber::operator!=(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        return(this->number != converted);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//end - Boolean Functions

//
//Add one to number/Subtract one of number
//
//Operator ++
PhysicalNumber& PhysicalNumber::operator++(){
    this->number = this->number+1;
    return *this;
}
PhysicalNumber& PhysicalNumber::operator++(int){
    PhysicalNumber ret(*this);
    this->number++;
    return ret;
}
//Operator --
PhysicalNumber& PhysicalNumber::operator--(){
    this->number = this->number-1;
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(int){
    PhysicalNumber ret(*this);
    this->number--;
    return ret;
}

//
//Strams Functions
//
//OStream
ostream& ariel::operator<<(ostream& oStream, const PhysicalNumber& physicalNumber){
    if(physicalNumber.unit==Unit::CM){
        oStream << physicalNumber.number << "[cm]";
    }
    else if(physicalNumber.unit==Unit::M){
        oStream << physicalNumber.number << "[m]";
    }
    else if(physicalNumber.unit==Unit::KM){
       oStream << physicalNumber.number << "[km]";
    }
    else if(physicalNumber.unit==Unit::SEC){
        oStream << physicalNumber.number << "[sec]";
    }
    else if(physicalNumber.unit==Unit::MIN){
        oStream << physicalNumber.number << "[min]";
    }
    else if(physicalNumber.unit==Unit::HOUR){
        oStream << physicalNumber.number << "[hour]";
    }
    else if(physicalNumber.unit==Unit::G){
        oStream << physicalNumber.number << "[g]";
    }
    else if(physicalNumber.unit==Unit::KG){
        oStream << physicalNumber.number << "[kg]";
    }
    else if(physicalNumber.unit==Unit::TON){
        oStream << physicalNumber.number << "[ton]";
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
    return oStream;
}
//IStream
istream& ariel::operator>>(istream& iStream, PhysicalNumber& physicalNumber){
    string myString="";
    string subString="";
    string num="";
    bool flag=true;
    double stringNum=0;
    iStream >> myString;
    int open = 0;
    int close = 0;
    open = myString.find("[");
    close = myString.find("]");
    if ((open != string::npos) && (close != string::npos)){
        subString = myString.substr(open + 1, close - open - 1);
        if(subString == "cm" ){
            physicalNumber.unit = Unit::CM;
        }
        else if(subString =="m"){
            physicalNumber.unit = Unit::M;
        }
        else if(subString =="km"){
            physicalNumber.unit = Unit::KM;
        }
        else if(subString =="sec"){
            physicalNumber.unit = Unit::SEC;
        }
        else if(subString =="min"){
            physicalNumber.unit = Unit::MIN;
        }
        else if(subString =="hour"){
            physicalNumber.unit = Unit::HOUR;
        }
        else if(subString =="g"){
            physicalNumber.unit = Unit::G;
        }
        else if(subString =="kg"){
            physicalNumber.unit = Unit::KG;
        }
        else if(subString =="ton"){
            physicalNumber.unit = Unit::TON;
        }
        else{
            flag = false;
            auto errorState = iStream.rdstate();
        }
        num = myString.substr(0, open);
        if (flag){
            try
            {
                stringNum = stod(num);
            }

            catch (exception &e)
            {
                auto errorState = iStream.rdstate();
                return iStream;
            }
            physicalNumber.number = stringNum;
        }  
    }
    else{
         auto errorState = iStream.rdstate();
    }
    return iStream;
}

//end - Strams Functions



