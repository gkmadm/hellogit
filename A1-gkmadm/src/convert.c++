
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void convert(string infile);

int main()
{
    vector<string> file_names = {"bin/input", "bin/plant", "bin/triangle", 
                                 "bin/dragon", "bin/input2"};

    cout<<endl<<endl<<"Welcome to data converter..."<<endl;   
    
    for (auto file: file_names)
        convert(file);

}



void convert(string infile)
{
 

   cout<<endl<<"Converting '"<<infile<<"' to '"<<infile<<".bin'"<<endl;

   //logic to convert 


}
