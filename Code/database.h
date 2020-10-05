
#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "music.h"
#include "album.h"

class Artistt;

class DataBase
{
public:
	void add_album(Album* new_album);
	void add_music(Music* new_music);
	void add_artist(Artistt* new_artist);
	std::vector<string> getComplete(string kind);
	std::vector<Music*> get_musics();
	std::vector<Album*> get_albums();
	std::vector<Artistt*> get_artists();
	std::vector<string> search(string item_name);
	string getPath(string music_name);
protected:
	std::vector<Music*> musics;
	std::vector<Album*> albums;
	std::vector<Artistt*> artists;
};



#endif //SHAPE_H