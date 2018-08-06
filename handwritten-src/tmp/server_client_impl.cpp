#include <algorithm>
#include <random>

#include "server_response.hpp"
#include "server_request.hpp"
#include "request_callback.hpp"

#include "server_client_impl.hpp"
#include "http_request.hpp"

namespace loginsystem {

std::shared_ptr<ServerClient> ServerClient::create() {
    return std::make_shared<ServerClientImpl>();
}

ServerClientImpl::ServerClientImpl () {
}

#define UNUSED(x)(void)x;

void ServerClientImpl::request(const ServerRequest & request, const std::shared_ptr<RequestCallback> & callback) {

	UNUSED(request);


//loginsystem::HttpRequest::HttpRequest(std::string const&, int)
	//HttpRequest httpReq("192.168.10.100", 8888);

    //std::string res = httpReq.HttpGet("/getsomething/");

    //res = httpReq.HttpPost("/postsomething/", HttpRequest::genJsonString("something", 100));

	//ServerResponse response(res);
    ServerResponse response("hello");
    callback->callback(response);

}

}
