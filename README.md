# justdoit
one more todo list implementation - university project

## API
#### get api description
REQUEST:
```
GET /justdoit
Accept: application/json
{
	"_links": {
		"addList": { "href": "/justdoit/new" },
	}
}
```
RESPONSE:
```
HTTP/1.1 200 Created
```
#### create new todo list
Client should not go directly to /justdoit/new and should use link from
"addList" instead.<br>
REQUEST:
```
POST /justdoit/new
Accept: application/json
{
	"todo": {
		"title": "todo list title",
	}
}
```
RESPONSE:
```
HTTP/1.1 201 Created
Location: /justdoit/{id}
```
#### get the todo list
REQUEST:
```
GET /justdoit/{id}
```
RESPONSE:
```
Content-Type: application/vnd.collection+json
{
	"collection" : {
		"version" : "1.0",
		"href": "/justdoit/{id}",
		"title": "todo list title"
		"items": [
			{
				"href": "/justdoit/{id}/{taskId}",
				"data": [
					{
						"name": "title",
						"value": "task title",
					},
					{
						"name": "briefDescription",
						"value": "brief task description",
					}
				]
			},
		]
		"queries:" [
			{
				"rel": "add",
				"href": "/justdoit/{id}/new",
			},
		]
	}
}
```
#### add a task to the todo list
Client should not go directly to /justdoit/{id}/new and should use link from
"addTask" instead.<br>
REQUEST:
```
POST /justdoit/{id}/new
Accept: application/json
{
	"task": {
		"title": "task title",
		"briefDescription": "brief task description",
	}
}
```
RESPONSE:
```
HTTP/1.1 201 Created
Location: /justdoit/{id}/{taskId}
```
#### remove the task
REQUEST:
```
DELETE /justdoit/{id}/{taskId}
```
RESPONSE:
```
HTTP/1.1 200 OK
```
#### remove the todo list
REQUEST:
```
DELETE /justdoit/{id}
```
RESPONSE:
```
HTTP/1.1 200 OK
```
#### modify the task
REQUEST:
```
PUT /justdoit/{id}/{taskId}
{
	"task": {
		"title": "new task title",
		"briefDescription": "new brief description",
	}
}
```
RESPONSE:
```
HTTP/1.1 200 OK
```
#### modify the list
REQUEST:
```
PUT /justdoit/{id}/
{
	"todo": {
		"title": "new todo list title",
	}
}
```
RESPONSE:
```
HTTP/1.1 200 OK
```
