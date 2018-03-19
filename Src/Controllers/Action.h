#ifndef ACTION_H
#define ACTION_H

#include <functional>
#include <app/Message.h>
#include <support/SupportDefs.h>

using namespace std;

class Action
{
    public:
        Action(uint32 what, function<void(BMessage*)> actionFunction);
        virtual ~Action();

        bool HandlesMessage(BMessage* message);
        void Execute(BMessage* message);

    private:
        uint32 _what;
        function<void(BMessage*)> _actionFunction;
};

#endif
