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
    if(physicalNumber1->unit == CM || physicalNumber1->unit == M || physicalNumber1->unit == KM){
        if(physicalNumber2->unit == CM || physicalNumber2->unit == M || physicalNumber2->unit == KM){
            return true;
        }
        else if(physicalNumber2->unit == SEC || physicalNumber2->unit == MIN || physicalNumber2->unit == HOUR || physicalNumber2->unit == G || physicalNumber2->unit == KG || physicalNumber2->unit == TON){
            return false;
        }
        else{
            throw std::invalid_argument( "physicalNumber2 : Invalid unit data\n" );
        }
    }
    //Checks if both physical numbers belong to SEC, MIN, HOUR category
    else if(physicalNumber1->unit == SEC || physicalNumber1->unit == MIN || physicalNumber1->unit == HOUR){
        if(physicalNumber2->unit == SEC || physicalNumber2->unit == MIN || physicalNumber2->unit == HOUR){
            return true;
        }
        else if(physicalNumber2->unit == CM || physicalNumber2->unit == M || physicalNumber2->unit == KM || physicalNumber2->unit == G || physicalNumber2->unit == KG || physicalNumber2->unit == TON){
            return false;
        }
        else{
            throw std::invalid_argument( "physicalNumber2 : Invalid unit data\n" );
        }
    }
    //Checks if both physical numbers belong to G, KG, TON category
    else if(physicalNumber1->unit == G || physicalNumber1->unit == KG || physicalNumber1->unit == TON){
        if(physicalNumber2->unit == G || physicalNumber2->unit == KG || physicalNumber2->unit == TON){
            return true;
        }
        else if(physicalNumber2->unit == CM || physicalNumber2->unit == M || physicalNumber2->unit == KM || physicalNumber2->unit == SEC || physicalNumber2->unit == MIN || physicalNumber2->unit == HOUR){
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
        if(physicalNumber1->unit == CM){
            if(physicalNumber2->unit == CM){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == M){
                return (physicalNumber2->number*100)
            }
            else if(physicalNumber2->unit == KM){
                return (physicalNumber2->number*100000)
            }
        }
        else if(physicalNumber1->unit == M){
            if(physicalNumber2->unit == M){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == CM){
                return (physicalNumber2->number/100)
            }
            else if(physicalNumber2->unit == KM){
                return (physicalNumber2->number*1000)
            }
        }
        else if(physicalNumber1->unit == KM){
            if(physicalNumber2->unit == KM){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == CM){
                return (physicalNumber2->number/100000)
            }
            else if(physicalNumber2->unit == M){
                return (physicalNumber2->number/1000)
            }
        }
        else if(physicalNumber1->unit == SEC){
            if(physicalNumber2->unit == SEC){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == MIN){
                return (physicalNumber2->number*60)
            }
            else if(physicalNumber2->unit == HOUR){
                return (physicalNumber2->number*3600)
            }
        }
        else if(physicalNumber1->unit == MIN){
            if(physicalNumber2->unit == MIN){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == SEC){
                return (physicalNumber2->number/60)
            }
            else if(physicalNumber2->unit == HOUR){
                return (physicalNumber2->number*60)
            }
        }
        else if(physicalNumber1->unit == HOUR){
            if(physicalNumber2->unit == HOUR){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == SEC){
                return (physicalNumber2->number/3600)
            }
            else if(physicalNumber2->unit == MIN){
                return (physicalNumber2->number/60)
            }
        }
        else if(physicalNumber1->unit == G){
            if(physicalNumber2->unit == G){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == KG){
                return (physicalNumber2->number*1000)
            }
            else if(physicalNumber2->unit == TON){
                return (physicalNumber2->number*1000000)
            }
        }
        else if(physicalNumber1->unit == KG){
            if(physicalNumber2->unit == KG){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == G){
                return (physicalNumber2->number/1000)
            }
            else if(physicalNumber2->unit == TON){
                return (physicalNumber2->number*1000)
            }
            
        }
        else if(physicalNumber1->unit == TON){
            if(physicalNumber2->unit == TON){
                return physicalNumber2->number;
            }
            else if(physicalNumber2->unit == G){
                return (physicalNumber2->number/1000000)
            }
            else if(physicalNumber2->unit == KG){
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

