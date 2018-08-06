#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "server_client_impl.hpp"
#include "server_client.hpp"
#include "check_session_response.hpp"
#include "login_response.hpp"
#include "register_response.hpp"

#include "uni_login.grpc.pb.h"
#include "uni_login.pb.h"
#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using proto::RegisterReq;
using proto::RegisterResp;
using proto::LoginReq;
using proto::LoginResp;
using proto::CheckSessionReq;
using proto::CheckSessionResp;

namespace loginsystem {

#define UNUSED(useless)(void)useless;

std::shared_ptr<ServerClient> ServerClient::create() {
    return std::make_shared<ServerClientImpl>();
}

ServerClientImpl::ServerClientImpl () {
}

RegisterResponse ServerClientImpl::register_account(const std::string & user_name, const std::string & password) {

/**
    proto::RegisterReq registerReq;
    registerReq.set_username(user_name);
    registerReq.set_password(password);
    auto channel = grpc::CreateChannel("120.77.169.75:53101", grpc::InsecureChannelCredentials());

    ClientContext context;
    std::shared_ptr<proto::UniLogin::Stub> stub_ = proto::UniLogin::NewStub(channel);
    RegisterResp registerResp;
    Status status = stub_->Register(&context, registerReq, &registerResp);

    bool success = registerResp.errcode() == 0;
    delete &registerReq;
    delete &context;
    delete &registerResp;
    if (status.ok()) {
        return RegisterResponse(success);
    } else {
        return RegisterResponse(false);
    }
**/
    UNUSED(user_name);
    UNUSED(password);
    return RegisterResponse(true);
}

LoginResponse ServerClientImpl::login_account(const std::string & user_name, const std::string & password) {
    UNUSED(user_name);
    UNUSED(password);
    return LoginResponse(true, "icezheng");
}

CheckSessionResponse ServerClientImpl::check_session(const std::string & session_id) {
    UNUSED(session_id);
    return CheckSessionResponse(true, true);

}



}
