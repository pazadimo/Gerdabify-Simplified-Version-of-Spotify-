
#ifndef ARTIST_H
#define ARTIST_H

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
#include "user.h"
class DataBase;

using namespace std;
class Music;
class Album;
class Artistt :public User, public Rated
{
public:
	virtual void rate(int _rate,User* this_user);
	virtual int getRate(User* this_user);
    virtual void addAlbum(string artist_name, string album_name);
    virtual void addMusic(string music_name, string file_path);
    void validate(){granted=true;}
    virtual int getUserRate();
    virtual int getCriticRate();
    string getCompleteName();
    vector<Album*> get_albums(){return albums;}
    vector<Music*> get_musics(){return musics;}
protected:
	std::vector<Music*> musics;
	std::vector<Album*> albums;
	bool granted;
};



#endif //SHAPE_H