#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "server_client.hpp"

namespace loginsystem {

class ServerClientImpl : public ServerClient {

public:
    ServerClientImpl();

    virtual RegisterResponse register_account(const std::string & user_name, const std::string & login) override;

    virtual LoginResponse login_account(const std::string & user_name, const std::string & password) override;

    virtual CheckSessionResponse check_session(const std::string & session_id) override;

};

}
