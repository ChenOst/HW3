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
    if(this->number < 0){
        this->number = -(this->number);
    }
    return PhysicalNumber(this->number, this->unit);
}
//end - Subtract Functions

//
//Boolean Functions
//
//Operator <
bool PhysicalNumber::operator<(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        if(this->number < converted){
            returh true;
        }
        else{
            return false;
        }
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator >
bool PhysicalNumber::operator>(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        if(this->number > converted){
            returh true;
        }
        else{
            return false;
        }
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator <=
bool PhysicalNumber::operator<=(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        if(this->number <= converted){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator >=
bool PhysicalNumber::operator>=(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        if(this->number >= converted){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator ==
bool PhysicalNumber::operator==(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        if(this->number == converted){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Operator !=
bool PhysicalNumber::operator!=(const PhysicalNumber& physicalNumber) const{
    if(isValid(*this, physicalNumber)){
        double converted = convertUnit(*this, physicalNumber);
        if(this->number != converted){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//end - Boolean Functions

//
//Strams Functions
//
//OStream
ostream& ariel::operator<<(ostream& oStream, const PhysicalNumber& physicalNumber){
    if(physicalNumber->Unit==Unit::CM){
        return oStream << physicalNumber->number << "[CM]";
    }
    else if(physicalNumber->Unit==Unit::M){
        return oStream << physicalNumber->number << "[M]";
    }
    else if(physicalNumber->Unit==Unit::KM){
        return oStream << physicalNumber->number << "[KM]";
    }
    else if(physicalNumber->Unit==Unit::SEC){
        return oStream << physicalNumber->number << "[SEC]";
    }
    else if(physicalNumber->Unit==Unit::MIN){
        return oStream << physicalNumber->number << "[MIN]";
    }
    else if(physicalNumber->Unit==Unit::HOUR){
        return oStream << physicalNumber->number << "[HOUR]";
    }
    else if(physicalNumber->Unit==Unit::G){
        return oStream << physicalNumber->number << "[G]";
    }
    else if(physicalNumber->Unit==Unit::KG){
        return oStream << physicalNumber->number << "[KG]";
    }
    else if(physicalNumber->Unit==Unit::TON){
        return oStream << physicalNumber->number << "[TON]";
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
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
        subString = myString.substr(open + 1, close - 1);
        if(subString == "CM" ){
            physicalNumber->unit = Unit::CM;
        }
        else if(subString =="M"){
            physicalNumber->unit = Unit::M;
        }
        else if(subString =="KM"){
            physicalNumber->unit = Unit::KM;
        }
        else if(subString =="SEC"){
            physicalNumber->unit = Unit::SEC;
        }
        else if(subString =="MIN"){
            physicalNumber->unit = Unit::MIN;
        }
        else if(subString =="HOUR"){
            physicalNumber->unit = Unit::HOUR;
        }
        else if(subString =="G"){
            physicalNumber->unit = Unit::G;
        }
        else if(subString =="KG"){
            physicalNumber->unit = Unit::KG;
        }
        else if(subString =="TON"){
            physicalNumber->unit = Unit::TON;
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
                auto errorState = iStream.rdstate(); // remember error state
                return iStream;
            }
            physicalNumber->number = stringNum;
        }
    else{
         auto errorState = iStream.rdstate();
    }
    return iStream;
}

//end - Strams Functions

//
//Add one to number/Subtract one of number
//
//Operator ++
PhysicalNumber& PhysicalNumber::operator++(){
    this->number = this->number+1;
    return *this;
}
//Operator --
PhysicalNumber& PhysicalNumber::operator--(){
    this->number = this->number-1;
    return *this;
}

