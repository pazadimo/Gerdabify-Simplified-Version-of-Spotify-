
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "album.h"
#include "artist.h"
using namespace std;
	void Album::set_artist(Artistt* artist){
		belonged_artist=artist;
	}
	void Album::set_name(string album_name){
		name=album_name;
	}
	void Album::change_order(int index1,int index2){
		Music* temp=musics[index1];
		musics.erase(musics.begin()+index1);
		musics.insert(musics.begin()+index2,temp);
	}
	void Album::add_music(Music* new_musix){
		musics.push_back(new_musix);
	}

	string Album::getCompleteName(){
		return  belonged_artist->get_userdata().username+"-"+name;
	}