#include<iostream>
#include "Unit.h"
using std::ostream;
using std::istream;

namespace ariel{
    class PhysicalNumber{
        private:
            double number;
            Unit unit;
            bool isValid(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2) const;

        public:
            PhysicalNumber(double number, Unit unit);
            //~PhysicalNumber();

            PhysicalNumber operator+(const PhysicalNumber& physicalNumber) const;
            PhysicalNumber& operator+=(const PhysicalNumber& physicalNumber);
            PhysicalNumber operator+() const;

            PhysicalNumber operator-(const PhysicalNumber& physicalNumber) const;
            PhysicalNumber& operator-=(const PhysicalNumber& physicalNumber);
            PhysicalNumber operator-() const;

            bool operator<(const PhysicalNumber& physicalNumber) const;
            bool operator>(const PhysicalNumber& physicalNumber) const;
            bool operator<=(const PhysicalNumber& physicalNumber) const;
            bool operator>=(const PhysicalNumber& physicalNumber) const;
            bool operator==(const PhysicalNumber& physicalNumber) const;
            bool operator!=(const PhysicalNumber& physicalNumber) const;

            friend ostream& operator<<(ostream& oStream, const PhysicalNumber& physicalNumber);
            friend istream& operator>>(istream& iStream, PhysicalNumber& physicalNumber);

            PhysicalNumber& operator++();
            PhysicalNumber& operator--();
        
            double convertUnit(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2) const;
    };
            ostream& operator<<(ostream& oStream, const PhysicalNumber& physicalNumber);
            istream& operator>>(istream& iStream, PhysicalNumber& physicalNumber);

};

