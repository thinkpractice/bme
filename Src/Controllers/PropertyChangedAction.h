#ifndef PROPERTYCHANGEDACTION_H
#define PROPERTYCHANGEDACTION_H

#include <memory>
#include "Action.h"
#include "property.h"

class PropertyChangedAction : public Action
{
public:
    PropertyChangedAction(std::shared_ptr<property> property, ActionCallbackFunction callbackFunction);
    virtual ~PropertyChangedAction();

    virtual bool HandlesMessage(BMessage* message);

private:
    BString _propertyId;
};

#endif // PROPERTYCHANGEDACTION_H
