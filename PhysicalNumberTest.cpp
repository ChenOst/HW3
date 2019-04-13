/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber pn1(25, Unit::CM);
    PhysicalNumber pn2(520, Unit::M);
    PhysicalNumber pn3(13, Unit::KM);
    PhysicalNumber pn4(7, Unit::SEC);
    PhysicalNumber pn5(9, Unit::MIN);
    PhysicalNumber pn6(12, Unit::HOUR);
    PhysicalNumber pn7(2, Unit::G);
    PhysicalNumber pn8(140, Unit::KG);
    PhysicalNumber pn9(84, Unit::TON);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
    .CHECK_OUTPUT(pn2+pn3, "13520[m]")
    .CHECK_OUTPUT(pn4+pn5, "547[sec]")
    .CHECK_OUTPUT(pn9+pn8, "84.14[ton]")

    .CHECK_THROWS(pn1+pn4)
    .CHECK_THROWS(pn2+pn5)
    .CHECK_THROWS(pn3+pn6)
    .CHECK_THROWS(pn4+pn7)
    .CHECK_THROWS(pn5+pn8)
    .CHECK_THROWS(pn6+pn9)

    .CHECK_THROWS(pn1-pn9)
    .CHECK_THROWS(pn2-pn8)
    .CHECK_THROWS(pn4-pn3)
    .CHECK_THROWS(pn5-pn2)
    .CHECK_THROWS(pn6-pn3)
    .CHECK_THROWS(pn3-pn9)

    .CHECK_THROWS(pn1+=pn7)
    .CHECK_THROWS(pn3+=pn5)
    .CHECK_THROWS(pn7+=pn6)
    .CHECK_THROWS(pn4+=pn9)
    .CHECK_THROWS(pn2+=pn8)
    .CHECK_THROWS(pn4+=pn2)

    .CHECK_THROWS(pn7-=pn3)
    .CHECK_THROWS(pn4-=pn7)
    .CHECK_THROWS(pn6-=pn1)
    .CHECK_THROWS(pn3-=pn8)
    .CHECK_THROWS(pn5-=pn8)
    .CHECK_THROWS(pn9-=pn6)

    .CHECK_THROWS(pn7==pn1)
    .CHECK_THROWS(pn4==pn2)
    .CHECK_THROWS(pn3==pn5)
    .CHECK_THROWS(pn6==pn3)
    .CHECK_THROWS(pn2==pn8)
    .CHECK_THROWS(pn1==pn5)

    .CHECK_THROWS(pn9!=pn6)
    .CHECK_THROWS(pn4!=pn8)
    .CHECK_THROWS(pn1!=pn4)
    .CHECK_THROWS(pn6!=pn9)
    .CHECK_THROWS(pn7!=pn2)
    .CHECK_THROWS(pn1!=pn7)

    .CHECK_THROWS(pn2<=pn8)
    .CHECK_THROWS(pn4<=pn3)
    .CHECK_THROWS(pn2<=pn8)
    .CHECK_THROWS(pn4<=pn3)
    .CHECK_THROWS(pn2<=pn8)
    .CHECK_THROWS(pn4<=pn3)

    .CHECK_THROWS(pn5>=pn8)
    .CHECK_THROWS(pn4>=pn3)
    .CHECK_THROWS(pn6>=pn7)
    .CHECK_THROWS(pn9>=pn1)
    .CHECK_THROWS(pn2>=pn4)
    .CHECK_THROWS(pn7>=pn1)

    .CHECK_THROWS(pn2<pn4)
    .CHECK_THROWS(pn4<pn7)
    .CHECK_THROWS(pn1<pn4)
    .CHECK_THROWS(pn4<pn3)
    .CHECK_THROWS(pn2<pn5)
    .CHECK_THROWS(pn4<pn7)

    .CHECK_THROWS(pn6>pn8)
    .CHECK_THROWS(pn5>pn9)
    .CHECK_THROWS(pn2>pn5)
    .CHECK_THROWS(pn4>pn9)
    .CHECK_THROWS(pn1>pn8)
    .CHECK_THROWS(pn2>pn6)

    
  
      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}