#include <iostream>
#include <map>
#include <string>
#include "gerdabServer.hpp"
#include "playlisthandler.h"
#include "api.hpp"

    void PlayListHandler::callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
        string new_playlist_name= req->getParam("name");
        res->body<< "<!DOCTYPE html><html><head>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"http://uupload.ir/files/w6bz_33.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }</style>";
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
    void PlayListHandler::set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
