#include "ViewController.h"

ViewController::ViewController(BView *owner)
                 :  _owner(owner)
{
}

ViewController::~ViewController()
{
}

BView* ViewController::Owner()
{
    return _owner;
}
