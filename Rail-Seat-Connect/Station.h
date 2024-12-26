// Name: Shrinivas Khiste
// Roll number: 19CS30043
// Start of Station.h
#ifndef _STATION_H
#define _STATION_H
#include <bits/stdc++.h>

using namespace std;

class Station{
    const string name_;

    Station(string name);

    public:
        static Station CreateStation(string name);  

        string GetName() const; //Returns name of the Station.

        int GetDistance(const Station &other) const; //Returns distance of this station from another

        friend ostream& operator<<(ostream &os,const Station &s); //output stream operator

        static void UnitTest(); // static function to run unit tests

        ~Station();
};
#endif //_STATION_H
// End of Station.h