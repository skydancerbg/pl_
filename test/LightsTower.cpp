// //
// //
// //

#include "LightsTower.h"

// //LightsTower::LightsTower(RelayClass relay[]):relay_(relay)
// LightsTower::LightsTower(const String &LightsTowerName, vector<Valve> valves)
// {
//     this->valves_ = valves;
//     name_ = LightsTowerName;
//     enable_ = true;
//     state_ = false;
//     //FILLARRAY(LightsTowerRelaysPins_, 255);
//     // this->;
// }


LightsTower::LightsTower(int id, vector<Light *> &lights, vector<int> &towerlightIds, int workerResponseTime): id_(id)
{
    // const char *cName = jSource["name"]; // "LightsTower0"
    // name_ = cName;
    workerResponseTime_ = workerResponseTime;
    // for (auto it = towerLights.begin(); it != towerLights.end(); ++it);
    for (int i = 0; i < towerlightIds.size(); ++i)
    {
        // int index = it->as<JsonVariant>(); new Light(0,5,true) new (*it)->getId(),(*it)->getPinNumber(), (*it)->is()
        int index = towerlightIds[i];
        // lights_.push_back(::lights[index]);
        lights_ = *lights;
    }
    stopDisplay();
    state_ = false;
}

void LightsTower::setName(const string &newName)
{
    name_ = newName;
}

const string LightsTower::getName()
{
    return name_;
}

void LightsTower::displayRed()
{
    if (!enable_)
        return;
    // for (auto it = valves_.begin(); it != valves_.end(); it++)
    //     (*it)->on();
    stopDisplay();
    lights_[0]->on();
    state_ = true;
    Sprintln("displayRed");
}

void LightsTower::displayYellow()
{
    if (!enable_)
        return;
    // for (auto it = valves_.begin(); it != valves_.end(); it++)
    //     (*it)->on();
    stopDisplay();
    lights_[1]->on();
    state_ = true;
}

void LightsTower::displayGreen()
{
    if (!enable_)
        return;
    // for (auto it = valves_.begin(); it != valves_.end(); it++)
    //     (*it)->on();
    stopDisplay();
    lights_[2]->on();
    state_ = true;
}

void LightsTower::stopDisplay()
{
    if (!state_)
        return;
    for (auto it = lights_.begin(); it != lights_.end(); it++)
        (*it)->off();
    state_ = false;
    Sprintln("stopDisplay");
}

void LightsTower::enable() { enable_ = true; }

void LightsTower::disable()
{
    if (!enable_)
        return;
    stopDisplay();
    enable_ = false;
}

bool LightsTower::isDisplaying() { return state_; }
bool LightsTower::isEnabled() { return enable_; }

void LightsTower::setWorkerResponseTime(int time) { workerResponseTime_ = time; }
int LightsTower::getWorkerResponseTime() { return workerResponseTime_; }

vector<Light *> *LightsTower::GetLights() { return &lights_; }

// void LightsTower::serialize(JsonObject &target)
// {
//     target["name"] = name_.c_str(); //"LightsTower0";
//     target["state"] = state_;           //ON/OFF ne e state ami status meje bi???
//     target["enabled"] = enable_;
//     target["manualWateringTime"] = manualWateringTime_;

//     auto jValves = target.createNestedArray("LightsTowerValves");
//     for (auto it = valves_.begin(); it != valves_.end(); it++)
//         jValves.add((*it)->getId());
// }
