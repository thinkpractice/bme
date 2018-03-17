/*****************************************************************
 * Copyright (c) 2005 Tim de Jong 								 *
 *							       								 *
 * All rights reserved.											 *
 * Distributed under the terms of the MIT License.               *
 *****************************************************************/
#ifndef STATUS_H
#include "Status.h"
#endif

#include <support/TypeConstants.h>
#include <support/ClassInfo.h>
#include <translation/TranslationUtils.h>
#include "ProtocolConstants.h"

Status::Status()
            :   BArchivable()
{
}

Status::Status(BString statName, BString guid, BPath iconPath,
        bool usrChoice, bool isOnline, rgb_color statusColour)
                :   BArchivable(),
                    _statusName(statName),
                    _guid(guid),
                    _iconPath(iconPath),
                    _userChoice(usrChoice),
                    _isOnline(isOnline),
                    _statusColour(statusColour)
{
}

Status::Status(BMessage* archive)
            :   BArchivable(archive)
{
    archive->FindString("Status::statusName",&_statusName);
    archive->FindString("Status::guid",&_guid);
    archive->FindBool("Status::userChoice",&_userChoice);
    rgb_color *findColour = &_statusColour;
    ssize_t size;
    archive->FindData("Status::statusColour",B_RGB_COLOR_TYPE,(const void**)&findColour, &size);
}

Status::~Status()
{
}

BBitmap* Status::StatusIcon()
{
    return BTranslationUtils::GetBitmap(_iconPath.Path());
}

void Status::SetStatusName(BString name)
{
    _statusName = name;
}

BString Status::GetStatusName()
{
    return _statusName;
}

bool Status::IsOnline() const
{
    return _isOnline;
}

void Status::SetUserChoice(bool userChoice)
{
    _userChoice = userChoice;
}

bool Status::IsUserChoice() const
{
    return _userChoice;
}

void Status::SetStatusColour(rgb_color colour)
{
    _statusColour = colour;
}

rgb_color Status::StatusColour() const
{
    return _statusColour;
}

BArchivable* Status::Instantiate(BMessage *archive)
{
    if (validate_instantiation(archive, "Status"))
      return new Status(archive);
    return NULL;
}

status_t Status::Archive(BMessage *archive, bool deep) const
{
    archive->AddString("class","Status");
    archive->AddString("Status::statusName",_statusName);
    archive->AddString("Status::guid",_guid);
    archive->AddBool("Status::userChoice",_userChoice);
    archive->AddData("Status::statusColour",B_RGB_COLOR_TYPE,(void**)&_statusColour,sizeof(rgb_color));
    return B_OK;
}
