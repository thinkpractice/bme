#include "Controller.h"
#include "PropertyChangedAction.h"

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

//TODO: provide method to unbind
void Controller::Bind(uint32 what, Action::ActionCallbackFunction handlerFunction)
{
    Action action(what, handlerFunction);
    _actions.push_back(action);
}

//TODO: provide method to unobserve
void Controller::Observe(const BMessenger& observer, const std::shared_ptr<property> propertyToBind, Action::ActionCallbackFunction handlerFunction)
{
    this->StartWatching(observer, property::kPropertyChanged);
    PropertyChangedAction action(propertyToBind, handlerFunction);
    _actions.push_back(action);
}
