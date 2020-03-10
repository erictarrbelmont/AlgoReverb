//
//  APF.hpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#ifndef APF_hpp
#define APF_hpp

#include "FractionalDelay.hpp"
#include <cmath>
using namespace std;

class APF {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    APF();
    
    APF(float delay, float speed);
    
    // Destructor
    ~APF();
    
    float processSample(float x,int channel);

    void setFs(float Fs);

    void setDepth(float depth);
    void setFeedbackGain(float feedbackGain);
    
private:
    
    float Fs = 48000.f;
    
    float depth = 10.0f; // parameter for modulation
    float feedbackGain = 0.5f;
    
    // DELAY LINES.
    FractionalDelay fractionalDelay;
    
    
    // DELAY LINE FEEDBACK VARIABLES
    float fb[2] = {0.f};
    
};



#endif /* FDN_hpp */
