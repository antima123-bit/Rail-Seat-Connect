// Name: Shrinivas Khiste
// Roll number: 19CS30043
// Start of Railways.h
#ifndef _RAILWAYS_H
#define _RAILWAYS_H
#include <bits/stdc++.h>

#include "Booking.h"
#include "Station.h"

using namespace std;

class Railways {
  Railways();

  static const vector<string> sStations;  // list of all station names

  static map<pair<string, string>, int> sDistStations;  // map storing distance

 public:
  ~Railways();

  static const Railways &
  railways();  // Function made to maintain the singleton property

  int GetDistance(const Station &s1, const Station &s2)
      const;  // Takes two stations as input as returns distance between them.

  static void UnitTest();  // static function to run unit tests

  friend Station Station::CreateStation(string name);
  friend Booking *Booking::BookASeat(Station &f, Station &t, Date &bo, Date &r,
                                     const BookingClasses &b, Passenger &p,
                                     BookingCategory &bc);
};
#endif  //_RAILWAYS_H
        // End of Railways.h