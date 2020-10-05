
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "albumplace.h"
#include "music.h"

using namespace std;
	void AlbumPlace::set_album(Album* _this_album){
        this_album=_this_album; 
    }
    ArtistPlace* AlbumPlace::goToArtist(){
        ArtistPlace* new_place= new ArtistPlace; 
        new_place->set_type("artist") ; 
        new_place->set_artist(this_album->get_artist());

        return new_place;
    }

    List AlbumPlace::list(){
        List new_list;
        for(int i=0 ; i<this_album->get_musics().size();i++){
            new_list.push_back(this_album->get_musics()[i]->get_name());
        }
        return new_list;
    }

    List AlbumPlace::listMusics(){
        List new_list;
        for(int i=0 ; i<this_album->get_musics().size();i++){
            new_list.push_back(this_album->get_musics()[i]->get_name());
        }
        return new_list;
    }

    string AlbumPlace::getName(){
        return this_album->get_name();
    }

    int AlbumPlace::getRate(User* this_user){
        return this_album->getRate(this_user);
    }



    int AlbumPlace::getUserRate(){
        return this_album->getUserRate();
    }

    int AlbumPlace::getCriticRate(){
        return this_album->getCriticRate();
    }

    string AlbumPlace::getCompleteName(){
        return this_album->getCompleteName();

    }