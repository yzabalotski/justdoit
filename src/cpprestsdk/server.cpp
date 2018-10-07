#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

#include <iostream>
using namespace std;

#define PRINT(msg) cout << (msg)

#define DEBUG

#ifdef DEBUG
# define DPRINT(msg) PRINT(msg)
#else
# define DPRINT(msg)
#endif

void handle_task_url(http_request request, size_t idx, const std::vector<std::string> &path, size_t listIdIdx)
{
if (idx + 1U < path.size())
	request.reply(status_codes::NotFound);
else
	request.reply(status_codes::OK, "return task");
}

void handle_tasks_url(http_request request, size_t idx, const std::vector<std::string> &path, size_t listIdIdx)
{
++idx;
if (idx >= path.size())
	request.reply(status_codes::OK, "return all tasks");
else
	handle_task_url(request, idx, path, listIdIdx);
}

void handle_todolist_url(http_request request, size_t idx, const std::vector<std::string> &path)
{
size_t listIdIdx = idx;
++idx;
if (idx >= path.size())
	request.reply(status_codes::OK, "return todolist");
else if (path[idx] != "tasks")
	request.reply(status_codes::NotFound);
else
	handle_tasks_url(request, idx, path, listIdIdx);
}

void handle_todolists_url(http_request request, size_t idx, const std::vector<std::string> &path)
{
++idx;
if (idx >= path.size())
	request.reply(status_codes::OK, "return all todolists");
else
	handle_todolist_url(request, idx, path);
}

void handle_get(http_request request)
{
DPRINT("\nGET:url:" + uri::decode(request.relative_uri().path()) + "\n");

auto path = uri::split_path(uri::decode(request.relative_uri().path()));

size_t idx = 0U;
if (idx >= path.size() || path[idx] != "todolists") {
	request.reply(status_codes::NotFound);
	return;
}

handle_todolists_url(request, idx, path);
}

int main(void)
{
	http_listener listener("http://localhost:9999/justdoit");
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
