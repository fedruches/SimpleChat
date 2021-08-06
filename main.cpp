#include <iostream>

#include <boost/asio.hpp>

#include "message.h"
#include "chat_client.h"

using namespace std;

boost::asio::io_context io_context;

tcp::resolver r(io_context);
tcp::resolver::query q("localhost", "5000");
tcp::socket s(io_context);

int main()
{    
//    boost::asio::io_context io_context;
//    tcp::resolver resolver(io_context);
//    auto endpoints = resolver.resolve("localhost", "5000");

//    ChatClient chatClient(io_context, endpoints);

//    std::thread ioContextThread([&io_context](){ io_context.run(); });

//    ioContextThread.join();

    Message message;
    message.EncodeMessage("Hello");
    std::cout << message.DecodeMessage() << std::endl;

    message.DecodeHeader();

    return 0;
}