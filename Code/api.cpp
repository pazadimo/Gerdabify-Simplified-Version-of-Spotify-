#include "api.hpp"
using namespace std;


void GerdabifyAPI::enterBrowserMode(){
	logic->enterBrowserMode();
}
bool GerdabifyAPI::signup(UserData user_info, string password){
	return logic->signup(user_info,password);
}
void GerdabifyAPI::login(string username, string password){
	logic->login(username,password);
	
}
bool GerdabifyAPI:: login_server(string username, string password){
	return logic->login_server(username,password);
	
}
void GerdabifyAPI::addMusic(string music_name, string file_path){
	logic->addMusic(music_name,file_path);
}
void GerdabifyAPI::addAlbum(string artist_name, string album_name){
	logic->addAlbum(artist_name,album_name);
}
UserData GerdabifyAPI::getUserDetails(string username){
	return logic->getUserDetails(username);
}

void GerdabifyAPI::goToHome(){
	logic->goToHome();
}
void GerdabifyAPI::goToPlayList(){
	logic->goToPlayList();
}
void GerdabifyAPI::goToLibrary(){
	logic->goToLibrary();
}

void GerdabifyAPI::goToAlbum(){
	logic->goToAlbum();
}

void GerdabifyAPI::goToArtist(){
	logic->goToArtist();
}
void GerdabifyAPI:: validate(){

	logic->validate();
}
void GerdabifyAPI::createPlaylist(string playlist_name){
	logic->createPlaylist(playlist_name);
}

void GerdabifyAPI::clearPlaylist(string playlist_name){
	logic->clearPlaylist(playlist_name);
}

void GerdabifyAPI::orderItem(string comp_music_name , int index){
	logic->orderItem(comp_music_name,index);
}
List GerdabifyAPI::search(string item_name){
	return logic->search(item_name);
}

void GerdabifyAPI::select(string selected_name){
	logic->select(selected_name);
}

void GerdabifyAPI::goTo(string selected_item){
	logic->goTo(selected_item);
}

void GerdabifyAPI::addTo(string selected_name){
	logic->addTo(selected_name);
}

List GerdabifyAPI::list(){

	return logic->list();
}

string GerdabifyAPI::getPath(string music_name){
	return logic->getPath(music_name);
}

List GerdabifyAPI::listMusics(){

	return logic->listMusics();
}

List GerdabifyAPI::listComplete(string kind){

	return logic->listComplete(kind);
}

List GerdabifyAPI::listAlbums(){

	return logic->listAlbums();
}

List GerdabifyAPI::listPlaylists(){

	return logic->listPlaylists();
}

List GerdabifyAPI::listArtists(){

	return logic->listArtists();
}

void GerdabifyAPI::rate(int _rate){

	return logic->rate(_rate);
}

string GerdabifyAPI::getArtist(){

	return logic->getArtist();;
}

string GerdabifyAPI::getAlbum(){
	return logic->getAlbum();;
}

string GerdabifyAPI::getName(){
	return logic->getName();;
}

int GerdabifyAPI::getRate(){
	return logic->getRate();;
}

int GerdabifyAPI::getUserRate(){
	return logic->getUserRate();;
}

int GerdabifyAPI::getCriticRate(){
	return logic->getCriticRate();;
}


string GerdabifyAPI::getCompleteName(){
	return logic->getCompleteName();;
}

void GerdabifyAPI::enterPlayerMode(){
	logic->enterPlayerMode();;
}

void GerdabifyAPI::play(){
	logic->play();;
}

void GerdabifyAPI::next(){
	logic->next();;
}

void GerdabifyAPI::previous(){
	logic->previous();;
}

void GerdabifyAPI::remove(string _music){
	logic->remove(_music);
}

void GerdabifyAPI::pause(){
	logic->pause();
}

void GerdabifyAPI::repeat(){
	logic->repeat();
}

void GerdabifyAPI::shuffle(){
	logic->shuffle();
}