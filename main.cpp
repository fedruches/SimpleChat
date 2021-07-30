#include <iostream>

#include <boost/asio.hpp>

#include "message.h"

using namespace std;

int main()
{
    Message message;
    message.EncodeMessage("Hello World!");

    std::cout << BOOST_VERSION << std::endl;
    std::cout << message.DecodeMessage() << std::endl;

    return 0;
}