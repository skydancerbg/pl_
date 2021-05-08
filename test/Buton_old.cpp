#include "Button.h"
#include "Definitions.h"

// Button::Button(int id, int pin): id_(id)

Button::Button(const InitialData &idata)

// Button::Button(int id, JsonObject &jSource) : id_(id)
{
    id_= idata.id;
    // const char *cName = jSource["name"];
    // name_ = cName;

    pin_ = idata.pinNumber;
    if (pin_ != INVALID_PIN)
    {
        pinMode(pin_, INPUT_PULLUP);
        // Always try to avoid duplicate code.
        // Instead of writing digitalWrite(pin, LOW) here,
        // call the function off() which already does that
        // off();
    }
    state_ = false; // ? tova trqbwa da e false po default!!!!!!
}

// void Button::on()
// {
//     if (pin_ != INVALID_PIN)
//     {
//         if (isActiveHigh_)
//         {
//             digitalWrite(pin_, HIGH);
//         }
//         else
//         {
//             digitalWrite(pin_, LOW);
//         }
//     }
// }
// void Button::off()
// {
//     if (pin_ != INVALID_PIN)
//     {
//         if (isActiveHigh_)
//         {
//             digitalWrite(pin_, LOW);
//         }
//         else
//         {
//             digitalWrite(pin_, HIGH);
//         }
//     }
// }
// bool Button::state()
// {
//     // false - OFF, true - ON
//     return state_;
// }
// bool Button::isActiveHigh()
// {
//     return isActiveHigh_;
// }

// int Button::getPinNumber()
// {
//     return pin_;
// }



///////////////////////////////////////
// void Button::setManualTimeON(int manualTimeON)
// {
//     manualTimeON_ = manualTimeON;
// }
// int Button::getManualTimeON()
// {
//     return manualTimeON_;
// }
// void Button::setName(char *name)
// {
//     name_ = name;
// }
// const String Button::getName()
// {
//     return name_;
// }

int Button::getId() { return id_; }