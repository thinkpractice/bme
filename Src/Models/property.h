/*
 * Copyright 2015 Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef PROPERTY_H
#define PROPERTY_H


#include <SupportDefs.h>

template <class T>
class property
{
public:
	property();
	virtual ~property();
		
	void operator= (const T& value);			
	const T Value();
				
private:
	T _value;

};

property::property()
{
}

property::~property()
{
}

void property::operator= (T& value)
{
	_value = value
}

T property::Value() const
{
	return _value
}

#endif // _H
