// Name: Shrinivas Khiste
// Roll number: 19CS30043
#include "Railways.h"

#include "Exception.h"

Railways::~Railways() {}

Railways::Railways() {}

const vector<string> Railways::sStations{
    "Mumbai", "Delhi", "Kolkata", "Chennai", "Bangalore",
};

map<pair<string, string>, int> Railways::sDistStations = {
    {{"Mumbai", "Delhi"}, 1447},     {{"Mumbai", "Bangalore"}, 981},
    {{"Mumbai", "Kolkata"}, 2014},   {{"Mumbai", "Chennai"}, 1338},
    {{"Delhi", "Bangalore"}, 2150},  {{"Delhi", "Kolkata"}, 1472},
    {{"Delhi", "Chennai"}, 2180},    {{"Bangalore", "Kolkata"}, 1871},
    {{"Bangalore", "Chennai"}, 350}, {{"Kolkata", "Chennai"}, 1659},
};

const Railways &Railways::railways() {
  bool isError = false;
  static const Railways IndianRailways;

  set<string> s(Railways::sStations.begin(), Railways::sStations.end());
  try {
    if (s.size() != 5) {
      DuplicateStation ex;
      throw ex;
    }
  } catch (DuplicateStation e) {
    e.print();
    isError = true;
  }
  try {
    if (Railways::sDistStations.size() != 10) {
      DuplicateDistance ex;
      throw ex;
    }
  } catch (DuplicateDistance e) {
    e.print();
    isError = true;
  }

  if (isError) {
    throw Bad_Railways();
  }

  return IndianRailways;
}

int Railways::GetDistance(const Station &s1, const Station &s2) const {
  if (Railways::sDistStations.find({s1.GetName(), s2.GetName()}) ==
      Railways::sDistStations.end()) {
    return Railways::sDistStations[{s2.GetName(), s1.GetName()}];
  }
  return Railways::sDistStations[{s1.GetName(), s2.GetName()}];
}

void Railways::UnitTest() {
  Station s1 = Station::CreateStation("Mumbai"),
          s2 = Station::CreateStation("Delhi");

  // Check Get Distance
  assert(Railways::railways().GetDistance(s1, s2) == 1447);

  // Check for reverse
  assert(Railways::railways().GetDistance(s2, s1) == 1447);
}