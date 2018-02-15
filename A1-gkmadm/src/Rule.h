#ifndef Rule_H
#define Rule_H
using namespace std;

class Rule {
private :
char fromChar;
string toString;
Rule (){
fromChar='X';
toString="def";
}

void setfromChar ( char v){
v = fromChar;
}

void settoString ( string s){
s = toString;
}

string gettoString (){
return toString;
}

char getfromChar (){
return fromChar;
}
};
#endif
