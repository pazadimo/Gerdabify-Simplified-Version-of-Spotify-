
#ifndef MUSIC_H
#define MUSIC_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "rated.h"


using namespace std;

class Album;
class Artistt; 
class Music : public Rated{
public:
	void set_name_path(string music_name,string music_path);
	void set_artist(Artistt* artist);
	void set_album(Album* _album);
	string get_name(){return name;}
	string get_path(){return path;}
	Album* get_album(){return belonged_Album;}
	Artistt* get_artist(){return belonged_artist;}
	void validate(){granted=true;}
	string getCompleteName();
protected:
	Artistt* belonged_artist;
	string name;
	int length;
	bool granted;
	string path;
	Album* belonged_Album;
};



#endif //SHAPE_H