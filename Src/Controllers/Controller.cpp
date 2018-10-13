#include "Controller.h"
#include "PropertyChangedAction.h"

Controller::Controller(std::shared_ptr<T> owner)
            :   BHandler(),
                _owner(owner)
{
}

Controller::~Controller()
{
}

void Controller::MessageReceived(BMessage* message)
{
    for (auto& action : _actions)
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
void Controller::Observe(const BMessenger& target, const std::shared_ptr<base_property> propertyToBind, Action::ActionCallbackFunction handlerFunction)
{
    this->StartWatching(target, base_property::kPropertyChanged);
    PropertyChangedAction action(propertyToBind, handlerFunction);
    _actions.push_back(action);
}

void Controller::Observe(const std::shared_ptr<base_property> propertyToBind, Action::ActionCallbackFunction handlerFunction)
{
    BMessenger messenger(this);
    Observe(messenger, propertyToBind, handlerFunction);
}

