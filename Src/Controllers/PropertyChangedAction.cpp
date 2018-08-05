#include "PropertyChangedAction.h"

PropertyChangedAction::PropertyChangedAction(std::shared_ptr<property> property, ActionCallbackFunction callbackFunction)
                            :	Action(B_OBSERVER_NOTICE_CHANGE, callbackFunction),
                                _propertyId(property->PropertyId())
{
}

PropertyChangedAction::~PropertyChangedAction()
{
}

bool PropertyChangedAction::HandlesMessage(BMessage *message)
{
    BString messagePropertyId;
    message->FindString(property::kPropertyIdField, &messagePropertyId);

    uint32 originalWhat;
    message->FindUInt32(B_OBSERVE_ORIGINAL_WHAT, &originalWhat);
    return Action::HandlesMessage(message) &&
            originalWhat == property::kPropertyChanged &&
            messagePropertyId == _propertyId;
}
