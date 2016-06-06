#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

#include <iomanip>
#include "piano.h"
#include <MidiFile.h>
#ifdef _WIN32
#pragma warning(disable:4996)	
#endif
using namespace std;
class Player{
MidiFile* midi;
Piano* piano;
unsigned int currentSong, currentEvent, songCount, currentChannel;
vector<char*> songs;
float timer;
bool playing;

void clear();
void prepareSongTitles();
public:
    Player(vector<char*> files,Piano* piano);
    virtual ~Player();
    void playNext();
    void playPrevious();
    void channelUp();
    void channelDown();
    void start();
    void stop();
	char* getCurrentSong();
    void tick(float elapsed);

};
#endif
