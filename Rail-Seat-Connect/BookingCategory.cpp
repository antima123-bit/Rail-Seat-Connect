#include "BookingCategory.h"

#include <ctime>

#include "Booking.h"
// General
bool General::CheckValidity(Passenger &p, Date &dor) { return true; }

Booking *General::CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                                      const BookingClasses &b, Passenger &p) {
  GeneralBooking *booking = new GeneralBooking(f, t, bo, r, b, p, *this);

  return booking;
}

string General::GetName() { return name_; }

General::General(string n, string r) {
  name_ = n;
  remark_ = r;
}

General &General::Type() {
  static General obj("General", "G");
  return obj;
}

// Ladies
bool Ladies::CheckValidity(Passenger &p, Date &dor) {
  return !Gender::IsMale(p.GetGender());
}

Booking *Ladies::CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                                     const BookingClasses &b, Passenger &p) {
  LadiesBooking *booking = new LadiesBooking(f, t, bo, r, b, p, *this);

  return booking;
}

string Ladies::GetName() { return name_; }

Ladies::Ladies(string n, string r) {
  name_ = n;
  remark_ = r;
}

Ladies &Ladies::Type() {
  static Ladies obj("Ladies", "G");
  return obj;
}

// SeniorCitizen
bool SeniorCitizen::CheckValidity(Passenger &p, Date &dor) {
  if ((Gender::IsMale(p.GetGender())) &&
      (Date::calculateAge(p.GetDOB()) >= 60)) {
    return true;
  }
  if ((!Gender::IsMale(p.GetGender())) &&
      (Date::calculateAge(p.GetDOB()) >= 58)) {
    return true;
  }
  return false;
}

Booking *SeniorCitizen::CreateBookingObject(Station &f, Station &t, Date &bo,
                                            Date &r, const BookingClasses &b,
                                            Passenger &p) {
  SeniorCitizenBooking *booking =
      new SeniorCitizenBooking(f, t, bo, r, b, p, *this);

  return booking;
}

string SeniorCitizen::GetName() { return name_; }

SeniorCitizen::SeniorCitizen(string n, string r) {
  name_ = n;
  remark_ = r;
}

SeniorCitizen &SeniorCitizen::Type() {
  static SeniorCitizen obj("SeniorCitizen", "G");
  return obj;
}

// Divyang
bool Divyang::CheckValidity(Passenger &p, Date &dor) {
  return p.GetDivyangType() != NULL;
}

Booking *Divyang::CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                                      const BookingClasses &b, Passenger &p) {
  DivyangBooking *booking = new DivyangBooking(f, t, bo, r, b, p, *this);

  return booking;
}

string Divyang::GetName() { return name_; }

Divyang::Divyang(string n, string r) {
  name_ = n;
  remark_ = r;
}

Divyang &Divyang::Type() {
  static Divyang obj("Divyang", "G");
  return obj;
}

// Tatkal
bool Tatkal::CheckValidity(Passenger &p, Date &dor) {
  time_t today = time(0);

  tm *ltm = localtime(&today);
  if (ltm->tm_mday - 1 == dor.GetDate()) {
    return true;
  }
  return false;
}

Booking *Tatkal::CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                                     const BookingClasses &b, Passenger &p) {
  TatkalBooking *booking = new TatkalBooking(f, t, bo, r, b, p, *this);

  return booking;
}

string Tatkal::GetName() { return name_; }

Tatkal::Tatkal(string n, string r) {
  name_ = n;
  remark_ = r;
}

Tatkal &Tatkal::Type() {
  static Tatkal obj("Tatkal", "G");
  return obj;
}

// PremiumTatkal
bool PremiumTatkal::CheckValidity(Passenger &p, Date &dor) {
  time_t today = time(0);

  tm *ltm = localtime(&today);

  if (ltm->tm_mday - 1 == dor.GetDate()) {
    return true;
  }
  return false;
}

Booking *PremiumTatkal::CreateBookingObject(Station &f, Station &t, Date &bo,
                                            Date &r, const BookingClasses &b,
                                            Passenger &p) {
  PremiumTatkalBooking *booking =
      new PremiumTatkalBooking(f, t, bo, r, b, p, *this);

  return booking;
}

string PremiumTatkal::GetName() { return name_; }

PremiumTatkal::PremiumTatkal(string n, string r) {
  name_ = n;
  remark_ = r;
}

PremiumTatkal &PremiumTatkal::Type() {
  static PremiumTatkal obj("PremiumTatkal", "G");
  return obj;
}

void BookingCategory::UnitTest() {
  DivyangType *d = DivyangType::Blind::Type();
  Passenger p =
      Passenger::CreatePassenger("First", Gender::Male::Type(), "123456789012",
                                 Date::CreateDate(12, 10, 1920), "", "", "", d);

  Date r = Date::CreateDate(8, 4, 2021);

  BookingCategory &lbc = Ladies::Type();
  BookingCategory &gbc = General::Type();
  BookingCategory &scbc = SeniorCitizen::Type();
  BookingCategory &dbc = Divyang::Type();
  BookingCategory &tbc = Tatkal::Type();
  BookingCategory &ptbc = PremiumTatkal::Type();

  // name
  assert(lbc.GetName() == "Ladies");

  // validity
  assert(gbc.CheckValidity(p, r) == true);
  assert(lbc.CheckValidity(p, r) == false);
  assert(scbc.CheckValidity(p, r) == true);
  assert(dbc.CheckValidity(p, r) == true);
  assert(tbc.CheckValidity(p, r) == true);
  assert(ptbc.CheckValidity(p, r) == true);
}
