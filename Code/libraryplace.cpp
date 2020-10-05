
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
#include "database.h"
#include "artist.h"
using namespace std;
    void LibraryPlace::set_library(DataBase* _this_library){this_library=_this_library;}
    List LibraryPlace::list(){
        List new_list;
        for(int i=0 ; i<this_library->get_artists().size();i++){
            new_list.push_back(this_library->get_artists()[i]->get_name());
        }
        return new_list;
    }
    List LibraryPlace::listMusics(){
        List new_list;
        for(int i=0 ; i<this_library->get_musics().size();i++){
            new_list.push_back(this_library->get_musics()[i]->get_name());
        }
        return new_list;
    }

    List LibraryPlace::listAlbums(){
        List new_list;
        for(int i=0 ; i<this_library->get_albums().size();i++){
            new_list.push_back(this_library->get_albums()[i]->get_name());
        }
        return new_list;
    }
    string LibraryPlace::getName(){
        return "library";
    }

    string LibraryPlace::getCompleteName(){
        return "library";

    }