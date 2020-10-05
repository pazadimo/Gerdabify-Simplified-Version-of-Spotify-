#include <vector>
#include <string>

#include "logic.hpp"

using namespace std;




class GerdabifyAPI
{
public:
     GerdabifyAPI(){
        logic=new Logic;
    }
    void enterBrowserMode();
    void goToHome();
    void goToPlayList();
    void goToLibrary();
    void goToAlbum();
    void goToArtist();
    List search(string);////////ta namoos naghes hhhhhhhaaaaaaaaa
    void select(string);
    void addTo(string);
    List list();
    List listMusics();
    List listComplete(string kind);
    List listAlbums();
    List listPlaylists();
    List listArtists();
  
    void goTo(string);
    void createPlaylist(string);
    void clearPlaylist(string);
    void orderItem(string, int);
    void rate(int);



    string getArtist();
    string getAlbum();
    string getName();
    string getPath(string music_name);
    int getRate();
    int getUserRate();
    int getCriticRate();
    string getCompleteName();
    void remove(string);
    void enterPlayerMode();
    void play();
    void next();
    void pause();
    void previous();
    void repeat();
    void shuffle();

    bool signup(UserData user_info, string password);
   void login(string username, string password);
   bool login_server(string username, string password);


    void addMusic(string, string);
    void addAlbum(string, string);
    UserData getUserDetails(string);
    void validate();

private:
    Logic* logic;
};
