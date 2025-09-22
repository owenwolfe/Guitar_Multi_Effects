#pragma once
#include "EffectChain.h"
#include <string>

void processOffline(const std::string& inputFile, const std::string& outputFile, EffectChain& chain);
void setupRealtime(EffectChain& chain);

