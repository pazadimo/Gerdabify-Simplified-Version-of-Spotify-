#include <iostream>
#include <map>
#include <string>
#include "gerdabServer.hpp"
#include "api.hpp"


class HomePageHandler: public RequestHandler{
    void callback(Request* req, Response* res) {

        
        cout<<req->getParam("token")<<endl;
        // res->body<< "<!DOCTYPE html><html><head>";
        // res->body<<"<style>   body{  background-image: url("<<'"'<<"http://images.medicaldaily.com/sites/medicaldaily.com/files/2014/03/11/listening-music_0.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }</style>";
        // res->body<< "</head>";
        ifstream myfile ("r.html");
        string line;
        while ( getline (myfile,line) ){
            res->body<< line;
        }
       // res->body << "<body><h1>GerdabServer</h1><p>This is Gerdab Server Home Page</p></body>";

    }
};

class SignUpHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
        UserData this_user;
        bool completed=true;
        res->body << "<body><h1>Gerdab Server</h1>";
        this_user.username= req->getParam("username");
        this_user.firstname= req->getParam("firstname");
        this_user.lastname= req->getParam("lastname");
        string pass= req->getParam("password");
        if(this_user.username==""){
            completed=false;
            res->body <<" <p>No username <p/>";
        }
        if(this_user.firstname==""){
            completed=false;
            res->body <<"<p>No firsname <p/>";
        }
        if(this_user.lastname==""){
            completed=false;
            res->body <<"<p>No lastname <p/>";
        }
        if(pass==""){
            completed=false;
            res->body <<"<p>No password <p/>";
        }
        string type=req->getParam("type");
        if(type=="admin")
            this_user.userType=Admin;
        else if(type=="artist")
            this_user.userType=Artist;
        else  if(type=="Normal")
            this_user.userType=Normal;
        else if(type=="editor")
            this_user.userType=Editor;
        else if(type==""){
            completed=false;
            res->body <<" <p>No type <p/>";
        }
        else{
            completed=false;
            res->body <<" <p>Invalid type <p/>";
        }
        if(completed==true){
            if(this_api->signup(this_user,pass)){
                res->body << "<p>This is gerdab server main Page    Hello  "<<this_user.firstname<<"<p/>";
                res->body << "<p>your username is your token<p/></body>";
            } 
            else{
                 res->body << "<p>username has been used before<p/></body>";
            }  
        }
    }
public:
    void set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
    GerdabifyAPI* this_api;

};

class LoginHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
        UserData this_user;
        string username= req->getParam("username");
        string pass= req->getParam("password");
        res->body<< "<!DOCTYPE html><html><head>";

         res->body <<"<html>";
          res->body <<"<form>";
         res->body<<"<input class="<<'"'<<"MyButton"<<'"'<<" type="<<'"'<<"button"<<'"'<<" value="<<'"'<<"Your Text Here"<<'"'<<" onclick="<<'"'<<"href='127.0.0.1:5000/playlists?token=admin'"<<'"'<<"/>";
         res->body <<"</form>"; 
        
        res->body<<"<style>   body{  background-image: url("<<'"'<<"/home/novin/Downloads/ph2/1.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }</style>";
        res->body<< "</head>";

         if(this_api->login_server(username,pass)==true){
            res->body << "<body><h1>Gerdab Server</h1><p>"<<username<<" is logged in </p><p>your username is your token</p></body></html>";
            
        }
        else
            res->body << "<body><h1>username or password is wrong!!!   :/</h1></body>";
    }
public:
    void set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
    GerdabifyAPI* this_api;

};

std::vector<string> pars(string complete){
    std::vector<string> out;
    string a=complete;//this_api->listComplete(item)[i]
    int i1=a.find("-");
    a[i1]='|';
    int i2=a.find("-");
    a[i2]='|';
    out.push_back(a.substr(0,i1));
    out.push_back(a.substr(i1+1,i2-i1-1));
    out.push_back(a.substr(i2+1,a.size()-i2-1));
    return out;
}

std::vector<string> pars2(string complete){
    std::vector<string> out;
    string a=complete;//this_api->listComplete(item)[i]
    int i1=a.find("-");
    a[i1]='|';
    //int i2=a.find("-");
    //a[i2]='|';
    out.push_back(a.substr(0,i1));
    //out.push_back(a.substr(i1+1,i2-i1-1));
    out.push_back(a.substr(i1+1,a.size()-i1-1));
    return out;
}

class SearchHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
        res->body << "<style> table, th, td {border: 1px solid black; background-color: yellow;text-align: center;}</style><body><table style="<<'"'<<"width:100"<<'%'<<'"'<<"><tr><th>Artist</th><th>Album</th><th>music</th></tr>";
        this_api->login_server(token,"default");
        string item= req->getParam("keyword");
        std::vector<string> v=this_api->listComplete(item);
        if(this_api->login_server(token,"default")==true){
            for (int i=0;i<this_api->listComplete(item).size();i++){
                std::vector<string> v2=pars(this_api->listComplete(item)[i]);
                res->body<<"<tr><td>"<<v2[0]<<"</td><td>"<<v2[1]<<"</td><td>"<<v2[2]<<"</td>";
            }
            res->body << "</tr></body>";
        }
        else
            res->body << "<body><h1>token mot found :/</h1></body>";
    }
public:
    void set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
    GerdabifyAPI* this_api;

};

class MusicsHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
        //string item= req->getParam("keyword");
         res->body<< "<!DOCTYPE html><html><head>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"/home/novin/Downloads/ph2/1.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }";
        res->body << " table, th, td {border: 1px solid black; background-color: yellow;text-align: center;}</style></head><body><table style="<<'"'<<"width:100"<<'%'<<'"'<<"><tr><th>Artist</th><th>Album</th><th>music</th></tr>";
        if(this_api->login_server(token,"default")==true){
            for (int i=0;i<this_api->listComplete("music").size();i++){
                std::vector<string> v2=pars(this_api->listComplete("music")[i]);
                res->body<<"<tr><td>"<<v2[0]<<"</td><td>"<<v2[1]<<"</td><td>"<<v2[2]<<"</td>";
            }
            res->body << "</tr></body>";
        }
        else
            res->body << "<body><h1>token mot found :/</h1></body>";
    }
public:
    void set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
    GerdabifyAPI* this_api;

};

class AlbumsHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
         res->body<< "<!DOCTYPE html><html><head>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"/home/novin/Downloads/ph2/1.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }";
        res->body << " table, th, td {border: 1px solid black; background-color: yellow;text-align: center;}</style></head><body><table style="<<'"'<<"width:100"<<'%'<<'"'<<"><tr><th>Artist</th><th>Album</tr>";        
        if(this_api->login_server(token,"default")==true){
            for (int i=0;i<this_api->listComplete("album").size();i++){
                 std::vector<string> v2=pars2(this_api->listComplete("album")[i]);
                 res->body<<"<tr><td>"<<v2[0]<<"</td><td>"<<v2[1]<<"</td>";
            }
            res->body << "</tr></body>";
        }
        else
            res->body << "<body><h1>token mot found :/</h1></body>";
    }
public:
    void set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
    GerdabifyAPI* this_api;

};

class ArtistsHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
         res->body<< "<!DOCTYPE html><html><head>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"http://uupload.ir/files/w6bz_33.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }";
        res->body << " table, th, td {border: 1px solid black; background-color: yellow;text-align: center;}</style></head><body><table style="<<'"'<<"width:100"<<'%'<<'"'<<"><tr><th>Artist</th></tr>"; if(this_api->login_server(token,"default")==true){
            for (int i=0;i<this_api->listComplete("artist").size();i++){
                //std::vector<string> v2=pars(this_api->listComplete("artist")[i]);
                res->body<<"<tr><td>"<<this_api->listComplete("artist")[i]<<"</td>";
            }
            res->body << "</tr></body>";
        }
        else
            res->body << "<body><h1>token mot found :/</h1></body>";
    }
public:
    void set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
    GerdabifyAPI* this_api;

};

class PlayListsHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
         res->body<< "<!DOCTYPE html><html><head>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"/home/novin/Downloads/ph2/1.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }";

         res->body << "<style> table, th, td {border: 1px solid black; background-color: yellow;text-align: center;}</style><body><table style="<<'"'<<"width:100"<<'%'<<'"'<<"><tr><th>Artist</th></tr>";
        if(this_api->login_server(token,"default")==true){
            for (int i=0;i<this_api->listComplete("playlists").size();i++){
                 std::vector<string> v2=pars2(this_api->listComplete("playlists")[i]);
                 res->body<<"<tr><td>"<<v2[0]<<"</td><td>"<<v2[1]<<"</td>";
            }
            res->body << "</tr></body>";
        }
        else
            res->body << "<body><h1>token mot found :/</h1></body>";
    }
public:
    void set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
    GerdabifyAPI* this_api;

};

class PlayListHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
        string new_playlist_name= req->getParam("name");
        res->body<< "<!DOCTYPE html><html><head>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"/home/novin/Downloads/ph2/1.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }</style>";
        res->body<< "</head>";
        try{
            if(this_api->login_server(token,"default")==true){
                this_api->createPlaylist(new_playlist_name);
                res->body << "<body>";
                res->body << "<p>playlist"<< new_playlist_name <<" created</p>";
                res->body << "</body>";
            }
            else{
                res->body << "<body><h1>token mot found :/</h1></body>";
            }
        }
        catch(AlreadyExists e){
             res->body << "<body><h1>playlist already exists :/</h1></body>";
        }

    }
public:
    void set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
    GerdabifyAPI* this_api;

};

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
    hooshang2.firstname="hooshang2";
    hooshang2.username="hooshang2";
    hooshang2.userType=Artist;
    k->signup(hooshang2,"2");
    k->login("hooshang2","2");
    k->enterBrowserMode();
   // h.login("hooshang3","3");
    k->addMusic("Hello","beat.wav");
    k->addMusic("hamid","hamid.wav");
    k->addMusic("ame","ame.wav");
    k->addAlbum("hooshang2","21");
    k->goToHome();
    k->goToLibrary();
    k->createPlaylist("*BESTS*");
    k->select("Hello");
    k->goTo("*BESTS*");
    k->select("Hello");
    k->addTo("hooshang2-*BESTS*");
    k->addTo("hooshang2-21");
   // k->addTo("21-Hello");
    k->addTo("queue");
    k->select("ame");
    k->addTo("hooshang2-*BESTS*");
    k->addTo("hooshang2-21");
    k->addTo("queue");
   // k->addTo("21-ame");
    k->select("hamid");
    k->addTo("hooshang2-*BESTS*");
    k->addTo("hooshang2-21");
    k->addTo("queue");
   // k->addTo("21-hamid");



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
