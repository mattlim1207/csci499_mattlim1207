#include <iostream>
#include <string>

#include "Caw.h"
#include <glog/logging.h>
#include <gflags/gflags.h>

DEFINE_string(user, "", "Username for login");
DEFINE_string(registeruser, "", "Username for registration");
DEFINE_string(caw, "", "Caw the given text");
DEFINE_string(reply, "", "Set the caw as a reply to a given caw id");
DEFINE_string(read, "", "Read the given caw id");
DEFINE_string(follow, "", "Follow the given username");
DEFINE_bool(profile, false, "See profile");


int main(int argc, char** argv)
{

	gflags::ParseCommandLineFlags(&argc, &argv, true);
	//Flags that don't require user to be logged in
	if(FLAGS_registeruser != ""){
		Caw::registeruserHandler(FLAGS_registeruser);
    }

    //Flags that require user is logged in, checks for username variable to be filled
    if(FLAGS_user != ""){
	    if(FLAGS_caw != ""){
			Caw::cawHandler(FLAGS_user, FLAGS_caw, FLAGS_reply);    
	    } 
	    if(FLAGS_follow != ""){
	    	Caw::followHandler(FLAGS_user, FLAGS_follow);	
	    }
	    if(FLAGS_profile){
	    	Caw::profileHandler(FLAGS_user);
	    }
	    if(FLAGS_read != ""){
	    	Caw::readHandler(FLAGS_read);
	    }
	}
	else if(FLAGS_registeruser == ""){
		std::cout << "Bad Command: Not logged in" << std::endl;
	}
}


//Incomplete functions, will implement later to actually perform correct functions
void Caw::registeruserHandler(std::string username){
	std::cout << "Registered " + username << std::endl;
}
std::string Caw::cawHandler(std::string username, std::string text, std::string id){
	std::cout << "Cawed " + text << " to " << id << std::endl;
	return text;
}
void Caw::followHandler(std::string username, std::string user){
	std::cout << "Followed " + user << std::endl;
}
void Caw::readHandler(std::string id){
	std::cout << "Reading from " + id << std::endl;
}
void Caw::profileHandler(std::string user){
	std::cout << "You are " + user << std::endl;
}
