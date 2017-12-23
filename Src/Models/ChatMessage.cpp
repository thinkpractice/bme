#ifndef CHAT_MESSAGE_H
#include "ChatMessage.h"
#endif

#include "Contact.h"

ChatMessage::ChatMessage(Contact* contact, const BString& messageText)
                :   _sender(contact),
                    _messageText(messageText)
{
}

ChatMessage::ChatMessage(const ChatMessage& chatMessage)
{
    _sender = chatMessage.Sender();
    _messageText = chatMessage.GetText();
}

ChatMessage::ChatMessage(BMessage *archive)
{
}

ChatMessage::~ChatMessage()
{
}

Contact* ChatMessage::Sender() const
{
    return _sender;
}

void ChatMessage::SetText(const BString& messageText)
{
    _messageText = messageText;
}

BString ChatMessage::GetText() const
{
    return _messageText;
}

bigtime_t ChatMessage::Timestamp()
{
    return _timestamp;
}

void ChatMessage::SetTimeStamp(bigtime_t timestamp)
{
    _timestamp = timestamp;
}

