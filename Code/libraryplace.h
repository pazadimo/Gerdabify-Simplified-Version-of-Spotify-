
#ifndef LIBRARYPLACE_H
#define LIBRARYPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

class DataBase;
using namespace std;
string getName();
class LibraryPlace :public Place
{
public:
    void set_library(DataBase* _this_library);
    
    List list();
    List listMusics();
    List listAlbums();
    string getName();
    string getCompleteName();

protected:
	DataBase* this_library;
};



#endif //SHAPE_H