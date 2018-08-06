

#include "uni_login_client.h"

#include "uni_login.grpc.pb.h"
#include <grpcpp/grpcpp.h>

    const std::string server_ip = "120.77.169.75:53101";

    UniLoginClient::UniLoginClient(){}

    UniLoginClient::~UniLoginClient(){}

    proto::RegisterResp RegisterAccount(std::string  userName, std::string password) {
        auto channel = grpc::CreateChannel(server_ip, grpc::InsecureChannelCredentials());
        std::shared_ptr<proto::UniLogin::Stub> stub_ = proto::UniLogin::NewStub(channel);
        proto::RegisterReq registerReq;
        registerReq.set_username(userName);
        registerReq.set_password(password);
        grpc::ClientContext context;
        proto::RegisterResp  registerResp;
        grpc::Status status = stub_->Register(&context, registerReq, &registerResp);
        return registerResp;
    }

    proto::LoginResp LoginAccount(std::string userName, std::string password) {
        auto channel = grpc::CreateChannel(server_ip, grpc::InsecureChannelCredentials());
        std::shared_ptr<proto::UniLogin::Stub> stub_ = proto::UniLogin::NewStub(channel);
        proto::LoginReq loginReq;
        loginReq.set_username(userName);
        loginReq.set_password(password);
        grpc::ClientContext context;
        proto::LoginResp loginResp;
        grpc::Status status = stub_->Login(&context, loginReq, &loginResp);
        return loginResp;
    }

    proto::CheckSessionResp CheckSession( std::string sessionId) {
        auto channel = grpc::CreateChannel(server_ip, grpc::InsecureChannelCredentials());
        std::shared_ptr<proto::UniLogin::Stub> stub_ = proto::UniLogin::NewStub(channel);
        proto::CheckSessionReq checkSessionReq;
        checkSessionReq.set_sessionid(sessionId);
        grpc::ClientContext context;
        proto::CheckSessionResp checkSessionResp;
        grpc::Status status = stub_->CheckSession(&context, checkSessionReq, &checkSessionResp);
        return checkSessionResp;
    }

