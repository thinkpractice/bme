#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include "Controller.h"
#include <interface/View.h>

class ViewController : public Controller
{
    public:
        ViewController(BView* owner);
        virtual ~ViewController();

        BView* Owner();

    private:
        BView* _owner;
};

#endif
