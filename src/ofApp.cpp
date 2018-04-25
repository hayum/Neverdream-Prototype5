#include "ofApp.h"

using namespace ofxCv;
using namespace cv;
ofImage intro,bg, wall,intro1,intro2,ending;
ofImage gesture[4];
int wid, height,wid2, height2;
int frame, nFrame;
int oldalpha,oldalpha2;
int newalpha=255,newalpha2=255;
int byteData=-1, byteDatain=-1, oldByte=-1,oldByte2;
float v;
bool playing,playingS,playingS2,showNext,soundOn,played[5], soundOns;

unsigned long actualTime, sucessTimer,beginTime;
unsigned int sucessTimeDelta,waitDelta;
int frameB[5],frameS[4],frameS2[4];

void ofApp::setup() {
    //finder.setup("haarcascade_frontalface_default.xml");
    //finder.setPreset(ObjectFinder::Fast);
    
    
	//ofSetVerticalSync(true);
	ofSetFrameRate(30);
   
    sucessTimeDelta = 6000;
    sucessTimer= ofGetElapsedTimeMillis();
	//cam.setup(640, 480);
    waitDelta=60000;
    
    ofEnableAlphaBlending();
    serial.setup("/dev/cu.usbmodem1411", 9600);

    
    intro.load("p2/intro00.jpg");
    intro1.load("p2/intro01.jpg");
    intro2.load("p2/gestureintro.jpg");
    ending.load("p2/ending.jpg");

    
    small[0].load("p2/Rsmall1.mov");
    small[0].play();
    small[1].load("p2/Rsmall2.mov");
    small[1].play();
    small[2].load("p2/Rsmall3.mov");
    small[2].play();
    small[3].load("p2/Rsmall4.mov");
    small[3].play();
    
    small2[0].load("p2/ending1.mov");
    small2[0].play();
    small2[1].load("p2/ending22.mov");
    small2[1].play();
    small2[2].load("p2/ending3.mov");
    small2[2].play();
    small2[3].load("p2/ending4.mov");
    small2[3].play();

    for(int i=0;i<4;i++){
        frameS[i]=static_cast<int>(small[i].getDuration()*30);
        //cout<<frameS[i]<<endl;
        
    }
    playingS=false;
    
    for(int i=0;i<4;i++){
        frameS2[i]=static_cast<int>(small2[i].getDuration()*30);
        cout<<frameS2[i]<<endl;
        
    }
    playingS2=false;
    mySound.load("bgm.mp3");
    crow.load("crow.mp3");
    open.load("bgm/fan.mp3");
    sleep.load("bgm/Rsleep.mp3");
    paint.load("bgm/paint.mp3");
    reunite.load("bgm/reunite2.mp3");
    
    v=1.0f;
    wid=ofGetWindowWidth();
    height=ofGetWindowHeight();
}


void ofApp::setupGui(){

    wid2=ofGetWindowWidth();
    height2=ofGetWindowHeight();


    
    wall.load("p2/Wall1.png");
    
    Big[0].load("p2/Big1.mov");
    Big[0].play();
    Big[1].load("p2/Big2.mov");
    Big[1].play();
    Big[2].load("p2/Big33.mov");
    Big[2].play();
    Big[3].load("p2/Big44.mov");
    Big[3].play();
    Big[4].load("p2/sum.mov");
    Big[4].play();
    
    for(int i=0;i<5;i++){
        frameB[i]=static_cast<int>(Big[i].getDuration()*30);
        cout<<frameB[i]<<endl;
        
    }
    playing=false;

}



void ofApp::update() {
    wid=ofGetWindowWidth();
    height=ofGetWindowHeight();

//    cam.update();
//    if(cam.isFrameNew()) {
//        finder.update(cam);
//    }
    
    
    actualTime = ofGetElapsedTimeMillis();
    
    //Simple if statement to inform user if Arduino is sending serial messages.
    if (serial.available() < 0) {
        msg = "Arduino Error";
    }
    else {
        //While statement looping through serial messages when serial is being provided.
        while (serial.available() > 0) {
            
            //byte data is being writen into byteData as int.
            byteDatain = serial.readByte();
            
            //byteData is converted into a string for drawing later.
            msg = "cm: " + ofToString(byteData);
            
            //oldByte=byteData;
            
            byteData=byteDatain;
            playingS=false;
            playing=false;
            showNext=false;
            soundOns=false;
        }
        
    }
   
    /*---------if linear------------*/
//    if(byteDatain>0 && !played[byteDatain-1] && byteDatain-oldByte==1){
//       byteData=byteDatain;
//        played[byteDatain-1]=true;
//            showNext=false;
//             oldByte=byteData;
//        playing=false;
//        playingS=false;
//        beginTime== ofGetElapsedTimeMillis();
//
//    }
//    cout<<byteDatain;
//    cout<<oldByte;
//  cout<<byteData<<endl;
//    if (oldByte!=0 && actualTime - beginTime > waitDelta){
//        for(int i=0;i<4;i++){
//            played[i]=0;
//        }
//        playing=false;
//        playingS=false;
//        showNext=false;
//        oldByte=-1;
//        byteData=-1;
//        cout<<"here"<<endl;
//
//    }

}

void ofApp::draw() {
    
 
	
   
//    if(oldByte!= byteData){
//        oldalpha=0;
//        oldByte=byteData;
//        nFrame=0;
//        
//       showNext=false;
//  }

/*---------------------fade in------------------*/
//    if(nFrame<200){
//    newalpha = oldalpha+2;
//    if (newalpha > 255) {
//        newalpha = 255;
//    }
//    ofSetColor(255,255,255,newalpha);
//    oldalpha = newalpha;
//    }
//    frame++;
    //ofBackground(255,255,255);
    
    if(byteData==-1 || byteData==0){
        //ofBackground(0);
        intro.draw(0, 0, wid, height);
    }
    
//    else if(byteData==5){
//         ending.draw(0,0,wid,height);
//    }
//    else if(byteData==0){
//        
//      if (actualTime - sucessTimer > sucessTimeDelta) {
//          
//              newalpha = oldalpha+2;
//              if (newalpha > 255) {
//                  newalpha = 255;
//              }
//              ofSetColor(255,255,255,newalpha);
//              oldalpha = newalpha;
//            ofBackground(255,255,255);
//            gesture[0].draw(0, 0, wid, height);
//        }
//      else{
//          intro.draw(0, 0, wid, height);
//      }
//        
//    }

    else if(byteData<5){
        //cout<< frameS[byteData-1]-3<<endl;
       
        if(!playingS){
            small[byteData-1].setFrame(0);
            playingS=true;
        }
        small[byteData-1].draw(0, 0,wid,height);

        if(small[byteData-1].getCurrentFrame()>=(frameS[byteData-1]-3) && playingS){
            small[byteData-1].stop();
            small[byteData-1].close();
            ofBackground(0,0,0);
        }
        else if(small[byteData-1].getCurrentFrame()<(frameS[byteData-1]-3) ){
            small[byteData-1].update();
            if(byteData==2 && mySound.isPlaying()){
                mySound.setVolume(v);
                v=v-0.003f;
                if(v<=0){
                    mySound.stop();
                    soundOn=false;
                }
            }
            
        }
        if(!soundOns && byteData==1){
            open.setVolume(0.4);
            open.play();
            soundOns=true;

        }
        if(!soundOns){
            if( byteData==2){
                sleep.setVolume(0.4);
                sleep.play();
            }
            else if(byteData==3){
                paint.play();
            }
            else if(byteData==4){
                reunite.setVolume(0.4);
                reunite.play();
            }
            soundOns=true;
        }
        
    }
//    else if(byteData==5){
//        intro.draw(0, 0, wid, height);
//    }

    if(showNext && byteData<=4){
         ofBackground(0,0,0);
        if(byteData==1){
            intro1.draw(0, 0, wid, height);
        }
        else if(byteData>1){
            if(!playingS2){
                small2[byteData-1].setFrame(0);
                playingS2=true;
                            }
            small2[byteData-1].draw(0, 0,wid,height);
            if(small2[byteData-1].getCurrentFrame()>=(frameS2[byteData-1]-3) && playingS2){
                small2[byteData-1].stop();
                small2[byteData-1].close();
                ofBackground(0,0,0);
                //intro2.draw(0,0,wid,height);
            }
            else if(small2[byteData-1].getCurrentFrame()<(frameS2[byteData-1]-3) ){
                small2[byteData-1].update();
            }

        }
    }

}



void ofApp::drawGui(ofEventArgs & args){
        wid2=ofGetWindowWidth();
        height2=ofGetWindowHeight();
    if(byteData==-1 || byteData==0){
        ofBackground(0);
    }
/*------------------fade in------------------*/
//    else if(byteData==0){
//        if (actualTime - sucessTimer > sucessTimeDelta) {
//        newalpha2 = oldalpha2+2;
//        if (newalpha2 > 255) {
//            newalpha2 = 255;
//        }
//        ofSetColor(255,255,255,newalpha);
//        oldalpha2 = newalpha2;
//        //ofBackground(0);
//        wall.draw(0,0,wid2, height2);
//        }
//        else{
//             ofBackground(0);
//        }
//    }
    
    else {
        if(byteData!=5){
            if(!playing && !small[byteData-1].isPlaying()){
                Big[byteData-1].setFrame(0);
                playing=true;
            }
            Big[byteData-1].draw(0, 0,wid2,height2);
            if(Big[byteData-1].getCurrentFrame()>=(frameB[byteData-1]-3) && playing){
                Big[byteData-1].stop();
                showNext=true;
                playingS2=false;
                if(byteData==3){
                    crow.stop();
                    soundOn=false;
                }
                if(byteData==4){
                    byteData=5;
                    playing=false;
                }

            }
            else if(!small[byteData-1].isPlaying() && Big[byteData-1].getCurrentFrame()<(frameB[byteData-1]-3) && !showNext ){
                Big[byteData-1].update();
                if(byteData==1 && !soundOn){
                
                    mySound.play();
                    soundOn=true;
                }
                else if(byteData==3 && !soundOn ){
                    crow.play();
                    soundOn=true;
                }
            
            }
        }
/*--------------ending video---------------*/
//        else if(showNext){
//            if(!playing){
//                Big[4].setFrame(0);
//                playing=true;
//                
//            }
//            Big[4].draw(0, 0,wid2,height2);
//            Big[4].update();
//            if(Big[4].getCurrentFrame()>=(frameB[4]-3) && playing){
//                Big[4].stop();
//                playing=false;
//            }
//            
//        }
    }
    
}


void ofApp::mousePressed(int x, int y, int button){
    if (button == 0) {
        if(byteData<5){
            byteData++;
            playingS=false;
             playing=false;
            showNext=false;
            soundOns=false;
        }
        else{
            byteData=0;
            oldByte=0;
            playing=false;
            playingS=false;
            showNext=false;
        }
   
  }
    cout<<byteData<<endl;
}
