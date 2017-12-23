#ifndef FILE_MESSAGE_ITEM_H
#define FILE_MESSAGE_ITEM_H

#include "MessageItem.h"

class FileMessageItem : public MessageItem
{
	public:
		FileMessageItem(ChatMessage* message);
		virtual				~FileMessageItem();
		
		virtual void 		DrawItem(BView* owner, BRect itemRect, bool drawEverything = false);
		virtual void 		Update(BView* owner, const BFont* font);
};

#endif
