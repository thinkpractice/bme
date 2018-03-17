/*****************************************************************
 * Copyright (c) 2005 Tim de Jong 								 *
 *							       								 *
 * All rights reserved.											 *
 * Distributed under the terms of the MIT License.               *
 *****************************************************************/
#ifndef STATUS_H
#include "Status.h"
#endif

#include <be/support/TypeConstants.h>
#include <be/support/ClassInfo.h>
#include "ProtocolConstants.h"

Status::Status()
            :   BArchivable()
{
}

Status::Status(BString statName, BString statAbbr, bool usrChoice, rgb_color statusColour)
                :   BArchivable(),
                    _statusName(statName),
                    _statusAbbreviation(statAbbr),
                    _userChoice(usrChoice),
                    _statusColour(statusColour)
{
}

/**	Archiving constructor
	Produces a Status object from a message archive.
	@param archive, the archived object.
 */
Status::Status(BMessage* archive)
            :   BArchivable(archive)
{
    archive->FindString("Status::statusName",&_statusName);
    archive->FindString("Status::statusAbbreviation",&_statusAbbreviation);
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
    //TODO return bitmap from a path that should be passed via the constuctor
    return nullptr;
}

void Status::SetStatusName(BString name)
{
    _statusName = name;
}

/**	Get the user readable name of this status.
	@return a human readable status name.
 */
BString Status::GetStatusName()
{
    return _statusName;
}

/**	Returns if this status represents an online status: true if
	it does, false otherwise.
	@return true if the status is one of the online statusses,
	false if it is the offline status.
 */
bool Status::IsOnline() const
{
    return _statusAbbreviation != Statusses::K_OFFLINE;
}

void Status::SetUserChoice(bool userChoice)
{
    _userChoice = userChoice;
}

/**	Returns if this status is a status that can be chosen by the user.
	@return true if the status can be set by the user, false if not.
 */
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

/** Instantiates a Status object from a message archive.
	@param archive, the archived Status object.
	@return a BArchivable object representing the instantiated object.
 */
BArchivable* Status::Instantiate(BMessage *archive)
{
    if (validate_instantiation(archive, "Status"))
      return new Status(archive);
    return NULL;
}

/**	Archives this object into a message.
	@param archive, the message object the Status object should be archived in.
	@param deep, if true the user bitmap is also saved into the message, if false
	only status name, abbreviation an userChoice are archived.
	@return B_OK if the archive operation was successfull.
 */
status_t Status::Archive(BMessage *archive, bool deep) const
{
    archive->AddString("class","Status");
    archive->AddString("Status::statusName",_statusName);
    archive->AddString("Status::statusAbbreviation",_statusAbbreviation);
    archive->AddBool("Status::userChoice",_userChoice);
    archive->AddData("Status::statusColour",B_RGB_COLOR_TYPE,(void**)&_statusColour,sizeof(rgb_color));
    return B_OK;
}
