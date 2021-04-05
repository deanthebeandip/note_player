#include "lab.h"
double gettempo(vector<Sound> &insound,double &tempo)
{
    char charholder; double d1,d2;
    for(int i = 0; i < insound.size()-5;i++)
    {
        if(insound[i].note =='L')
        {
            if(insound[i+1].note==':')
            {   
                if(insound[i+5].note == '6')
                    tempo = 16;
                else if(insound[i+5].note == '2')
                tempo = 32;
                else
                {
                    charholder = insound[i+4].note;
                    d1 = (double)(charholder);
                    tempo = d1-48;
    }}}}
    return tempo;
}
