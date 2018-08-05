#ifndef PROPERTY_H
#define PROPERTY_H

#include <memory>
#include <string>
#include <app/Message.h>
#include <support/String.h>

template <class T>
class property
{
    public:
        const uint32 kPropertyChanged = 'PrCh';
        const char* kPropertyIdField = "property::property_id";

    public:
        property(std::shared_ptr<BHandler> owner)
            :	_owner(owner)
        {
        }

        virtual ~property()
        {
        }

        BString PropertyId()
        {
            return _propertyId;
        }

        void operator= (const T& value)
        {
            _value = value;
            NotifyPropertyChanged(this);
        }

        operator T() const
        {
            return _value;
        }

    private:
        void NotifyPropertyChanged(property* changedProperty)
        {
            if (auto propertyOwner = _owner.lock())
            {
                //TODO: make property class BArchivable so we can send it in the notice?
                BMessage* changedMessage = new BMessage();
                changedMessage->AddString(kPropertyIdField, _propertyId);
                propertyOwner->SendNotices(kPropertyChanged, changedMessage);
            }
        }

    private:
        std::weak_ptr<BHandler> _owner;
        BString _propertyId;
        T _value;
};

template <class T>
std::shared_ptr<property<T>> NewProperty(T value)
{
    return std::make_shared<property<T>>(value);
}

#endif
