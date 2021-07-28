#include "message.h"

Message::Message() : messageLength_{0}
{

}

Message::DECODE_STATUS Message::DecodeMessage(const std::string &message)
{
    if (message.size() > maxMessageLength_)
    {
        BOOST_LOG_TRIVIAL(error) << "Too long message";
        return DECODE_STATUS::ERROR;
    }

    messageLength_ = message.size();
    std::memcpy(data_.data(), &messageLength_, headerLength_);


    return DECODE_STATUS::SUCCESS;
}