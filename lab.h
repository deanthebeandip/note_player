#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
//#include "catch.hpp"

struct Sound
{
    char note;
    double duration;
    int octave;
};

bool readABCfile(string, vector<Sound> &);
bool converter(vector<Sound> &insound,vector<Sound> &outsound);
bool measureconverter(vector<Sound> &insound,vector<Sound> &outsound, double &tempo);
double gettempo(vector<Sound> &insound,double &tempo);
bool playSong(vector<Sound> &insound,double &tempo, double userspeed);



/*
struct Entry
{
    Entry(std::string w="", std::string t="") : word(w),translation(t)
    {}
    bool operator == (const Entry &e) const
    { return (word == e.word) && (translation == e.translation);}
    std::string word;
    std::string translation;
};

struct Node
{
        Entry entry;
        Node *next;
};

bool insert(Node *&head, Entry);
bool loadList(Node *&head, std::string fileName);
bool loadDictionary(std::string f , Node *& node);
std::string search(Node *&head, std::string word);
bool add(Node *&head, std::string w,std::string t);
void destroyList(Node *head);
std::string search(Node *&head, std::string word);
bool loadDictinoary(std::string f, )

*/
