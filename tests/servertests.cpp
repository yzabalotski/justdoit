#include <string>

#include "gtest/gtest.h"

#include <cpprest/http_client.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

static std::string baseURL = "http://localhost:9999/";

TEST(API, url_justdoit)
{
http_client client(baseURL);

json::value expected = json::value::parse(
	"{\"_links\":{\"todolists\":{\"href\":\"/justdoit/todolists\"}}}");
client.request(methods::GET, "justdoit")
	.then([=] (http_response  response) {
		ASSERT_TRUE(response.status_code() == status_codes::OK);
		response.extract_json()
			.then([=] (json::value body) {
				ASSERT_TRUE(body == expected);
			}).wait();
	})
	.wait();

client.request(methods::GET, "justdoit/someNotSupportedURL")
	.then([=] (http_response  response) {
		ASSERT_TRUE(response.status_code() == status_codes::NotFound);
	})
	.wait();
}

int main(int argc, char **argv)
{
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
