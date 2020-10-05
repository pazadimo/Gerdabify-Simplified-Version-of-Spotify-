//#include <QCoreApplication>
//#include <QMediaPlayer>
//#include <QFileInfo>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include "api.hpp"

int main(int argc, char *argv[])
{
    cout <<"start\n";
	Logic h;
    UserData hooshang;
    hooshang.firstname="hooshang";
    hooshang.username="hooshang";
    hooshang.userType=Admin;
    h.signup(hooshang,"1");
    h.login("hooshang2","2");
    UserData hooshang2;
    hooshang2.firstname="hooshang2";
    hooshang2.username="hooshang2";
    hooshang2.userType=Artist;
    h.signup(hooshang2,"2");
    h.login("hooshang2","2");
    UserData hooshang3;
    hooshang3.firstname="hooshang3";
    hooshang3.username="hooshang3";
    hooshang3.userType=Normal;
    h.signup(hooshang3,"3");
    h.enterBrowserMode();
   // h.login("hooshang3","3");
    h.addMusic("Hello","beat.wav");
    h.addMusic("hamid","hamid.wav");
    h.addMusic("ame","ame.wav");
    h.addAlbum("hooshang2","21");
    h.getUserDetails("hooshang");
    h.getUserDetails("hooshang");
    h.goToHome();
    //h.goToPlayList();
    //h.validate();
    h.goToLibrary();
    h.createPlaylist("*BESTS*");
    h.select("Hello");
    h.goTo("*BESTS*");
    h.select("Hello");
    h.addTo("hooshang2-*BESTS*");
    h.addTo("hooshang2-21");
    h.addTo("queue");
    h.select("ame");
    h.addTo("hooshang2-*BESTS*");
    h.addTo("hooshang2-21");
    h.addTo("queue");
     h.select("hamid");
    h.addTo("hooshang2-*BESTS*");
    h.addTo("hooshang2-21");
    h.addTo("queue");
    //h.goTo("21");
    
    h.goToHome();
    h.goToLibrary();
    cout <<h.listAlbums()[0];
    h.select("21");
    h.goToArtist();
     h.rate(10);

    //h.login("hooshang","1");
    // h.select("21");
    // h.goToArtist();
    //h.validate();
    // h.rate(10);
   //cout<<  h.getArtist();
    // cout<<  h.getCriticRate();
    // cout<<  h.getCompleteName();
    // cout << h.search("hooshang2-*BESTS*")[0];
     h.enterPlayerMode();
     h.play();
     h.next();
     h.pause();
     h.play();
     h.repeat();
     h.previous();
     cout<<"DFfffffffff";
     //h.shuffle();
     cout << "sbbbbbbbbbbb";
     while(1);


}
