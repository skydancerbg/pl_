#include <Arduino.h>

#include <WiFi.h>
// #include "time.h" 
#include "TimeLib.h"
#include <TimeAlarms.h>
#include <TimedAction.h>
#include <Bounce2.h>
#include "StructsEnums.h"
#include "Light.h"
#include "Button.h"
#include "Program.h"

// #include "LightsTower.h"

const char *ssid = "code";
const char *password = "codeass123";

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 3600 * 2;     //winter time
const int daylightOffset_sec = 3600 * 1; //+ this for summer time

vector<Light *> lights;

// vector<LightsTower*> lightsTowers;

vector<Button *> buttons;

vector<int> twr = {0, 1, 2};
// vector<int> tower2lights = {3, 4, 5};

Program* program;

// LightsTower::LightsTower(int id, lights, vector<int> towerlightIds, int workerResponseTime)
// LightsTower lightsTowerEntr(0, lights,twr,30);

#define NUM_BUTTONS 8
const uint8_t BUTTON_PINS[NUM_BUTTONS] = {13, 18, 19, 22, 21, 23, 32, 33};
Bounce *debouncedBtns = new Bounce[NUM_BUTTONS];

void setupButtons();
void setupLights();
void processButtonPress(int pinNumber);
void clearAllLightSignals();
void printLocalTime();
void timerCallbackPrg();
void blinkFast();
void blinkSlow();

TimedAction blnkFast = TimedAction(250, blinkFast);
TimedAction blnkSlow = TimedAction(750, blinkSlow);

void setup()
{
  Serial.begin(115200);

  setupLights();

  setupButtons();

  // Add the buttonce to debounce libraary for processing
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    debouncedBtns[i].attach(BUTTON_PINS[i], INPUT_PULLUP); //setup the bounce instance for the current button
    debouncedBtns[i].interval(25);                         // interval in ms
  }

  program = new Program;
  program->StartProgram();

  // * Wi-Fi
  // //connect to WiFi
  // Serial.printf("Connecting to %s ", ssid);
  // WiFi.begin(ssid, password);
  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   delay(500);
  //   Serial.print(".");
  // }
  // Serial.println(" CONNECTED");
  // // Print ESP Local IP Address
  // Serial.println(WiFi.localIP());
  // //init and get the time
  // configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  // printLocalTime();

  // //disconnect WiFi as it's no longer needed
  // WiFi.disconnect(true);
  // WiFi.mode(WIFI_OFF);


}

void loop()
{

  Alarm.delay(1);

  blnkFast.check();
  blnkSlow.check();

  // printLocalTime();

  // READ AND DEBOUNCE BUTTONS:
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    // Update the Bounce instance :
    debouncedBtns[i].update();
    // If it fell, flag the need to toggle the LED
    if (debouncedBtns[i].fell())
    {
      program->processButtonPress(BUTTON_PINS[i]);
    }
  }

  Alarm.delay(1);
}

// void printLocalTime()
// {
//   struct tm timeinfo;
//   if (!getLocalTime(&timeinfo))
//   {
//     Serial.println("Failed to obtain time");
//     return;
//   }
//   Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
// }


// void processButtonPress(int pinNumber)
// {
//   for (auto it = buttons.begin(); it != buttons.end(); it++)
//   {
//     if ((*it)->isEnabled() && (*it)->getPinNumber() == pinNumber)
//     {
//       switch ((*it)->getId())
//       {
//       // NEW_CART_BTN_ENTR
//       case 0:
//         Sprintln("NEW_CART_BTN_ENTR");

//         clearAllLightSignals();
//         (*it)->clearPressed();
//         break;
//       // TECHNOLOGIST_ORDER_BTN_ENTR
//       case 1:
//         Sprintln("TECHNOLOGIST_ORDER_BTN_ENTR");
//         clearAllLightSignals();
//         (*it)->clearPressed();
//         break;
//       // EXTRACT_AND_TURN_BTN_EXIT
//       case 2:
//         Sprintln("EXTRACT_AND_TURN_BTN_EXIT");
//         clearAllLightSignals();
//         (*it)->clearPressed();
//         break;
//       // EXTRACT_NO_TURN_BTN_EXIT
//       case 3:
//         Sprintln("EXTRACT_NO_TURN_BTN_EXIT");
//         clearAllLightSignals();
//         (*it)->clearPressed();
//         break;
//       // TECHNOLOGIST_ORDER_BTN_EXIT
//       case 4:
//         Sprintln("TECHNOLOGIST_ORDER_BTN_EXIT");
//         clearAllLightSignals();
//         (*it)->clearPressed();
//         break;
//       // TECHNOLOGIST_CLEAR_LIGHTS_BTN
//       case 5:
//         Sprintln("TECHNOLOGIST_CLEAR_LIGHTS_BTN");
//         clearAllLightSignals();
//         (*it)->clearPressed();
//         break;
//       // TECHNOLOGIST_EMERGENCY_LIGHTS_BTN
//       case 6:
//         Sprintln("TECHNOLOGIST_EMERGENCY_LIGHTS_BTN");
//         lights[LID::RED_ENTR_TOWER]->on();
//         lights[LID::RED_EXIT_TOWER]->on();
//         (*it)->clearPressed();
//         break;
//       // DOOR_OPEN_SWITCH
//       case 7:
//         Sprintln("DOOR_OPEN_SWITCH");
//         /* code */
//         (*it)->clearPressed();
//         break;

//       default:
//         break;
//       }
//     }
//   }
// }

// void clearAllLightSignals()
// {
//   for (auto it = lights.begin(); it != lights.end(); it++)
//   {
//     (*it)->disable_blink();
//     (*it)->off();
//   }
// }

void timerCallbackPrg()
{
  // Process the alarm callback at the Program class instance
  program->TimerCallback();
}

void blinkFast()
{
  // Sprintln("blinkFast");
  for (auto it = lights.begin(); it != lights.end(); it++)
  {
    if ((*it)->getBlinkMode() == BlinkMode::BLINK_FAST)
    {
      (*it)->toggle();
    }
  }
}

void blinkSlow()
{
  // Sprintln("blinkSlow");
  for (auto it = lights.begin(); it != lights.end(); it++)
  {
    if ((*it)->getBlinkMode() == BlinkMode::BLINK_SLOW)
    {
      (*it)->toggle();
    }
  }
}