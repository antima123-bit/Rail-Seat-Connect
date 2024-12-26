// Name: Shrinivas Khiste
// Roll number: 19CS30043
#ifndef __BOOKINGCLASSES_H__
#define __BOOKINGCLASSES_H__

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BookingClassTypes;

class BookingClasses {
  static const float sFareLoadFactor, sReservationCharge, sMinTatkalCharge,
      sMaxTatkalCharge, sTatkalLoadFactor;
  static const bool sIsSeating, sIsAc, sIsLuxury;
  static const int sNumTiers, sMinDistanceTatkal;
  static const string sName;

  struct ACFirstClassType {};
  struct ExecutiveChairCarType {};
  struct AC2TierType {};
  struct FirstClassType {};
  struct AC3TierType {};
  struct ACChairCarType {};
  struct SleeperType {};
  struct SecondSittingType {};

 public:
  BookingClasses(){};  // default constructor

  virtual bool IsSitting() const = 0;
  virtual int GetNumberOfTiers() const = 0;
  virtual string GetName() const = 0;
  virtual bool IsAC() const = 0;
  virtual bool IsLuxury() const = 0;
  virtual float GetFareLoadFactor() const = 0;
  virtual float GetReservationCharge() const = 0;
  virtual float GetMinTatkalCharge() const = 0;
  virtual float GetMaxTatkalCharge() const = 0;
  virtual float GetMinDistanceTatkal() const = 0;
  virtual float GetTatkalLoadFactor() const = 0;

  virtual ~BookingClasses(){};  // Virtual Destructor for base class

  friend ostream &operator<<(
      ostream &os, const BookingClasses &b);  // friend ostream operator

  typedef BookingClassTypes<ACFirstClassType> ACFirstClass;
  typedef BookingClassTypes<ExecutiveChairCarType> ExecutiveChairCar;
  typedef BookingClassTypes<AC2TierType> AC2Tier;
  typedef BookingClassTypes<FirstClassType> FirstClass;
  typedef BookingClassTypes<AC3TierType> AC3Tier;
  typedef BookingClassTypes<ACChairCarType> ACChairCar;
  typedef BookingClassTypes<SleeperType> Sleeper;
  typedef BookingClassTypes<SecondSittingType> SecondSitting;
};

template <typename T>
class BookingClassTypes : public BookingClasses {
  static const float sFareLoadFactor, sReservationCharge, sMinTatkalCharge,
      sMaxTatkalCharge, sTatkalLoadFactor;
  static const bool sIsSeating, sIsAc, sIsLuxury;
  static const int sNumTiers, sMinDistanceTatkal;
  static const string sName;

  BookingClassTypes(){};

  ~BookingClassTypes(){};

 public:
  static const BookingClassTypes<T> &Type() {
    static const BookingClassTypes<T> obj;

    return obj;
  };

  bool IsSitting() const { return sIsSeating; };
  int GetNumberOfTiers() const { return sNumTiers; };
  string GetName() const { return sName; };
  bool IsAC() const { return sIsAc; };
  bool IsLuxury() const { return sIsLuxury; };
  float GetFareLoadFactor() const { return sFareLoadFactor; };
  float GetReservationCharge() const { return sReservationCharge; };
  float GetMinTatkalCharge() const { return sMinTatkalCharge; };
  float GetMaxTatkalCharge() const { return sMaxTatkalCharge; };
  float GetMinDistanceTatkal() const { return sMinDistanceTatkal; };
  float GetTatkalLoadFactor() const { return sTatkalLoadFactor; };
};

#endif  // __BOOKINGCLASSES_H__