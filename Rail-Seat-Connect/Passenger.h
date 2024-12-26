// Name: Shrinivas Khiste
// Roll number: 19CS30043
// Start of Passenger.h
#ifndef _PASSENGER_H
#define _PASSENGER_H
#include <bits/stdc++.h>

#include "Date.h"
#include "Divyang.h"
#include "Gender.h"

using namespace std;

class Passenger {
  string firstName_, middleName_, lastName_, aadhar_, mobile_, disabilityId_,
      disabilityType_;
  DivyangType *divyangType_;
  const Date dob_;
  const Gender &gender_;

  Passenger(string f, const Gender &g, string a, const Date &d, string m,
            string l, string mob, DivyangType *dt, string disI);

 public:
  static Passenger CreatePassenger(string f, const Gender &g, string a,
                                   const Date &d, string m = "", string l = "",
                                   string mob = "", DivyangType *dt = NULL,
                                   string disI = "");

  const Gender &GetGender() const;

  DivyangType *GetDivyangType() const;

  const Date &GetDOB() const;

  static void UnitTest();
};

#endif  // _PASSENGER_H
// End of Passenger.h
