#include "lab.h"
bool measureconverter(vector<Sound> &insound,vector<Sound> &outsound,double & tempo)
{
    Sound temp;
    vector<Sound> repeattemp;
    int pos, counter=0, repeatsignal=-1, repeatcounter = 0;
    double time; 
    
    for(int i=0; i<insound.size();i++)
    {
        if(insound[i].note =='|')
        {
            if(insound[i-1].note != ':')
            {
                time =0;pos=1;
                while(time!=tempo && insound[i-pos].note !='|')
                {
                    time=insound[i-pos].duration + time;
                    pos++;
                }
                for(int p = pos;p>0;p--)
                {
                    temp = insound[i+1-p];
                    outsound.push_back(temp);
                }
            }
        }
        if(insound[i].note == ':')
        {
            repeatsignal=repeatsignal*-1;
            if(repeatsignal == -1)
            {
                pos = 1; time=0;
                while(time != tempo && insound[i-pos].note !=':')
                {
                    time = time + insound[i-pos].duration;
                    pos++; 
                }
                //cout << "Position is: "<<pos<<endl;
                for(int p = 0; p<pos-1;p++)
                {
                    repeattemp.push_back(insound[i-(p+1)]);
                }
                
                for(int set = 0; set< 2; set++)
                {
                    for(int rev = 0; rev < repeattemp.size() ; rev++)
                    outsound.push_back(repeattemp[repeattemp.size()-rev-1]);
                }
                repeattemp.clear();
            }
    }
    }
    return true;
}
