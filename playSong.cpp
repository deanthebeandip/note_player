#include "lab.h"
bool playSong(vector<Sound> &insound,double &tempo, double userspeed)
{
    string playCad, stringnote, notespeed, chartostring, uppernote, cmd="";
    double notespeedm;
   
    for(int i=0; i<insound.size();i++)
    {   
        if(insound[i].note!='|' && insound[i].note!=':')
        {
            playCad = "play -n synth 1 pluck NOTEO"; //Declare play command
            size_t pos = playCad.find("NOTEO"); //Find the position to replace
            uppernote = toupper(insound[i].note); //upper case
            chartostring = string(uppernote);//turn from char to string
            stringnote = chartostring + to_string(insound[i].octave); //Add octave(double to string)
            playCad.replace(pos,5,stringnote); //Replaced
                    
            //Replace the speed
            notespeedm=(insound[i].duration * userspeed)/(tempo/2) ;//My own personal tweak to make the music bearable
            notespeed = to_string(notespeedm); //turn double into string
            size_t speedpos = playCad.find("1"); // find position of "1"
            playCad.replace(speedpos,1,notespeed); // replace the 1 with the speed
            //cout << "This note's string is: "<<playCad<<endl;
            system(playCad.c_str());
        }
    }
}
