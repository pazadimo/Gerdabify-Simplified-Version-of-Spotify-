
#ifndef ALBUMPLACE_H
#define ALBUMPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
//#include "list_user.h"
//#include "database.h"
#include "album.h"
#include "place.h"
#include "artistplace.h"
using namespace std;

class AlbumPlace :public Place
{
public:
	void set_album(Album* _this_album);
	ArtistPlace* goToArtist();
	Album* get_album(){return this_album;}
	List list();
	List listMusics();
	string getName();
	int getRate(User* this_user);
	int getCriticRate();
	int getUserRate();
	string getCompleteName();
protected:
	Album* this_album;
};



#endif //SHAPE_H