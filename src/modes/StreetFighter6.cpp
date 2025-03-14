#include "modes/StreetFighter6.hpp"

StreetFighter6::StreetFighter6(socd::SocdType socd_type) : ControllerMode(socd_type) {
    _socd_pair_count = 1;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left, &InputState::right},
    };
}

void StreetFighter6::HandleSocd(InputState &inputs) {
    if (inputs.down && (inputs.mod_x || inputs.c_up)) {
        inputs.down = false;
    }
    InputMode::HandleSocd(inputs);
}

void StreetFighter6::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.mod_x || inputs.up2;

    // Menu keys
    outputs.start = inputs.start;
    outputs.select = inputs.c_left;
    outputs.home = inputs.c_down;

    // Right hand bottom row
    outputs.a = inputs.b;
    outputs.b = inputs.x;
    outputs.triggerRDigital = inputs.z;
    outputs.triggerLDigital = inputs.up;

    // Right hand top row
    outputs.x = inputs.r;
    outputs.y = inputs.y;

    // Inverted to make menu traversal easier, requires rebinding in game
    outputs.buttonL = inputs.lightshield;
    outputs.buttonR = inputs.midshield;

    // Dedicated parry button
    outputs.rightStickClick = inputs.a;
}

void StreetFighter6::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
    outputs.triggerLAnalog = outputs.triggerLDigital ? 255 : 0;
    outputs.triggerRAnalog = outputs.triggerRDigital ? 255 : 0;
}
