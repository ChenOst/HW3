#include <iostream>
#include "PhysicalNumber.h"
using namespace std;

ariel::PhysicalNumber::PhysicalNumber(double number, Unit unit){
    this->number=number;
    this->unit=unit;
}

ariel::PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber physicalNumber){
    return PhysicalNumber(this->number, this->unit);
}

ariel::PhysicalNumber& ariel::PhysicalNumber::operator+=(const PhysicalNumber physicalNumber){
    return *this;
}

//If the PhysicalNumber->number is negative change to positive
ariel::PhysicalNumber& ariel::PhysicalNumber::operator+(){
    if(this->number<0){
        this->number=-(this->number);
    }
    return *this;
}

ariel::PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber physicalNumber){
    return PhysicalNumber(this->number, this->unit);
}

ariel::PhysicalNumber& ariel::PhysicalNumber::operator-=(const PhysicalNumber physicalNumber){
    return *this;
}
//If the PhysicalNumber->number is positive change to negative
ariel::PhysicalNumber& ariel::PhysicalNumber::operator-(){
    if(this->number>0){
        this->number=-(this->number);
    }
    return *this;
}

bool ariel::operator<(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2){
    return false;
}
bool ariel::operator>(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2){
     return false;
}

bool ariel::operator<=(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2){
    return false;
}
bool ariel::operator>=(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2){
     return false;
}

bool ariel::operator==(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2){
    return false;
}
bool ariel::operator!=(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2){
     return false;
}

ostream& ariel::operator<<(ostream& oStream, const PhysicalNumber& physicalNumber){
    return oStream;
}

istream& ariel::operator>> (istream& iStream, PhysicalNumber& physicalNumber){
    return iStream;
}

//Make the number increase in 1
ariel::PhysicalNumber& ariel::PhysicalNumber::operator++(){
    this->number=this->number+1;
    return *this;
}
//Make the number decrease in 1
ariel::PhysicalNumber& ariel::PhysicalNumber::operator--(){
    this->number=this->number-1;
    return *this;
}