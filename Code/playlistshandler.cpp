#include <iostream>
#include <map>
#include <string>
#include "gerdabServer.hpp"
#include "playlistshandler.h"
#include "api.hpp"
    std::vector<string> pars_playlists(string complete){
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
    void PlayListsHandler::callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
         res->body<< "<!DOCTYPE html><html><head>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"http://uupload.ir/files/w6bz_33.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }";
        res->body << " table, th, td {border: 1px solid black; background-color: yellow;text-align: center;}</style></head><body><table style="<<'"'<<"width:100"<<'%'<<'"'<<"><tr><th>Artist</th><th>Album</tr>";        
         if(this_api->login_server(token,"default")==true){
             res->body<<"<tr>";
            for (int i=0;i<this_api->listComplete("playlists").size();i++){
                 std::vector<string> v2=pars_playlists(this_api->listComplete("playlists")[i]);
                 res->body<<"<tr><td>"<<v2[0]<<"</td><td>"<<v2[1]<<"</td>";
            }
            res->body << "</tr></body>";
        }
        else
            res->body << "<body><h1>token mot found :/</h1></body>";
    }
    void PlayListsHandler::set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
