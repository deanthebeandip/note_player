// TESTTUNE.CPP
//
// This program plays a tune.
#include <iostream>
#include "music.h"
static char title[] = "––– Mary Had a Little Lamb –––";


static const float tempo = 1.2;
static MUSICELMT music[] = {
 {PLAYNOTE, {16, 8}}, // 0 –– E
 {PLAYNOTE, {15, 8}}, // 1 –– D
 {PLAYNOTE, {14, 8}}, // 2 –– C
 {PLAYNOTE, {15, 8}}, // 3 –– D
 {PLAYNOTE, {16, 8}}, // 4 –– E
 {PLAYNOTE, {16, 8}}, // 5 –– E
 {PLAYNOTE, {16, 8}}, // 6 –– E
 {PLAYNOTE, {–1, 8}}, // 7 –– ~
 {PLAYNOTE, {15, 8}}, // 8 –– D
 {PLAYNOTE, {15, 8}}, // 9 –– D
 {PLAYNOTE, {15, 8}}, // 10 –– D
 {PLAYNOTE, {–1, 8}}, // 11 –– ~
 {PLAYNOTE, {16, 8}}, // 12 –– E
 {PLAYNOTE, {18, 8}}, // 13 –– G
 {PLAYNOTE, {18, 8}}, // 14 –– G
 {PLAYNOTE, {–1, 8}}, // 15 –– ~
 {PLAYFRAGMENT, {0, 6}}, // 16 –– Repeat No. 0 through 6
 {PLAYNOTE, {16, 8}}, // 17 –– E
 {PLAYNOTE, {15, 8}}, // 18 –– D
 {PLAYNOTE, {15, 8}}, // 19 –– D
 {PLAYNOTE, {16, 8}}, // 20 –– E
 {PLAYNOTE, {15, 8}}, // 21 –– D
 {PLAYNOTE, {14, 8}}, // 22 –– C
 {PLAYNOTE, {–1, 24}}, // 23 –– ~~~
 {PLAYFRAGMENT, {0, 23}}, // 24 –– 2 times:
 // Repeat No. 0 through 23
 {PLAYSTOP, {0, 0}} // 25 –– Stop
};
int main()
{
 cout << title << endl;
 PlayMusic(music, tempo);
 return 0;
}
