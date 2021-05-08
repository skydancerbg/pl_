#include "Program.h"
#include "Definitions.h"
#include <Bounce2.h>

Program::Program()
{
    // blinkMode_ = 0;
    // state_ = false;        // false - OFF, true - ON
    // blink_enable_ = false; // false - OFF, true - ON
    // emergency_ = false;
}
void Program::StartProgram()
{
    status_ = ProgramStatuses::PSTATUS::TIMER_STARTED;

    // Clear all light signals
    clearAllLightSignals();
    onboardLed_ON();

    // Enable technologists buttons
    for (auto it = buttons.begin(); it != buttons.end(); it++)
    {
        (*it)->disable();
        switch ((*it)->getId())
        {

        // TECHNOLOGIST_ORDER_BTN
        case 5:
            // Sprintln("enable TECHNOLOGIST_ORDER_BTN");
            (*it)->enable();
            break;
        // TECHNOLOGIST_EMERGENCY_LIGHTS_BTN
        case 6:
            // Sprintln("enable TECHNOLOGIST_EMERGENCY_LIGHTS_BTN");
            (*it)->enable();
            break;

        default:
            break;
        }
    }
    StartAlarm(removeCartSeconds_);
}

void Program::WaitForActionEntrStart(bool extend)
{
    if (!extend)
    {
        StartAlarm(waitForActionSeconds_);
        status_ = ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED_ENTR;
    }
    else
    {
        StartAlarm(extendedWaitForActionSeconds_);
        status_ = ProgramStatuses::PSTATUS::EXTENDED_WAIT_FOR_ACTION_TIMER_STARTED_ENTR;
    }

    // Enable ENTR товер button Lights
    clearAllLightSignals();
    for (auto it = lights.begin(); it != lights.end(); it++)
    {
        switch ((*it)->getId())
        {

        // TECHNOLOGIST_ORDER_BTN
        case 1:
            // Sprintln("YELLOW_ENTR_TOWER");
            (*it)->on();
            if (status_ == ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED_ENTR)
            {
                Sprintln("BlinkMode::BLINK_SLOW");

                (*it)->setBlinkMode(BlinkMode::BLINK_SLOW);
                (*it)->enable_blink();
            }
            else
            {
                Sprintln("BlinkMode::BLINK_FAST");

                (*it)->setBlinkMode(BlinkMode::BLINK_FAST);
                (*it)->enable_blink(); /* code */
            }

            break;

        // YELLOW_BTN_BOX_ENTR
        case 3:
            // Sprintln("YELLOW_BTN_BOX_ENTR");
            (*it)->on();
            if (status_ == ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED_ENTR)
            {
                (*it)->setBlinkMode(BlinkMode::BLINK_SLOW);
                (*it)->enable_blink();
            }
            else
            {
                (*it)->setBlinkMode(BlinkMode::BLINK_FAST);
                (*it)->enable_blink(); /* code */
            }
            break;

        default:
            break;
        }
    }

    // Enable ENTR buttons
    for (auto it = buttons.begin(); it != buttons.end(); it++)
    {
        switch ((*it)->getId())
        {

        // NEW_CART_BTN_ENTR
        case 0:
            // Sprintln("NEW_CART_BTN_ENTR");
            (*it)->enable();
            break;
        // TECHNOLOGIST_ORDER_BTN_ENTR
        // case 1:
        //     // Sprintln("TECHNOLOGIST_ORDER_BTN_ENTR");
        //     (*it)->enable();
        //     break;

        default:
            break;
        }
    }
}

void Program::WaitForActionExitStart(bool extend)
{
    if (!extend)
    {
        StartAlarm(waitForActionSeconds_);
        status_ = ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED_EXIT;
    }
    else
    {
        StartAlarm(extendedWaitForActionSeconds_);
        status_ = ProgramStatuses::PSTATUS::EXTENDED_WAIT_FOR_ACTION_TIMER_STARTED_EXIT;
    }

    // Enable EXIT tower and button Lights
    clearAllLightSignals();
    for (auto it = lights.begin(); it != lights.end(); it++)
    {
        switch ((*it)->getId())
        {

        // YELLOW_EXIT_TOWER
        case 6:
            (*it)->on();
            if (status_ == ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED_EXIT)
            {
                Sprintln("BlinkMode::BLINK_SLOW");

                (*it)->setBlinkMode(BlinkMode::BLINK_SLOW);
                (*it)->enable_blink();
            }
            else
            {
                Sprintln("BlinkMode::BLINK_FAST");

                (*it)->setBlinkMode(BlinkMode::BLINK_FAST);
                (*it)->enable_blink(); /* code */
            }

            break;

        // YELLOW_BTN_BOX_EXIT
        case 8:
            // Sprintln("YELLOW_BTN_BOX_ENTR");
            (*it)->on();
            if (status_ == ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED_EXIT)
            {
                (*it)->setBlinkMode(BlinkMode::BLINK_SLOW);
                (*it)->enable_blink();
            }
            else
            {
                (*it)->setBlinkMode(BlinkMode::BLINK_FAST);
                (*it)->enable_blink(); /* code */
            }
            break;

        default:
            break;
        }
    }

    // Enable EXIT buttons
    for (auto it = buttons.begin(); it != buttons.end(); it++)
    {
        switch ((*it)->getId())
        {

        // EXTRACT_AND_TURN_BTN_EXIT
        case 2:
            // Sprintln("EXTRACT_AND_TURN_BTN_EXIT");
            (*it)->enable();
            break;

        // EXTRACT_NO_TURN_BTN_EXIT
        case 3:
            // Sprintln("EXTRACT_NO_TURN_BTN_EXIT");
            (*it)->enable();
            break;

        // TECHNOLOGIST_ORDER_BTN_EXIT
        // case 4:
        //     // Sprintln("TECHNOLOGIST_ORDER_BTN_EXIT");
        //     (*it)->enable();
        //     break;

        default:
            break;
        }
    }
}

// int Program::calcTimeReminingSecs(time_t start, time_t end)
// {
// }

void Program::SetTimeToRemoveCart(int timerRemoveCartInSeconds)
{
    removeCartSeconds_ = timerRemoveCartInSeconds;
}

// int Program::getId() { return id_; }
// int Program::getPinNumber() { return pin_; }

bool Program::getState() { return state_; }

void Program::StartAlarm(int seconds)

{
    Sprintln("StartAlarm");
    alarmStartTime_ = now();
    alarmId_ = Alarm.timerOnce(seconds, timerCallbackPrg);
    // Sprintln(alarmId_);
    // Sprintln("\n");
}
void Program::CancelTimer()
{
    Sprintln("Start alarm");
    alarmCanceledTime_ = now();
    Alarm.disable(alarmId_);
    // Sprintln("CancelTimer - end\n");
}

void Program::processButtonPress(int pinNumber)
{
    for (auto it = buttons.begin(); it != buttons.end(); it++)
    {
        if ((*it)->isEnabled() && (*it)->getPinNumber() == pinNumber)
        {
            // Sprint("PinNumber");
            // Sprintln("TECHNOLOGIST_ORDER_BTN_ENTR");

            // bool pressed = !digitalRead((*it)->getPinNumber());
            // if (pressed)
            // {
            // (*it)->press();
            switch ((*it)->getId())
            {
            // NEW_CART_BTN_ENTR
            case 0:
                Sprintln("NEW_CART_BTN_ENTR");
                CancelTimer();
                (*it)->clearPressed();
                clearAllLightSignals();
                buttons[BID::NEW_CART_BTN_ENTR]->disable();
               StartProgram();
                break;
            // TECHNOLOGIST_ORDER_BTN_ENTR
            case 1:
                Sprintln("TECHNOLOGIST_ORDER_BTN_ENTR");
                (*it)->clearPressed();
                break;
            // EXTRACT_AND_TURN_BTN_EXIT
            case 2:
                Sprintln("EXTRACT_AND_TURN_BTN_EXIT");
                CancelTimer();
                (*it)->clearPressed();
                clearAllLightSignals();
                buttons[BID::EXTRACT_AND_TURN_BTN_EXIT]->disable();
                buttons[BID::EXTRACT_NO_TURN_BTN_EXIT]->disable();
                WaitForActionEntrStart(false);
                break;
            // EXTRACT_NO_TURN_BTN_EXIT
            case 3:
                Sprintln("EXTRACT_NO_TURN_BTN_EXIT");
                CancelTimer();
                (*it)->clearPressed();
                clearAllLightSignals();
                buttons[BID::EXTRACT_AND_TURN_BTN_EXIT]->disable();
                buttons[BID::EXTRACT_NO_TURN_BTN_EXIT]->disable();
                WaitForActionEntrStart(false);
                break;
            // TECHNOLOGIST_ORDER_BTN_EXIT
            case 4:
                Sprintln("TECHNOLOGIST_ORDER_BTN_EXIT");
                clearAllLightSignals();
                CancelTimer();
                (*it)->clearPressed();
                break;
            // TECHNOLOGIST_ORDER_BTN
            case 5:
                Sprintln("TECHNOLOGIST_ORDER_BTN");
                (*it)->clearPressed();
                clearAllLightSignals();

                break;
            // TECHNOLOGIST_EMERGENCY_LIGHTS_BTN
            case 6:
                Sprintln("TECHNOLOGIST_EMERGENCY_LIGHTS_BTN");
                if (!emergency_)
                {
                    CancelTimer();
                    emergency_ = true;
                    clearAllLightSignals();
                    lights[LID::RED_ENTR_TOWER]->on();
                    lights[LID::RED_EXIT_TOWER]->on();
                }else
                {
                    emergency_ = false;
                    clearAllLightSignals();
                    StartProgram();
                }
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

void Program::clearAllLightSignals()
{
    for (auto it = lights.begin(); it != lights.end(); it++)
    {
        (*it)->disable_blink();
        (*it)->off();
    }
}
void Program::onboardLed_ON()
{
    lights[LID::ONBOARD_LED]->on();
}
void Program::onboardLed_OFF()
{
    lights[LID::ONBOARD_LED]->off();
}
void Program::startEmergencySignal()
{
        clearAllLightSignals();
        lights[LID::RED_EXIT_TOWER]->on();
        lights[LID::RED_ENTR_TOWER]->on();
}
void Program::stopEmergencySignal()
{
        clearAllLightSignals();
}

void Program::TimerCallback()
{
    // Sprintln("Program  - TimerCallback\n");
    // int id = Alarm.getTriggeredAlarmId();
    // Sprintln("Program  - getTriggeredAlarmId() " + id);
    // Sprintln(id);
    if (status_ == ProgramStatuses::PSTATUS::TIMER_STARTED)
    {
        Sprintln("WaitForActionExitStart(false)");
        onboardLed_OFF();
        WaitForActionExitStart(false); // INITIAL TIMER
        // status_ = ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED;
    }
    else if (status_ == ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED_EXIT)
    {
        Sprintln("WaitForActionExitStart(true)");
        WaitForActionExitStart(true); //EXTENDED TIME TIMER
        // status_ = ProgramStatuses::PSTATUS::EXTENDED_WAIT_FOR_ACTION_TIMER_STARTED;
    } else if (status_ == ProgramStatuses::PSTATUS::EXTENDED_WAIT_FOR_ACTION_TIMER_STARTED_EXIT)
    {
        // ! Emergcy!!!!!!! 
        emergency_ = true;
        startEmergencySignal();
        Sprintln("Emergcy!!!!!!!");
        // WaitForActionEntrStart(false);
        // status_ = ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED;
    }
    else if (status_ == ProgramStatuses::PSTATUS::WAIT_FOR_ACTION_TIMER_STARTED_ENTR)
    {
        Sprintln("WaitForActionEntrStart(true)");
        WaitForActionEntrStart(true);
        // status_ = ProgramStatuses::PSTATUS::EXTENDED_WAIT_FOR_ACTION_TIMER_STARTED;
    }
    else if (status_ == ProgramStatuses::PSTATUS::EXTENDED_WAIT_FOR_ACTION_TIMER_STARTED_ENTR)
    {
        // ! Emergcy!!!!!!! 
        emergency_ = true;
        startEmergencySignal();
        Sprintln("Emergcy!!!!!!!");
    }
}