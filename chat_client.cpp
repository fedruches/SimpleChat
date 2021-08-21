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
    std::cout << "do_connect()" << std::endl;

    boost::asio::async_connect(socket_, endpoints,
                               [](const boost::system::error_code &ec, const tcp::endpoint)
    {
        if (!ec)
            std::cout << "Successfull connection" << std::endl;
        else
            std::cout << "Connection failed. Reason: " << ec.message() << std::endl;
    });
}

void ChatClient::do_read_header()
{
    std::cout << "do_read_header()" << std::endl;

    boost::asio::async_read(socket_,
                            boost::asio::buffer(readMsg_.GetData(), Message::GetHeaderLength()),
                            [this](const boost::system::error_code &ec, std::size_t /*lenght*/)
    {
        if (!ec && readMsg_.DecodeHeader())
            do_read_body();
        else
            socket_.close();
    });
}

void ChatClient::do_read_body()
{
    std::cout << "do_read_body()" << std::endl;

    boost::asio::async_read(socket_,
                            boost::asio::buffer(readMsg_.GetBody(), readMsg_.GetMessageLength()),
                            [this](const boost::system::error_code &ec, std::size_t /*lenght*/)
    {
        if (!ec)
        {
            std::cout.write(readMsg_.GetBody(), readMsg_.GetMessageLength());
            std::cout << std::endl;
            do_read_header();
        }
        else
            socket_.close();
    });
}
