#pragma once

#include "ofMain.h"

class Particle{
    
public:
    void setup();
    void update();
    void draw();
    glm:: vec3 posV;
    glm:: vec3 velV;
};
