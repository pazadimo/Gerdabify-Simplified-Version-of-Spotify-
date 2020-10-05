
#ifndef ARTISTPLACE_H
#define ARTISTPLACE_H

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
class Artistt;
using namespace std;
class ArtistPlace :public Place
{
public:
	void set_artist(Artistt* _this_artist);
	Artistt* get_artist();
	List list();
	List listMusics();
	List listAlbums();
	string getName();
	int getRate(User* this_user);
	int getUserRate();
	int getCriticRate();
	string getCompleteName();
    //void goToHome();
protected:
	Artistt* this_artist;
};



#endif //SHAPE_H