#include "ofApp.h"

int main() {
	//ofSetupOpenGL(640, 480, OF_WINDOW);
//    ofSetupOpenGL(320, 480, OF_WINDOW);
//	ofRunApp(new ofApp());
    
    
    
    ofGLFWWindowSettings settings;
    settings.width =640;
    //320;
    settings.height = 1024;
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
      mainWindow->setVerticalSync(false);
    settings.width = 500;
    settings.height = 300;
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = true;
    // uncomment next line to share main's OpenGL resources with gui
    //settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    guiWindow->setVerticalSync(false);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setupGui();
    ofAddListener(guiWindow->events().draw,mainApp.get(),&ofApp::drawGui);
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();

    
    
    
}
