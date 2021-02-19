#include <gflags/gflags.h>

#include <string>

DECLARE_string(user);
DECLARE_string(registeruser);
DECLARE_string(caw);
DECLARE_string(reply);
DECLARE_string(read);
DECLARE_string(follow);
DECLARE_bool(profile);

// Simple set of static functions offered by "Caw" for "Faz"
class Caw {
 public:
  // Registers user with given username
  static void RegisteruserHandler(const std::string &username);

  // Sends caw from the given user with the given text, optionally marked as a
  // reply to another caw of given id
  static std::string CawHandler(const std::string &username,
                                const std::string &text,
                                const std::string &id = "");

  // Follows user with given username
  static void FollowHandler(const std::string &username,
                            const std::string &user);

  // Returns caw with given id
  static void ReadHandler(const std::string &id);
  
  // Returns profile of given user
  static void ProfileHandler(const std::string &user);
};