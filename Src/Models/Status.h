/*****************************************************************
 * Copyright (c) 2005 Tim de Jong 								 *
 *							       								 *
 * All rights reserved.											 *
 * Distributed under the terms of the MIT License.               *
 *****************************************************************/
#ifndef STATUS_H
#define STATUS_H

#include <app/Message.h>
#include <interface/Bitmap.h>
#include <support/Archivable.h>
#include <support/String.h>
#include <support/SupportDefs.h>
#include <map>

using namespace std;

/** Class representing different IM statusses
    @author Tim de Jong
 */
class Status : public BArchivable
{
    public:
        Status();
        Status(BString statusName, BString statusAbbr, bool usrChoice, rgb_color statusColour);
        Status(BMessage* archive);
        virtual ~Status();

        BBitmap* StatusIcon();

        void SetStatusName(BString name);
        BString GetStatusName();

        bool IsOnline() const;

        void SetUserChoice(bool userChoice);
        bool IsUserChoice() const;

        void SetStatusColour(rgb_color colour);
        rgb_color StatusColour() const;

        //archivable methods
        static BArchivable* Instantiate(BMessage *archive);
        virtual status_t Archive(BMessage *archive, bool deep = true) const;

    private:
        BString _statusName,
                _statusAbbreviation;

        bool _userChoice;
        rgb_color _statusColour;
};

#endif
