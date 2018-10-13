#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <functional>
#include <app/Handler.h>
#include <app/Messenger.h>
#include "Action.h"
#include "property.h"

template <class T>
class Controller : public BHandler
{
    public:
        Controller(std::shared_ptr<T> owner);
        virtual ~Controller();

        virtual void MessageReceived(BMessage* message);
        
        std::shared_ptr<T> Owner() {return _owner;}
        
        template <class V> V FindView(const char* name) { return dynamic_cast<V>(Owner()->FindView(name)); }

        void Bind(uint32 what, Action::ActionCallbackFunction handlerFunction);
        void Observe(const BMessenger& target, const std::shared_ptr<base_property> propertyToBind, Action::ActionCallbackFunction handlerFunction);
        void Observe(const std::shared_ptr<base_property> propertyToBind, Action::ActionCallbackFunction handlerFunction);

    private:
        std::shared_ptr<T> _owner;
        std::vector<Action> _actions;
        std::vector<std::shared_ptr<base_property>> _properties;
};

#endif
