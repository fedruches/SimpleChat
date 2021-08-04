#include "chat_client.h"

ChatClient::ChatClient(boost::asio::io_context &io_context, const tcp::resolver::results_type &endpoints)
    : io_context_{io_context}, socket_{io_context}
{
    do_connect(endpoints);
}

ChatClient::~ChatClient()
{
    std::cout << "ChatClient destructor" << std::endl;
}

void ChatClient::do_connect(const tcp::resolver::results_type &endpoints)
{
    boost::asio::async_connect(socket_, endpoints,
                               [this](const boost::system::error_code &ec, const tcp::endpoint)
    {
        if (!ec)
            std::cout << "Successfull connection" << std::endl;
        else
            std::cout << "Connection failed. Reason: " << ec.message() << std::endl;
    });
}
