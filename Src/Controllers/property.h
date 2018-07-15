#ifndef PROPERTY_H
#define PROPERTY_H

#include <memory>

template <class T>
class property
{
    public:
        const uint32 kPropertyChanged = 'PrCh';

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
                propertyOwner->SendNotices(kPropertyChanged);
            }
        }

    private:
        std::weak_ptr<BHandler> _owner;
        T _value;
};

template <class T>
std::shared_ptr<property<T>> NewProperty(T value)
{
    return std::make_shared<property<T>>(value);
}

#endif
