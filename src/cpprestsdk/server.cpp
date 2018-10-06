#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

#include <iostream>
using namespace std;

#define PRINT(msg) wcout << msg

void handle_get(http_request request)
{
	PRINT("\nhandle GET\n");
	request.reply(status_codes::OK, "hello, world!");
}

int main(void)
{
	http_listener listener("http://localhost:9999/restdemo");
	listener.support(methods::GET, handle_get);

	try {
		listener.open()
			.then([&listener]() { PRINT("\nstarting to listen\n"); })
			.wait();

		while (true);
	}
	catch (exception const & e) {
		wcout << e.what() << endl;
	}

	return 0;
}
