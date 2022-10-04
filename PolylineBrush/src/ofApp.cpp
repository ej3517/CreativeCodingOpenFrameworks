#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBeginSaveScreenAsPDF("screenshot-" + ofGetTimestampString() + ".pdf", false);
	minDistance = 10;
	leftMouseButtonPressed = false;
	polylinesColor = ofColor::white;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (leftMouseButtonPressed) {
		ofPoint mousePos(ofGetMouseX(), ofGetMouseY());
		if (lastPoint.distance(mousePos) >= minDistance) {
			// a.distance computes the euclidian distance between point a and point b
			currentPolyline.curveTo(mousePos);
			lastPoint = mousePos;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(polylinesColor); // White color for saved polylines
	for (int i = 0; i < polylines.size(); i++) {
		ofPolyline polyline = polylines[i];
		polyline.draw();

		float tangentLength = 160;
		float lengthPolyline = polyline.getPerimeter();
		float stepIndex = 1;
		float currentIndex = 0;
		ofSetColor(255, 100);
		while (currentIndex<lengthPolyline) {
			glm::vec3 vertex = polyline.getPointAtIndexInterpolated(currentIndex);
			glm::vec3 tangent = polyline.getTangentAtIndexInterpolated(currentIndex) * tangentLength;
			ofDrawLine(vertex - tangent / 2, vertex + tangent / 2);
			currentIndex += stepIndex;
		}
		/*
		float tangentLength = 80;
		ofSetColor(255, 100);
		for (int p = 0; p < 500; p += 1) {
			glm::vec3 vertex = polyline.getPointAtPercent(p / 500.0);
			float floatIndex = polyline.getIndexAtPercent(p / 500.0);
			glm::vec3 tangent = polyline.getTangentAtIndexInterpolated(floatIndex) * tangentLength;
			ofDrawLine(vertex - tangent / 2, vertex + tangent / 2);
		}
		*/
		/*
		vector<glm::vec3> vertices = polyline.getVertices();
		float tangentLength = 80;
		float normalLength = 50;
		for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
			glm::vec3 vertex = vertices[vertexIndex]; // get the vertex
			glm::vec3 tangent = polyline.getTangentAtIndex(vertexIndex) * tangentLength;
			ofDrawLine(vertex - tangent / 2, vertex + tangent / 2);
		}
		/*
		/*
		float normalLength = 50;
		ofSetColor(255, 100);
		for (int p = 0; p < 500; p += 1) {
			glm::vec3 vertex = polyline.getPointAtPercent(p / 500.0);
			float floatIndex = polyline.getIndexAtPercent(p / 500.0);
			glm::vec3 normal = polyline.getNormalAtIndexInterpolated(floatIndex) * normalLength;
			ofDrawLine(vertex - normal / 2, vertex + normal / 2);
		}
		*/
		/*
		vector<glm::vec3> vertices = polyline.getVertices();
		float normalLength = 50;
		for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
			glm::vec3 vertex = vertices[vertexIndex]; // get the vertex
			glm::vec3 normal = polyline.getNormalAtIndex(vertexIndex) * normalLength;
			ofDrawLine(vertex - normal / 2, vertex + normal / 2);
		}
		*/
		/*
		for (int p = 0; p < 100; p+=10) {
			glm::vec3 point = polyline.getPointAtPercent(p / 100.0);
			ofDrawCircle(point, 5);
		}
		*/
		/*
		vector<glm::vec3> vertices = polyline.getVertices();
		for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
			glm::vec3 vertex = vertices[vertexIndex];
			ofDrawCircle(vertex, 5);
		}
		*/
	}
	ofSetColor(255, 100, 0); // orange color for active popyline
	currentPolyline.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r') polylinesColor = ofColor::red;
	else if (key == 'g') polylinesColor = ofColor::green;
	else if (key == 'b') polylinesColor = ofColor::blue;
	else if (key == 's') ofEndSaveScreenAsPDF();
	else if (key == 'd') {
		memoryPolylines.push(polylines.back());
		polylines.pop_back();
	}
	else if (key == 'z') {
		polylines.push_back(memoryPolylines.top());
		memoryPolylines.pop();
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
	if (button == OF_MOUSE_BUTTON_LEFT) {
		leftMouseButtonPressed = true;
		currentPolyline.curveTo(x, y);
		currentPolyline.curveTo(x, y); // Necessary duplicate for control point
		lastPoint.set(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT) {
		leftMouseButtonPressed = false;
		currentPolyline.curveTo(x, y); // Necessary duplicate for control point
		//currentPolyline.simplify(0.75);
		polylines.push_back(currentPolyline);
		currentPolyline.clear();
	}
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
