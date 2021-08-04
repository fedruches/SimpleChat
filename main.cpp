#include <iostream>

#include <boost/asio.hpp>

#include "message.h"
#include "chat_client.h"

using namespace std;

int main()
{    
    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve("localhost", "5000");

    ChatClient chatClient(io_context, endpoints);

    std::thread ioContextThread([&io_context](){ io_context.run(); });

    ioContextThread.join();

    return 0;
}