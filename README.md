# justdoit
one more todo list implementation - university project

## API

#### create new todo list
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
{
	"todo": {
		"title": "todo list title",
		"tasks": [
			{
				"self": { "href": "/justdoit/{id}/{taskId}" },
				"title": "task title",
				"briefDescription": "brief task description",
			},
		]
	}
	"_links:" {
		"self": { "href": "/justdoit/{id}" },
		"addTask": { "href": "/justdoit/{id}/new" },
	}
}
```
#### add a task to the todo list
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
