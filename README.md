## Simple HTTP Server with `cpp-httplib`

This example demonstrates how to set up a basic HTTP server using the [`cpp-httplib`](https://github.com/yhirose/cpp-httplib) library.

See the full backend C++ code at [the repo](https://github.com/JR-Bam/ez-http/blob/main/main.cpp) and the frontend html/javascript code also at [the repo](https://github.com/JR-Bam/ez-http/blob/main/static/index.html).
### Code Explanation
#### >> Header
```cpp
#include "httplib.h"
```
Httplib is a header-only library, meaning you only need to include one .h file as a dependency.
#### >> Initialize server
```cpp
httplib::Server server;
```
Initializes an http server, this is usually the starting statement of your program.
#### >> Initialize static folder
```cpp
server.set_base_dir("./static");
```
Similar to putting HTML files in the htdocs folder in XAMPP, this will look for a "static" folder in the same directory as the executable file and try to find index.html inside it. When you navigate to http://localhost:8080/ after running the compiled executable, it will automatically serve index.html. See [`gallery/frontend1.png`](https://github.com/JR-Bam/ez-http/blob/main/gallery/frontend1.png).
#### >> Request Handler
```cpp
server.Get("/hello", [](const httplib::Request& req, httplib::Response& res){
    res.set_content("Hello World!", "text/plain");
});
```
This is a Request Handler. It initializes "routes" that listen to HTTP Methods. See [`MDN Web Docs: HTTP Methods`](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods)
 for more information.

If our web server is live at http://localhost:8080, the statement above will listen to http://localhost:8080/hello for a "GET" HTTP request made by index.html (located in the static folder). The server will respond with "Hello World!" which will be displayed on the webpage. See [`gallery/frontend2.png`](https://github.com/JR-Bam/ez-http/blob/main/gallery/frontend2.png) for the result.
#### >> Setup Host and Port
```cpp
server.listen("127.0.0.1", 8080);
```
Set up the server to be hosted at http://localhost:8080

### To Note

- When you run the exe file, it will stay running until you input CTRL+C. To make the server stop elegantly you have to call ```server.stop();``` somewhere.
- The static folder must be relative to the exe file.
- We are normally following the REST architechture when making a web server. Read more [at this page](https://www.redhat.com/en/topics/api/what-is-a-rest-api).

