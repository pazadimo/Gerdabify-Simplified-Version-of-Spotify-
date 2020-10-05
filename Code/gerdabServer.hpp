
#include "web++.hpp"
#include <map>
#include <string>
using namespace std;
class Server
{
private:
    WPPServer* server;
public:
    Server();
    void start(int port);
    void get(string path, RequestHandler* handler);
    void post(string path, RequestHandler* handler);
};
