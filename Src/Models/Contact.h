/*****************************************************************
 * Copyright (c) 2005 Tim de Jong								 *
 *							       								 *
 * All rights reserved.											 *
 * Distributed under the terms of the MIT License.               *
 *****************************************************************/
#ifndef CONTACT_H
#define CONTACT_H

#include <app/Message.h>
#include <support/String.h>
#include <support/Archivable.h>
#include "Status.h"

using namespace std;

class Contact : public BArchivable
{
    public:
        Contact();
        Contact(BString passport, BString friendlyName, BString guid);
        Contact(BMessage* message);
        virtual ~Contact();
        
        BString GUID();

        void SetPassport(BString passport);
        BString Passport();

        void SetFriendlyName(BString friendlyName);
        BString FriendlyName();
        
        void SetStatus(Status *status);
        Status* GetStatus();

        bool HasPersonalMessage();
        void SetPersonalMessage(BString personalMessage);
        BString PersonalMessage();
        
        bool IsBlocked();
        bool IsOnline();
        
        virtual status_t Archive(BMessage* archive, bool deep = true);

    public:
        static BArchivable* Instantiate(BMessage* archive);

    private:
        BString _passport,
                _friendlyName,
                _guid,
                _personalMessage;
                            
        bool _hasPersonalMessage;
        
        Status* _status;
};

#endif
