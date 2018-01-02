#ifndef CHAT_MESSAGE_H
#include "ChatMessage.h"
#endif

#include "Contact.h"

ChatMessage::ChatMessage(Contact* contact, const BString& messageText)
                :   BArchivable(),
                    _sender(contact),
                    _messageText(messageText)
{
}

ChatMessage::ChatMessage(const ChatMessage& chatMessage)
                :   BArchivable()
{
    _sender = chatMessage.Sender();
    _messageText = chatMessage.GetText();
}

ChatMessage::ChatMessage(BMessage *archive)
                : BArchivable(archive)
{
    archive->FindString(kMessageText, &_messageText);
    archive->FindInt64(kTimeStamp, &_timestamp);
    
    BMessage contactMessage;
    archive->FindMessage(kSender, &contactMessage);
    BArchivable* contactArchivable = Contact::Instantiate(&contactMessage);
    _sender = static_cast<Contact*>(contactArchivable);
}

ChatMessage::~ChatMessage()
{
    //delete _sender;
}

Contact* ChatMessage::Sender() const
{
    return _sender;
}

status_t ChatMessage::Archive(BMessage *into, bool deep) const
{
    status_t status = BArchivable::Archive(into, deep);
    status = into->AddString("class", "ChatMessage");
    status = into->AddString(kMessageText, _messageText);
    status = into->AddInt64(kTimeStamp, _timestamp);
    status = _sender->Archive(into);
    return status;
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

BArchivable* ChatMessage::Instantiate(BMessage* archive)
{
    if (!validate_instantiation(archive, "ChatMessage"))
        return NULL;
    return new ChatMessage(archive);
}

