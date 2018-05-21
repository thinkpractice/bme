#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include "Controller.h"
#include <interface/View.h>

class ViewController : public Controller
{
    public:
        ViewController(BView* owner);
        virtual ~ViewController();

        virtual void MessageReceived(BMessage* message);

        BView* Owner();

    private:
        BView* _owner;
};

#endif
