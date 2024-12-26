// Name: Shrinivas Khiste
// Roll number: 19CS30043
#include "BookingClasses.h"

ostream& operator<<(ostream &os, const BookingClasses &b) 
{
  cout << b.GetName() << "\n";
  cout << " : Mode: ";
  if (b.IsSitting()) {
    cout << "Seating\n";
  } else {
    cout << "Sleeping\n";
  }
  cout << " : Comfort: ";
  if (b.IsAC()) {
    cout << "AC\n";
  } else {
    cout << "Non-AC\n";
  }
  cout << " : Bunks: " << b.GetNumberOfTiers() << "\n";
  cout << " : Luxury: ";
  if (b.IsLuxury()) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return os;
}
