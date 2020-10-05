#include <iostream>
#include <map>
#include <string>
#include "gerdabServer.hpp"
#include "signuphandler.h"
#include "api.hpp"

    void SignUpHandler:: callback(Request* req, Response* res) {
        UserData this_user;
        bool completed=true;
        res->body << "<body><h1>Gerdab Server</h1>";
        res->body<<"<style>   body{  background-image: url("<<'"'<<"http://uupload.ir/files/w6bz_33.jpg"<<'"'<<"); height: 100" <<'%'<<";   background-repeat: no-repeat; background-size: cover; }</style>";
        //res->body << <style>   body{  background-image: url("http://uupload.ir/files/w6bz_33.jpg"); height: 100%;   background-repeat: repeat; background-size: cover;  }</style>
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
        string type=req->getParam("userType");
        if(type=="admin")
            this_user.userType=Admin;
        else if(type=="artist")
            this_user.userType=Artist;
        else  if(type=="normal")
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
    void SignUpHandler::set_api(GerdabifyAPI* _this_api) {
       this_api=_this_api;
    }
