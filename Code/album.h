#ifndef ALBUM_H
#define ALBUM_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
//#include "music.h"

#include "rated.h"

using namespace std;
class Artistt;
class Music;

class Album :public Rated
{
public:
	void add_music(Music* new_musix);
	void set_name(string album_name);
	void set_artist(Artistt* artist);
	Artistt* get_artist(){return belonged_artist;}
	string get_name(){return name;}
	void validate(){granted=true;}
	void change_order(int index1,int index2);
	string getCompleteName();
	std::vector<Music*>& get_musics(){return musics;}
protected:
	std::vector<Music*> musics;
	Artistt* belonged_artist;
	string artist_name;
	string name;
	bool granted;
	int length;
	string path;


};



#endif //SHAPE_H