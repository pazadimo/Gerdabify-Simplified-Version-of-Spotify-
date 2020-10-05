#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "gerdabPlayer.hpp"


class Music;
class Queue
{
public:
	void add_music(Music* new_music);
	std::vector<Music*> get_musics();
	void play();
	void next();
	void previous();
	void pause();
	void repeat();
	void shuffle();
protected:
	std::vector<Music*> musics;
	GerdabPlayer player;
	bool cont;
	//class play
};



#endif //SHAPE_H