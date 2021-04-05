#include "lab.h"
bool readABCfile(string filename, vector<Sound> & v )
{
    bool r = true;
    ifstream ifs(filename);
    if(ifs)
    {
        Sound s;
        while(ifs>>s.note) 
            v.push_back(s);
    }
    else {cout<<"Error opening file" <<endl; r = false;}
}
