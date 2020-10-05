
#ifndef HOMEPLACE_H
#define HOMEPLACE_H

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
#include "playlistplace.h"
#include "libraryplace.h"


using namespace std;
class HomePlace :public Place
{
public:
     PlaylistPlace* goToPlayList();
     LibraryPlace* goToLibrary();
     List list();
     string getName();
     string getCompleteName();
protected:
	
};



#endif //SHAPE_H