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

            bool operator< (const PhysicalNumber& physicalNumber);
            bool operator> (const PhysicalNumber& physicalNumber);
            bool operator<= (const PhysicalNumber& physicalNumber);
            bool operator>= (const PhysicalNumber& physicalNumber);
            bool operator== (const PhysicalNumber& physicalNumber);
            bool operator!= (const PhysicalNumber& physicalNumber);

            friend ostream& operator<< (ostream& oStream, const PhysicalNumber& physicalNumber);
            friend istream& operator>> (istream& iStream, PhysicalNumber& physicalNumber);

            PhysicalNumber& operator++();
            PhysicalNumber& operator--();
        
            double convertUnit(const PhysicalNumber& physicalNumber1, const PhysicalNumber& physicalNumber2);
    };
            ostream& operator<< (ostream& oStream, const PhysicalNumber& physicalNumber);
            istream& operator>> (istream& iStream, PhysicalNumber& physicalNumber);

};

