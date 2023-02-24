#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
   
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));

    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));

    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    ofSetSphereResolution(100);
        //myParticle.setup();
        
        material.setShininess( 120 );
        // the light highlight of the material //
        material.setSpecularColor(ofColor(255,255,255,255));
}

//--------------------------------------------------------------
void ofApp::update(){
    pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);
    pointLight2.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.15)*(ofGetWidth()*.3),
                            ofGetHeight()*.5 + sin(ofGetElapsedTimef()*.7)*(ofGetHeight()), -300);

    pointLight3.setPosition(
                            cos(ofGetElapsedTimef()*1.5) * ofGetWidth()*.5,
                            sin(ofGetElapsedTimef()*1.5f) * ofGetWidth()*.5,
                            cos(ofGetElapsedTimef()*.2) * ofGetWidth()
    );
    Particle newParticle;//spawn a new particle
    newParticle.setup();//setup
    myParticle.push_back(newParticle);
  
    for(int i=0; i <myParticle.size(); i++){
        myParticle[i].update();
        //for(int k=i+1; k>0; k--){
           //int myDistance= glm::distance(myParticle[i].posV,myParticle[k].posV);
           //if( myDistance<1){
                //myParticle[i].velV*=-1;
               //myParticle[k].velV*=-1;
                //cout << "COLLISION"<<endl;
           //}
       //}
        
//if(myParticle[i].posV.y<1000||myParticle[i].posV.y>ofGetHeight()-1000){
       //myParticle[i].velV.y*=-1;
   // }
       if(myParticle[i].posV.x>ofGetWidth()*2 || myParticle[i].posV.x<-ofGetWidth()*2 ||
          myParticle[i].posV.y>ofGetHeight()*2 || myParticle[i].posV.y<-ofGetHeight()*2){
         myParticle.erase(myParticle.begin()+i);
        }
    }
    cout << myParticle.size() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_CIRCULAR);
    cam.begin();
    ofRotateXDeg(-90);
    ofEnableDepthTest();

    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();
    material.begin();
    for(int i=0; i < myParticle.size(); i++){

        myParticle[i].draw();

    }
    material.end();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
