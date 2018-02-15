#include "ofApp.h"
#include <fstream>
#include "Rule.h"


int ofApp::linearSearch(auto& Data, auto key)
{
	
  for(auto i = 0u; i < Data.size(); i++)
   {    //Hint: when Data is changed to a vector of objects, we must call
        //the method to get a character from the object Data[i]

     if (Data[i].getfromChar() == key)
      return i;
  }
   return -1;//not found
}

void ofApp::processAxiom()
{
 string str = "";//temporary string to hold "working" copy of axiom
 int where = -1; //store location in the "parallel" vectors fromChars and toStrings

 for(auto ch : axiom) //for each character in axiom
  {
     where = linearSearch(rules,ch);//look for ch in fromChars vector
     
     if (where == -1)
     {
       str += ch; //ch was not found so its value is not changed in new string    
     }
    else // ch was found in fromChars vector
     {
       str += rules[where].gettoString(); //replace ch with corresponding string
     }
  }//end for 


axiom = str;//update axiom to the new state (after all replacements made)
}

//--------------------------------------------------------------
void ofApp::setup(){
    // Read input data
    getData();

    // Process the Axiom
    for (auto i = 0u; i < N; i++)//N times
      processAxiom();//replace chars in axiom with corresponding strings
}

//--------------------------------------------------------------
void ofApp::update(){

}
//--------------------------------------------------------------
void ofApp::draw(){

ofBackground(0);
ofTranslate(xpos,ypos);

for (auto ch: axiom)//for each character in the axiom string 
{
    switch(ch)
    {

        case 'H':
        case 'G':
	case 'C': ofDrawLine(0,0,0,-length);
		  ofTranslate(0,-length);
		  break;

	case 'D': ofPushMatrix();
                  length-=change_len;
                  break;

	case 'E': ofPopMatrix();
                  length+=change_len;
                  break;

	case 'A': ofRotate(angle);break;
	case 'B': ofRotate(-angle);break;
    
    }// end switch
}//end for

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a') 
	xpos+=10;

    if (key == 'd') 
	xpos-=10;

    if (key == 'w') 
	ypos+=10;

    if (key == 's') 
	ypos-=10;
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

void ofApp::getData()
{
    Rule variable;
    auto name = std::getenv("myfile");
    auto filename = name? name: "input";
	
    ifstream in{filename};
    string str = "";
    char ch = '?';

    if(in)//file opened correctly
     {
       in>>length>>change_len>>angle;//no error checking (hope for the best)
       in>>axiom;
       in>>R; 
       
      for(auto i = 0u; i < R; i++)
         {
           in>>ch>>str;//read a character and its replacement string
      
           //place them in "parallel" vectors     
       
	     variable.setfromChar(ch);
	     variable.settoString(str);
	     rules.push_back(variable);
         }
	    
      
      in>>N;

     }else throw ifstream::failure("Error opening file: " + string{filename});   
}


