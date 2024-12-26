#ifndef __BOOKINGCATEGORY_H__
#define __BOOKINGCATEGORY_H__

#include <cstring>

#include "Booking.h"
#include "BookingClasses.h"
#include "Passenger.h"
#include "Station.h"

using namespace std;

class Booking;

class BookingCategory {
  string name_, remark_;

 public:
  BookingCategory(){};
  virtual ~BookingCategory(){};
  virtual Booking *CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                    const BookingClasses &b, Passenger &p)=0;

  virtual bool CheckValidity(Passenger &p,Date &dor) = 0;

  virtual string GetName() = 0;

  static void UnitTest();
};

class General : public BookingCategory {
  string name_, remark_;

  General(string n,string r);

 public:
  static General &Type();

  Booking *CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                    const BookingClasses &b, Passenger &p);

  bool CheckValidity(Passenger &p,Date &dor);

  string GetName();

  ~General(){};
};

class Ladies : public BookingCategory {
  string name_, remark_;

  Ladies(string n,string r);

 public:
  static Ladies &Type();

  Booking *CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                    const BookingClasses &b, Passenger &p);

  bool CheckValidity(Passenger &p,Date &dor);

  string GetName();

  ~Ladies(){};
};

class SeniorCitizen : public BookingCategory {
  string name_, remark_;

  SeniorCitizen(string n,string r);

 public:
  static SeniorCitizen &Type();

  Booking *CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                    const BookingClasses &b, Passenger &p);

  bool CheckValidity(Passenger &p,Date &dor);

  string GetName();

  ~SeniorCitizen(){};
};
class Divyang : public BookingCategory {
  string name_, remark_;

  Divyang(string n,string r);

 public:
  static Divyang &Type();

  Booking *CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                    const BookingClasses &b, Passenger &p);

  bool CheckValidity(Passenger &p,Date &dor);

  string GetName();

  ~Divyang(){};
};
class Tatkal : public BookingCategory {
  string name_, remark_;

  Tatkal(string n,string r);

 public:
  static Tatkal &Type();

  Booking *CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                    const BookingClasses &b, Passenger &p);

  bool CheckValidity(Passenger &p,Date &dor);

  string GetName();

  ~Tatkal(){};
};
class PremiumTatkal : public BookingCategory {
  string name_, remark_;

  PremiumTatkal(string n,string r);

 public:
  static PremiumTatkal &Type();

  Booking *CreateBookingObject(Station &f, Station &t, Date &bo, Date &r,
                    const BookingClasses &b, Passenger &p);

  bool CheckValidity(Passenger &p,Date &dor);

  string GetName();

  ~PremiumTatkal(){};
};

#endif  // __BOOKINGCATEGORY_H__