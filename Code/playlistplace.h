
#ifndef PLAYLISTPLACE_H
#define PLAYLISTPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "place.h"
#include "playlist.h"


using namespace std;

class PlaylistPlace :public Place
{
public:
	vector<Playlist*>& get_playlist(){return this_playlists;}
	void set_playlist(vector<Playlist*> _this_playlists){this_playlists=_this_playlists;}
	string getName(){return "playlists";}
	string getCompleteName(){return "playlists";}
    //void goToHome();
protected:
	vector<Playlist*> this_playlists;
};



#endif //SHAPE_H