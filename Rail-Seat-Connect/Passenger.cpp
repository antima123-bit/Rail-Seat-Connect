// Name: Shrinivas Khiste
// Roll number: 19CS30043
#include "Passenger.h"

// #include "Date.h"
#include "Exception.h"

Passenger::Passenger(string f, const Gender &g, string a, const Date &d,
                     string m, string l, string mob, DivyangType *dt,
                     string disI)
    : firstName_(f),
      middleName_(m),
      lastName_(l),
      aadhar_(a),
      mobile_(mob),
      disabilityId_(disI),
      divyangType_(dt),
      dob_(d),
      gender_(g) {}

Passenger Passenger::CreatePassenger(string f, const Gender &g, string a,
                                     const Date &d, string m, string l,
                                     string mob, DivyangType *dt, string disI) {
  bool isError = false;
  try {
    if ((l.length() == 0 && f.length() == 0)) {
      InvalidName ex;
      throw ex;
    }
  } catch (InvalidName e) {
    isError = true;
    e.print();
  }

  if (mob.length() != 0) {
    try {
      if (mob.length() != 10) {
        InvalidNumber ex;
        throw ex;
      }
      for (int i = 0; i < mob.length(); i++) {
        if (!isdigit(mob[i])) {
          InvalidNumber ex;
          throw ex;
        }
      }
    } catch (InvalidNumber e) {
      isError = true;
      e.print();
    }
  }

  try {
    if (a.length() != 12) {
      InvalidAadhar ex;
      throw ex;
    }

    for (int i = 0; i < a.length(); i++) {
      if (!isdigit(a[i])) {
        InvalidAadhar ex;
        throw ex;
      }
    }
  } catch (InvalidAadhar e) {
    isError = true;
    e.print();
  }

  try {
    time_t now = time(0);

    tm *ltm = localtime(&now);

    Date today =
        Date::CreateDate(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
    if (d >= today) {
      InvalidDOB ex;
      throw ex;
    }
  } catch (InvalidDOB e) {
    isError = true;
    e.print();
  }

  if (isError) {
    throw Bad_Passenger();
  }

  return Passenger(f, g, a, d, m, l, mob, dt, disI);
}

const Gender &Passenger::GetGender() const { return gender_; }

DivyangType *Passenger::GetDivyangType() const { return divyangType_; }

const Date &Passenger::GetDOB() const { return dob_; }

void Passenger::UnitTest() {
  // Constructors
  Passenger p1 =
      Passenger::CreatePassenger("First", Gender::Male::Type(), "123456789012",
                                 Date::CreateDate(12, 10, 2020));
  Passenger p2 =
      Passenger::CreatePassenger("", Gender::Male::Type(), "123456789012",
                                 Date::CreateDate(12, 10, 2020), "", "Last");

  // Exceptions
  try {
    Passenger p3 =
        Passenger::CreatePassenger("", Gender::Male::Type(), "123456789012",
                                   Date::CreateDate(12, 10, 2020));
  } catch (Bad_Passenger e) {
    e.print();
  }

  try {
    Passenger p4 =
        Passenger::CreatePassenger("First", Gender::Male::Type(), "12345678901",
                                   Date::CreateDate(12, 10, 2020));
  } catch (Bad_Passenger e) {
    e.print();
  }

  try {
    Passenger p5 = Passenger::CreatePassenger("First", Gender::Male::Type(),
                                              "123456789012",
                                              Date::CreateDate(12, 10, 2021));
  } catch (Bad_Passenger e) {
    e.print();
  }

  try {
    Passenger p5 = Passenger::CreatePassenger(
        "First", Gender::Male::Type(), "123456789021",
        Date::CreateDate(12, 10, 2020), "", "", "123456789");
  } catch (Bad_Passenger e) {
    e.print();
  }

  try {
    Passenger p6 = Passenger::CreatePassenger(
        "First", Gender::Male::Type(), "123456a89021",
        Date::CreateDate(12, 10, 2020), "", "", "1234567890");
  } catch (Bad_Passenger e) {
    e.print();
  }

  try {
    Passenger p7 = Passenger::CreatePassenger(
        "First", Gender::Male::Type(), "123456189021",
        Date::CreateDate(12, 10, 2020), "", "", "12345a789");
  } catch (Bad_Passenger e) {
    e.print();
  }

  // Multiple
  try {
    Passenger p7 = Passenger::CreatePassenger(
        "First", Gender::Male::Type(), "12345a189021",
        Date::CreateDate(12, 10, 2020), "", "", "12345a789");
  } catch (Bad_Passenger e) {
    e.print();
  }
}
