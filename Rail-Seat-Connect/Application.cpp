// Name: Shrinivas Khiste
// Roll number: 19CS30043
#include <bits/stdc++.h>

#include "Booking.h"
#include "BookingClasses.h"
#include "Concession.h"
#include "Railways.h"
#include "Station.h"

using namespace std;

template <>
const float BookingClasses::ACFirstClass::sFareLoadFactor = 6.50;
template <>
const float BookingClasses::ACFirstClass::sReservationCharge = 60.0;
template <>
const float BookingClasses::ACFirstClass::sMinTatkalCharge = 400.0;
template <>
const float BookingClasses::ACFirstClass::sMaxTatkalCharge = 500.0;
template <>
const float BookingClasses::ACFirstClass::sTatkalLoadFactor = 0.30;
template <>
const bool BookingClasses::ACFirstClass::sIsSeating = false;
template <>
const bool BookingClasses::ACFirstClass::sIsAc = true;
template <>
const bool BookingClasses::ACFirstClass::sIsLuxury = true;
template <>
const int BookingClasses::ACFirstClass::sNumTiers = 2;
template <>
const int BookingClasses::ACFirstClass::sMinDistanceTatkal = 500;
template <>
const string BookingClasses::ACFirstClass::sName = "ACFirstClass";

template <>
const float BookingClasses::ExecutiveChairCar::sFareLoadFactor = 5.00;
template <>
const float BookingClasses::ExecutiveChairCar::sReservationCharge = 60.0;
template <>
const float BookingClasses::ExecutiveChairCar::sMinTatkalCharge = 400.0;
template <>
const float BookingClasses::ExecutiveChairCar::sMaxTatkalCharge = 500.0;
template <>
const float BookingClasses::ExecutiveChairCar::sTatkalLoadFactor = 0.30;
template <>
const bool BookingClasses::ExecutiveChairCar::sIsSeating = true;
template <>
const bool BookingClasses::ExecutiveChairCar::sIsAc = true;
template <>
const bool BookingClasses::ExecutiveChairCar::sIsLuxury = true;
template <>
const int BookingClasses::ExecutiveChairCar::sNumTiers = 0;
template <>
const int BookingClasses::ExecutiveChairCar::sMinDistanceTatkal = 250;
template <>
const string BookingClasses::ExecutiveChairCar::sName = "ExecutiveChairCar";

template <>
const float BookingClasses::AC2Tier::sFareLoadFactor = 4.00;
template <>
const float BookingClasses::AC2Tier::sReservationCharge = 50.0;
template <>
const float BookingClasses::AC2Tier::sMinTatkalCharge = 400.0;
template <>
const float BookingClasses::AC2Tier::sMaxTatkalCharge = 500.0;
template <>
const float BookingClasses::AC2Tier::sTatkalLoadFactor = 0.30;
template <>
const bool BookingClasses::AC2Tier::sIsSeating = false;
template <>
const bool BookingClasses::AC2Tier::sIsAc = true;
template <>
const bool BookingClasses::AC2Tier::sIsLuxury = false;
template <>
const int BookingClasses::AC2Tier::sNumTiers = 2;
template <>
const int BookingClasses::AC2Tier::sMinDistanceTatkal = 500;
template <>
const string BookingClasses::AC2Tier::sName = "AC2Tier";

template <>
const float BookingClasses::FirstClass::sFareLoadFactor = 3.00;
template <>
const float BookingClasses::FirstClass::sReservationCharge = 50.0;
template <>
const float BookingClasses::FirstClass::sMinTatkalCharge = 400.0;
template <>
const float BookingClasses::FirstClass::sMaxTatkalCharge = 500.0;
template <>
const float BookingClasses::FirstClass::sTatkalLoadFactor = 0.30;
template <>
const bool BookingClasses::FirstClass::sIsSeating = false;
template <>
const bool BookingClasses::FirstClass::sIsAc = false;
template <>
const bool BookingClasses::FirstClass::sIsLuxury = true;
template <>
const int BookingClasses::FirstClass::sNumTiers = 2;
template <>
const int BookingClasses::FirstClass::sMinDistanceTatkal = 500;
template <>
const string BookingClasses::FirstClass::sName = "FirstClass";

template <>
const float BookingClasses::AC3Tier::sFareLoadFactor = 2.50;
template <>
const float BookingClasses::AC3Tier::sReservationCharge = 40.0;
template <>
const float BookingClasses::AC3Tier::sMinTatkalCharge = 300.0;
template <>
const float BookingClasses::AC3Tier::sMaxTatkalCharge = 400.0;
template <>
const float BookingClasses::AC3Tier::sTatkalLoadFactor = 0.30;
template <>
const bool BookingClasses::AC3Tier::sIsSeating = false;
template <>
const bool BookingClasses::AC3Tier::sIsAc = true;
template <>
const bool BookingClasses::AC3Tier::sIsLuxury = false;
template <>
const int BookingClasses::AC3Tier::sNumTiers = 3;
template <>
const int BookingClasses::AC3Tier::sMinDistanceTatkal = 500;
template <>
const string BookingClasses::AC3Tier::sName = "AC3Tier";

template <>
const float BookingClasses::ACChairCar::sFareLoadFactor = 2.00;
template <>
const float BookingClasses::ACChairCar::sReservationCharge = 40.0;
template <>
const float BookingClasses::ACChairCar::sMinTatkalCharge = 125.0;
template <>
const float BookingClasses::ACChairCar::sMaxTatkalCharge = 225.0;
template <>
const float BookingClasses::ACChairCar::sTatkalLoadFactor = 0.30;
template <>
const bool BookingClasses::ACChairCar::sIsSeating = true;
template <>
const bool BookingClasses::ACChairCar::sIsAc = true;
template <>
const bool BookingClasses::ACChairCar::sIsLuxury = false;
template <>
const int BookingClasses::ACChairCar::sNumTiers = 0;
template <>
const int BookingClasses::ACChairCar::sMinDistanceTatkal = 250;
template <>
const string BookingClasses::ACChairCar::sName = "ACChairCar";

template <>
const float BookingClasses::Sleeper::sFareLoadFactor = 1.00;
template <>
const float BookingClasses::Sleeper::sReservationCharge = 20.0;
template <>
const float BookingClasses::Sleeper::sMinTatkalCharge = 100.0;
template <>
const float BookingClasses::Sleeper::sMaxTatkalCharge = 200.0;
template <>
const float BookingClasses::Sleeper::sTatkalLoadFactor = 0.30;
template <>
const bool BookingClasses::Sleeper::sIsSeating = false;
template <>
const bool BookingClasses::Sleeper::sIsAc = false;
template <>
const bool BookingClasses::Sleeper::sIsLuxury = false;
template <>
const int BookingClasses::Sleeper::sNumTiers = 3;
template <>
const int BookingClasses::Sleeper::sMinDistanceTatkal = 500;
template <>
const string BookingClasses::Sleeper::sName = "Sleeper";

template <>
const float BookingClasses::SecondSitting::sFareLoadFactor = 0.60;
template <>
const float BookingClasses::SecondSitting::sReservationCharge = 15.0;
template <>
const float BookingClasses::SecondSitting::sMinTatkalCharge = 10.0;
template <>
const float BookingClasses::SecondSitting::sMaxTatkalCharge = 15.0;
template <>
const float BookingClasses::SecondSitting::sTatkalLoadFactor = 0.10;
template <>
const bool BookingClasses::SecondSitting::sIsSeating = true;
template <>
const bool BookingClasses::SecondSitting::sIsAc = false;
template <>
const bool BookingClasses::SecondSitting::sIsLuxury = false;
template <>
const int BookingClasses::SecondSitting::sNumTiers = 0;
template <>
const int BookingClasses::SecondSitting::sMinDistanceTatkal = 100;
template <>
const string BookingClasses::SecondSitting::sName = "SecondSitting";

const float Booking::sBaseFarePerKm = 0.50;
int Booking::sBookingPNRSerial = 1;

void runUnitTests() {
  // Station::UnitTest();
  // Railways::UnitTest();

  // Passenger::UnitTest();
  // Concession::UnitTest();

  // Date::UnitTest();
  // BookingCategory::UnitTest();

  // Booking::UnitTest();
}

void ApplicationTest(){
  Station f = Station::CreateStation("Mumbai");
  Station t = Station::CreateStation("Delhi");

  Date bo = Date::CreateDate(4, 10, 2020);
  Date r = Date::CreateDate(9, 4, 2021);

  Passenger p =
      Passenger::CreatePassenger("First", Gender::Male::Type(), "123456789012",
                                 Date::CreateDate(12, 10, 2020));

  // Constructor
  Booking *b = Booking::BookASeat(f, t, bo, r, BookingClasses::AC3Tier::Type(),
                                  p, General::Type());

  cout<<*b;
}

int main() {
  runUnitTests();
  ApplicationTest();
  return 0;
}
