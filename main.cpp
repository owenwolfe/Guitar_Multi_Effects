#include "Distortion.h"
#include "Delay.h"
#include "EffectChain.h"
#include "AudioIO.h"
#include <iostream>

int main() {
    EffectChain chain;
    chain.addEffect(new Distortion(2.0f));
    chain.addEffect(new Delay(44100, 22050)); // 0.5s delay at 44.1kHz

    int mode;
    std::cout << "Select mode: 1 = Offline, 2 = Real-time: ";
    std::cin >> mode;

    if (mode == 1) {
        std::string inputFile, outputFile;
        std::cout << "Input WAV: "; std::cin >> inputFile;
        std::cout << "Output WAV: "; std::cin >> outputFile;
        processOffline(inputFile, outputFile, chain);
        std::cout << "Processing done!\n";
    } else {
        setupRealtime(chain);
    }

    return 0;
}

