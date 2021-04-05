#include "lab.h"
int main()
{
    //Declare 3 vectors
    vector<Sound> abcsound;
    vector<Sound> actualnotes;
    vector<Sound> forrealnotes;
    double tempo, userspeed;
    int octave; string cmd = "", filename;
    
    //Prompt user for the abc file to play
    cout << "Enter file name to play: ";
    cin>> filename;
    
    //Read abc file, get the tempo, convert raw char abc into actual notes, then convert notes into playable notes
    if(readABCfile(filename,abcsound)) 
    {   
        gettempo(abcsound,tempo);
        if (converter(abcsound,actualnotes)) 
        {
            if(measureconverter(actualnotes,forrealnotes,tempo)) //Convert raw sound to measures
            {//Notes are now playable by system
                cout << "===============Measure conversion complete==============="<<endl<<endl;}
        }
    }
    
    //Displaying each version
    cout << "===============abc sound==============="<<endl;
    for(int i =0; i<abcsound.size();i++){cout <<abcsound[i].note <<" ";}; cout << endl;
    cout << "===============actualnotes==============="<<endl;
    for(int i =0; i<actualnotes.size();i++){cout <<actualnotes[i].note <<" ";}; cout << endl;
    cout <<endl<< "===============forrealnotes==============="<<endl;
    for(int i =0; i<forrealnotes.size();i++){cout <<forrealnotes[i].note<<" ";} cout << endl<<endl;
    
    
    //Pop open the image before play Song
    //cout << "What speed would you like to play at? (recommended 1.20): "; cin >> userspeed;
    cmd += "abcm2ps -E " + filename + " && display -alpha off Out001.eps &";
    system(cmd.c_str());
    playSong(forrealnotes, tempo, 1.20); //Play the song
    system("pkill -9 display"); //Close the image
    cout << "Song over"<<endl;
    return 0;
}

//cmd: alsamixergui
//string cmd; //How to load the image


