
#include "Definitions.h"
#include "StructsEnums.h"
#include "Button.h"
#include <Bounce2.h>

void setupButtons(){
  // buttons.push_back((new Button ( {BID::NEW_CART_BTN_ENTR,33,CU::BUTTON_BOX_ENTR, BF::CartInserted}), bounce));

  buttons.push_back(new Button ( {BID::NEW_CART_BTN_ENTR,33,CU::BUTTON_BOX_ENTR, BF::CartInserted}));
  buttons.push_back(new Button ( {BID::TECHNOLOGIST_ORDER_BTN_ENTR,32,CU::BUTTON_BOX_ENTR, BF::TechnologistOrderCompleted}));

  buttons.push_back(new Button ( {BID::EXTRACT_AND_TURN_BTN_EXIT,18,CU::BUTTON_BOX_EXIT, BF::CartExtractedPreviousTurned}));
  buttons.push_back(new Button ( {BID::EXTRACT_NO_TURN_BTN_EXIT,19,CU::BUTTON_BOX_EXIT, BF::CartExtractedNoPreviousTurnig}));
  buttons.push_back(new Button ( {BID::TECHNOLOGIST_ORDER_BTN_EXIT,21,CU::BUTTON_BOX_EXIT, BF::TechnologistOrderCompleted}));
  
  buttons.push_back(new Button ( {BID::TECHNOLOGIST_ORDER_BTN,23,CU::TECHNOLOGIST_CTRL_BOX, BF::ClearAllSignals}));
  buttons.push_back(new Button ( {BID::TECHNOLOGIST_EMERGENCY_LIGHTS_BTN,22,CU::TECHNOLOGIST_CTRL_BOX, BF::Emergency}));
  
  buttons.push_back(new Button ( {BID::DOOR_OPEN_SWITCH,13,CU::TECHNOLOGIST_CTRL_BOX, BF::DOOR_OPEN}));

}
 