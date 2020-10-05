
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "user.h"
#include "artist.h"


using namespace std;
	void User::set_default(UserData _this_user,string _password,DataBase* _this_data_base){
		this_user=_this_user;
		password=_password;
		current_place=new HomePlace;
		current_place->set_type("home");
		this_data_base=_this_data_base;

	}
	UserData User::get_user(){
		return this_user;
	}
	void User::validate_it(){

		throw NotAuthorized();
	}
	UserData User::getUserDetails(string name){
		throw MethodNotAvailable();
	}
	void User::addAlbum(string artist_name, string album_name){
		throw NotAuthorized();
	}
	void User::addMusic(string music_name, string file_path){
		throw NotAuthorized();
	}
	string User::get_username(){
		return this_user.username;
	}
    string User::get_password(){
		return password;
	}
	void User::enterBrowserMode(){
		user_mode=Browser;
	}
	void User::goToHome(){
		current_place=new HomePlace;
		current_place->set_type("home");
	}
	void User::goToPlayList(){
		current_place=current_place->goToPlayList();
		dynamic_cast<PlaylistPlace*>(current_place)->set_playlist(playlists);
		//cout << "current place"<<current_place->get_type()<<"\n";
	}
	void User::goToPlayLibrary(){
		current_place=current_place->goToLibrary();
		dynamic_cast<LibraryPlace*>(current_place)->set_library(this_data_base);
		//cout << "current place"<<current_place->get_type()<<"\n";
	}

	void User::goToAlbum(){
		current_place=current_place->goToAlbum();
		//cout << "current place"<<current_place->get_type()<<"\n";
	}
	void User::goToArtist(){
		current_place=current_place->goToArtist();
		//cout << "current22 place"<<current_place->get_type()<<"\n";
	}

	void User::createPlaylist(string playlist_name){
		for(int i=0;i<playlists.size();i++){
			if(playlists[i]->get_name()==playlist_name)
				throw  	AlreadyExists();	
		}
		Playlist* new_playlist=new Playlist;
		new_playlist->set_name(playlist_name);
		playlists.push_back(new_playlist);
		//cout<< "playlist #"<<playlists.size()<<new_playlist->get_name()<<"created\n";
	}
	void User::clearPlaylist(string playlist_name){
		for(int i=0;i<playlists.size();i++){
			if(playlists[i]->get_name()==playlist_name){
				//cout<< "playlist #"<<i<<playlists[i]->get_name()<<"cleared\n";
				playlists.erase(playlists.begin()+i);
			}
		}
	}
	void User::orderItem(string comp_music_name ,int index){
		int index2=-1;
		int i1=comp_music_name.find("-");
		comp_music_name[i1]='|';
		int i2=comp_music_name.find("-");
		comp_music_name[i2]='|';
		string artist_name=comp_music_name.substr(0,i1);
		string album_name=comp_music_name.substr(i1+1,i2-i1-1);
		string music_name=comp_music_name.substr(i2+1,comp_music_name.size()-i2);
		if(current_playlist != 0)
		for (int i=0;i<current_playlist->get_musics().size();i++){	
			if(current_playlist->get_musics()[i]->getCompleteName()==comp_music_name){
				index2=i;
			}
		}
		if(index2==-1)
		 	throw ItemDoesNotExists();
		if(current_playlist->get_musics().size()<index || index<1)
			throw InvalidArguments();
		current_playlist->change_order(index2,index-1);

	}

	List User::search(string item_name){
		 List search_result;
		 search_result= this_data_base->search(item_name);
		for(int i=0;i<playlists.size();i++){
			if(this_user.username+"-"+playlists[i]->get_name()==item_name){
				//cout<< "playlist #"<<i<<playlists[i]->get_name()<<"searched\n";
				search_result.push_back(playlists[i]->get_name());
			}
		}	
		

		return search_result;
	}

	void User::select(string selected_name){
		bool founded;
		//cout<< "artist #"<<0<<this_data_base->get_artists()[0]->get_name()<<"selected\n";
		for(int i=0;i<playlists.size();i++){
			if(playlists[i]->get_name()==selected_name){
				//cout<< "playlist #"<<i<<playlists[i]->get_name()<<"selected\n";
				current_playlist=playlists[i];
				current_place=new OnlyPlaylistPlace;
				current_place->set_type("onlyplaylist");
				founded=true;
			}
		}
		for(int i=0;i<this_data_base->get_musics().size();i++){
			if(this_data_base->get_musics()[i]->get_name()==selected_name){
				//cout<< "music #"<<i<<this_data_base->get_musics()[i]->get_name()<<"selected\n";
				MusicPlace* new_MusicPlace =new MusicPlace;
				new_MusicPlace->set_type("music");
				new_MusicPlace->set_music(this_data_base->get_musics()[i]);
				current_place=new_MusicPlace;
				founded=true;
			}
		}
		for(int i=0;i<this_data_base->get_albums().size();i++){
			if(this_data_base->get_albums()[i]->get_name()==selected_name){
				//cout<< "album #"<<i<<this_data_base->get_albums()[i]->get_name()<<"selected\n";
				AlbumPlace* new_AlbumPlace =new AlbumPlace;
				new_AlbumPlace->set_type("album");
				new_AlbumPlace->set_album(this_data_base->get_albums()[i]);
				current_place=new_AlbumPlace;
				founded=true;
			}
		}
		for(int i=0;i<this_data_base->get_artists().size();i++){
			if(this_data_base->get_artists()[i]->get_name()==selected_name){
				//cout<< "artist #"<<i<<this_data_base->get_artists()[i]->get_name()<<"selected\n";
				ArtistPlace* new_ArtistPlace =new ArtistPlace;
				new_ArtistPlace->set_type("artist");
				new_ArtistPlace->set_artist(this_data_base->get_artists()[i]);
				current_place=new_ArtistPlace;
				founded=true;
			}
		}
		if(founded==0)
			throw ItemDoesNotExists();
	}

	void User::goTo(string selected_name){
		bool founded;
		if(selected_name=="queue"){
			QueuePlace* new_queue_place=new QueuePlace;
			new_queue_place->set_type("queue");
			current_place=new_queue_place;
			//cout<< "going to "<<new_queue_place->get_type()<<"\n";
			founded=true;
		}
		else{
			for(int i=0;i<playlists.size();i++){
				if(playlists[i]->get_name()==selected_name){
					//cout<< "playlist #"<<i<<playlists[i]->get_name()<<"went to it\n";
					current_playlist=playlists[i];
					current_place=new OnlyPlaylistPlace;
					current_place->set_type("onlyplaylist");
					founded=true;
				}
			}
		}
		if(founded==0)
			throw ItemDoesNotExists();
	}


	void User::addTo(string selected_name){
		bool founded;
		int i1;
		string artist_name;
		string album_playlist_name;
		if(selected_name != "queue"){
			 i1=selected_name.find("-");
			selected_name[i1]='|';
			artist_name=selected_name.substr(0,i1);
			if(artist_name != this_user.username)
				throw NotAuthorized();
			album_playlist_name=selected_name.substr(i1+1,selected_name.size()-i1-1);
		}
		if(current_place->get_type() !="music" && current_place->get_type()!="album" )
			throw MethodNotAvailable();
		if(selected_name=="queue"){
			founded=true;
			if(current_place->get_type()=="music"){
				if(dynamic_cast<MusicPlace*>(current_place)->get_music()->get_artist()->get_name() != this_user.username)
					throw NotAuthorized();
				current_queue.add_music(dynamic_cast<MusicPlace*>(current_place)->get_music());
			}
			else if(current_place->get_type()=="album"){
				for(int i=0 ;i< dynamic_cast<AlbumPlace*>(current_place)->get_album()->get_musics().size();i++){
					current_queue.add_music(dynamic_cast<AlbumPlace*>(current_place)->get_album()->get_musics()[i]);
				}
			}
		}
		





		for(int i=0 ;i< playlists.size();i++){
			if(playlists[i]->get_name()==album_playlist_name){
				founded=true;
				if(current_place->get_type()=="music"){
					if(dynamic_cast<MusicPlace*>(current_place)->get_music()->get_artist()->get_name() != this_user.username)
						throw NotAuthorized();
					playlists[i]->add_music(dynamic_cast<MusicPlace*>(current_place)->get_music());
				}
				else if(current_place->get_type()=="album"){
					for(int i=0 ;i< dynamic_cast<AlbumPlace*>(current_place)->get_album()->get_musics().size();i++){
						playlists[i]->add_music(dynamic_cast<AlbumPlace*>(current_place)->get_album()->get_musics()[i]);
					}
				}		
			}	
		}



		for(int i=0 ;i< this_data_base->get_albums().size();i++){
			if(this_data_base->get_albums()[i]->get_name()==album_playlist_name){
				founded=true;
				if(current_place->get_type()=="music"){
					if(dynamic_cast<MusicPlace*>(current_place)->get_music()->get_artist()->get_name() != this_user.username)
						throw NotAuthorized();
					this_data_base->get_albums()[i]->add_music(dynamic_cast<MusicPlace*>(current_place)->get_music());
					dynamic_cast<MusicPlace*>(current_place)->get_music()->set_album(this_data_base->get_albums()[i]);
				}
				else if(current_place->get_type()=="album"){
					for(int i=0 ;i< dynamic_cast<AlbumPlace*>(current_place)->get_album()->get_musics().size();i++){
						this_data_base->get_albums()[i]->add_music(dynamic_cast<AlbumPlace*>(current_place)->get_album()->get_musics()[i]);
					}
				}		
			}	
		}

		if(founded==0)
			throw ItemDoesNotExists();

	}

	List User::list(){
		if(current_place->get_type()=="onlyplaylist"){
			 List new_list;
        	for(int i=0 ; i<current_playlist->get_musics().size();i++){
        	    new_list.push_back(current_playlist->get_musics()[i]->get_name());
        	}
        	return new_list;
		}
		else
			return 	current_place->list();
	}


	List User::listMusics(){
		if(current_place->get_type()=="onlyplaylist"){
			 List new_list;
        	for(int i=0 ; i<current_playlist->get_musics().size();i++)
        	    new_list.push_back(current_playlist->get_musics()[i]->get_name());
        	return new_list;
		}
		else
			return 	current_place->listMusics();
	}

	List User::listComplete(string kind){
		if(kind=="playlists"){
			 List new_list;
        	for(int i=0 ; i<playlists.size();i++)
        	    new_list.push_back(this_user.username+"-"+playlists[i]->get_name());
        	return new_list;
		}
		else
			return 	this_data_base->getComplete(kind);
	}

	List User::listAlbums(){
		return 	current_place->listMusics();
	}

	List User::listPlaylists(){
		if(current_place->get_type()=="playlist"){
			 List new_list;
        	for(int i=0 ; i<playlists.size();i++){
        	    new_list.push_back(playlists[i]->get_name());
        	}
        	return new_list;
		}
		else
			throw MethodNotAvailable();
	}
	List User::listArtists(){
		if(current_place->get_type()=="library"){
			 List new_list;
        	for(int i=0 ; i<this_data_base->get_artists().size();i++){
        	    new_list.push_back(this_data_base->get_artists()[i]->get_name());
        	}
        	return new_list;
		}
		else
			throw MethodNotAvailable();
	}
	void User::rate(int _rate){
		if(_rate>100 || _rate<0)
			throw InvalidArguments();
		if(current_place->get_type()=="music"){
			 dynamic_cast<MusicPlace*>(current_place)->get_music()->rate(_rate,this);
		}
		else if(current_place->get_type()=="album"){
			 dynamic_cast<AlbumPlace*>(current_place)->get_album()->rate(_rate,this);
		}
		else if(current_place->get_type()=="artist"){
			 dynamic_cast<ArtistPlace*>(current_place)->get_artist()->rate(_rate,this);
		}
		else 
			throw MethodNotAvailable();
	}


	string User::getArtist(){
		if(current_place->get_type()=="music"){
			 return dynamic_cast<MusicPlace*>(current_place)->get_music()->get_artist()->get_name();
		}
		else if(current_place->get_type()=="album"){
			 return dynamic_cast<AlbumPlace*>(current_place)->get_album()->get_artist()->get_name();
		}
		else 
			throw MethodNotAvailable();
	}


	string User::getAlbum(){
		if(current_place->get_type()=="music"){
			 return dynamic_cast<MusicPlace*>(current_place)->get_music()->get_album()->get_name();
		}
		else 
			throw MethodNotAvailable();
	}

	string User::getName(){
		if(current_place->get_type()=="playlist")
			return current_playlist->get_name();
		return current_place->getName();
	}

	
	int User::getRate(){
		return current_place->getRate(this);;
	}


	int User::getUserRate(){
		return current_place->getUserRate();;
	}

	int User::getCriticRate(){
		return current_place->getCriticRate();;
	}



string User::getCompleteName(){
	if(current_place->get_type()=="onlyplaylist"){
		return this_user.username+"-"+current_playlist->get_name();
	}
	return current_place->getCompleteName();;
}

void User::remove(string _music){
	bool founded;
	for(int i=0;i<this_data_base->get_musics().size();i++){
		if(this_data_base->get_musics()[i]->getCompleteName()==_music){
			//cout<< "music #"<<i<<this_data_base->get_musics()[i]->get_name()<<"selected\n";
			MusicPlace* new_MusicPlace =new MusicPlace;
			new_MusicPlace->set_type("music");
			new_MusicPlace->set_music(this_data_base->get_musics()[i]);
				current_place=new_MusicPlace;
				founded=true;
		}
	}
	
}


void User::enterPlayerMode(){
	user_mode=Play;
}

void User::play(){
	if(user_mode ==Play)
		current_queue.play();
	else{
		if(current_place->get_type()=="music"){
				current_queue.add_music(dynamic_cast<MusicPlace*>(current_place)->get_music());
			}
		else if(current_place->get_type()=="album"){
			for(int i=0 ;i< dynamic_cast<AlbumPlace*>(current_place)->get_album()->get_musics().size();i++){
				current_queue.add_music(dynamic_cast<AlbumPlace*>(current_place)->get_album()->get_musics()[i]);
			}
		}
		else if(current_place->get_type()=="artist"){
			for(int i=0 ;i< dynamic_cast<ArtistPlace*>(current_place)->get_artist()->get_musics().size();i++){
				current_queue.add_music(dynamic_cast<ArtistPlace*>(current_place)->get_artist()->get_musics()[i]);
			}
		}
		else if(current_place->get_type()=="onlyplaylist"){
			for(int i=0 ;i< current_playlist->get_musics().size();i++){
				current_queue.add_music(current_playlist->get_musics()[i]);
			}
		}
	}
	

}

void User::next(){
	if(user_mode ==Play)
		current_queue.next();
	else
		throw MethodNotAvailable();
}

void User::previous(){
	if(user_mode ==Play)
		current_queue.previous();
	else
		throw MethodNotAvailable();
}

void User::pause(){
	if(user_mode ==Play)
		current_queue.pause();
	else
		throw MethodNotAvailable();
}

void User::repeat(){
	if(user_mode ==Play)
		current_queue.repeat();
	else
		throw MethodNotAvailable();
}

void User::shuffle(){
	if(user_mode ==Play)
		current_queue.shuffle();
	else
		throw MethodNotAvailable();
}