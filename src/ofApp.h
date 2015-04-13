#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofVideoGrabber cam;
	ofxCv::ObjectFinder finder;
	ofImage sunglasses;
    ofLight pointLight;
    ofLight pointLight2;
    ofLight pointLight3;
    ofSpherePrimitive sphere;
    ofBoxPrimitive cube1 ;
    ofBoxPrimitive cube2 ;
    ofMaterial material;
};
