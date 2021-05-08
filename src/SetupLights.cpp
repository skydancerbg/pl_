
#include "Definitions.h"
#include "StructsEnums.h"
#include "Light.h"


void setupLights(){
  lights.push_back(new Light ( {LID::RED_ENTR_TOWER,12,CU::LIGHT_TOWER_ENTR, LF::EMERGENCY}));
  lights.push_back(new Light ( {LID::YELLOW_ENTR_TOWER,14,CU::LIGHT_TOWER_ENTR, LF::INSERT_CART}));
  lights.push_back(new Light ( {LID::GREEN_ENTR_TOWER,27,CU::LIGHT_TOWER_ENTR, LF::TECHNOLOGIST_ORDER}));


  lights.push_back(new Light ( {LID::YELLOW_BTN_BOX_ENTR,26,CU::BUTTON_BOX_ENTR, LF::INSERT_CART}));
  lights.push_back(new Light ( {LID::GREEN_BTN_BOX_ENTR,25,CU::BUTTON_BOX_ENTR, LF::TECHNOLOGIST_ORDER}));
  
  lights.push_back(new Light ( {LID::RED_EXIT_TOWER,0,CU::LIGHT_TOWER_EXIT, LF::EMERGENCY}));
  lights.push_back(new Light ( {LID::YELLOW_EXIT_TOWER,4,CU::LIGHT_TOWER_EXIT, LF::EXTRACT_AND_TURN}));
  lights.push_back(new Light ( {LID::GREEN_EXIT_TOWER,16,CU::LIGHT_TOWER_EXIT, LF::TECHNOLOGIST_ORDER}));

  lights.push_back(new Light ( {LID::YELLOW_BTN_BOX_EXIT,17,CU::BUTTON_BOX_EXIT, LF::INSERT_CART}));
  lights.push_back(new Light ( {LID::GREEN_BTN_BOX_EXIT,5,CU::BUTTON_BOX_EXIT, LF::TECHNOLOGIST_ORDER}));
  
  lights.push_back(new Light ( {LID::BLUE_DOOR_OPEN,3,CU::TECHNOLOGIST_CTRL_BOX, LF::DOOR_OPEN}));
  lights.push_back(new Light ( {LID::ONBOARD_LED,2,CU::ONBOARD_LED, LF::ONBOARD_LED}));
}