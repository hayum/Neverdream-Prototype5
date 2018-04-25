#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp {
public:
//	void setup();
//	void update();
//	void draw();
//
    
    void setup();
    void setupGui();
    void update();
    void draw();
    void drawGui(ofEventArgs & args);
    void mousePressed(int x, int y, int button);
    
	ofVideoGrabber cam;
	ofxCv::ObjectFinder finder;
    
    
    
    ofParameterGroup parameters;
    ofParameter<float> radius;
    ofParameter<ofColor> color;
    ofxPanel gui;
    
    
    //Custom variables for on screen string and font.
    string msg;
    ofTrueTypeFont font;
    
    //New serial object.
    ofSerial serial;
    
    ofSoundPlayer   mySound,crow, open,sleep,paint,reunite;
    ofVideoPlayer Big[5],small[4],small2[4];
};
