#include <iostream>
#include <map>
#include <string>
#include "gerdabServer.hpp"
#include "homehandler.h"


void HomePageHandler:: callback(Request* req, Response* res) {
        cout<<req->getParam("token")<<endl;
        // res->body<< "<!DOCTYPE html><html><head>";
        // res->body<<"<style>   body{  background-image: url("<<'"'<<"http://images.medicaldaily.com/sites/medicaldaily.com/files/2014/03/11/listening-music_0.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }</style>";
        // res->body<< "</head>";
        ifstream myfile ("home.html");
        string line;
        while ( getline (myfile,line) ){
            res->body<< line;
        }
       // res->body << "<body><h1>GerdabServer</h1><p>This is Gerdab Server Home Page</p></body>";

    }