#pragma once
#include "Effect.h"
#include <vector>

class Delay : public Effect {
    std::vector<float> buffer;
    int writeIndex = 0;
    int delaySamples;
public:
    Delay(int maxDelaySamples, int delaySamples);
    void process(float* input, int numSamples) override;
};

