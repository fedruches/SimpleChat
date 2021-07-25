#ifndef MESSAGE_H
#define MESSAGE_H
#pragma once

#include <array>

class Message
{
public:
    Message();



private:
    const static std::size_t headerLength_ = 4;

    const static std::size_t maxMessageLength_ = 512;

    std::size_t messageLength_;

    std::array<char, headerLength_ + maxMessageLength_> data_;
};

#endif // MESSAGE_H
