#pragma once

class Effect {
public:
    virtual void process(float* buffer, int numSamples) = 0;
    virtual ~Effect() {}
};

