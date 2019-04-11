#include <iostream>
#include <stdexcept>
#include "string"
#include "PhysicalNumber.h"
using namespace std;

ariel::PhysicalNumber::PhysicalNumber(double number, Unit unit){
    this->number=number;
    this->unit=unit;
}//end - ariel::PhysicalNumber::PhysicalNumber

//Checks if the units belong to the same category and if the unit data is valid
bool ariel::PhysicalNumber::isValid(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2) const{
    //Checks if both physical numbers belong to CM, M, KM category
    if(physicalNumber1->unit == Unit::CM || physicalNumber1->unit == Unit::M || physicalNumber1->unit == Unit::KM){
        if(physicalNumber2->unit == Unit::CM || physicalNumber2->unit == Unit::M || physicalNumber2->unit == Unit::KM){
            return true;
        }
        else if(physicalNumber2->unit == Unit::SEC || physicalNumber2->unit == Unit::MIN || physicalNumber2->unit == Unit::HOUR || physicalNumber2->unit == Unit::G || physicalNumber2->unit == Unit::KG || physicalNumber2->unit == Unit::TON){
            return false;
        }
        else{
            throw std::invalid_argument( "physicalNumber2 : Invalid unit data\n" );
        }
    }
    //Checks if both physical numbers belong to SEC, MIN, HOUR category
    else if(physicalNumber1->unit == Unit::SEC || physicalNumber1->unit == Unit::MIN || physicalNumber1->unit == Unit::HOUR){
        if(physicalNumber2->unit == Unit::SEC || physicalNumber2->unit == Unit::MIN || physicalNumber2->unit == Unit::HOUR){
            return true;
        }
        else if(physicalNumber2->unit == Unit::CM || physicalNumber2->unit == Unit::M || physicalNumber2->unit == Unit::KM || physicalNumber2->unit == Unit::G || physicalNumber2->unit == Unit::KG || physicalNumber2->unit == Unit::TON){
            return false;
        }
        else{
            throw std::invalid_argument( "physicalNumber2 : Invalid unit data\n" );
        }
    }
    //Checks if both physical numbers belong to G, KG, TON category
    else if(physicalNumber1->unit == Unit::G || physicalNumber1->unit == Unit::KG || physicalNumber1->unit == Unit::TON){
        if(physicalNumber2->unit == Unit::G || physicalNumber2->unit == Unit::KG || physicalNumber2->unit == Unit::TON){
            return true;
        }
        else if(physicalNumber2->unit == Unit::CM || physicalNumber2->unit == Unit::M || physicalNumber2->unit == Unit::KM || physicalNumber2->unit == Unit::SEC || physicalNumber2->unit == Unit::MIN || physicalNumber2->unit == Unit::HOUR){
            return false;
        }
        else{
            throw std::invalid_argument( "physicalNumber2 : Invalid unit data\n" );
        }
    }
    else{
        throw std::invalid_argument( "physicalNumber1 : Invalid unit data\n" );
    }
}//end - bool ariel::PhysicalNumber::isValid

//Convert the number depending on the unit type
double ariel::PhysicalNumber::convertUnit(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2) const{
    if(isValid(physicalNumber1, physicalNumber2)){
        if(physicalNumber1->unit == Unit::CM){
            if(physicalNumber2->unit == Unit::CM){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == Unit::M){
                return (physicalNumber2->number*100)
            }
            else if(physicalNumber2->unit == Unit::KM){
                return (physicalNumber2->number*100000)
            }
        }
        else if(physicalNumber1->unit == Unit::M){
            if(physicalNumber2->unit == Unit::M){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == Unit::CM){
                return (physicalNumber2->number/100)
            }
            else if(physicalNumber2->unit == Unit::KM){
                return (physicalNumber2->number*1000)
            }
        }
        else if(physicalNumber1->unit == Unit::KM){
            if(physicalNumber2->unit == Unit::KM){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == Unit::CM){
                return (physicalNumber2->number/100000)
            }
            else if(physicalNumber2->unit == Unit::M){
                return (physicalNumber2->number/1000)
            }
        }
        else if(physicalNumber1->unit == Unit::SEC){
            if(physicalNumber2->unit == Unit::SEC){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == Unit::MIN){
                return (physicalNumber2->number*60)
            }
            else if(physicalNumber2->unit == Unit::HOUR){
                return (physicalNumber2->number*3600)
            }
        }
        else if(physicalNumber1->unit == Unit::MIN){
            if(physicalNumber2->unit == Unit::MIN){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == Unit::SEC){
                return (physicalNumber2->number/60)
            }
            else if(physicalNumber2->unit == Unit::HOUR){
                return (physicalNumber2->number*60)
            }
        }
        else if(physicalNumber1->unit == Unit::HOUR){
            if(physicalNumber2->unit == Unit::HOUR){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == Unit::SEC){
                return (physicalNumber2->number/3600)
            }
            else if(physicalNumber2->unit == Unit::MIN){
                return (physicalNumber2->number/60)
            }
        }
        else if(physicalNumber1->unit == Unit::G){
            if(physicalNumber2->unit == Unit::G){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == Unit::KG){
                return (physicalNumber2->number*1000)
            }
            else if(physicalNumber2->unit == Unit::TON){
                return (physicalNumber2->number*1000000)
            }
        }
        else if(physicalNumber1->unit == Unit::KG){
            if(physicalNumber2->unit == Unit::KG){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == Unit::G){
                return (physicalNumber2->number/1000)
            }
            else if(physicalNumber2->unit == Unit::TON){
                return (physicalNumber2->number*1000)
            }
            
        }
        else if(physicalNumber1->unit == Unit::TON){
            if(physicalNumber2->unit == Unit::TON){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == Unit::G){
                return (physicalNumber2->number/1000000)
            }
            else if(physicalNumber2->unit == Unit::KG){
                return (physicalNumber2->number/1000)
            }
        }
        else{
            throw std::invalid_argument( "Invalid unit data\n" );
        }
    }
    else{
        throw std::invalid_argument( "The data is from different categorys(units)\n" );
    }
}//end - double ariel::PhysicalNumber::convertUnit

//
//Add Functions
//

//Add two numbers
ariel::PhysicalNumber::PhysicalNumber ariel::PhysicalNumber::operator+ (const PhysicalNumber& physicalNumber) const{
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
        return PhysicalNumber(this->number + converted, this->unit);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}

//Change this number by adding the physicalNumber->number to it
ariel::PhysicalNumber::PhysicalNumber& ariel::PhysicalNumber::operator+= (const PhysicalNumber& physicalNumber){
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
        this->number = this->number + converted;
        return *this;
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Change the sign of physicalNumber->number
ariel::PhysicalNumber::PhysicalNumber ariel::PhysicalNumber::operator+() const{
    return PhysicalNumber(this->number, this->unit);
}
//end - Add Functions

//
//Subtract Functions
//

//Subtract two numbers
ariel::PhysicalNumber::PhysicalNumber ariel::PhysicalNumber::operator- (const PhysicalNumber& physicalNumber) const{
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
        return PhysicalNumber(this->number - converted, this->unit);
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
}
//Change this number by subtract the physicalNumber->number from it
ariel::PhysicalNumber::PhysicalNumber& ariel::PhysicalNumber::operator-= (const PhysicalNumber& physicalNumber){
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
        this->number = this->number - converted;
        return *this;
    }
    else{
        throw std::invalid_argument( "Invalid unit data\n" );
    }
    
}
//Change the sign of physicalNumber->number
ariel::PhysicalNumber::PhysicalNumber ariel::PhysicalNumber::operator-() const{
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
bool ariel::PhysicalNumber::operator< (const PhysicalNumber& physicalNumber) const{
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
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
bool ariel::PhysicalNumber::operator> (const PhysicalNumber& physicalNumber) const{
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
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
bool ariel::PhysicalNumber::operator<= (const PhysicalNumber& physicalNumber) const{
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
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
bool ariel::PhysicalNumber::operator>= (const PhysicalNumber& physicalNumber) const{
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
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
bool ariel::PhysicalNumber::operator== (const PhysicalNumber& physicalNumber) const{
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
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
bool ariel::PhysicalNumber::operator!= (const PhysicalNumber& physicalNumber) const{
    if(isValid(this, physicalNumber)){
        double converted = convertUnit(this, physicalNumber);
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
friend ostream& ariel::PhysicalNumber::operator<< (ostream& oStream, const PhysicalNumber& physicalNumber){
    return *ostream;
}
//IStream
friend istream& ariel::PhysicalNumber::operator>> (istream& iStream, PhysicalNumber& physicalNumber){
    return *istream;
}
//end - Strams Functions

//
//Add one to number/Subtract one of number
//
//Operator ++
ariel::PhysicalNumber::PhysicalNumber& ariel::PhysicalNumber::operator++(){
    this->number = this->number+1;
    return *this;
}
//Operator --
ariel::PhysicalNumber::PhysicalNumber& ariel::PhysicalNumber::operator--(){
    this->number = this->number-1;
    return *this;
}

