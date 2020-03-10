//
//  APF.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "APF.hpp"


APF::APF(){
}

APF::APF(float delay, float speed){
    fractionalDelay.setDelaySamples(delay);
    fractionalDelay.setSpeed(speed);
}

// Destructor
APF::~APF(){
}


float APF::processSample(float x, int channel){
    
    // Inputs to Delay Lines
    float inDL = x + feedbackGain * fb[channel];
    
    // Output of Delay
    float outDL = fractionalDelay.processSample(inDL, channel);
    
    float y = -feedbackGain * x + outDL;
    
    // Calculate FB terms for next loop
    fb[channel] = y;
    
    return y;
}

void APF::setFs(float Fs){
    this->Fs = Fs;
    fractionalDelay.setFs(Fs);
}


void APF::setFeedbackGain(float feedbackGain){
    this->feedbackGain = feedbackGain;
}

void APF::setDepth(float depth){
    if (depth >= 1.0f && depth <= 10.0f){
        this->depth = depth;
        fractionalDelay.setDepth(depth);
    }
}
