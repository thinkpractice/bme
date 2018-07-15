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
        
        template <class T> T FindView(const char* name) { return dynamic_cast<T>(Owner()->FindView(name)); }

    private:
        BView* _owner;
};

#endif
