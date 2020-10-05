#include <iostream>
#include <map>
#include <string>
#include "gerdabServer.hpp"
#include "artisthandler.h"
#include "api.hpp"

    void ArtistsHandler::callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
         res->body<< "<!DOCTYPE html><html><head>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"http://uupload.ir/files/w6bz_33.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }";
        res->body << " table, th, td {border: 1px solid black; background-color: yellow;text-align: center;}</style></head><body><table style="<<'"'<<"width:100"<<'%'<<'"'<<"><tr><th>Artist</th></tr>"; if(this_api->login_server(token,"default")==true){
            for (int i=0;i<this_api->listComplete("artist").size();i++){
                res->body<<"<tr><td>"<<this_api->listComplete("artist")[i]<<"</td>";
            }
            res->body << "</tr></body>";
        }
        else
            res->body << "<body><h1>token mot found :/</h1></body>";
    }
    void ArtistsHandler::set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
