#include <string>
#include <gflags/gflags.h>

DECLARE_string(user);
DECLARE_string(registeruser);
DECLARE_string(caw);
DECLARE_string(reply);
DECLARE_string(read);
DECLARE_string(follow);
DECLARE_bool(profile);

class Caw
{
	public:
	    static void registeruserHandler(std::string username); //
	    static std::string cawHandler(std::string username, std::string text, std::string id = ""); //Returns id of the caw, 
	    static void followHandler(std::string username, std::string user); //User will be implemented at a later date
	    static void readHandler(std::string id);
	    static void profileHandler(std::string user);
};