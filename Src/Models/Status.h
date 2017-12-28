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
        Status(BString statusName, BString statusAbbr, BBitmap* icon, bool usrChoice, rgb_color statusColour);
        Status(BMessage* archive);
        virtual ~Status();
        
        void SetStatusName(BString name);
        BString GetStatusName();
        
        void SetAbbreviation(BString abbreviation);
        BString GetAbbreviation();
        
        BBitmap* GetStatusIcon(int32 width = 18);
        void AddIcon(BBitmap *statusIcon);

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
        
        map< int32,BBitmap* > _statusIcons;
};

#endif
