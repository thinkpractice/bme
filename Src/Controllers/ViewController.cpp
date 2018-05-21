#include "ViewController.h"

ViewController::ViewController(BView *owner)
                 :   Controller(),
                     _owner(owner)
{
}

ViewController::~ViewController()
{
}

void ViewController::MessageReceived(BMessage* message)
{
    Controller::MessageReceived(message);
}

BView* ViewController::Owner()
{
    return _owner;
}
