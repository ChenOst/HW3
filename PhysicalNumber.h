#include<iostream>
#include "Unit.h"
using std::ostream;
using std::istream;

namespace ariel{
    class PhysicalNumber{
        private:
            double number;
            Unit unit;
        public:
            PhysicalNumber(double number, Unit unit);
            ~PhysicalNumber();

            PhysicalNumber operator+ (const PhysicalNumber physicalNumber);
            PhysicalNumber& operator+= (const PhysicalNumber physicalNumber);
            PhysicalNumber& operator+();

            PhysicalNumber operator- (const PhysicalNumber physicalNumber);
            PhysicalNumber& operator-= (const PhysicalNumber physicalNumber);
            PhysicalNumber& operator-();

            friend bool operator< (const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2);
            friend bool operator> (const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2);
            friend bool operator<= (const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2);
            friend bool operator>= (const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2);
            friend bool operator== (const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2);
            friend bool operator!= (const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2);

            friend ostream& operator<< (ostream& oStream, const PhysicalNumber& physicalNumber);
            friend istream& operator>> (istream& iStream, PhysicalNumber& physicalNumber);

            PhysicalNumber& operator++();
            PhysicalNumber& operator--();
    };
};

