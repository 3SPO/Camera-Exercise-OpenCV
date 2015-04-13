#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    // this sets up all of the primitives, lights, and camera in order to be manipulated later.
    
	ofSetVerticalSync(true);
	ofSetFrameRate(120);
	finder.setup("haarcascade_frontalface_alt2.xml");
	finder.setPreset(ObjectFinder::Fast);
	finder.getTracker().setSmoothingRate(.3);
	cam.initGrabber(640, 480);
	sunglasses.loadImage("sunglasses.png");
	ofEnableAlphaBlending();
    sphere.setRadius( 50 );
    cube1.setHeight(200) ;
    cube2.setHeight(100) ;
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    
    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
    
    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    
    // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setShininess( 120 );
    // the light highlight of the material //
    material.setSpecularColor(ofColor(255, 255, 255, 255));
    
    ofSetSphereResolution(24);
}

void ofApp::update() {
    // the update section keeps the webcam refreshed and allows the lights to move around the scene giving the objects a more 3d feel.
    
	cam.update();
	if(cam.isFrameNew()) {
		finder.update(cam);
	}
    pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);
    pointLight2.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.15)*(ofGetWidth()*.3),
                            ofGetHeight()*.5 + sin(ofGetElapsedTimef()*.7)*(ofGetHeight()), -300);
    
    pointLight3.setPosition(
                            cos(ofGetElapsedTimef()*1.5) * ofGetWidth()*.5,
                            sin(ofGetElapsedTimef()*1.5f) * ofGetWidth()*.5,
                            cos(ofGetElapsedTimef()*.2) * ofGetWidth()
                            );
}

void ofApp::draw() {
    //this is where all of the work is done, this draws the camera and the shapes and tracks the shapes in order to follow the face.
    
	cam.draw(0, 0);
    ofEnableDepthTest();
    
    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();
    
    material.begin();
	
    // each for loop handles one of the shapes and keeps it in line with the face. Each loop creates a rectangle that follows the face and then using draw the primitive is drawn to the invisible rectangle on the face.
    
	for(int i = 0; i < finder.size(); i++) {
		ofRectangle object = finder.getObjectSmoothed(i);
		sunglasses.setAnchorPercent(.5, .5);
		float scaleAmount = .9 * object.width / sunglasses.getWidth();
		ofPushMatrix();
		ofTranslate(object.x + object.width / 2.73, object.y + object.height * .42);
		ofScale(scaleAmount, scaleAmount);
        sphere.draw() ;
		//sunglasses.draw(0, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(object.getPosition());
		ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
		ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
		ofPopMatrix();
	}
    for(int i = 0; i < finder.size(); i++) {
        ofRectangle object = finder.getObjectSmoothed(i);
        sunglasses.setAnchorPercent(.5, .5);
        float scaleAmount = .9 * object.width / sunglasses.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 1.52, object.y + object.height * .42);
        ofScale(scaleAmount, scaleAmount);
        sphere.draw() ;
        //sunglasses.draw(0, 0);
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
    }
    for(int i = 0; i < finder.size(); i++) {
        ofRectangle object = finder.getObjectSmoothed(i);
        sunglasses.setAnchorPercent(.5, .5);
        float scaleAmount = .9 * object.width / sunglasses.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 1.1 , object.y + object.height * .57, -30);
        ofScale(scaleAmount, scaleAmount);
        cube1.draw() ;
        //sunglasses.draw(0, 0);
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
    }
    for(int i = 0; i < finder.size(); i++) {
        ofRectangle object = finder.getObjectSmoothed(i);
        sunglasses.setAnchorPercent(.5, .5);
        float scaleAmount = .9 * object.width / sunglasses.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 20.1 , object.y + object.height * .57, -30);
        ofScale(scaleAmount, scaleAmount);
        cube1.draw() ;
        //sunglasses.draw(0, 0);
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
    }
    for(int i = 0; i < finder.size(); i++) {
        ofRectangle object = finder.getObjectSmoothed(i);
        sunglasses.setAnchorPercent(.5, .5);
        float scaleAmount = .9 * object.width / sunglasses.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 60.1 , object.y + object.height * .57, -30);
        ofScale(scaleAmount, scaleAmount);
        cube2.draw() ;
        //sunglasses.draw(0, 0);
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
    }
    for(int i = 0; i < finder.size(); i++) {
        ofRectangle object = finder.getObjectSmoothed(i);
        sunglasses.setAnchorPercent(.5, .5);
        float scaleAmount = .9 * object.width / sunglasses.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 1.05 , object.y + object.height * .57, -30);
        ofScale(scaleAmount, scaleAmount);
        cube2.draw() ;
        //sunglasses.draw(0, 0);
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
    }
}
