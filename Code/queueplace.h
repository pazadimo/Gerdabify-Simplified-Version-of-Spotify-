
#ifndef QUEUEPLACE_H
#define QUEUEPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "place.h"


using namespace std;

class QueuePlace :public Place
{
public:
	string getName(){return "queue";}
	string getCompleteName(){
        return "queue";
    }
protected:

};



#endif //SHAPE_H