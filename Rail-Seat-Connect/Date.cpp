// Name: Shrinivas Khiste
// Roll number: 19CS30043
#include "Date.h"

#include <ctime>

#include "Exception.h"

const vector<string> Date::sMonthNames{"Jan", "Feb", "Mar", "Apr",
                                       "May", "Jun", "Jul", "Aug",
                                       "Sep", "Oct", "Nov", "Dec"};

Date::Date(UINT d, UINT m, UINT y) : date_(d), month_(m), year_(y) {}

Date::Date(UINT d, string mon, UINT y) : date_(d), year_(y) {
  month_ = find(sMonthNames.begin(), sMonthNames.end(), mon) -
           sMonthNames.begin() + 1;
}

Date Date::CreateDate(UINT d, UINT m, UINT y) {
  bool isError = false;

  try {
    if (y < 1900 || y > 2099) {
      InvalidYear ex;
      throw ex;
    }
  } catch (InvalidYear e) {
    e.print();
    isError = true;
  }

  try {
    if ((m > 12 || m < 1) || (d < 1 || d > 31)) {
      InvalidDate ex;
      throw ex;
    } else if ((m == 4 || m == 6 | m == 9 || m == 11) && (d > 30)) {
      InvalidDate ex;
      throw ex;
    } else if (m == 2 && ((y % 4 == 0 && d > 29) || (y % 4 != 0 && d > 28))) {
      InvalidDate ex;
      throw ex;
    }
  } catch (InvalidDate e) {
    e.print();
    isError = true;
  }

  if (isError) {
    throw Bad_Date();
  }

  Date d1(d, m, y);

  return d1;
}

Date Date::CreateDate(UINT d, string m, UINT y) {
  bool isError = false;

  try {
    if (y < 1900 || y > 2099) {
      InvalidYear ex;
      throw ex;
    }
  } catch (InvalidYear e) {
    e.print();
    isError = true;
  }

  try {
    if (find(sMonthNames.begin(), sMonthNames.end(), m) == sMonthNames.end() ||
        (d < 1 || d > 31)) {
      InvalidDate ex;
      throw ex;
    } else if ((m == "Apr" || m == "Jun" | m == "Sep" || m == "Dec") &&
               (d > 30)) {
      InvalidDate ex;
      throw ex;
    } else if (m == "Feb" &&
               ((y % 4 == 0 && d > 29) || (y % 4 != 0 && d > 28))) {
      InvalidDate ex;
      throw ex;
    }
  } catch (InvalidDate e) {
    e.print();
    isError = true;
  }

  if (isError) {
    throw Bad_Date();
  }

  Date d1(d, m, y);

  return d1;
}

bool Date::oneYearSpan(Date &d) {
  time_t today = time(0);

  tm *ltm = localtime(&today);

  if (d.year_ <= 1900 + ltm->tm_year) {
    return false;
  }
  if (d.year_ == 1900 + ltm->tm_year + 1) {
    if (d.month_ < ltm->tm_mon + 1) {
      return false;
    } else if (d.month_ == ltm->tm_mon + 1) {
      if (d.date_ < ltm->tm_mday) {
        return false;
      }
    }
  }
  return true;
}

int Date::calculateAge(const Date &d) {
  time_t today = time(0);

  tm *ltm = localtime(&today);

  return 1900 + ltm->tm_year - d.year_;
}

bool Date::isLeap(Date &d) { return d.year_ % 4 == 0; }

int Date::GetDate() { return date_; }

Date::~Date() {}

bool operator>=(const Date &d1, const Date &d2) { return d1 > d2 || d1 == d2; }

bool operator<=(const Date &d1, const Date &d2) { return d1 < d2 || d1 == d2; }

bool operator>(const Date &d1, const Date &d2) {
  if (d1.year_ != d2.year_) {
    return d1.year_ > d2.year_;
  } else {
    if (d1.month_ != d2.month_) {
      return d1.month_ > d2.month_;
    } else {
      return d1.date_ > d2.date_;
    }
  }
}

bool operator<(const Date &d1, const Date &d2) { return (!(d1 > d2)); }

ostream &operator<<(ostream &os, const Date d) {
  cout << d.date_ << "/" << Date::sMonthNames[d.month_ - 1] << "/" << d.year_;

  return os;
}

void Date::UnitTest() {
  Date d = Date::CreateDate(10, 3, 2021);
  Date d1 = Date::CreateDate(10, "Mar", 2021);

  // Check constructor
  assert(d.date_ == 10 && d.month_ == 3 && d.year_ == 2021);
  assert(d1.date_ == 10 && d1.month_ == 3 && d1.year_ == 2021);

  // Exceptions
  try {
    Date d = CreateDate(10, 4, 1800);
  } catch (Bad_Date e) {
    e.print();
  }
  try {
    Date d = CreateDate(10, 13, 2021);
  } catch (Bad_Date e) {
    e.print();
  }

  try {
    Date d = CreateDate(31, 11, 2021);
  } catch (Bad_Date e) {
    e.print();
  }

  // no exception here
  try {
    Date d = CreateDate(29, 2, 2020);
  } catch (Bad_Date e) {
    e.print();
  }

  try {
    Date d = CreateDate(29, "mar", 2021);
  } catch (Bad_Date e) {
    e.print();
  }

  try {
    Date d = CreateDate(29, "Feb", 2021);
  } catch (Bad_Date e) {
    e.print();
  }
}

bool operator==(const Date &d1, const Date &d2) {
  if (d1.date_ == d2.date_ && d1.month_ == d2.month_ && d1.year_ == d2.year_) {
    return true;
  }
  return false;
}
