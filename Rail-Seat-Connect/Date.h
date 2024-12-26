// Name: Shrinivas Khiste
// Roll number: 19CS30043
#ifndef __DATE_H__
#define __DATE_H_

#include <bits/stdc++.h>

using namespace std;

class Date {
  static const vector<string> sMonthNames;  // list of all month names

  typedef unsigned int UINT;
  UINT date_;
  UINT month_;
  UINT year_;

  Date(UINT d, UINT m, UINT y);

  Date(UINT d, string mon, UINT y);

 public:

  static Date CreateDate(UINT d, UINT m, UINT y);
  static Date CreateDate(UINT d, string mon, UINT y);

  static bool oneYearSpan(Date &d);

  static int calculateAge(const Date &d);

  static bool isLeap(Date &d);

  int GetDate();

  ~Date();

  friend ostream &operator<<(ostream &os,
                             const Date d);  // output stream operator

  friend bool operator==(const Date &, const Date &);  // equality operator
  friend bool operator<(const Date &, const Date &);
  friend bool operator<=(const Date &, const Date &);
  friend bool operator>=(const Date &, const Date &);
  friend bool operator>(const Date &, const Date &);

  static void UnitTest();  // static function to run unit tests
};
#endif  // __DATE_H__