#include <dirent.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

#define SERVER_NAME "Web++"
#define SERVER_VERSION "1.0.1"

#define BUFSIZE 8096

using namespace std;
class Request {
public:
    Request();
    std::string method;
    std::string path;
    std::string params;
    map<string, string> headers;
    map<string, string> query;
    map<string, string> cookies;
    string getParam(string key){
        return query[key];
    }
    string getHeader(string key){
        return headers[key];
    }
};
class Response {
public:
    Response();
    int code;
    string phrase;
    string type;
    string date;
    stringstream body;
    void send(string str);
    void send(const char* str);
};
class RequestHandler{
public:
    virtual void callback(Request*, Response*) = 0;
};
class Exception : public std::exception {
    public:
        Exception();
        Exception(const char* pStr);
        const char* getMessage();
    private:
        const char* pMessage;

};

struct Route {
    string path;
    string method;
    RequestHandler* handler;
    string params;
};



class WPPServer {
    public:
        void get(string, RequestHandler*);
        void post(string, RequestHandler*);
        void all(string, RequestHandler*);
        bool start(int, string);
        bool start(int);
        bool start();
    private:
        void* main_loop(void*);
        void parse_headers(char*, Request*, Response*);
        bool match_route(Request*, Response*);
        string trim(string);
        void split(string, string, int, vector<string>*);
        vector<Route> ROUTES;
        map<string, string> mime;

};

