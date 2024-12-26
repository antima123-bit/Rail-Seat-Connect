// Name: Shrinivas Khiste
// Roll number: 19CS30043
#include "Station.h"

#include "Exception.h"
#include "Railways.h"

Station::Station(string name) : name_(name) {}

Station Station::CreateStation(string name) {
  bool isError = false;

  try {
    if (name.length() == 0) {
      Bad_Station ex;
      throw ex;
    }
  } catch (Bad_Station e) {
    e.print();
    isError = true;
  }

  if (isError) {
    throw Bad_Station();
  }

  return Station(name);
}

string Station::GetName() const { return name_; }

int Station::GetDistance(const Station &other) const {
  return Railways::railways().GetDistance(*this, other);
}

ostream &operator<<(ostream &os, const Station &s) {
  os << s.name_;
  return os;
}

Station::~Station() {}

void Station::UnitTest() {
  Station s = Station::CreateStation("Mumbai");

  // check name
  assert(s.GetName() == "Mumbai");

  // check exception
  try {
    Station s1 = Station::CreateStation("");
  } catch (Bad_Station &e) {
    e.print();
  }

  // check distance
  Station s2=Station::CreateStation("Delhi");
  assert(s.GetDistance(s2) == 1447);
}