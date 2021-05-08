#ifndef Light_h
#define Light_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Definitions.h"
// #include <TimeLib.h>
// #include <TimeAlarms.h>
// #include <ArduinoJson.h>

using namespace std;
class Light
{
protected:
private:
  int id_;
  int pin_;
  bool isActiveHigh_ = true;
  bool state_ = false; // false - OFF, true - ON
  String name_;
  // int manualTimeON_ = 0;

public:
  Light(int id, int pin, bool activeHigh);
  //  Light(int id, JsonObject& jSource);

  //void init(int pin, bool activeLow);
  int getId();
  // void setName(char *name);
  // const String getName();
  void on();
  void off();
  bool state();
  bool isActiveHigh();
  int getPinNumber();
  bool Blink();
  bool isBlinking();

  // void setManualTimeON(int manualTimeON);
  // int getManualTimeON();
};

extern vector<Light *> lights;

#endif