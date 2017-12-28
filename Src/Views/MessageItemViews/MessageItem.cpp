#ifndef MESSAGE_ITEM_H
#include "MessageItem.h"
#endif

#include "ChatMessage.h"

MessageItem::MessageItem(ChatMessage* message)
				: BListItem(),
                _message(message)
{
}

MessageItem::~MessageItem()
{
	delete _message;
}

ChatMessage* MessageItem::Message()
{
	return _message;
}
					
void MessageItem::SetMessage(ChatMessage* message)
{
	if (_message)
	{
		//clean up the old message		
		delete _message;
	}
	_message = message;
}
