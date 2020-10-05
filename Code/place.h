
#ifndef PLACED_H
#define PLACED_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include <string.h>
#include "Exception.h"
#include "list_user.h"

using namespace std;
class PlaylistPlace;
class LibraryPlace;
class AlbumPlace;
class ArtistPlace;
class User;
class Place
{
public:
    virtual PlaylistPlace* goToPlayList();
    virtual LibraryPlace* goToLibrary();
    virtual AlbumPlace* goToAlbum();
    virtual ArtistPlace* goToArtist();
    virtual void select(string name);
    virtual void set_type(string _type);
    virtual string get_type();
    virtual List list();
    virtual List listMusics();
    virtual List listAlbums();
    virtual string getName();
    virtual int getRate(User* this_user);
    virtual int getUserRate();
    virtual int getCriticRate();
    virtual string getCompleteName();
protected:
	string type;

};



#endif //SHAPE_H