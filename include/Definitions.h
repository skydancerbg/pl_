#pragma once

# define ROUTER_PASSW_ACCESS

// #define USE_OFFICE_ROUTER
// #define USE_SIMO_ROUTER
#define USE_STEFAN_ROUTER

//https://arduino.stackexchange.com/questions/9857/can-i-make-the-arduino-ignore-serial-print
//If you insist on top performance, the best thing would be to use a macro for that:

#define Sbegin(a) (Serial.begin(a))
#define Sprintln(a) (Serial.println(a))
#define Sprint(a) (Serial.print(a))
#define Swrite(a) (Serial.write(a))

//Then instead of
//Serial.println(F("Hello world!"));
//write
//Sprintln(F("Hello world!"));

//etc.To deactivate the Serial printing, define the macro empty :
//#define Sbegin(a)
//#define Sprintln(a)
//#define Sprint(a)
//#define Swrite(a)

#define INVALID_PIN 255
#define INVALID_BTN_LIGHT_ID 255
