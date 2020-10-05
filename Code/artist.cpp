
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
#include "database.h"

using namespace std;
	void Artistt::addAlbum(string artist_name, string album_name){
		Album* new_album=new Album;
		new_album->set_artist(this);
		new_album->set_name(album_name);
		this_data_base->add_album(new_album);
		albums.push_back(new_album);
	}
	void Artistt::addMusic(string music_name, string file_path){
		cout <<"fsssssssssssssssss";
		Music* new_music=new Music;
		new_music->set_artist(this);
		new_music->set_name_path(music_name,file_path);
		this_data_base->add_music(new_music);
		cout << new_music->get_name();
		musics.push_back(new_music);
	}
	void Artistt:: rate(int _rate,User* this_user){
		int index=-1;
		for(int i=0;i<users.size();i++){
			if(users[i]->get_userdata().username==this_user->get_userdata().username)
				index=i;
		}
		if(index==-1){
			users.push_back(this_user);
			rates.push_back(_rate);
		}
		else{
			rates[index]=_rate;
		}
		
	}
	int Artistt:: getRate(User* this_user){
		int index=-1;
		for(int i=0;i<users.size();i++){
			if(users[i]->get_userdata().username==this_user->get_userdata().username)
				index=i;
		}
		if(index==-1){
			return 0;
		}
		else{
			return rates[index];
		}
	}

	int Artistt::getUserRate(){
		int count=0;
		int number=0;
		for(int i=0;i<users.size();i++){
			if(users[i]->get_userdata().userType!=Editor && users[i]->get_userdata().userType!=Admin){
				count+=rates[i];
				number++;
			}
		}
		if (number !=0)
		return (int)(count/number);
	}

	int Artistt::getCriticRate(){
		int count=0;
		int number=0;
		for(int i=0;i<users.size();i++){
			if(users[i]->get_userdata().userType==Editor ){
				count+=rates[i];
				number++;
			}
		}
		if (number !=0)
		return (int)(count/number);
	}

	string Artistt::getCompleteName(){
        return this_user.username;
    }