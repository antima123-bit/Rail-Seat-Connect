#include "Booking.h"

#include <bits/stdc++.h>

#include <cmath>

#include "Concession.h"
#include "Exception.h"
#include "Railways.h"

// vector<Booking> Booking::sBookings={};

ostream& operator<< (ostream& os,const Booking &b){

    os<<"PNR Number: "<<b.PNR_<<"\n";
    os<<"From Station: "<<b.fromStation_<<"\n";
    os<<"To Station: "<<b.toStation_<<"\n";
    os<<"Travel Date: "<<b.dateOfReservation_<<"\n";
    os<<"Travel Class: "<<b.b_.GetName();
    os<<"Fare: "<<b.calculatedFare<<"\n\n";

    return os;
}

Booking::Booking(Station &f, Station &t, Date &bo, Date &r,
                 const BookingClasses &b, Passenger &p, BookingCategory &bc)
    : fromStation_(f),
      toStation_(t),
      dateOfBooking(bo),
      dateOfReservation_(r),
      b_(b),
      p_(p),
      bc_(bc) {
  PNR_ = sBookingPNRSerial++;
}

Booking *Booking::BookASeat(Station &f, Station &t, Date &bo, Date &r,
                            const BookingClasses &b, Passenger &p,
                            BookingCategory &bc) {
  bool isError = false;
  try {
    if (find(Railways::sStations.begin(), Railways::sStations.begin(),
             f.GetName()) == Railways::sStations.end()) {
      InvalidStation ex;
      throw ex;
    }
    if (find(Railways::sStations.begin(), Railways::sStations.begin(),
             t.GetName()) == Railways::sStations.end()) {
      InvalidStation ex;
      throw ex;
    }
  } catch (InvalidStation e) {
    isError = true;
    e.print();
  }

  try {
    if (Date::oneYearSpan(bo)) {
      InvalidBookingDate ex;
      throw ex;
    }
  } catch (InvalidBookingDate e) {
    e.print();
    isError = true;
  }

  try {
    if (!bc.CheckValidity(p, bo)) {
      InvalidCategory ex;
      throw ex;
    }
  } catch (InvalidCategory e) {
    e.print();
    isError = true;
  }

  if (isError) {
    throw Bad_Booking();
  }

  return bc.CreateBookingObject(f, t, bo, r, b, p);
}

GeneralBooking::GeneralBooking(Station &f, Station &t, Date &bo, Date &r,
                               const BookingClasses &b, Passenger &p,
                               BookingCategory &bc)
    : Booking(f, t, bo, r, b, p, bc) {
  calculatedFare = calculateFare();
  // Booking::sBookings.push_back(*this);
}

int GeneralBooking::calculateFare() {
  float baseFare, loadedFare, concession;
  int finalFare;

  baseFare = (float)Railways::railways().GetDistance(fromStation_, toStation_) *
             Booking::sBaseFarePerKm;

  loadedFare = baseFare * b_.GetFareLoadFactor();

  GeneralConcession c;

  concession = loadedFare * c.GetConcessionFactor();

  finalFare = round(loadedFare - concession + b_.GetReservationCharge());

  return finalFare;
}

LadiesBooking::LadiesBooking(Station &f, Station &t, Date &bo, Date &r,
                             const BookingClasses &b, Passenger &p,
                             BookingCategory &bc)
    : Booking(f, t, bo, r, b, p, bc) {
  calculatedFare = calculateFare();
  // Booking::sBookings.push_back(*this);
}

int LadiesBooking::calculateFare() {
  float baseFare, loadedFare, concession;
  int finalFare;

  baseFare = (float)Railways::railways().GetDistance(fromStation_, toStation_) *
             Booking::sBaseFarePerKm;

  loadedFare = baseFare * b_.GetFareLoadFactor();

  LadiesConcession c;

  concession = loadedFare * c.GetConcessionFactor(p_);

  finalFare = round(loadedFare - concession + b_.GetReservationCharge());

  return finalFare;
}

SeniorCitizenBooking::SeniorCitizenBooking(Station &f, Station &t, Date &bo,
                                           Date &r, const BookingClasses &b,
                                           Passenger &p, BookingCategory &bc)
    : Booking(f, t, bo, r, b, p, bc) {
  calculatedFare = calculateFare();
  // Booking::sBookings.push_back(*this);
}

int SeniorCitizenBooking::calculateFare() {
  float baseFare, loadedFare, concession;
  int finalFare;

  baseFare = (float)Railways::railways().GetDistance(fromStation_, toStation_) *
             Booking::sBaseFarePerKm;

  loadedFare = baseFare * b_.GetFareLoadFactor();

  SeniorCitizenConcession c;

  concession = loadedFare * c.GetConcessionFactor(p_);

  finalFare = round(loadedFare - concession + b_.GetReservationCharge());

  return finalFare;
}

DivyangBooking::DivyangBooking(Station &f, Station &t, Date &bo, Date &r,
                               const BookingClasses &b, Passenger &p,
                               BookingCategory &bc)
    : Booking(f, t, bo, r, b, p, bc) {
  calculatedFare = calculateFare();
  // Booking::sBookings.push_back(*this);
}

int DivyangBooking::calculateFare() {
  float baseFare, loadedFare, concession;
  int finalFare;

  baseFare = (float)Railways::railways().GetDistance(fromStation_, toStation_) *
             Booking::sBaseFarePerKm;

  loadedFare = baseFare * b_.GetFareLoadFactor();

  DivyangConcession c;

  concession = loadedFare * c.GetConcessionFactor(p_, b_);

  finalFare = round(loadedFare - concession + b_.GetReservationCharge());

  return finalFare;
}

TatkalBooking::TatkalBooking(Station &f, Station &t, Date &bo, Date &r,
                             const BookingClasses &b, Passenger &p,
                             BookingCategory &bc)
    : Booking(f, t, bo, r, b, p, bc) {
  calculatedFare = calculateFare();
  // Booking::sBookings.push_back(*this);
}

int TatkalBooking::calculateFare() {
  float baseFare, loadedFare, tatkalCharges = 0.0, distance;
  int finalFare;

  distance = (float)Railways::railways().GetDistance(fromStation_, toStation_);

  baseFare = distance * Booking::sBaseFarePerKm;

  loadedFare = baseFare * b_.GetFareLoadFactor();

  if ((int)distance >= b_.GetMinDistanceTatkal()) {
    tatkalCharges = loadedFare * b_.GetTatkalLoadFactor();

    if (tatkalCharges < b_.GetMinTatkalCharge())
      tatkalCharges = b_.GetMinTatkalCharge();
    else if (tatkalCharges > b_.GetMaxTatkalCharge())
      tatkalCharges = b_.GetMaxTatkalCharge();
  }

  finalFare = round(loadedFare + tatkalCharges + b_.GetReservationCharge());

  return finalFare;
}

PremiumTatkalBooking::PremiumTatkalBooking(Station &f, Station &t, Date &bo,
                                           Date &r, const BookingClasses &b,
                                           Passenger &p, BookingCategory &bc)
    : Booking(f, t, bo, r, b, p, bc) {
  calculatedFare = calculateFare();
  // Booking::sBookings.push_back(*this);
}

int PremiumTatkalBooking::calculateFare() {
  float baseFare, loadedFare, tatkalCharges = 0.0, distance;
  int finalFare;

  distance = (float)Railways::railways().GetDistance(fromStation_, toStation_);

  baseFare = distance * Booking::sBaseFarePerKm;

  loadedFare = baseFare * b_.GetFareLoadFactor();

  if ((int)distance >= b_.GetMinDistanceTatkal()) {
    tatkalCharges = loadedFare * 2 * b_.GetTatkalLoadFactor();

    if (tatkalCharges < b_.GetMinTatkalCharge())
      tatkalCharges = b_.GetMinTatkalCharge();
    else if (tatkalCharges > b_.GetMaxTatkalCharge())
      tatkalCharges = b_.GetMaxTatkalCharge();
  }

  finalFare = round(loadedFare + tatkalCharges + b_.GetReservationCharge());

  return finalFare;
}

void Booking::UnitTest() {
  Station f = Station::CreateStation("Mumbai");
  Station t = Station::CreateStation("Delhi");

  Date bo = Date::CreateDate(4, 10, 2020);
  Date r = Date::CreateDate(9, 4, 2021);

  Passenger p =
      Passenger::CreatePassenger("First", Gender::Male::Type(), "123456789012",
                                 Date::CreateDate(12, 10, 2020));

  // Constructor
  Booking *b1 = Booking::BookASeat(f, t, bo, r, BookingClasses::AC3Tier::Type(),
                                  p, General::Type());
  Booking *b2=Booking::BookASeat(f, t, bo, r, BookingClasses::AC3Tier::Type(),
                                  p, Tatkal::Type());

  // check
  assert(b1->calculatedFare == 1849);

}