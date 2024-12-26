#include "Divyang.h"

using namespace std;

template <>
const string DivyangType::Blind::sType = "Blind";

template <>
const string DivyangType::OrthopaedicallyHandicapped::sType =
    "OrthopaedicallyHandicapped";

template <>
const string DivyangType::CancerPatient::sType = "CancerPatient";

template <>
const string DivyangType::TBPatient::sType = "TBPatient";
