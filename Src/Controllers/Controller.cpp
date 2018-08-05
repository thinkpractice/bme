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

//TODO: provide method to unbind
void Controller::Bind(uint32 what, std::function<void(BMessage*)> handlerFunction)
{
    Action action(what, handlerFunction);
    _actions.push_back(action);
}

//TODO: provide method to unobserve
void Controller::Observe(const BMessenger& observer, const std::shared_ptr<property> propertyToBind)
{
    this->StartWatching(observer, property::kPropertyChanged);
    std::string propertyId = propertyToBind->PropertyId();
    Bind(B_OBSERVER_NOTICE_CHANGE, [=](BMessage* message)
    {
        uint32 originalWhat;
        message->FindUInt32(B_OBSERVE_ORIGINAL_WHAT, &originalWhat);

        if (originalWhat == property::kPropertyChanged && == propertyId)
        {

        }
    });
}
