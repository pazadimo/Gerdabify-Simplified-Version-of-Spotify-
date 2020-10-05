
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "homeplace.h"

using namespace std;
	PlaylistPlace* HomePlace::goToPlayList(){
        PlaylistPlace* new_place= new PlaylistPlace; 
        new_place->set_type("playlist") ; 
        return new_place;
    }
    LibraryPlace* HomePlace::goToLibrary(){
        LibraryPlace* new_place= new LibraryPlace; 
        new_place->set_type("library") ; 
        return new_place;
    }
    List HomePlace::list(){
        List new_list;
        new_list.push_back("library");
        new_list.push_back("playlists");
        return new_list;
    }

     string HomePlace::getName(){
        return "home";
    }


    string HomePlace::getCompleteName(){
        return "Home";
    }