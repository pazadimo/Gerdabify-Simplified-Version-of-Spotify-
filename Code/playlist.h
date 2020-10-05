#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

class Music;
class Playlist
{
public:
	void set_name(std::string _name){name=_name;}
	std::string get_name(){return name;}
	void add_music(Music* new_music){musics.push_back(new_music);}
	std::vector<Music*> get_musics(){return musics; }
	void change_order(int index1,int index2){
		Music* temp=musics[index1];
		musics.erase(musics.begin()+index1);
		musics.insert(musics.begin()+index2,temp);
	}
protected:
	std::vector<Music*> musics;
	std::string name;

};



#endif //SHAPE_H