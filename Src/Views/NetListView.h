/*****************************************************************
 * Copyright (c) 2005 Simon Taylor, Tim de Jong					 *
 *							       								 *
 * All rights reserved.											 *
 * Distributed under the terms of the MIT License.               *
 *****************************************************************/ 
#ifndef _NET_LIST_VIEW_H_
#define _NET_LIST_VIEW_H_

#include <ListView.h>

class NetListView : public BListView
{
	public:
		NetListView(BRect frame, const char *name, list_view_type type, uint32 resizeMask, uint32 flags);
		virtual void FrameResized(float width, float height);
	private:
		static bool UpdateItem(BListItem* item, void* data);
		float oldWidth;
};

#endif
