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
