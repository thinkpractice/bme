/*
 * Copyright 2015 Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */


#include "ContactView.h"
#include "GradientView.h"
#include "UserPictView.h"
#include "MailView.h"

ContactView::ContactView(BRect frame)
				: BView(frame,"contactView",B_FOLLOW_ALL_SIDES,B_WILL_DRAW);
{
	//construct gradientView for top!
	BRect gradientFrame(0.0f,0.0f,frame.Width(),0.30f * frame.Height());	
	GradientView *loginView = new GradientView(gradientFrame, "gradient", B_FOLLOW_LEFT_RIGHT, AppConstants::K_TOP_COLOUR, AppConstants::K_BOTTOM_COLOUR);
	AddChild(loginView);
	
	BRect bitmapFrame(0.0f, 0.0f, 91.0f, 91.0f);
	BBitmap *bitmap = new BBitmap(bitmapFrame, B_RGB32);
	BRect userPictFrame(5.0f,10.0f,96.0f,101.0f);
	UserPictView *userPictView = new UserPictView(userPictFrame,bitmap,"userPictView",new BMessage(InterfaceMessages::K_USER_CHANGE_DISPLAYPIC_MSG),B_FOLLOW_NONE,0);
	loginView->AddChild(userPictView);
		
	BRect userNameFrame(userPictFrame.right + 10.0f,10.0f,gradientFrame.right - 10.0f,25.0f);
	m_userNameView = new EditableStringView(userNameFrame,"userNameView","<Insert Name Here>", new BMessage(InterfaceMessages::K_USER_CHANGE_NAME_MSG));	
	loginView->AddChild(m_userNameView);
	BFont usernameFont(be_bold_font);
	usernameFont.SetSize(12.0f);
	m_userNameView->SetFont(&usernameFont);
	m_userNameView->SetFont(be_bold_font, B_FONT_ALL);
	
	m_statusMenu = new StatusMenu();
	AddStatusItems(m_statusMenu);
	
	BRect statusFrame(userNameFrame.left, userNameFrame.bottom + 5.0f, userNameFrame.left + 100.0f, userNameFrame.bottom + 25.0f);
	BMenuField *statusField = new BMenuField(statusFrame,"statusField","",m_statusMenu);
	statusField->SetDivider(0.0f);
	loginView->AddChild(statusField);
	m_statusMenu->SetTargetForItems(this);
			
	BRect personalMessageFrame(statusFrame.left, statusFrame.bottom + 10.0f, gradientFrame.right - 10.0f, statusFrame.bottom + 25.0f);
	m_personalMessageView = new EditableStringView(personalMessageFrame,"personalMessageView","<Insert Personal Message Here>", new BMessage(InterfaceMessages::K_USER_SET_PERSONAL_MSG));	
	loginView->AddChild(m_personalMessageView);
	BFont personalFont;
	personalFont.SetFace(B_ITALIC_FACE);
	personalFont.SetSize(10.0f);
	m_personalMessageView->SetFont(&personalFont);
	
	BRect mailFrame(statusFrame.left,personalMessageFrame.bottom + 10.0f,gradientFrame.right - 10.0f, personalMessageFrame.bottom + 25.0f);
	MailView *mailView = new MailView(mailFrame);
	loginView->AddChild(mailView);
	
	BRect contactListFrame(0.0f,gradientFrame.bottom + 1.0f, frame.Width() - B_V_SCROLL_BAR_WIDTH, frame.Height());
	m_contactListView = new ContactListView(contactListFrame,"contactListView",B_SINGLE_SELECTION_LIST, B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
	m_contactListView->SetInvocationMessage(new BMessage(InterfaceMessages::K_CONTACT_LIST_INVOKE_MSG));
	
	BScrollView *contactScrollView = new BScrollView("contactScroll",m_contactListView, B_FOLLOW_ALL_SIDES, 0,false,true, B_NO_BORDER);
	contactView->AddChild(contactScrollView);
		
	return contactView;
}

ContactView::~ContactView();
{
}

void ContactView::AddStatusItems(StatusMenu *statusMenu)
{
	for (SI p = statusses.begin(); p != statusses.end(); ++p)
	{
		Status *status = (*p).second;
		/*if (status->IsUserChoice())
		{
			BBitmap *statusIcon = status->GetStatusIcon();
			BMessage *statusMessage = new BMessage(InterfaceMessages::K_USER_CHANGE_STATUS_MSG);
			statusMessage->AddPointer(K_NEW_STATUS,status);
			
			BString statusName = status->GetStatusName();
			StatusItem* statusItem = new StatusItem(statusIcon,statusName.String(),statusMessage);
			statusMenu->AddItem(statusItem);			
		}*/
	}	
}
