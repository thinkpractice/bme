#ifndef PROPERTY_H
#define PROPERTY_H

template <class T>
class property
{
    public:
        property() {};
        virtual ~property() {};

        void operator= (const T& value) {_value = value;}
        operator T() const { return _value; }

    private:
        T _value;
};

#endif
