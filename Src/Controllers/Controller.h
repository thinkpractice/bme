#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <functional>
#include <app/Handler.h>
#include "Action.h"
#include "property.h"

class Controller : public BHandler
{
    public:
        Controller();
        virtual ~Controller();

        virtual void MessageReceived(BMessage* message);
        void Bind(uint32 what, Action::ActionCallbackFunction handlerFunction);
        void Observe(const BMessenger& target, const std::shared_ptr<property> propertyToBind, Action::ActionCallbackFunction handlerFunction);

    private:
        std::vector<Action> _actions;
        std::vector<std::shared_ptr<property>> _properties;
};

#endif
