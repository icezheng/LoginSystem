// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: uni_login.proto

#include "uni_login.pb.h"
#include "uni_login.grpc.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace proto {

static const char* UniLogin_method_names[] = {
  "/proto.UniLogin/Login",
  "/proto.UniLogin/Register",
  "/proto.UniLogin/CheckSession",
};

std::unique_ptr< UniLogin::Stub> UniLogin::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< UniLogin::Stub> stub(new UniLogin::Stub(channel));
  return stub;
}

UniLogin::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Login_(UniLogin_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Register_(UniLogin_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CheckSession_(UniLogin_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status UniLogin::Stub::Login(::grpc::ClientContext* context, const ::proto::LoginReq& request, ::proto::LoginResp* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Login_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::proto::LoginResp>* UniLogin::Stub::AsyncLoginRaw(::grpc::ClientContext* context, const ::proto::LoginReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::proto::LoginResp>::Create(channel_.get(), cq, rpcmethod_Login_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::proto::LoginResp>* UniLogin::Stub::PrepareAsyncLoginRaw(::grpc::ClientContext* context, const ::proto::LoginReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::proto::LoginResp>::Create(channel_.get(), cq, rpcmethod_Login_, context, request, false);
}

::grpc::Status UniLogin::Stub::Register(::grpc::ClientContext* context, const ::proto::RegisterReq& request, ::proto::RegisterResp* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Register_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::proto::RegisterResp>* UniLogin::Stub::AsyncRegisterRaw(::grpc::ClientContext* context, const ::proto::RegisterReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::proto::RegisterResp>::Create(channel_.get(), cq, rpcmethod_Register_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::proto::RegisterResp>* UniLogin::Stub::PrepareAsyncRegisterRaw(::grpc::ClientContext* context, const ::proto::RegisterReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::proto::RegisterResp>::Create(channel_.get(), cq, rpcmethod_Register_, context, request, false);
}

::grpc::Status UniLogin::Stub::CheckSession(::grpc::ClientContext* context, const ::proto::CheckSessionReq& request, ::proto::CheckSessionResp* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_CheckSession_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::proto::CheckSessionResp>* UniLogin::Stub::AsyncCheckSessionRaw(::grpc::ClientContext* context, const ::proto::CheckSessionReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::proto::CheckSessionResp>::Create(channel_.get(), cq, rpcmethod_CheckSession_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::proto::CheckSessionResp>* UniLogin::Stub::PrepareAsyncCheckSessionRaw(::grpc::ClientContext* context, const ::proto::CheckSessionReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::proto::CheckSessionResp>::Create(channel_.get(), cq, rpcmethod_CheckSession_, context, request, false);
}

UniLogin::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      UniLogin_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< UniLogin::Service, ::proto::LoginReq, ::proto::LoginResp>(
          std::mem_fn(&UniLogin::Service::Login), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      UniLogin_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< UniLogin::Service, ::proto::RegisterReq, ::proto::RegisterResp>(
          std::mem_fn(&UniLogin::Service::Register), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      UniLogin_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< UniLogin::Service, ::proto::CheckSessionReq, ::proto::CheckSessionResp>(
          std::mem_fn(&UniLogin::Service::CheckSession), this)));
}

UniLogin::Service::~Service() {
}

::grpc::Status UniLogin::Service::Login(::grpc::ServerContext* context, const ::proto::LoginReq* request, ::proto::LoginResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status UniLogin::Service::Register(::grpc::ServerContext* context, const ::proto::RegisterReq* request, ::proto::RegisterResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status UniLogin::Service::CheckSession(::grpc::ServerContext* context, const ::proto::CheckSessionReq* request, ::proto::CheckSessionResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace proto

