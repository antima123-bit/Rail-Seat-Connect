#ifndef __BOOKING_H__
#define __BOOKING_H__

#include "BookingCategory.h"
#include "BookingClasses.h"
#include "Passenger.h"
#include "Station.h"

using namespace std;

class BookingCategory;

template <typename T>
class BookingTypes;

class Booking {
 protected:
  const Station fromStation_, toStation_;
  const Date dateOfBooking, dateOfReservation_;
  const BookingClasses &b_;
  Passenger &p_;
  BookingCategory &bc_;
  int PNR_, calculatedFare;

  static const float sBaseFarePerKm;  // base fair per km
  static int sBookingPNRSerial;       // next PNR serial

 public:
  // static vector<Booking> sBookings;
  Booking(Station &f, Station &t, Date &bo, Date &r, const BookingClasses &b,
          Passenger &p, BookingCategory &bc);

  static Booking *BookASeat(Station &f, Station &t, Date &bo, Date &r,
                            const BookingClasses &b, Passenger &p,
                            BookingCategory &bc);

  virtual int calculateFare() = 0;

  friend ostream& operator<< (ostream& os,const Booking& b);

  virtual ~Booking(){};

  static void UnitTest();
};

class GeneralBooking : public Booking {
 public:
  GeneralBooking(Station &f, Station &t, Date &bo, Date &r,
                 const BookingClasses &b, Passenger &p, BookingCategory &bc);

  int calculateFare();
};

class LadiesBooking : public Booking {
 public:
  LadiesBooking(Station &f, Station &t, Date &bo, Date &r,
                const BookingClasses &b, Passenger &p, BookingCategory &bc);

  int calculateFare();
};

class SeniorCitizenBooking : public Booking {
 public:
  SeniorCitizenBooking(Station &f, Station &t, Date &bo, Date &r,
                       const BookingClasses &b, Passenger &p,
                       BookingCategory &bc);

  int calculateFare();
};

class DivyangBooking : public Booking {
 public:
  DivyangBooking(Station &f, Station &t, Date &bo, Date &r,
                 const BookingClasses &b, Passenger &p, BookingCategory &bc);

  int calculateFare();
};

class TatkalBooking : public Booking {
 public:
  TatkalBooking(Station &f, Station &t, Date &bo, Date &r,
                const BookingClasses &b, Passenger &p, BookingCategory &bc);

  int calculateFare();
};

class PremiumTatkalBooking : public Booking {
 public:
  PremiumTatkalBooking(Station &f, Station &t, Date &bo, Date &r,
                       const BookingClasses &b, Passenger &p,
                       BookingCategory &bc);

  int calculateFare();
};
#endif  // __BOOKING_H__