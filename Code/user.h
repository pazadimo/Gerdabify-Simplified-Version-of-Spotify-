
#ifndef USER_H
#define USER_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "playlist.h"
#include "queue.h"
#include "place.h"

#include "database.h"
#include "homeplace.h"
#include "playlistplace.h"
#include "albumplace.h"
#include "artistplace.h"
#include "onlyplaylistplace.h"
#include "musicplace.h"
#include "queueplace.h"

enum ModeType{Browser,Play};


class User
{
public:
	void set_default(UserData _this_user,string _password,DataBase* _this_data_base);
	UserData get_user();
	virtual void validate_it();
    virtual UserData getUserDetails(string name);
    virtual void addAlbum(string artist_name, string album_name);
    virtual void addMusic(string music_name, string file_path);
    string get_username();
    string get_password();
    UserData get_userdata(){return this_user;}
    string get_name(){return this_user.username;}
    void enterBrowserMode();
    void goToHome();////////////
    void goToPlayList();/////////
    void goToPlayLibrary();////////
    void goToAlbum();//////////
    void goToArtist();////////
    void createPlaylist(string playlist_name);
    void clearPlaylist(string playlist_name);
    void orderItem(string comp_music_name ,int index);
    List search(string item_name);
    void select(string selected_name);
    void goTo(string selected_name);
    void addTo(string selected_name);
    List list();
    List listMusics();
    List listComplete(string kind);
    List listAlbums();
    List listPlaylists();
    List listArtists();
    void rate(int _rate);
    string getArtist();
    string getAlbum();
    string getName();
    int getRate();
    int getUserRate();
    int getCriticRate();
    string getCompleteName();
    void enterPlayerMode();
    void play();
    void next();
    void remove(string _music);
    void pause();
    void repeat();
    void shuffle();
    void previous();
protected:
	UserData this_user;
	string password;
	Place* current_place;
	std::vector<Playlist*> playlists;
	DataBase* this_data_base;
	ModeType user_mode;
	Playlist* current_playlist;
	Queue current_queue;

};



#endif //SHAPE_H