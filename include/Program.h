#ifndef Program_h
#define Program_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "TimeLib.h"
#include <TimeAlarms.h>
#include <TimedAction.h>
#include <vector>
#include <Bounce2.h>
#include "StructsEnums.h"
#include "Light.h"
#include "Button.h"

using namespace std;

namespace ProgramStatuses //LightFunction
{
  enum PSTATUS
  {
    TIMER_STARTED,
    TIMER_FIRED,
    TIMER_PAUSED,
    WAIT_FOR_ACTION_TIMER_STARTED_ENTR,
    EXTENDED_WAIT_FOR_ACTION_TIMER_STARTED_ENTR,
    WAIT_FOR_ACTION_TIMER_STARTED_EXIT,
    EXTENDED_WAIT_FOR_ACTION_TIMER_STARTED_EXIT
  };
}

class Program
{

protected:
private:
    int id_;
    int pin_;
    int blinkMode_ = 0;
    bool state_ = false;        // false - OFF, true - ON
    ProgramStatuses::PSTATUS status_;  
    bool blink_enable_ = false; // false - OFF, true - ON
    bool emergency_ = false;
    bool doorOpen_= false;
    int ctrlUnit_;
    int function_;
    int removeCartSeconds_ = 5;
    int removeCartPausedRemaining_;
    int waitForActionSeconds_ =10;
    int extendedWaitForActionSeconds_ =10;
    time_t alarmStartTime_, waitAlarmStartTime_, alarmCanceledTime_;

    AlarmID_t alarmId_;
    void StartTimer(int seconds);
    int calcTimeReminingSecs(time_t start,time_t end);

public:
    Program();
    // int getId();
    // int getPinNumber();
    // void enable_blink();
    // void disable_blink();
    // void on();
    // void off();
    // void toggle();
    // void setBlinkMode(int mode);
    // int getBlinkMode();

    bool getState();
    // void SetAlarm(time_t time);
    void StartProgram();
    void WaitForActionExitStart(bool extend);
    void WaitForActionEntrStart(bool extend);
    // void ExtendedWaitForActionEntrStart();
    void WaitForActionExitStart();
    void ExtendedWaitForActionExitStart();
    void SetTimeToRemoveCart(int timeToRemoveCartInSeconds);
    void CancelTimer();
    void PauseTimer();
    void ContinueTimer();
    void TimerCallback();
    void processButtonPress(int pinNumber);
    void clearAllLightSignals();
    void onboardLed_ON();
    void onboardLed_OFF();
    void startEmergencySignal();
    void stopEmergencySignal();
};

extern void timerCallbackPrg();
extern vector<Program *> programs;

#endif