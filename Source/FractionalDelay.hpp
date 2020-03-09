//
//  FractionalDelay.hpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#ifndef FractionalDelay_hpp
#define FractionalDelay_hpp

#include <cmath>
using namespace std;

class FractionalDelay {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    FractionalDelay();
    
    FractionalDelay(float delay, float speed);
    
    // Destructor
    ~FractionalDelay();
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setDelaySamples(float delay);
    
    void setSpeed(float speed);
    void setDepth(float depth);

    
private:
    
    float Fs = 48000.f;
    
    float delay = 5.f;
    
    const int MAX_BUFFER_SIZE = 96000;
    float delayBuffer[96000][2] = {0.0f};
    int index[2] = {0};
    
    float speed = 1.0f; // Hz, frequency of LFO
    float depth = 10.0f; // percentage of intensity, control amp of LFO
    
    float currentAngle[2] = {0.0f};
    float angleChange = speed * (1.f/Fs) * 2.f * M_PI;
    
    
    
};



#endif /* FractionalDelay_hpp */
