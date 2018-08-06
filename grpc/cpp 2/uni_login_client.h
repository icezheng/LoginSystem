//
// Created by icezheng on 2018/8/2.
//
#pragma once

#include <string>

#include "uni_login.grpc.pb.h"
#include <string>
#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>

class UniLoginClient{
    public:
        UniLoginClient();

        ~UniLoginClient();

        virtual proto::RegisterResp RegisterAccount(std::string userName, std::string password);

        virtual proto::LoginResp LoginAccount(std::string userName, std::string password);

        virtual proto::CheckSessionResp CheckSession(std::string sessionId);
};
