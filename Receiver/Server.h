#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class Server {

    void handler(int n)
    {
        if(n%100>0 && n%32 == 0)
        {
            std::cout << "message received\n";
        }
        else
        {
            std::cerr << "error\n";
        }

    }


public:
    Server() = default;
    void start()
    {
        try
        {
            boost::asio::io_service io_service;

            udp::socket socket(io_service, udp::endpoint(udp::v4(), 13));

            while (true)
            {
                boost::array<int, 1> recv_buf;
                udp::endpoint remote_endpoint;
                boost::system::error_code error;
                socket.receive_from(boost::asio::buffer(recv_buf),
                                    remote_endpoint, 0, error);

                if (error && error != boost::asio::error::message_size)
                    throw boost::system::system_error(error);
                for(auto i: recv_buf)
                {
                    handler(i);
                }
            }
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

    }

};


