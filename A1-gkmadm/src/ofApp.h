#pragma once

#include "ofMain.h"
#include "Rule.h"
#include <vector>
#include <string>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


	private: 

		//text stuff
		string axiom = ""; //starting string
		vector<Rule> rules;
		unsigned R = 0;
		unsigned N = 0;
		
		//drawing stuff 
		int length = 0;//length of line to draw
		unsigned change_len = 0;//amount to change length by
		float angle = 0.0f;//angle of rotation in degrees

		// private "helper" methods
		int linearSearch(auto& Data, auto key);
		void processAxiom( ); 
                void getData();

		//internal stuff (Don't worry about it)
		unsigned xpos = ofGetWidth()/2;
                unsigned ypos = ofGetHeight();
    };
