#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <exception>
#include <iostream>

using namespace std;

class Bad_Date : public exception {
 public:
  void print();
  ~Bad_Date(){};
};

class InvalidDate : public Bad_Date {
 public:
  void print();
  ~InvalidDate(){};
};

class InvalidYear : public Bad_Date {
 public:
  void print();
  ~InvalidYear(){};
};

class Bad_Station : public exception {
 public:
  void print();
  ~Bad_Station(){};
};


class Bad_Railways : public exception {
 public:
  void print();
  ~Bad_Railways(){};
};

class DuplicateStation : public Bad_Railways {
 public:
  void print();
  ~DuplicateStation(){};
};

class DuplicateDistance : public Bad_Railways {
 public:
  void print();
  ~DuplicateDistance(){};
};

class Bad_Passenger : public exception {
 public:
  void print();
  ~Bad_Passenger(){};
};

class InvalidName : public Bad_Passenger {
 public:
  void print();
  ~InvalidName(){};
};

class InvalidAadhar : public Bad_Passenger {
 public:
  void print();
  ~InvalidAadhar(){};
};

class InvalidNumber : public Bad_Passenger {
 public:
  void print();
  ~InvalidNumber(){};
};

class InvalidDOB : public Bad_Passenger {
 public:
  void print();
  ~InvalidDOB(){};
};

class Bad_Booking : public exception {
 public:
  void print();
  ~Bad_Booking(){};
};

class InvalidStation : public Bad_Booking {
 public:
  void print();
  ~InvalidStation(){};
};

class InvalidBookingDate : public Bad_Booking {
 public:
  void print();
  ~InvalidBookingDate(){};
};

class InvalidCategory : public Bad_Booking {
 public:
  void print();
  ~InvalidCategory(){};
};

#endif  // __EXCEPTION_H__