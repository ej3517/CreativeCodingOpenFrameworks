#include "ofApp.h"
#define _USE_MATH_DEFINES
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup(){
	straightSegmentPolyline.addVertex(100, 100); // Add a new point: (100,100)
	straightSegmentPolyline.addVertex(150, 150); // etc
	straightSegmentPolyline.addVertex(200, 100);
	straightSegmentPolyline.addVertex(250, 150);
	straightSegmentPolyline.addVertex(300, 100);

	curvedSegmentPolyline.curveTo(350, 100); // These curves are Catmull-rom splines 
	curvedSegmentPolyline.curveTo(350, 100); // Necessary Duplicate for Control Point 
	curvedSegmentPolyline.curveTo(400, 150);
	curvedSegmentPolyline.curveTo(450, 100);
	curvedSegmentPolyline.curveTo(500, 150);
	curvedSegmentPolyline.curveTo(550, 100);
	curvedSegmentPolyline.curveTo(550, 100); // Necessary Duplicate for Control Point

	closedShapePolyline.addVertex(600, 125);
	closedShapePolyline.addVertex(700, 100);
	closedShapePolyline.addVertex(800, 125);
	closedShapePolyline.addVertex(700, 150);
	closedShapePolyline.close(); // Connect first and last vertices

	// Set up the public variables
	transparency = 150;
	brushWidth = 5.0;
	offsetDistance = 200;
	numberOfShapes = 2;
	lastPos.set(ofGetMouseX(), ofGetMouseY());

	ofSetBackgroundAuto(false);
	ofBackground(0);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	/*
	ofBackground(0);
	ofSetLineWidth(2.0);
	ofSetColor(255, 100, 0);
	straightSegmentPolyline.draw();
	curvedSegmentPolyline.draw();
	closedShapePolyline.draw();
	*/

	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
		ofSetLineWidth(brushWidth);
		int maxOffset = offsetDistance;
		int alpha = transparency;

		for (int i = 0; i < numberOfShapes; i++) {

			ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

			// Generate random variables
			// uniform distribution
			float u1 = ofRandom(1);
			float u2 = ofRandom(1);
			// normal distribution
			float z = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);

			// set up the offset distance
			float offsetDistance = maxOffset * z;

			// send a single string message, setting the log level
			//ofLog(OF_LOG_NOTICE) << "the number is " << ofToString(z);

			// triangel initial position pointing to the right
			ofVec2f p1(0, 35);
			ofVec2f p2(100, 0);
			ofVec2f p3(0, -35);

			// offset
			ofVec2f triangleOffset(offsetDistance, 0);
			triangleOffset.rotate(90);

			p1 += triangleOffset;
			p2 += triangleOffset;
			p3 += triangleOffset;

			// Randomly rotate the position of the triangle
			float rotation = ofRandom(360);
			p1.rotate(rotation);
			p2.rotate(rotation);
			p3.rotate(rotation);

			// Shift the position of the triangel to the mouse;
			p1 += mousePos;
			p2 += mousePos;
			p3 += mousePos;

			// randome color selection
			ofColor myAqua = ofColor::aqua;
			ofColor myPurple = ofColor::purple;
			// ofColor randomColor = myAqua.getLerped(myPurple, ofRandom(1.0));
			float randomColorInterpolationCoeff = ofMap(lastPos.distance(mousePos), 0, 300, 0.0, 1.0); // make shorter lines more opaque
			lastPos.set(ofGetMouseX(), ofGetMouseY());
			ofColor randomColor = myAqua.getLerped(myPurple, randomColorInterpolationCoeff);
			

			ofSetColor(randomColor, alpha);
			ofDrawTriangle(p1, p2, p3);

		}

		// BRUSH TRIANGLE
		/*
		int numTriangles = 10;
		int minOffset = 20;
		int maxOffset = 70;
		int alpha = 150;

		for (int i = 0; i < numTriangles; i++) {
			float offsetDistance = ofRandom(minOffset, maxOffset);

			ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

			// triangel initial position pointing to the right
			ofVec2f p1(0, 35);
			ofVec2f p2(100, 0);
			ofVec2f p3(0, -35);

			// offset
			ofVec2f triangleOffset(offsetDistance, 0);
			triangleOffset.rotate(90);

			p1 += triangleOffset;
			p2 += triangleOffset;
			p3 += triangleOffset;

			// Randomly rotate the position of the triangle
			float rotation = ofRandom(360);
			p1.rotate(rotation);
			p2.rotate(rotation);
			p3.rotate(rotation);

			// Shift the position of the triangel to the mouse;
			p1 += mousePos;
			p2 += mousePos;
			p3 += mousePos;

			// randome color selection
			ofColor myAqua = ofColor::aqua;
			ofColor myPurple = ofColor::purple;
			ofColor randomColor = myAqua.getLerped(myPurple, ofRandom(1.0));

			ofSetColor(randomColor, alpha);
			ofDrawTriangle(p1, p2, p3);

		}
		*/

		//THIS IS THE LINE BRUSH
		/* 
		int numLines = 30;
		int minRadius = 25;
		int maxRadius = 125;
		for (int i = 0; i < numLines; i++) {
			float angle = ofRandom(ofDegToRad(360));
			float distance = ofRandom(minRadius, maxRadius);
			float xOffSet = distance * cos(angle);
			float yOffSet = distance * sin(angle);
			float alpha = ofMap(distance, minRadius, maxRadius, 50, 0); // make shorter lines more opaque
			ofSetColor(255, alpha);
			ofDrawLine(ofGetMouseX(), ofGetMouseY(), ofGetMouseX() + xOffSet, ofGetMouseY() + yOffSet);
			ofSetLineWidth(ofRandom(1.0, 5.0)); // remember to recalibrate the line width when we do a new brush
		}
		*/

		//THIS IS THE CIRCLE BRUSH
		/* 
		int maxRadius = 100;
		int radiusStepSize = 5;
		int alpha = 3;
		int maxOffSetDistance = 100;

		for (int radius = maxRadius; radius > 0; radius -= radiusStepSize) {
			float angle = ofRandom(ofDegToRad(360));
			float distance = ofRandom(maxOffSetDistance);
			float xOffSet = cos(angle)*distance;
			float yOffSet = sin(angle)*distance;
			
			float randomColor = ofRandom(1.0);
			ofColor myRed(255,0,0);
			ofColor myBlue(0, 0, 255);
			ofSetColor(myRed.getLerped(myBlue,randomColor), alpha);
			ofDrawCircle(ofGetMouseX() + xOffSet, ofGetMouseY() + yOffSet, radius);
		}
		*/

		// THIS IS THE RECTANGLE BRUSH
		/* 
		for(int i = 0; i<10; i++){
			
			float randomColour = ofRandom(255);
			float width = ofRandom(5, 20);
			float height = ofRandom(5, 20);
			float xOffSet = ofRandom(-100, 100);
			float yOffSet = ofRandom(-100, 100);

			ofSetColor(randomColour);
			ofSetRectMode(OF_RECTMODE_CENTER);
			ofDrawRectangle(ofGetMouseX() + xOffSet, ofGetMouseY() + yOffSet, width, height);
			

			float randomColour = ofRandom(255);
			float width = ofRandom(5, 20);
			float height = ofRandom(5, 20);
			float radius = ofRandom(5, 100);
			float angle = ofRandom(ofDegToRad(360.0));
			float xOffSet = radius*cos(angle);
			float yOffSet = radius*sin(angle);


			ofSetColor(randomColour);
			ofSetRectMode(OF_RECTMODE_CENTER);
			ofDrawRectangle(ofGetMouseX() + xOffSet, ofGetMouseY() + yOffSet, width, height);
		}
		*/
	}
	if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
		ofBackground(0);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 's'){
		glReadBuffer(GL_FRONT); // HACK: only needed on windows, when using ofSetAutoBackground(false)
		ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png");
	}
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
