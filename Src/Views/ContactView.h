/*
 * Copyright 2015 Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef CONTACT_VIEW_H
#define CONTACT_VIEW_H


#include <SupportDefs.h>
#include <interface/View.h>
#include "EditableStringView.h"
#include "StatusMenu.h"
#include "ContactListView.h"

class ContactView : public BView
{
public:
	ContactView(BRect frame);
	virtual ~ContactView();
	
private:
	void AddStatusItems(StatusMenu *statusMenu);
	
private:
	EditableStringView	*m_userNameView,
						*m_personalMessageView;
	StatusMenu 			*m_statusMenu;
	ContactListView		*m_contactListView;
};


#endif // _H
