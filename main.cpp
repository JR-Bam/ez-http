#include "httplib.h"

int main(){
    // * Initialize an http server
    httplib::Server server;

    /* 
     * Same thing as putting the html files on htdocs in xampp. This will look for a "static" folder in the same
     * directory as the exe file and inside the static folder will try to find index.html.
     * Whenever you go to http://localhost:8080/ after running the compiled exe file,
     * it will automatically serve index.html to that webpage. See gallery/frontend1.png.
     */
    server.set_base_dir("./static");

    /*
     * This is a Request Handler. They initialize "routes" that listen to HTTP Methods. 
     * See https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods.
     * 
     * Given our web server is live on http://localhost:8080, this statement below will
     * listen to http://localhost:8080/hello for a "GET" http request which will be done
     * by index.html (see the static folder). It will then respond with "Hello World!"
     * which will be caught by index.html and be displayed. See gallery/frontend2.png.
    */
    server.Get("/hello", [](const httplib::Request& req, httplib::Response& res){
        res.set_content("Hello World!", "text/plain");
    });

    // * Sets up our server to be hosted on http://localhost:8080
    server.listen("127.0.0.1", 8080);
    return 0;
}
