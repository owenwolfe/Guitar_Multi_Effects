#include "EffectChain.h"

void EffectChain::addEffect(Effect* e) {
    effects.push_back(e);
}

void EffectChain::process(float* buffer, int numSamples) {
    for (auto* e : effects)
        e->process(buffer, numSamples);
}

EffectChain::~EffectChain() {
    for (auto* e : effects) delete e;
}

