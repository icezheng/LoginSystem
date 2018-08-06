#pragma once

#include "server_client.hpp"
#include "server_request.hpp"
#include "request_callback.hpp"

namespace loginsystem {

class ServerClientImpl : public ServerClient {

public:
    ServerClientImpl();
    virtual void request(const ServerRequest & request, const std::shared_ptr<RequestCallback> & callback) override;

};

}
