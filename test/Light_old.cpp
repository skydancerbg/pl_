#include "Light.h"
#include "Definitions.h"
// #include <TimeLib.h>
// #include <TimeAlarms.h>

// Light::Light(void)
// {
//     // Use 'this->' to make the difference between the
//     // 'pin' attribute of the class and the
//     // local variable 'pin' created from the parameter.
//     //   this->pin = pin;
//     pin_ = INVALID_LIGHT_PIN;
//     isActiveHigh_ = true;
//     state_ = false;
//     // init();
// }

// Light::Light(int id, int pin, bool activeHigh) : id_(id)
// {
//     pin_ = pin;
//     isActiveHigh_ = activeHigh;
//     state_ = false;
//     if (pin_ != INVALID_LIGHT_PIN)
//     {
//         pinMode(pin_, OUTPUT);
//         // Always try to avoid duplicate code.
//         // Instead of writing digitalWrite(pin, LOW) here,
//         // call the function off() which already does that
//         off();
//     }
// }

Light::Light(int id, int pin, bool activeHigh): id_(id)

// Light::Light(int id, JsonObject &jSource) : id_(id)
{
    // const char *cName = jSource["name"];
    // name_ = cName;

    pin_ = pin;
    if (pin_ != INVALID_PIN)
    {
        pinMode(pin_, OUTPUT);
        // Always try to avoid duplicate code.
        // Instead of writing digitalWrite(pin, LOW) here,
        // call the function off() which already does that
        off();
    }
    isActiveHigh_ = activeHigh;
    state_ = false; // ? tova trqbwa da e false po default!!!!!!
    // manualTimeON_ = jSource["manualTimeON"];
}

void Light::on()
{
    if (pin_ != INVALID_PIN)
    {
        if (isActiveHigh_)
        {
            digitalWrite(pin_, HIGH);
        }
        else
        {
            digitalWrite(pin_, LOW);
        }
    }
}
void Light::off()
{
    if (pin_ != INVALID_PIN)
    {
        if (isActiveHigh_)
        {
            digitalWrite(pin_, LOW);
        }
        else
        {
            digitalWrite(pin_, HIGH);
        }
    }
}
bool Light::state()
{
    // false - OFF, true - ON
    return state_;
}
bool Light::isActiveHigh()
{
    return isActiveHigh_;
}

int Light::getPinNumber()
{
    return pin_;
}
// void Light::setManualTimeON(int manualTimeON)
// {
//     manualTimeON_ = manualTimeON;
// }
// int Light::getManualTimeON()
// {
//     return manualTimeON_;
// }
// void Light::setName(char *name)
// {
//     name_ = name;
// }
// const String Light::getName()
// {
//     return name_;
// }

int Light::getId() { return id_; }