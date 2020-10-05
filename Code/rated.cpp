
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "user.h"
#include "rated.h"

using namespace std;
	void Rated:: rate(int _rate,User* this_user){
		int index=-1;
		for(int i=0;i<users.size();i++){
			if(users[i]->get_userdata().username==this_user->get_userdata().username)
				index=i;
		}
		if(index==-1){
			users.push_back(this_user);
			rates.push_back(_rate);
		}
		else{
			rates[index]=_rate;
		}
		
	}

	int Rated:: getRate(User* this_user){
		int index=-1;
		for(int i=0;i<users.size();i++){
			if(users[i]->get_userdata().username==this_user->get_userdata().username)
				index=i;
		}
		if(index==-1){
			return 0;
		}
		else{
			return rates[index];
		}
	}
	int Rated::getUserRate(){
		int count=0;
		int number=0;
		for(int i=0;i<users.size();i++){
			if(users[i]->get_userdata().userType!=Editor && users[i]->get_userdata().userType!=Admin){
				count+=rates[i];
				number++;
			}
		}
		if (number !=0)
		return (int)(count/number);
	}

	int Rated::getCriticRate(){
		int count=0;
		int number=0;
		for(int i=0;i<users.size();i++){
			if(users[i]->get_userdata().userType==Editor ){
				count+=rates[i];
				number++;
			}
		}
		if (number !=0)
		return (int)(count/number);
	}