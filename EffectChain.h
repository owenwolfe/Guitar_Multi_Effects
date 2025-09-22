#pragma once
#include "Effect.h"
#include <vector>

class EffectChain {
    std::vector<Effect*> effects;
public:
    void addEffect(Effect* e);
    void process(float* buffer, int numSamples);
    ~EffectChain();
};

