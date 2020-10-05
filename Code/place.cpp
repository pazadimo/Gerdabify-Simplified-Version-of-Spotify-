
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

using namespace std;
	PlaylistPlace* Place::goToPlayList(){
		throw MethodNotAvailable();
	}
    LibraryPlace* Place::goToLibrary(){
    	throw MethodNotAvailable();
    }
    AlbumPlace* Place::goToAlbum(){
    	throw MethodNotAvailable();
    }
    ArtistPlace* Place::goToArtist(){
    	throw MethodNotAvailable();
    }
    void Place::select(string name){//////???????????
    	throw ItemDoesNotExists();
    }
    void Place::set_type(string _type){
    	type=_type;
    }

    string Place::get_type(){return type;}
    List Place::list(){
        List new_list;
        return new_list;
    }

    List Place::listMusics(){
        List new_list;
        return new_list;
    }

    List Place::listAlbums(){
        List new_list;
        return new_list;
    }

    string Place::getName(){
        return "";
    }

    int Place::getRate(User* this_user){
        throw MethodNotAvailable();
    }


    int Place::getUserRate(){
        throw MethodNotAvailable();
        return 0;

    }

    int Place::getCriticRate(){
        throw MethodNotAvailable();
        return 0;
        
    }

    string Place::getCompleteName(){
        return " ";
    }