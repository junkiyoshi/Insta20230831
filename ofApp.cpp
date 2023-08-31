#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(5);
	ofEnableDepthTest();

	ofSetCircleResolution(60);
}


//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofRotateY(ofGetFrameNum() * 2);

	ofNoFill();
	ofSetColor(0);
	ofDrawCircle(glm::vec2(), 250);

	ofRotateX(25);

	auto radius = 200;
	for (int i = 0; i < 64; i++) {
		
		ofRotateZ(ofRandom(360));
		ofRotateY(ofRandom(360));
		ofRotateX(ofRandom(360));

		auto deg_start = ofRandom(360) + ofGetFrameNum() * 5;
		for (int deg = deg_start; deg < deg_start + 30; deg++) {

			ofFill();
			ofSetColor(39, ofMap(deg, deg_start, deg_start + 30, 0, 255));

			ofDrawSphere(radius * cos(deg * DEG_TO_RAD), 0, radius * sin(deg * DEG_TO_RAD), 5);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}