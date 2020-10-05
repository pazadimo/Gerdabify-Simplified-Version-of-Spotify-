#include <iostream>
#include <map>
#include <string>
#include "gerdabServer.hpp"
#include "musichandler.h"
#include "api.hpp"

    std::vector<string> pars_music(string complete){
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
    void MusicsHandler::callback(Request* req, Response* res) {
        UserData this_user;
        string token= req->getParam("token");
        //string item= req->getParam("keyword");
         res->body<< "<!DOCTYPE html><html><head>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"http://uupload.ir/files/w6bz_33.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }";
        res->body << " table, th, td {border: 1px solid black; background-color: yellow;text-align: center;}</style></head><body><table style="<<'"'<<"width:100"<<'%'<<'"'<<"><tr><th>Artist</th><th>Album</th><th>music</th></tr>";
        if(this_api->login_server(token,"default")==true){
            for (int i=0;i<this_api->listComplete("music").size();i++){
                std::vector<string> v2=pars_music(this_api->listComplete("music")[i]);
                res->body<<"<tr><td>"<<v2[0]<<"</td><td>"<<v2[1]<<"</td><td>"<<v2[2]<<"</td><td>";
                res->body<<"<audio controls>";
                //res->body<<"<source src="<<'"'<<"http://dl.songsara.net/RaMt%21N/95/12-Esfand/Nguyen%20Thu%20Thuy%20-%20Dan%20Nhi%20-%20Yeu%20%28Love%29%20%282011%29%20SONGSARA.NET/04%20Uoc%20Gi.mp3"<<'"'; 
                res->body<<"<source src="<<'"'<<this_api->getPath(v2[2])<<'"'; 
                res->body<<"type="<<'"'<<"audio/mpeg"<<'"'<<">";
                res->body<<"</audio></td>";
            }
            res->body << "</tr></body>";
        }
        else
            res->body << "<body><h1>token mot found :/</h1></body>";
    }
    void MusicsHandler::set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
