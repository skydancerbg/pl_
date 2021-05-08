#ifndef Button_h
#define Button_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Definitions.h"
#include "StructsEnums.h"

// #include <TimeLib.h>
// #include <TimeAlarms.h>
// #include <ArduinoJson.h>

using namespace std;
class Button
{
protected:
private:
  int id_;
  int pin_;
  bool enabled_= false;
  bool state_ = false; // false - OFF, true - ON
  String name_;
  // int manualTimeON_ = 0;

public:
  // Button(int id, int pin, initialData *idata);

  Button(const InitialData &idata);
  int getId();
  // void setName(char *name);
  // const String getName();
  void enable(); //is disabled by default!
	void disable();
  bool state();
  int getPinNumber();
  void read();
  bool wasPressed();
  bool clear();

  // void setManualTimeON(int manualTimeON);
  // int getManualTimeON();
};

extern vector<Button *> buttons;

#endif