#include "Concession.h"

float GeneralConcession::GetConcessionFactor() { return 0.0; }

float LadiesConcession::GetConcessionFactor(const Passenger &p) { return 0.0; }

float SeniorCitizenConcession::GetConcessionFactor(const Passenger &p) {
  if (Gender::IsMale(p.GetGender())) {
    return 0.40;
  } else {
    return 0.50;
  }
}

map<pair<string, string>, int>
    DivyangConcession::sDisabilityConcessionFactorMatrix = {
        {{"ACFirstClass", "Blind"}, 0.50},
        {{"ACFirstClass", "OrthopaedicallyHandicapped"}, 0.50},
        {{"ACFirstClass", "CancerPatient"}, 0.50},
        {{"ACFirstClass", "TBPatient"}, 0.00},

        {{"ExecutiveChairCar", "Blind"}, 0.75},
        {{"ExecutiveChairCar", "OrthopaedicallyHandicapped"}, 0.75},
        {{"ExecutiveChairCar", "CancerPatient"}, 0.75},
        {{"ExecutiveChairCar", "TBPatient"}, 0.00},

        {{"AC2Tier", "Blind"}, 0.50},
        {{"AC2Tier", "OrthopaedicallyHandicapped"}, 0.50},
        {{"AC2Tier", "CancerPatient"}, 0.50},
        {{"AC2Tier", "TBPatient"}, 0.00},

        {{"FirstClass", "Blind"}, 0.75},
        {{"FirstClass", "OrthopaedicallyHandicapped"}, 0.75},
        {{"FirstClass", "CancerPatient"}, 0.75},
        {{"FirstClass", "TBPatient"}, 0.75},

        {{"AC3Tier", "Blind"}, 0.75},
        {{"AC3Tier", "OrthopaedicallyHandicapped"}, 0.75},
        {{"AC3Tier", "CancerPatient"}, 1.00},
        {{"AC3Tier", "TBPatient"}, 0.00},

        {{"ACChairCar", "Blind"}, 0.75},
        {{"ACChairCar", "OrthopaedicallyHandicapped"}, 0.75},
        {{"ACChairCar", "CancerPatient"}, 1.00},
        {{"ACChairCar", "TBPatient"}, 0.00},

        {{"Sleeper", "Blind"}, 0.75},
        {{"Sleeper", "OrthopaedicallyHandicapped"}, 0.75},
        {{"Sleeper", "CancerPatient"}, 1.00},
        {{"Sleeper", "TBPatient"}, 0.75},

        {{"SecondSitting", "Blind"}, 0.75},
        {{"SecondSitting", "OrthopaedicallyHandicapped"}, 0.75},
        {{"SecondSitting", "CancerPatient"}, 1.00},
        {{"SecondSitting", "TBPatient"}, 0.75},
};

float DivyangConcession::GetConcessionFactor(const Passenger &p,
                                             const BookingClasses &bc) {
  return sDisabilityConcessionFactorMatrix[{bc.GetName(),
                                            p.GetDivyangType()->GetType()}];
}

void Concession::UnitTest() {
  DivyangType *d = DivyangType::Blind::Type();
  Passenger p =
      Passenger::CreatePassenger("First", Gender::Male::Type(), "123456789012",
                                 Date::CreateDate(12, 10, 1920), "", "", "", d);

  GeneralConcession gc;
  LadiesConcession lc;
  SeniorCitizenConcession sc;
  DivyangConcession dc;

  assert(gc.GetConcessionFactor() == 0);
  assert(lc.GetConcessionFactor(p) == 0);
  assert(sc.GetConcessionFactor(p) - 0.40 < 1e-5);
  assert(dc.GetConcessionFactor(p, BookingClasses::AC3Tier::Type())-0.75< 1e-5);
}
