#include "Action.h"

Action::Action(uint32 what, ActionCallbackFunction actionFunction)
            :   _what(what),
                _actionFunction(actionFunction)
{
}

Action::~Action()
{
}

bool Action::HandlesMessage(BMessage* message)
{
    return message->what == _what;
}

void Action::Execute(BMessage* message)
{
    _actionFunction(message);
}
