#ifndef MESSAGE_H
#define MESSAGE_H
#pragma once

#include <array>
#include <string>

#include <boost/log/trivial.hpp>

class Message
{
public:
    enum class ENCODE_STATUS : uint8_t
    {
        SUCCESS = 0,
        ERROR = 1
    };

    Message();

    inline std::size_t GetLength() const { return messageLength_; }

    ENCODE_STATUS EncodeMessage(const std::string &message);

    std::string DecodeMessage();

private:
    // 65535 max length
    static const uint16_t headerLength_ = 2;

    static const std::size_t maxMessageLength_ = 512;

    std::size_t messageLength_;

    std::array<char, headerLength_ + maxMessageLength_> data_;
};

#endif // MESSAGE_H
