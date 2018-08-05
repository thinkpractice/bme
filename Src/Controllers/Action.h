#ifndef ACTION_H
#define ACTION_H

#include <functional>
#include <app/Message.h>
#include <support/SupportDefs.h>

class Action
{
    public:
        using ActionCallbackFunction = std::function<void(BMessage*)>;

    public:
        Action(uint32 what, ActionCallbackFunction actionFunction);
        virtual ~Action();

        virtual bool HandlesMessage(BMessage* message);
        void Execute(BMessage* message);

    private:
        uint32 _what;
        ActionCallbackFunction _actionFunction;
};

#endif
