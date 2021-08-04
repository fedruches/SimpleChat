#include "message.h"

Message::Message() : messageLength_{0}
{
    data_.fill(0);
}

Message::ENCODE_STATUS Message::EncodeMessage(const std::string &message)
{
    if (message.size() > maxMessageLength_)
    {
        BOOST_LOG_TRIVIAL(error) << "Too long message";
        return ENCODE_STATUS::ERROR;
    }

    messageLength_ = message.size();        
    std::memcpy(data_.data(), &messageLength_, sizeof(messageLength_));
    std::memcpy(data_.data() + sizeof(messageLength_), message.c_str(), messageLength_);

    return ENCODE_STATUS::SUCCESS;
}

std::string Message::DecodeMessage()
{
    std::size_t messageLength = *reinterpret_cast<std::size_t*>(data_.data());
    std::string message(messageLength_, 0);
    std::memcpy(message.data(), data_.data() + sizeof(messageLength), messageLength);

    return message;
}

Message::DECODE_STATUS Message::DecodeHeader()
{
    std::array<char, headerLength_> header;
    std::memcpy(header.data(), data_.data(), headerLength_);
    messageLength_ = *reinterpret_cast<std::size_t*>(header.data());

    if (messageLength_ > maxMessageLength_)
    {
        messageLength_ = 0;
        return DECODE_STATUS::ERROR;
    }
    return DECODE_STATUS::SUCCESS;
}