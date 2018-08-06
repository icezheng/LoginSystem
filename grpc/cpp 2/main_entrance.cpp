/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "uni_login.grpc.pb.h"
#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using proto::RegisterReq;
using proto::UniLogin;
using proto::RegisterResp;

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).


    RegisterReq registerReq{};
    registerReq.set_username("icezheng2");
    registerReq.set_password("1234");
    ClientContext context;
    auto channel = grpc::CreateChannel("120.77.169.75:53101", grpc::InsecureChannelCredentials());
    std::shared_ptr<proto::UniLogin::Stub> stub_ = proto::UniLogin::NewStub(channel);
    RegisterResp registerResp;
    Status status = stub_->Register(&context, registerReq, &registerResp);
    bool success = registerResp.errcode() == 0;
    std::cout << success << std::endl;

    return 0;
}
