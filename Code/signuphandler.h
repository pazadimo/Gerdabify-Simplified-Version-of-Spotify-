#include <iostream>
#include <map>
#include <string>

class GerdabifyAPI;
class SignUpHandler: public RequestHandler{
    void callback(Request* req, Response* res);
public:
    void set_api(GerdabifyAPI* _this_api);
    GerdabifyAPI* this_api;

};