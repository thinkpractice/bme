#include "ViewController.h"

ViewController::ViewController(BView *owner)
                    :   Controller(),
                        _owner(owner)
{
}

ViewController::~ViewController()
{
}

BView* ViewController::Owner()
{
    return _owner;
}
