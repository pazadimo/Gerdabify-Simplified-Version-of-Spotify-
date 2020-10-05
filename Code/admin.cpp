
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "admin.h"
#include "artist.h"
#include "musicplace.h"


using namespace std;
	 void Adminn::validate_it(){
		cout<<current_place->get_type();
		if(current_place->get_type()=="album")
			dynamic_cast<AlbumPlace*>(current_place)->get_album()->validate();
		else if(current_place->get_type()=="artist")
			dynamic_cast<ArtistPlace*>(current_place)->get_artist()->validate();
		else if(current_place->get_type()=="music")
			dynamic_cast<MusicPlace*>(current_place)->get_music()->validate();
		else 
			throw MethodNotAvailable();
	 }