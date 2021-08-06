#ifndef MESSAGE_H
#define MESSAGE_H
#pragma once

#include <array>
#include <string>
#include <cstdint>
#include <iostream>

#include <boost/log/trivial.hpp>

#undef SUCCESS
#undef ERROR

class Message
{
public:
    enum class ENCODE_STATUS : uint8_t
    {
        SUCCESS = 0,
        ERROR
    };

    void DeleteAll();

    Message();

    inline std::size_t GetLength() const { return messageLength_; }

    ENCODE_STATUS EncodeMessage(const std::string &message);
    
    std::string DecodeMessage();

    void EncodeHeader();

    bool DecodeHeader();

    std::size_t GetMessageLength() const;

    const char * GetData() const;

    char * GetData();

    inline static uint16_t GetHeaderLength() { return headerLength_; };

private:
    // 65535 max length
    static constexpr uint16_t headerLength_ = 2;

    static constexpr std::size_t maxMessageLength_ = 512;

    std::size_t messageLength_ = 0;

    std::array<char, headerLength_ + maxMessageLength_> data_;
};


#endif // MESSAGE_H