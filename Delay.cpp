#include "Delay.h"

Delay::Delay(int maxDelaySamples, int d) : buffer(maxDelaySamples, 0.0f), delaySamples(d) {}

void Delay::process(float* input, int numSamples) {
    for (int i = 0; i < numSamples; ++i) {
        float delayedSample = buffer[writeIndex];
        buffer[writeIndex] = input[i] + 0.5f * delayedSample;
        input[i] += delayedSample;
        writeIndex = (writeIndex + 1) % buffer.size();
    }
}

