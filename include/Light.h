#ifndef Light_h
#define Light_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Definitions.h"
#include "StructsEnums.h"

using namespace std;

namespace BlinkMode //LightFunction
{
  enum BM
  {
    NOT_BLINKING,
    BLINK_SLOW,
    BLINK_FAST,
  };
}

class Light
{
protected:
private:
  int id_;
  int pin_;
  int blinkMode_ = 0;
  bool state_ = false;  // false - OFF, true - ON
  bool blink_enable_ = false; // false - OFF, true - ON
  int ctrlUnit_;
  int function_;

public:
  Light(const LIGHTinit &idata);
  int getId();
  int getPinNumber();
  void enable_blink();
  void disable_blink();
  void on();
  void off();
  void toggle();
  void setBlinkMode(int mode);
  int getBlinkMode();
  bool getState();
};

extern vector<Light *> lights;

#endif