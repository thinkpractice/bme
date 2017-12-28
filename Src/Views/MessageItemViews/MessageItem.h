#ifndef MESSAGE_ITEM_H
#define MESSAGE_ITEM_H

#include <interface/ListItem.h>
class ChatMessage;

class MessageItem : public BListItem
{
	public:
		MessageItem(ChatMessage* message);
		virtual				~MessageItem();

		ChatMessage*		Message();					
		virtual	void		SetMessage(ChatMessage* message);		
		virtual void 		DrawItem(BView* owner, BRect itemRect, bool drawEverything = false) = 0;
		virtual void 		Update(BView* owner, const BFont* font) = 0;
		
	private:
		ChatMessage*		_message;		
};

#endif

