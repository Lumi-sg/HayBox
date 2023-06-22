#ifndef _MODES_STREETFIGHTER6_HPP
#define _MODES_STREETFIGHTER6_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

class StreetFighter6 : public ControllerMode {
  public:
    StreetFighter6(socd::SocdType socd_type);

  private:
    void HandleSocd(InputState &inputs);
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);
};

#endif
