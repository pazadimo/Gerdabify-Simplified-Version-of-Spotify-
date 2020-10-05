#include "logic.hpp"
using namespace std;
#include "database.h"

void Logic::enterBrowserMode(){
	current_user->enterBrowserMode();
}
bool Logic::signup(UserData user_info, string password){
	User* new_user;
	if(user_info.userType==Normal)
		new_user=new User;
	else if (user_info.userType==Artist)
		new_user=new Artistt;
	else if (user_info.userType==Admin)
		new_user=new Adminn;
	else if (user_info.userType==Editor)
		new_user=new User;
	else
		new_user=new User;
	for (int i=0;i<users.size();i++){
	 	if(users[i]->get_username()==user_info.username){
	 		return false;
	 	}
	 }
	new_user->set_default(user_info,password,&this_data_base);
	users.push_back(new_user);
	if (user_info.userType==Artist)
		this_data_base.add_artist((Artistt*)new_user);
	 cout << users.size();
	 return true;
}

void Logic::login(string username, string password){
	 for (int i=0;i<users.size();i++){
	 	if(users[i]->get_username()==username && users[i]->get_password()==password){
	 		cout <<users[i]->get_username()<<"\n";
			current_user=users[i];
			break;
	 	}
	 }
}

bool Logic::login_server(string username, string password){
	 for (int i=0;i<users.size();i++){
	 	if(users[i]->get_username()==username && (users[i]->get_password()==password || password=="default" )){
	 		cout <<users[i]->get_username()<<"\n";
			current_user=users[i];
			return true;
			break;
	 	}
	 }
	 return false;
}

void Logic::addMusic(string music_name, string file_path){
	current_user->addMusic(music_name,file_path);
}
void Logic::addAlbum(string artist_name, string album_name){
	current_user->addAlbum(artist_name,album_name);
}
UserData Logic::getUserDetails(string username){
	for (int i=0;i<users.size();i++){
		if(users[i]->get_username()==username){
			// cout << "getUserDetail"<<username<<"\n";
			return users[i]->get_userdata();
		}
	}
	throw  MethodNotAvailable();
}

void Logic::goToHome(){
	current_user->goToHome();
}
void Logic::goToPlayList(){
	current_user->goToPlayList();
}
void Logic::goToLibrary(){
	current_user->goToPlayLibrary();
}

void Logic::goToAlbum(){
	current_user->goToAlbum();
}

void Logic::goToArtist(){
	current_user->goToArtist();
}
void Logic:: validate(){
	// cout << "validate\n";
	current_user->validate_it();
}
void Logic::createPlaylist(string playlist_name){
	current_user->createPlaylist(playlist_name);
}

void Logic::clearPlaylist(string playlist_name){
	current_user->clearPlaylist(playlist_name);
}

void Logic::orderItem(string comp_music_name , int index){
	current_user->orderItem(comp_music_name,index);
}
List Logic::search(string item_name){
	return current_user->search(item_name);
}

void Logic::select(string selected_name){
	current_user->select(selected_name);
}

void Logic::goTo(string selected_item){
	current_user->goTo(selected_item);
}

void Logic::addTo(string selected_name){
	current_user->addTo(selected_name);
}

List Logic::list(){

	return current_user->list();
}

string Logic::getPath(string music_name){
	return this_data_base.getPath(music_name);
}


List Logic::listMusics(){

	return current_user->listMusics();
}

List Logic::listComplete(string kind){

	return current_user->listComplete(kind);
}

List Logic::listAlbums(){

	return current_user->listAlbums();
}

List Logic::listPlaylists(){

	return current_user->listPlaylists();
}

List Logic::listArtists(){

	return current_user->listArtists();
}

void Logic::rate(int _rate){

	return current_user->rate(_rate);
}

string Logic::getArtist(){

	return current_user->getArtist();;
}

string Logic::getAlbum(){
	return current_user->getAlbum();;
}

string Logic::getName(){
	return current_user->getName();;
}

int Logic::getRate(){
	return current_user->getRate();;
}

int Logic::getUserRate(){
	return current_user->getUserRate();;
}

int Logic::getCriticRate(){
	return current_user->getCriticRate();;
}


string Logic::getCompleteName(){
	return current_user->getCompleteName();;
}

void Logic::enterPlayerMode(){
	current_user->enterPlayerMode();;
}

void Logic::play(){
	current_user->play();;
}

void Logic::next(){
	current_user->next();;
}



void Logic::previous(){
	current_user->previous();;
}


void Logic::remove(string _music){
	current_user->remove(_music);
}

void Logic::pause(){
	current_user->pause();
}

void Logic::repeat(){
	current_user->repeat();
}

void Logic::shuffle(){
	current_user->shuffle();
}