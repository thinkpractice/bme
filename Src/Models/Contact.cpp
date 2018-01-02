/*****************************************************************
 * Copyright (c) 2005 Tim de Jong								 *
 *							       								 *
 * All rights reserved.											 *
 * Distributed under the terms of the MIT License.               *
 *****************************************************************/
#ifndef CONTACT_H
#include "Contact.h"
#endif

#include "ProtocolConstants.h"

#define kGuidField "Contact::Guid"
#define kPassportField  "Contact::Passport"
#define kFriendlyNameField "Contact::FriendlyName"
#define kPersonalMessageField "Contact::PersonalMessage"
#define kHasPersonalMessageField "Contact::HasPersonalMessage"

Contact::Contact()
            :   _hasPersonalMessage(false)
{
}

Contact::Contact(BString passport, BString friendlyName, BString guid)
            :   _passport(passport),
                _friendlyName(friendlyName),
                _guid(guid),
                _hasPersonalMessage(false),
{
}

Contact::Contact(BMessage* message)
{
    message->FindString(kGuidField, &_guid);
    message->FindString(kPassportField, &_passport);
    message->FindString(kFriendlyNameField, &_friendlyName);
    message->FindString(kPersonalMessageField, &_personalMessage);
    message->FindBool(kHasPersonalMessageField, &_hasPersonalMessage);
}

Contact::~Contact()
{
}

BString Contact::GUID()
{
    return _guid;
}

void Contact::SetPassport(BString passport)
{
    _passport = passport;
}

BString Contact::Passport()
{
    return _passport;
}

void Contact::SetFriendlyName(BString friendlyName)
{
    _friendlyName = friendlyName;
}

BString Contact::FriendlyName()
{
    return _friendlyName;
}

void Contact::SetStatus(Status *status)
{
    _status = status;
}

Status* Contact::GetStatus()
{
    return _status;
}

bool Contact::IsBlocked()
{
    return false;
}

bool Contact::IsOnline()
{
    return (_status->GetAbbreviation() != Statusses::K_OFFLINE);
}

bool Contact::HasPersonalMessage()
{
    return _hasPersonalMessage;
}

void Contact::SetPersonalMessage(BString personalMessage)
{
    _hasPersonalMessage = true;
    _personalMessage = personalMessage;
}

BString Contact::PersonalMessage()
{
    return _personalMessage;
}

