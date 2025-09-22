#include "Distortion.h"
#include <algorithm>

Distortion::Distortion(float g) : gain(g) {}

void Distortion::process(float* buffer, int numSamples) {
    for (int i = 0; i < numSamples; ++i) {
        buffer[i] *= gain;
        if (buffer[i] > 1.0f) buffer[i] = 1.0f;
        if (buffer[i] < -1.0f) buffer[i] = -1.0f;
    }
}

