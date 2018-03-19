#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <functional>
#include <app/Handler.h>
#include "Action.h"

using namespace std;

class Controller : public BHandler
{
    public:
        Controller();
        virtual ~Controller();

        virtual void MessageReceived(BMessage* message);
        void Bind(uint32 what, function<void(BMessage*)> handlerFunction);

    private:
        vector<Action> actions;
};

#endif
