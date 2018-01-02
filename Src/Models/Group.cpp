/*****************************************************************
 * Copyright (c) 2005 Tim de Jong								 *
 *							       								 *
 * All rights reserved.											 *
 * Distributed under the terms of the MIT License.               *
 *****************************************************************/
#ifndef GROUP_H
#include "Group.h"
#endif

Group::Group()
{
}

Group::Group(BString name, BString groupID)
		:	_groupName(name),
			_groupID(groupID)
{
}

Group::~Group()
{
}

void Group::SetGroupName(BString name)
{
    _groupName = name;
}

BString Group::GroupName()
{
    return _groupName;
}

void Group::SetGroupID(BString id)
{
    _groupID = id;
}

BString Group::GroupID()
{
    return _groupID;
}
