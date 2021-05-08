// Zone.h

#ifndef _LightsTower_h
#define _LightsTower_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Definitions.h>
#include "Light.h"
// #include <ArduinoJson.h>
using namespace std;
class LightsTower
{
private:
	//RelayClass relay_[MAX_NUMBER_OF_RELAYS];
	//int zoneRelaysPins_[MAX_NUMBER_OF_RELAYS]; // relay pin number
	int id_; 
	bool state_= false;
	//int numberOfRelays_;
	string name_;
	bool enable_ = true;
	int workerResponseTime_; // in minutes
	vector<Light*> *lights_;
	vector<int> towerlightIds_;
	//bool configured_ = false;
public:
	// LightsTower(const String& zoneName, vector<Light> lights_);
	LightsTower(int id, vector<Light *> &lights, vector<int> &towerlightIds,int workerResponseTime);

	// Zone(JsonObject& jSource);
	void setName(const string& newName);
	// void addRelay(int relayIdNumber);
	// void removeRelay(int relayIdNumber);
	const string getName();
	void stopDisplay();
	void displayRed();
	void displayYellow();
	void displayGreen();
	void enable(); //is enabled by default!
	void disable();
	// bool isConfigured();
	// void setConfigured();
	// void setNotConfigured();
	bool isDisplaying();
	bool isEnabled();
	void setWorkerResponseTime(int time);
	int getWorkerResponseTime();
	vector<Light*> *GetLights();
	// void serialize(JsonObject& target);
};

extern vector<LightsTower*> lightsTowers;

#endif

