#include <Arduino.h>

#include <WiFi.h>
#include "time.h"
#include "time.h"
// #include <Bounce2.h>
#include "StructsEnums.h"
#include "Light.h"
#include "Button.h"
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

// LightsTower::LightsTower(int id, lights, vector<int> towerlightIds, int workerResponseTime)
// LightsTower lightsTowerEntr(0, lights,twr,30);
void setupButtons();
void setupLights();
void readButtons();
void clearAllLightSignals();
void printLocalTime();

void setup()
{
  Serial.begin(115200);

  setupLights();
  setupButtons();
  // buttons[BID::DOOR_OPEN_SWITCH]->enable();
  buttons[BID::TECHNOLOGIST_CLEAR_LIGHTS_BTN]->enable();
  buttons[BID::TECHNOLOGIST_EMERGENCY_LIGHTS_BTN]->enable();
  // lightsTowers.push_back(new LightsTower(0,lights,twr,30));

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

  // ! TEST
  for (auto it = lights.begin(); it != lights.end(); it++)
  {
    Sprintln("");
    Sprintln((*it)->getPinNumber());
    (*it)->on();
    Sprintln("");
  }
}

void loop()
{

  delay(50);
  readButtons();
  delay(50);
  // printLocalTime();
}

void printLocalTime()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void readButtons()
{
  for (auto it = buttons.begin(); it != buttons.end(); it++)
  {
    if ((*it)->isEnabled())
    {
      // Sprint("PinNumber");
      // Sprintln("TECHNOLOGIST_ORDER_BTN_ENTR");

      bool pressed = !digitalRead((*it)->getPinNumber());
      if (pressed)
      {
        // (*it)->press();
        switch ((*it)->getId())
        {
        // NEW_CART_BTN_ENTR
        case 0:
          Sprintln("NEW_CART_BTN_ENTR");

          clearAllLightSignals();
          (*it)->clearPressed();
          break;
        // TECHNOLOGIST_ORDER_BTN_ENTR
        case 1:
          Sprintln("TECHNOLOGIST_ORDER_BTN_ENTR");
          clearAllLightSignals();
          (*it)->clearPressed();
          break;
        // EXTRACT_AND_TURN_BTN_EXIT
        case 2:
          Sprintln("EXTRACT_AND_TURN_BTN_EXIT");
          clearAllLightSignals();
          (*it)->clearPressed();
          break;
        // EXTRACT_NO_TURN_BTN_EXIT
        case 3:
          Sprintln("EXTRACT_NO_TURN_BTN_EXIT");
          clearAllLightSignals();
          (*it)->clearPressed();
          break;
        // TECHNOLOGIST_ORDER_BTN_EXIT
        case 4:
          Sprintln("TECHNOLOGIST_ORDER_BTN_EXIT");
          clearAllLightSignals();
          (*it)->clearPressed();
          break;
        // TECHNOLOGIST_CLEAR_LIGHTS_BTN
        case 5:
          Sprintln("TECHNOLOGIST_CLEAR_LIGHTS_BTN");
          clearAllLightSignals();
          (*it)->clearPressed();
          break;
        // TECHNOLOGIST_EMERGENCY_LIGHTS_BTN
        case 6:
          Sprintln("TECHNOLOGIST_EMERGENCY_LIGHTS_BTN");
          lights[LID::RED_ENTR_TOWER]->on();
          lights[LID::RED_EXIT_TOWER]->on();
          (*it)->clearPressed();
          break;
        // DOOR_OPEN_SWITCH
        case 7:
          Sprintln("DOOR_OPEN_SWITCH");
          /* code */
          (*it)->clearPressed();
          break;

        default:
          break;
        }
      }
    }
  }
}
void clearAllLightSignals()
{
  for (auto it = lights.begin(); it != lights.end(); it++)
  {
    (*it)->off();
  }
}
