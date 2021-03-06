#include "player.h"

Player::Player(vector<char*> files,Piano* piano){
    this->piano = piano;
    playing = false;
	songs = files;
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
            midi[i].joinTracks();
            midi[i].linkNotePairs();
            midi[i].doTimeAnalysis();
        }else{
            printf("[FAIL]\n");
            i--;
            songCount--;
        }
    }
	prepareSongTitles();
}
void Player::prepareSongTitles() {
	std::string s = ".mid";
	for (int i = 0; i < songs.size(); ++i) {
		int len = strlen(songs[i]);
		if (s.compare(songs[i] + len - 4)) {
			songs[i][len - 4] = '\0';
		}
		int pos = -1;
		for (int j = len - 1; j >= 0; j--) {
			if (songs[i][j] == '/') {
				pos = j;
				break;
			}
		}
		if (pos != -1) {
			char* name = new char[len + 1 - pos];
			strcpy(name, songs[i] + pos + 1);
			delete[] songs[i];
			songs[i] = name;
		}
	}
}
Player::~Player(){
    delete[] midi;
	for (auto& c : songs) {
		delete[] c;
	}
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
char* Player::getCurrentSong() {
	return songs[currentSong];
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
                float gain = midi[currentSong][currentChannel][currentEvent].getVelocity()/355.0f;
                piano->playAbsolute(note - piano->getLowestNote(),gain);
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
