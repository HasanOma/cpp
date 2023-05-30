#include <boost/asio.hpp>
#include <iostream>
#include <string.h>

const int PORT = 8080;

using namespace std;
using namespace boost::asio::ip;

class Server {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    string main_page() {
        return "HTTP/1.0 200 OK\n"
               "Content-Type: text/html; charset=utf-8\n"
               "Connection: Closed\r\n\r\n"
               "<!DOCTYPE html><html><body>"
               "<h1>Dette er hovedsiden!</h1>"
               "</body></html>";
    }

    string second_Page() {
        return  "HTTP/1.0 200 OK\n"
                "Content-Type: text/html; charset=utf-8\n"
                "Connection: Closed\r\n\r\n "
                "<!DOCTYPE html><html><body>"
                "<h1>Dette er en annen side</h1>"
                "</body></html>";
    }

    string error() {
        return "HTTP/1.0 200 OK\n"
               "Content-Type: text/html; charset=utf-8\n"
               "Connection: Closed\r\n\r\n"
               "<!DOCTYPE html><html><body>"
               "<p> 404 Not Found</p>"
               "</body></html>";
    }

    void handle_request(shared_ptr<Connection> connection) {
        auto rd_bfr = make_shared<boost::asio::streambuf>();
        // Read from client until newline ("\r\n")
        async_read_until(connection->socket, *rd_bfr, "\r\n",
                         [this, connection, rd_bfr](const boost::system::error_code &ec, size_t) {
                             if (!ec) {
                                 istream read_stream(rd_bfr.get());
                                 std::string message;
                                 getline(read_stream, message);
                                 message.pop_back();

                                 if (message == "quit") return;

                                 cout << "Message from a connected client: " << message << endl;

                                 auto buffer = make_shared<boost::asio::streambuf>();
                                 ostream stream(buffer.get());

                                 if(message == "GET /en_side HTTP/1.1"){

                                     stream << second_Page();
                                 }
                                 else if( message == "GET / HTTP/1.1") {
                                     stream << main_page();
                                 }
                                 else{
                                     stream << error();
                                 }

                                 async_write(connection->socket, *buffer,
                                             [this, connection, buffer](const boost::system::error_code &ec, size_t) {
                                                 if (!ec) handle_request(connection);
                                                 connection->socket.close();
                                             });
                             }
                         });


    }


    void accept() {
        auto connection = make_shared<Connection>(io_service);

        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    Server() : endpoint(tcp::v4(), PORT), acceptor(io_service, endpoint) {}

    void start() {
        accept();

        io_service.run();
    }
};

int main() {
    Server server;

    cout << "Starting server... " << endl
         << "Connect at http://localhost:"<< PORT <<"  Type 'quit' to disconnect." << endl;

    server.start();
}