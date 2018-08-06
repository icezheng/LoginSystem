// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#pragma once

#include <memory>
#include <string>

namespace loginsystem {

struct CheckSessionResponse;
struct LoginResponse;
struct RegisterResponse;

class ServerClient {
public:
    virtual ~ServerClient() {}

    static std::shared_ptr<ServerClient> create();

    virtual RegisterResponse register_account(const std::string & user_name, const std::string & password) = 0;

    virtual LoginResponse login_account(const std::string & user_name, const std::string & password) = 0;

    virtual CheckSessionResponse check_session(const std::string & session_id) = 0;
};

}  // namespace loginsystem