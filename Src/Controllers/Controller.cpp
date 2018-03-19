#include "Controller.h"

Controller::Controller()
            :   BHandler()
{
}

Controller::~Controller()
{
}

void Controller::MessageReceived(BMessage* message)
{
    for (auto& action : actions)
    {
        if (action.HandlesMessage(message))
            action.Execute(message);
    }
}

void Controller::Bind(uint32 what, function<void(BMessage*)> handlerFunction)
{
    Action action(what, handlerFunction);
    actions.push_back(action);
}


