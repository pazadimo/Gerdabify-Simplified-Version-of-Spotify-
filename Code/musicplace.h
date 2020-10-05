
#ifndef MUSICPLACE_H
#define MUSICPLACE_H

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

#include "albumplace.h"
#include "artistplace.h"

using namespace std;

class MusicPlace :public Place
{
public:
    AlbumPlace* goToAlbum();
    ArtistPlace* goToArtist();
    Music* get_music(){return this_music;}
    void set_music(Music* _this_music){this_music=_this_music;}
    List listMusics();
    List listAlbums();
    string getName();
    int getRate(User* this_user);
    int getUserRate();
    int getCriticRate();
    string getCompleteName();

protected:

	Music* this_music;
};



#endif //SHAPE_H