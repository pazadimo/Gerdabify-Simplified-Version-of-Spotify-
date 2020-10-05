#include <iostream>
#include <map>
#include <string>


class HomePageHandler: public RequestHandler{
    void callback(Request* req, Response* res);
};