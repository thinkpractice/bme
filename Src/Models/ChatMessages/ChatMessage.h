#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H

#include <app/Message.h>
#include <support/Archivable.h>
#include <support/String.h>

#define kMessageText    "ChatMessageText"
#define kTimeStamp      "ChatMessageTimeStamp"
#define kSender         "ChatMessageSender"

class Contact;

class ChatMessage : public BArchivable
{
    public:
        ChatMessage(Contact* contact, const BString& messageText);
        ChatMessage(const ChatMessage& chatMessage);
        ChatMessage(BMessage *archive);
        virtual ~ChatMessage();
        
        Contact* Sender() const;
        virtual status_t Archive(BMessage *into, bool deep = true) const;

        void SetText(const BString& messageText);
        BString GetText() const;

        bigtime_t Timestamp();
        void SetTimeStamp(bigtime_t timestamp);

    public:
        static BArchivable* Instantiate(BMessage *archive);
        
    private:
        BString _messageText;
        bigtime_t _timestamp;
        Contact* _sender;
};

#endif
