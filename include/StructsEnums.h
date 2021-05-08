#pragma once

namespace CU //CtrlUnit
{
enum CU
{
    LIGHT_TOWER_EXIT,
    BUTTON_BOX_EXIT,
    LIGHT_TOWER_ENTR,
    BUTTON_BOX_ENTR,
    TECHNOLOGIST_CTRL_BOX,
    ONBOARD_LED
};
}

namespace LF //LightFunction
{
enum LF
{
    EMERGENCY,
    INSERT_CART,
    EXTRACT_AND_TURN,
    TECHNOLOGIST_ORDER,
    DOOR_OPEN,
    ONBOARD_LED
};
}

namespace LID
{
enum LID
{
    RED_ENTR_TOWER,
    YELLOW_ENTR_TOWER,
    GREEN_ENTR_TOWER,
    YELLOW_BTN_BOX_ENTR,
    GREEN_BTN_BOX_ENTR,
    RED_EXIT_TOWER,
    YELLOW_EXIT_TOWER,
    GREEN_EXIT_TOWER,
    YELLOW_BTN_BOX_EXIT,
    GREEN_BTN_BOX_EXIT,
    BLUE_DOOR_OPEN,
    ONBOARD_LED
};
}

namespace BF //ButtonFunction
{
enum BF
{
    CartInserted,
    CartExtractedPreviousTurned,
    CartExtractedNoPreviousTurnig,
    TechnologistOrderCompleted,
    Emergency,
    ClearAllSignals,
    DOOR_OPEN,
    DOOR_CLOSED
};
}

namespace BID //BtnID
{
enum BID
{
    NEW_CART_BTN_ENTR,
    TECHNOLOGIST_ORDER_BTN_ENTR,
    EXTRACT_AND_TURN_BTN_EXIT,
    EXTRACT_NO_TURN_BTN_EXIT,
    TECHNOLOGIST_ORDER_BTN_EXIT,
    TECHNOLOGIST_ORDER_BTN,
    TECHNOLOGIST_EMERGENCY_LIGHTS_BTN,
    DOOR_OPEN_SWITCH,
    DOOR_CLOSED_SWITCH
};
}

struct BTNinit {
  int id;
  int pinNumber;
  CU::CU ctrlUnit;
  BF::BF btnFunction; 
};

struct LIGHTinit {
  int id;
  int pinNumber;
  CU::CU ctrlUnit;
  LF::LF lightFunction;
};



namespace Blink
{
enum BK
{
    BLINK_DISABLED,
    BLINK_SLOW,
    BLINK_FAST
};
}