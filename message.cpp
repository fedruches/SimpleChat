#include "message.h"

Message::Message() : messageLength_{0}
{

}

Message::ENCODE_STATUS Message::EncodeMessage(const std::string &message)
{
    if (message.size() > maxMessageLength_)
    {
        BOOST_LOG_TRIVIAL(error) << "Too long message";
        return ENCODE_STATUS::ERROR;
    }

    messageLength_ = message.size();        
    std::memcpy(data_.data(), &messageLength_, headerLength_);
    std::memcpy(data_.data() + headerLength_, message.c_str(), messageLength_);

    return ENCODE_STATUS::SUCCESS;
}

std::string  Message::DecodeMessage()
{
    std::size_t messageLength = *reinterpret_cast<std::size_t*>(data_.data());
    std::string message(messageLength, 0);
    std::memcpy(message.data(), data_.data() + headerLength_, messageLength);

    return message;
}