#ifndef MESSAGE_ITEM_H
#include "MessageItem.h"
#endif

#include "ChatMessage.h"

MessageItem::MessageItem(ChatMessage* message)
				: BListItem(),
                m_message(message)
{
}

MessageItem::~MessageItem()
{
	delete m_message;
}

ChatMessage* MessageItem::Message()
{
	return m_message;
}
					
void MessageItem::SetMessage(ChatMessage* message)
{
	if (m_message)
	{
		//clean up the old message		
		delete m_message;
	}
	m_message = message;
}
