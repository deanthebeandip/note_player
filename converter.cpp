#include "lab.h"

bool converter(vector<Sound> &insound,vector<Sound> &outsound)
{
    Sound temp, repeattemp;
    string currentnote,pastnote;
    int counter=0, mcounter=0;
    for(int i = 0; i < insound.size();i++)
    {
        currentnote = insound[i].note;
        pastnote = insound[i-1].note;
        if(insound[i].note == '2' && mcounter >=1)
        {
            if(insound[i-1].note== '/')
            {outsound[counter-1].duration=0.5;}
            else
            {outsound[counter-1].duration=2;}
        }
         if(insound[i].note == '3' && mcounter >=1)
        {
            if(insound[i-1].note== '/')
            {outsound[counter-1].duration=1/3;}
            else
            {outsound[counter-1].duration=3;}
        }
        else if (insound[i].note == '4' && mcounter>=1)
        {
            if(insound[i-1].note== '/')
            {outsound[counter-1].duration=0.25;}
            else
            {outsound[counter-1].duration=4;}
        }
        else if (insound[i].note == '8' && mcounter>=1)
        {
            if(insound[i-1].note== '/')
            {outsound[counter-1].duration=0.125;}
            else
            outsound[counter-1].duration=8;
            
        }
        
        else if (insound[i].note == '6'&& mcounter>=1)
        {
            if(mcounter>=1 && insound[i-1].note == '1')
            {
                if(insound[i-2].note== '/')
                {outsound[counter-1].duration=.0625;}
            }
        }
         else if (currentnote =="'")
        {
            if(pastnote=="'")
            {
                if(outsound[counter-1].octave == 6)
                    outsound[counter-1].octave++;
            }
            else
            {
                if(outsound[counter-1].octave ==5)
                    outsound[counter-1].octave++;
            }
        }
         else if (currentnote ==",")
        {if(outsound[counter-1].octave ==4)
            outsound[counter-1].octave--;}
        else if(insound[i].note == ':')
        {
            if(insound[i-1].note == 'K')
            {mcounter++;}
            else
            {
                if(mcounter>0)
                {   temp.note=insound[i].note;
                    temp.duration=0;
                    temp.octave=0;
                    outsound.push_back(temp);
                    counter++;}
            }
        }
        else
        {
            if(insound[i].note == '|')
            {
                if(insound[i-2].note == ':')
                {if(insound[i-3].note == 'K')
                    insound[i].note = 'n';}
                else
                {
                temp.note=insound[i].note;
                temp.duration=0;
                temp.octave=0;
                outsound.push_back(temp);
                counter++;
                }
            }
            else if(currentnote== "a" || currentnote== "b"|| currentnote== "c" || 
            currentnote== "d" ||currentnote== "e" ||currentnote== "f" ||currentnote== "g")
            {
                temp.note=insound[i].note;
                temp.duration=1;
                temp.octave =5;
                outsound.push_back(temp);
                counter++;
            }
            else if (currentnote== "A" || currentnote== "B" || currentnote== "C" || 
            currentnote== "D" ||currentnote== "E" ||currentnote== "F" ||currentnote== "G" )
            {
                temp.note=insound[i].note;
                temp.duration=1;
                temp.octave =4;
                outsound.push_back(temp);
                counter++;
            }  
        }
    }
    return true;
}
