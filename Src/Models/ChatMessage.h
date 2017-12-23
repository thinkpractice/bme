#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H

#include <app/Message.h>
#include <support/String.h>

class Contact;

class ChatMessage
{
    public:
        ChatMessage(Contact* contact, const BString& messageText);
        ChatMessage(const ChatMessage& chatMessage);
        ChatMessage(BMessage *archive);
        virtual ~ChatMessage();
        
        Contact* Sender() const;

        void SetText(const BString& messageText);
        BString GetText() const;

        bigtime_t Timestamp();
        void SetTimeStamp(bigtime_t timestamp);
    private:
        BString _messageText;
        bigtime_t _timestamp;
        Contact* _sender;
};

#endif
