#ifndef _MUSIC_H_
#define _MUSIC_H_

struct NOTE {
    int tone;
    int duration;
};
struct FRAGMENT {
    int start;
    int finish;
};
enum PLAY {PLAYNOTE, PLAYFRAGMENT, PLAYSTOP};

struct MUSICELMT {
    PLAY type;
    
    union 
    {
        NOTE note;
        FRAGMENT fragment;
    };
};



// Function prototypes:
void PlayNote (NOTE &note, float tempo);
void PlayMusicSimple (MUSICELMT music[], float tempo);
void PlayMusic (MUSICELMT music[], float tempo);
#endif // _MUSIC_H_
