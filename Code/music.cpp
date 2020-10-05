
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
#include "artist.h"
#include "album.h"

using namespace std;
	void Music::set_artist(Artistt* artist){
		belonged_artist=artist;
	}
	void Music::set_name_path(string music_name,string music_path){
		name=music_name;
		path=music_path;
	}

	string Music::getCompleteName(){
		return belonged_artist->get_userdata().username+"-"+ belonged_Album->get_name()+"-"+name;
	}

	void Music::set_album(Album* _album){
		belonged_Album=_album;
	}

	