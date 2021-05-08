#include "Light.h"
#include "Definitions.h"

Light::Light(const LIGHTinit &idata)
{
    id_ = idata.id;
    pin_ = idata.pinNumber;
    if (pin_ != INVALID_PIN)
    {
        pinMode(pin_, OUTPUT);
        // Always try to avoid duplicate code.
        // Instead of writing digitalWrite(pin, LOW) here,
        // call the function off() which already does that
        this -> off();
    }
    ctrlUnit_ = idata.ctrlUnit;
    function_ = idata.lightFunction;
}

int Light::getId() { return id_; }

int Light::getPinNumber() { return pin_; }

void Light::enable_blink() { blink_enable_ = true; }
void Light::disable_blink() { blink_enable_ = false; }

void Light::on()
{
    // Sprintln("Light.cpp  on()");

    if (pin_ != INVALID_PIN)
    {
        // if (isActiveHigh_)
        // {
        digitalWrite(pin_, HIGH);
        //     }
        //     else
        //     {
        //         digitalWrite(pin_, LOW);
        //     }
    }
}

void Light::off()
{
    // Sprintln("Light.cpp  off()");
    if (pin_ != INVALID_PIN)
    {
        // if (isActiveHigh_)
        // {
        digitalWrite(pin_, LOW);
    }
    //     else
    //     {
    //         digitalWrite(pin_, HIGH);
    //     }
    // }
}

// 1 - No blinking, 2 Slow blinking, 3 Fast blinking
void Light::setBlinkMode(int mode) { blinkMode_ = mode; }

// 1 - No blinking, 2 Slow blinking, 3 Fast blinking
int Light::getBlinkMode() { return blinkMode_; }

void Light::toggle()
{
    if (blink_enable_)
    {

        if (state_)
        {
            off();
            state_ = false;
        }
        else
        {
            on();
            state_ = true;
        }
    }
}
// false - OFF, true - ON
bool Light::getState()
{
    return state_;
}
