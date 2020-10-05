

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "queue.h"
#include "music.h"

void Queue::add_music(Music* new_music){
	musics.push_back(new_music);
}
std::vector<Music*> Queue:: get_musics(){
	return musics; 
}
void Queue::play(){
	if(cont==true)
		player.resume();
	else{
	std::vector<string> queue; 
	for(int i=0;i<musics.size();i++){
		queue.push_back(musics[i]->get_path());
	}
    player.setQueue(queue);
    player.setRepeat(0);
    player.play();
    cont=true;
	}

}

void Queue::next(){

	player.goToNext();
}

void Queue::previous(){

	player.goToPre();
}

void Queue::pause(){
	player.pause();
}

void Queue::repeat(){
	player.setRepeat(1);
}

void Queue::shuffle(){
	int size=musics.size();
	std::vector<string> queue; 
	for(int i=0;i<musics.size();i++){
		int d=rand()%musics.size();

	}
}
