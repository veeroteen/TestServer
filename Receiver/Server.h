#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class Server {

    void handler(const int n) const;


public:
    Server() = default;
    void start();

};


