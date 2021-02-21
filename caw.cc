#include "caw.h"

#include <glog/logging.h>

#include <iostream>

DEFINE_string(user, "", "Username for login");
DEFINE_string(registeruser, "", "Username for registration");
DEFINE_string(caw, "", "Caw the given text");
DEFINE_string(reply, "", "Set the caw as a reply to a given caw id");
DEFINE_string(read, "", "Read the given caw id");
DEFINE_string(follow, "", "Follow the given username");
DEFINE_bool(profile, false, "See profile");

int main(int argc, char **argv) {
  // Initialize google services
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // Flags that don't require user to be logged in
  if (FLAGS_registeruser != "") {
    Caw::RegisteruserHandler(FLAGS_registeruser);
  }

  // Flags that require user is logged in, checks if username is filled
  if (FLAGS_user != "") {
    if (FLAGS_caw != "") {
      Caw::CawHandler(FLAGS_user, FLAGS_caw, FLAGS_reply);
    }
    if (FLAGS_follow != "") {
      Caw::FollowHandler(FLAGS_user, FLAGS_follow);
    }
    if (FLAGS_profile) {
      Caw::ProfileHandler(FLAGS_user);
    }
    if (FLAGS_read != "") {
      Caw::ReadHandler(FLAGS_read);
    }
  } else if (FLAGS_registeruser == "") {
    std::cout << "Bad Command: Not logged in" << std::endl;
  }
}

// Incomplete functions, needs to be implemented
void Caw::RegisteruserHandler(const std::string &username) {
  LOG(INFO) << "Registered " + username << std::endl;
}
std::string Caw::CawHandler(const std::string &username,
                            const std::string &text, const std::string &id) {
  LOG(INFO) << "Cawed " + text << " to " << id << std::endl;
  return text;
}
void Caw::FollowHandler(const std::string &username, const std::string &user) {
  LOG(INFO) << "Followed " + user << std::endl;
}
void Caw::ReadHandler(const std::string &id) {
  LOG(INFO) << "Reading from " + id << std::endl;
}
void Caw::ProfileHandler(const std::string &user) {
  LOG(INFO) << "You are " + user << std::endl;
}
