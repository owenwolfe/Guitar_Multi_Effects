#include "AudioIO.h"
#include <sndfile.h>
#include <portaudio.h>
#include <vector>
#include <iostream>

// Offline WAV processing
void processOffline(const std::string& inputFile, const std::string& outputFile, EffectChain& chain) {
    SF_INFO sfInfo;
    SNDFILE* inFile = sf_open(inputFile.c_str(), SFM_READ, &sfInfo);
    if (!inFile) { std::cerr << "Failed to open input file\n"; return; }

    SNDFILE* outFile = sf_open(outputFile.c_str(), SFM_WRITE, &sfInfo);
    if (!outFile) { std::cerr << "Failed to open output file\n"; sf_close(inFile); return; }

    std::vector<float> buffer(sfInfo.frames * sfInfo.channels);
    sf_readf_float(inFile, buffer.data(), sfInfo.frames);

    chain.process(buffer.data(), buffer.size());

    sf_writef_float(outFile, buffer.data(), sfInfo.frames);

    sf_close(inFile);
    sf_close(outFile);
}

// Real-time processing skeleton
struct AudioData { EffectChain* chain; };

int audioCallback(const void* input, void* output, unsigned long frameCount,
                  const PaStreamCallbackTimeInfo*, PaStreamCallbackFlags, void* userData) {
    AudioData* data = (AudioData*)userData;
    float* in = (float*)input;
    float* out = (float*)output;

    std::vector<float> buffer(in, in + frameCount);
    data->chain->process(buffer.data(), buffer.size());
    std::copy(buffer.begin(), buffer.end(), out);

    return paContinue;
}

void setupRealtime(EffectChain& chain) {
    Pa_Initialize();
    PaStream* stream;
    AudioData data { &chain };

    Pa_OpenDefaultStream(&stream,
                         1, // mono input
                         1, // mono output
                         paFloat32,
                         44100,
                         256,
                         audioCallback,
                         &data);
    Pa_StartStream(stream);
    std::cout << "Press Enter to stop...\n";
    std::cin.get();
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
}

