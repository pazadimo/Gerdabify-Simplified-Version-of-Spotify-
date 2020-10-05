
#ifndef RATED_H
#define RATED_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

class User;

class Rated
{
public:
	virtual void rate(int _rate,User* this_user);
	virtual int getRate(User* this_user);
	virtual int getUserRate();
	virtual int getCriticRate();
protected:
	std::vector <User*>users;
	std::vector<int> rates;

};



#endif //SHAPE_H