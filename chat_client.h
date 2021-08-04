#ifndef CHAT_CLIENT_H
#define CHAT_CLIENT_H
#pragma once

#include <deque>
#include <thread>
#include <iostream>

#include <boost/asio.hpp>

#include "message.h"

using boost::asio::ip::tcp;

class ChatClient
{
public:
    ChatClient(boost::asio::io_context &io_context,
                const tcp::resolver::results_type &endpoints);

    ~ChatClient();

private:
    void do_connect(const tcp::resolver::results_type &endpoints);

private:
    boost::asio::io_context &io_context_;

    tcp::socket socket_;

    Message readMsg_;

    std::deque<Message> writeMsgs_;
};

#endif // CHAT_CLIENT_H
