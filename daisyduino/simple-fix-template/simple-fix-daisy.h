#pragma once

#include "DaisyDuino.h"

namespace synthux {
namespace simplefix {

enum class Analog {
    S30 = A0,
    S31 = A1,
    S32 = A2,
    S33 = A3
};

enum class Digital {
    S30 = D15,
    S31 = D16,
    S32 = D17,
    S33 = D18
};

template<class AP, class DP>
class Pin {
public:
  static int a(AP pin) {
    return int(pin);
  }

  static int d(DP pin) {
    return int(pin);
  }
};

using DaisyPin = Pin<Analog, Digital>; 
};
};

#define A(p) synthux::simplefix::DaisyPin::a(synthux::simplefix::Analog::p)
#define D(p) synthux::simplefix::DaisyPin::d(synthux::simplefix::Digital::p)
