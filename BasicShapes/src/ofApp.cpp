#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);

	// Draw some shapes
	ofDrawRectangle(50, 50, 100, 100); // tot left corner (50,50) and 100x100 dimensions
	ofDrawCircle(250, 100, 50); // Centered at (250,100), radius 50
	ofDrawEllipse(400, 100, 80, 100); // Three corners: (500, 150), (550,50), (50,150);
	ofDrawTriangle(500, 150, 550, 50, 600, 150); // Three corner first one (500, 150) second (550,50) and third (600,150)
	for (int i = 0; i < 11; i++) {
		ofDrawLine(700, 50+i*10, 800, 75+i*5); //Line from (700,50) to (700);
	}

	// Draw some shapes
	
	int y = 200;
	ofRectangle myRect(50, 50+y, 100, 100);
	ofDrawRectRounded(myRect, 10, 20, 30, 40); // tot left corner (50,50) and 100x100 dimensions
	ofDrawRectRounded(myRect, 10, 20, 30, 40);
	ofSetCircleResolution(50);
	ofDrawCircle(250, 100+y, 50); // Centered at (250,100), radius 50
	ofDrawEllipse(400, 100+y, 80, 100); //
	ofDrawTriangle(500, 150+y, 550, 50+y, 600, 150+y); // Three corner first one (500, 150) second (550,50) and third (600,150)
	for (int i = 0; i < 11; i++) {
		ofDrawLine(700, y+50 + i * 10, 800, y+75 + i * 5); //Line from (700,50) to (700);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
