#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <MidiFile.h>
#include <iomanip>
#include "piano.h"
using namespace std;
class Player{
MidiFile* midi;
Piano* piano;
unsigned int currentSong, currentEvent, songCount, currentChannel;
float timer;
bool playing;

void clear();
public:
    Player(vector<char*> files,Piano* piano);
    virtual ~Player();
    void playNext();
    void playPrevious();
    void channelUp();
    void channelDown();
    void start();
    void stop();
    void tick(float elapsed);

};
#endif
