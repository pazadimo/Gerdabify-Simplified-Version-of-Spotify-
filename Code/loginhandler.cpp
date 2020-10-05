#include <iostream>
#include <map>
#include <string>
#include "gerdabServer.hpp"
#include "loginhandler.h"
#include "api.hpp"

     void LoginHandler::callback(Request* req, Response* res) {
        UserData this_user;
        string username= req->getParam("username");
        string pass= req->getParam("password");

        if(this_api->login_server(username,pass)==true){
            res->body << "<body><h1>Gerdab Server</h1><p>"<<username<<" is logged in </p><p>your username is your token</p></body></html>";
            
        }
        else
            res->body << "<body><h1>username or password is wrong!!!   :/</h1></body>";
        ifstream myfile ("r.html");
        string line;
        while ( getline (myfile,line) ){
            res->body<< line;
        }
    }
    void LoginHandler::set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
