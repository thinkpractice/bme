#ifndef PROPERTY_H
#define PROPERTY_H

#include <memory>
#include <string>
#include <app/Message.h>
#include <app/Handler.h>
#include <support/String.h>

class base_property
{
public:
    static const uint32 kPropertyChanged = 'PrCh';
    static constexpr const char* kPropertyIdField = "base_property::property_id";

public:
    base_property() {}
    virtual ~base_property() {}

    BString PropertyId()
    {
        return _propertyId;
    }

private:
    BString _propertyId;
};

template <class T>
class property : public base_property
{
    public:
        property(std::shared_ptr<BHandler> owner)
            :	_owner(owner)
        {
        }

        virtual ~property()
        {
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
        T _value;
};

template <class T>
std::shared_ptr<base_property> NewProperty(T value)
{
    return std::make_shared<property<T>>(value);
}

#endif
