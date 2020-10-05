#include <iostream>
#include <map>
#include <string>
#include "gerdabServer.hpp"
#include "homehandler.h"
#include "signuphandler.h"
#include "loginhandler.h"
#include "searchhandler.h"
#include "musichandler.h"
#include "albumhandler.h"
#include "artisthandler.h"
#include "playlistshandler.h"
#include "playlisthandler.h"
#include "api.hpp"




class FormHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
        cout<<req->getParam("token")<<endl;
        res->body << "<body><h1>Gerdab Server</h1><p>This is gerdab server main page<p/></body>";

    }
};


int main(int argc, const char* argv[]) {
    try {

        Server server;
        GerdabifyAPI* k=new GerdabifyAPI;
        RequestHandler* homePage = new HomePageHandler();
        RequestHandler* form = new FormHandler();
        SignUpHandler* signup=new SignUpHandler();
        LoginHandler* login=new LoginHandler();
        SearchHandler* search=new SearchHandler();
        MusicsHandler* musics=new MusicsHandler();
        AlbumsHandler* albums=new AlbumsHandler();
        ArtistsHandler* artists=new ArtistsHandler();
        PlayListsHandler* playlists=new PlayListsHandler();
        PlayListHandler* playlist=new PlayListHandler();

        signup->set_api(k);
        login->set_api(k);
        search->set_api(k);
        musics->set_api(k);
        albums->set_api(k);
        artists->set_api(k);
        playlists->set_api(k);
        playlist->set_api(k);


        UserData hooshang;
    hooshang.firstname="hooshang";
    hooshang.username="hooshang";
    hooshang.userType=Admin;
    k->signup(hooshang,"1");
    k->login("hooshang2","2");
    UserData hooshang2;
    hooshang2.firstname="Wu";
    hooshang2.username="Wu";
    hooshang2.userType=Artist;
    k->signup(hooshang2,"2");
    k->login("Wu","2");
    k->enterBrowserMode();
   // h.login("hooshang3","3");
    k->addMusic("Hello","http://dl.songsara.net/RaMt%21N/95/12-Esfand/Nguyen%20Thu%20Thuy%20-%20Dan%20Nhi%20-%20Yeu%20%28Love%29%20%282011%29%20SONGSARA.NET/04%20Uoc%20Gi.mp3");
    k->addMusic("salam","http://dl.songsara.net/RaMt%21N/95/12-Esfand/Nguyen%20Thu%20Thuy%20-%20Dan%20Nhi%20-%20Yeu%20%28Love%29%20%282011%29%20SONGSARA.NET/06%20Con%20Mua%20Tinh%20Yeu%20%28Nghe%20Si%20Sao%20Tieu%20Nguyen%20Van%20Phu%29.mp3");
    k->addMusic("ame","http://dl.songsara.net/RaMt%21N/95/12-Esfand/Nguyen%20Thu%20Thuy%20-%20Dan%20Nhi%20-%20Yeu%20%28Love%29%20%282011%29%20SONGSARA.NET/10%20Tim%20Lai%20Giac%20Mo.mp3");
    k->addAlbum("Wu","Ghuzeng");
    k->goToHome();
    k->goToLibrary();
    k->createPlaylist("*BESTS*");
    k->select("Hello");
    k->goTo("*BESTS*");
    k->select("Hello");
    k->addTo("Wu-*BESTS*");
    k->addTo("Wu-Ghuzeng");
   // k->addTo("21-Hello");
    k->addTo("queue");
    k->select("ame");
    k->addTo("Wu-*BESTS*");
    k->addTo("Wu-Ghuzeng");
    k->addTo("queue");
   // k->addTo("21-ame");
    k->select("salam");
    k->addTo("Wu-*BESTS*");
    k->addTo("Wu-Ghuzeng");
    k->addTo("queue");
   // k->addTo("21-hamid");

  hooshang.firstname="ebrahim";
  hooshang.lastname="hamedi";
  hooshang.username="ebi";
  hooshang.userType=Artist;

  k->signup(hooshang,"ebi");
  k->login("ebi","ebi");
  k->addAlbum("ebi","Jane Javani");

  k->addMusic("Jane-Javani",
  "http://s3.srv1.mihandl.biz/nevisande/takahang/1393/Azar/29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/01%20Jane%20Javani.mp3");
  k->select("Jane-Javani");
  k->addTo("ebi-Jane Javani");

  k->addMusic("Habs",
  "http://s3.srv1.mihandl.biz/nevisande/takahang/1393/Azar/29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/02%20Habs.mp3");
  k->select("Habs");
  k->addTo("ebi-Jane Javani");

  k->addMusic("Donyaie Arezoo",
  "http://s3.srv1.mihandl.biz/nevisande/takahang/1393/Azar/29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/03%20Donyaye%20Arezo.mp3");
  k->select("Donyaie Arezoo");
  k->addTo("ebi-Jane Javani");

  k->addMusic("Boghz",
  "http://s3.srv1.mihandl.biz/nevisande/takahang/1393/Azar/29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/04%20Boghz.mp3");
  k->select("Boghz");
 k->addTo("ebi-Jane Javani");

  k->addMusic("Bi Etena",
  "http://s3.srv1.mihandl.biz/nevisande/takahang/1393/Azar/29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/Ebi%20-%20Jane%20Javani%20%28MP3%20320%29/05%20Bi%20Etena.mp3");
  k->select("Bi Etena");
  k->addTo("ebi-Jane Javani");


        server.get("/home", homePage);
        server.post("/search", search);
        server.get("/musics", musics);
        server.get("/albums", albums);
        server.get("/artists", artists);
        server.get("/playlists", playlists);

        server.post("/playlists", playlist);
        server.post("/signup", signup);
        server.get("/login", login);

        server.post("/form", form);

        cout << "Listening on port 5000" << endl;
        server.start(5000);
    } catch(Exception e) {
        cerr << "WebServer: " << e.getMessage() << endl;
    }

    return EXIT_SUCCESS;
}
