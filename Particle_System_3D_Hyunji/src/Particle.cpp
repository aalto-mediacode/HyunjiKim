#include "Particle.hpp"


//--------------------------------------------------------------
void Particle::setup(){

    posV={0,0,0};

     
    velV={ofRandom(-6, 6),ofRandom(-5,5),ofRandom(-5,5)};
    
}

//--------------------------------------------------------------
void Particle::update(){
    posV = posV+velV;
}

//--------------------------------------------------------------
void Particle::draw(){
   
    float c=cos(sqrt(posV.x*posV.x+velV.y+posV.y*posV.y+velV.y)*0.01);

    velV.z = c*2.5;
    ofDrawSphere(posV,10);
}
//--------------------------------------------------------------
