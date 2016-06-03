#include "player.h"

Player::Player(vector<char*> files,Piano* piano){
    this->piano = piano;
    currentSong = 0;
    currentEvent = 0;
    timer = 0;
    currentChannel = 0;
    songCount = files.size();
    midi = new MidiFile[files.size()];
    for(int i=0;i<files.size();++i){
        midi[i].read(files[i]);
        printf("[MIDI] %s :",files[i]);
        if(midi[i].status()){
            printf("[OK]\n");
            printf("MIDI size: %d\n",midi[i].size());
            for(int j=0;j<midi[i].size();++j){
                int count = 0;
                for(int k=0;k<midi[i][j].size();k++){
                    if(midi[i][j][k].isNoteOn())
                        count++;
                }
                printf("channel %d size: %d, notes: %d\n",j,midi[i][j].size(),count);

            }
            midi[i].linkNotePairs();
            midi[i].doTimeAnalysis();
        }else{
            printf("[FAIL]\n");
            i--;
            songCount--;
        }
    }
}

Player::~Player(){
    delete[] midi;
}

void Player::start(){
    playing = true;
    currentEvent = 0;
    timer = 0;
}

void Player::stop(){
    playing = false;
    clear();
}
void Player::clear(){
    timer = 0;
    currentEvent = 0;
    currentChannel = 0;
}
void Player::playNext(){
    if(currentSong+1 < songCount){
        currentSong++;
        printf("Song changed! Current song: %d\n",currentSong);
    }
    clear();
}

void Player::playPrevious(){
    if(currentSong > 0){
        currentSong--;
        printf("Song changed! Current song: %d\n",currentSong);
    }
    clear();
}
void Player::channelUp(){
    if(currentChannel+1<midi[currentSong].size()){
        currentChannel++;
        currentEvent = 0;
        timer = 0;
        printf("Channel changed! Current channel: %d\n",currentChannel);
    }

}
void Player::channelDown(){
    if(currentChannel >0 ){
        currentChannel--;
        currentEvent = 0;
        timer = 0;
        printf("Channel changed! Current channel: %d\n",currentChannel);
    }
}
void Player::tick(float elapsed){
    if(playing){
        timer += elapsed;
        int tick = midi[currentSong].getAbsoluteTickTime(timer);
        if(tick >= midi[currentSong][currentChannel][currentEvent].tick){
            if(midi[currentSong][currentChannel][currentEvent].isNoteOn()){
                int note = midi[currentSong][currentChannel][currentEvent].getKeyNumber();
                float gain = midi[currentSong][currentChannel][currentEvent].getVelocity()/127.0f;
                if(note>= piano->getLowestNote() && note <= piano->getHighestNote()){
                    piano->play(note - piano->getLowestNote(),gain);
                }
            }
            currentEvent++;
            while(currentEvent<midi[currentSong][currentChannel].size() && !midi[currentSong][currentChannel][currentEvent].isNoteOn()){
                currentEvent++;
            }
            if(currentEvent>=midi[currentSong][currentChannel].size()){
                if(currentSong +1<songCount){
                currentSong++;
                clear();
                }else{
                    playing = false;
                    clear();
                    timer = 0;
                }
            }
        }
    }
}
