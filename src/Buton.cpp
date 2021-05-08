#include "Button.h"
#include "Definitions.h"
#include <Bounce2.h>


// Button::Button(const BTNinit &idata, vector<Bounce *> &debounce)
Button::Button(const BTNinit &idata)
{
    id_= idata.id;
    pin_ = idata.pinNumber;
    if (pin_ != INVALID_PIN)
    {
        pinMode(pin_, INPUT_PULLUP);
    }
    ctrlUnit_=idata.ctrlUnit;
    function_=idata.btnFunction;
    // vectBounce_ = debounce;

    // Bounce bounce_ = Bounce();
    // bounce_ = Bounce();
    // bounce_.attach( pin_ ,  INPUT_PULLUP ); // USE INTERNAL PULL-UP
    // bounce_.interval(25);              // interval in ms
  
    // debounce.push_back(*bounce_);

}
void Button::read() { enabled_=false; }

 int Button::getId() { return id_; }

 int Button::getPinNumber() { return pin_; }

 void Button::enable() { enabled_=true; }

 void Button::disable() { enabled_=false; }

 bool Button::isEnabled(){ return enabled_; }

 bool Button::wasPressed(){ return wasPressed_; }

 void Button::clearPressed() { wasPressed_=false; }

