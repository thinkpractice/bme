/*****************************************************************
 * Copyright (c) 2005 Tim de Jong								 *
 *							       								 *
 * All rights reserved.											 *
 * Distributed under the terms of the MIT License.               *
 *****************************************************************/
#ifndef GROUP_H
#define GROUP_H

#include <support/String.h>

class Group
{
    public:
        Group();
        Group(BString name, BString groupID);
        virtual ~Group();
        
        void SetGroupName(BString name);
        BString GroupName();
        
        void SetGroupID(BString id);
        BString GroupID();
        
    private:
        BString _groupName,
                _groupID;
};

#endif
