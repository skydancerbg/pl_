#ifndef Button_h
#define Button_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Definitions.h"
#include "StructsEnums.h"
#include <Bounce2.h>

using namespace std;
class Button
{
protected:
private:
  int id_;
  int pin_;
  bool enabled_= false;
  bool wasPressed_ = false; // false - OFF, true - ON
  int ctrlUnit_;
  int function_;
  // vector<Bounce *> &vectBounce_;
  // Bounce bounce_;
public:

  // Button(const BTNinit &idata, vector<Bounce *> &debounce);
  Button(const BTNinit &idata);
  int getId();
  int  getPinNumber();
  void enable(); //is disabled by default!
	void disable();
  bool isEnabled();
  bool wasPressed();
  void clearPressed();
  void read();
};

extern vector<Button *> buttons;

#endif