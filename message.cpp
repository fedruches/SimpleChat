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

    std::memcpy(data_.data(), &messageLength_, sizeof(headerLength_));
    std::memcpy(data_.data() + sizeof(headerLength_), message.c_str(), messageLength_);

    return ENCODE_STATUS::SUCCESS;
}

std::string Message::DecodeMessage()
{
    std::string message(messageLength_, 0);
    std::memcpy(message.data(), data_.data() + sizeof(headerLength_), messageLength_);

    return message;
}

void Message::EncodeHeader()
{
    std::memcpy(data_.data(), &messageLength_, sizeof(headerLength_));
}

bool Message::DecodeHeader()
{
    messageLength_ = *reinterpret_cast<uint16_t*>(data_.data());

    std::cout << "messageLength_ " << messageLength_ << std::endl;

    if (messageLength_ > maxMessageLength_)
    {
        messageLength_ = 0;
        return false;
    }

    return true;
}

std::size_t Message::GetMessageLength() const
{
    return messageLength_;
}

const char *Message::GetData() const
{
    return data_.data();
}

char *Message::GetData()
{
    return data_.data();
}

const char *Message::GetBody() const
{
    return data_.data() + headerLength_;
}

char *Message::GetBody()
{
    return data_.data() + headerLength_;
}