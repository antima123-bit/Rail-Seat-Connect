#include "Exception.h"

void InvalidDate::print() { cout << "ERROR: Invalid Date encountered!\n"; }

void InvalidYear::print() {
  cout << "ERROR: Invalid Year entered! Should be between 1900 to 2099\n";
}

void Bad_Station::print() { cout << "ERROR: Invalid Station Name\n"; }

void DuplicateStation::print() { cout << "ERROR: Duplicate Station Name!\n"; }

void DuplicateDistance::print() { cout << "ERROR: Duplicate Distance!\n"; }

void Bad_Passenger::print() { cout << "ERROR: Invalid Passenger Details\n"; }

void InvalidName::print() { cout << "ERROR: Invalid Passenger Name!\n"; }

void InvalidAadhar::print() {
  cout << "ERROR: Invalid Passenger Aadhar Number!\n";
}

void InvalidNumber::print() { cout << "ERROR: Invalid Passenger Number!\n"; }

void InvalidDOB::print() { cout << "ERROR: Invalid Passenger DOB!\n"; }

void Bad_Booking::print() { cout << "ERROR: Invalid Booking Details\n"; }

void InvalidStation::print() {
  cout << "ERROR: Station not in list of Stations!\n";
}

void InvalidBookingDate::print() { cout << "ERROR: Invalid Booking Date!\n"; }

void InvalidCategory::print() { cout << "ERROR: Invalid Booking Category!\n"; }

void Bad_Date::print() { cout << "ERROR: Invalid Date\n"; }
