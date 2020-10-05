
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "musicplace.h"
#include "user.h"
using namespace std;
    AlbumPlace* MusicPlace::goToAlbum(){
    	AlbumPlace* new_place= new AlbumPlace; 
        new_place->set_type("album") ; 
        new_place->set_album(this_music->get_album());
        return new_place;
    }
    ArtistPlace* MusicPlace::goToArtist(){
    	ArtistPlace* new_place= new ArtistPlace; 
        new_place->set_type("artist") ; 
        new_place->set_artist(this_music->get_artist());
        return new_place;
    }

    List MusicPlace::listMusics(){
    	throw MethodNotAvailable();
        List new_list;
        return new_list;
    }

    List MusicPlace::listAlbums(){
    	throw MethodNotAvailable();
        List new_list;
        return new_list;
    }

    string MusicPlace::getName(){
        return this_music->get_name();
    }

    int MusicPlace::getRate(User* this_user){
        return this_music->getRate(this_user);
    }

    int MusicPlace::getUserRate(){
        return this_music->getUserRate();
    }

    int MusicPlace::getCriticRate(){
        return this_music->getCriticRate();
    }

     string MusicPlace::getCompleteName(){
       
        return this_music->getCompleteName();

    }
