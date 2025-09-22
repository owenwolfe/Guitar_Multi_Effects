#pragma once
#include "Effect.h"

class Distortion : public Effect {
    float gain;
public:
    Distortion(float g);
    void process(float* buffer, int numSamples) override;
};

