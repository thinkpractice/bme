#ifndef CONTACT_LIST_VIEW_CONTROLLER_H
#define CONTACT_LIST_VIEW_CONTROLLER_H

#include "ViewController.h"

class ContactListViewController : public ViewController
{
    public:
        ContactListViewController();
        virtual ~ContactListViewController();
    
    public:
        property<BString> UserName;
};

#endif
