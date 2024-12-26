#ifndef __CONCESSION_H__
#define __CONCESSION_H__

#include <bits/stdc++.h>

#include "BookingClasses.h"
#include "Passenger.h"

using namespace std;

class Concession {
  float concessionFactor_;

 public:
  Concession(){};

  float GetConcessionFactor();

  virtual ~Concession(){};

  static void UnitTest();
};

class GeneralConcession : public Concession {
 public:
  GeneralConcession(){};

  float GetConcessionFactor();

  ~GeneralConcession(){};
};

class LadiesConcession : public Concession {
 public:
  LadiesConcession(){};

  float GetConcessionFactor(const Passenger &p);

  ~LadiesConcession(){};
};

class SeniorCitizenConcession : public Concession {
 public:
  SeniorCitizenConcession(){};

  float GetConcessionFactor(const Passenger &p);

  ~SeniorCitizenConcession(){};
};

class DivyangConcession : public Concession {
  static map<pair<string, string>, int> sDisabilityConcessionFactorMatrix;

 public:
  DivyangConcession(){};

  float GetConcessionFactor(const Passenger &p, const BookingClasses &bc);

  ~DivyangConcession(){};
};

#endif  // __CONCESSION_H__