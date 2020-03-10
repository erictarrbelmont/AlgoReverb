//
//  FDN.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "FDN.hpp"


FDN::FDN(){
}

// Destructor
FDN::~FDN(){
}


float FDN::processSample(float x, int channel){
    
    // Inputs to Delay Lines
    float inDL1 = x + fb1[channel];
    float inDL2 = x + fb2[channel];
    float inDL3 = x + fb3[channel];
    float inDL4 = x + fb4[channel];
    
    // Output of Delay Lines
    float outDL1 = fractionalDelay1.processSample(inDL1, channel);
    float outDL2 = fractionalDelay2.processSample(inDL2, channel);
    float outDL3 = fractionalDelay3.processSample(inDL3, channel);
    float outDL4 = fractionalDelay4.processSample(inDL4, channel);
    
    // Combine parallel delay line paths
    float y = 0.25f * (outDL1 + outDL2 + outDL3 + outDL4);
    
    // Calculate FB terms for next loop
    fb1[channel] = feedbackGain * (-outDL2 + outDL3);
    fb2[channel] = feedbackGain * (outDL1 + outDL4);
    fb3[channel] = feedbackGain * (outDL1 + -outDL4);
    fb4[channel] = feedbackGain * (-outDL2 + -outDL3);
    
    return y;
}

void FDN::setFs(float Fs){
    this->Fs = Fs;
    fractionalDelay1.setFs(Fs);
    fractionalDelay2.setFs(Fs);
    fractionalDelay3.setFs(Fs);
    fractionalDelay4.setFs(Fs);
}


void FDN::setFeedbackGain(float feedbackGain){
    this->feedbackGain = feedbackGain;
}

void FDN::setDepth(float depth){
    if (depth >= 1.0f && depth <= 10.0f){
        this->depth = depth;
        fractionalDelay1.setDepth(depth);
        fractionalDelay2.setDepth(depth);
        fractionalDelay3.setDepth(depth);
        fractionalDelay4.setDepth(depth);
    }
}
