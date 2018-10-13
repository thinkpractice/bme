#include "Controller.h"
#include "PropertyChangedAction.h"

template <class T>
Controller<T>::Controller(std::shared_ptr<T> owner)
            :   BHandler(),
                _owner(owner)
{
}

template <class T>
Controller<T>::~Controller()
{
}

template <class T>
void Controller<T>::MessageReceived(BMessage* message)
{
    for (auto& action : _actions)
    {
        if (action.HandlesMessage(message))
            action.Execute(message);
    }
}

//TODO: provide method to unbind
template <class T>
void Controller<T>::Bind(uint32 what, Action::ActionCallbackFunction handlerFunction)
{
    Action action(what, handlerFunction);
    _actions.push_back(action);
}

//TODO: provide method to unobserve
template <class T>
void Controller<T>::Observe(const BMessenger& target, const std::shared_ptr<base_property> propertyToBind, Action::ActionCallbackFunction handlerFunction)
{
    this->StartWatching(target, base_property::kPropertyChanged);
    PropertyChangedAction action(propertyToBind, handlerFunction);
    _actions.push_back(action);
}

template <class T>
void Controller<T>::Observe(const std::shared_ptr<base_property> propertyToBind, Action::ActionCallbackFunction handlerFunction)
{
    BMessenger messenger(this);
    Observe(messenger, propertyToBind, handlerFunction);
}

