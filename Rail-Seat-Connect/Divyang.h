#ifndef __DIVYANG_H__
#define __DIVYANG_H__

#include <bits/stdc++.h>

#include <string>

using namespace std;

template <typename T>
class DivyangTypes;

class DivyangType {
  static const string sType;

  struct BlindType {};
  struct OrthopaedType {};
  struct CancerType {};
  struct TBType {};

 protected:
  DivyangType(){};

 public:
  virtual string GetType()=0;

  virtual ~DivyangType(){};

  typedef DivyangTypes<BlindType> Blind;
  typedef DivyangTypes<OrthopaedType> OrthopaedicallyHandicapped;
  typedef DivyangTypes<CancerType> CancerPatient;
  typedef DivyangTypes<TBType> TBPatient;
};

template <typename T>
class DivyangTypes : public DivyangType {
  static const string sType;

  DivyangTypes(){};

 public:
  static DivyangTypes<T>* Type() {
    static DivyangTypes<T> theObj;

    return &theObj;
  };

  string GetType() { return DivyangTypes<T>::sType; };

  ~DivyangTypes(){};
};

#endif  // __DIVYANG_H__