
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "artist.h"

#include "artistplace.h"
using namespace std;
   void ArtistPlace::set_artist(Artistt* _this_artist){this_artist=_this_artist; }
	Artistt* ArtistPlace::get_artist(){return this_artist;}
	List ArtistPlace::list(){
        List new_list;
        for(int i=0 ; i<this_artist->get_albums().size();i++){
            new_list.push_back(this_artist->get_albums()[i]->get_name());
        }
        return new_list;
    }

    List ArtistPlace::listMusics(){
        List new_list;
        for(int i=0 ; i<this_artist->get_musics().size();i++){
            new_list.push_back(this_artist->get_musics()[i]->get_name());
        }
        return new_list;
    }


    List ArtistPlace::listAlbums(){
        List new_list;
        for(int i=0 ; i<this_artist->get_albums().size();i++){
            new_list.push_back(this_artist->get_albums()[i]->get_name());
        }
        return new_list;
    }

    string ArtistPlace::getName(){
        return this_artist->get_name();
    }

    int ArtistPlace::getRate(User* this_user){
        return this_artist->getRate(this_user);
    }

    int ArtistPlace::getUserRate(){
        return this_artist->getUserRate();
    }

    int ArtistPlace::getCriticRate(){
        return this_artist->getCriticRate();
    }

    string ArtistPlace::getCompleteName(){
        return this_artist->get_name();
    }