#pragma once

// The idea behind it is to share the code easy without sending your private info to GitHub
// Private.h is optional and it just hosts your credentials. This is an example:
// const char* WIFI_SSID = “my ssid”;
// const char* WIFI_PASSWORD = “my wifi password”;




//WIFI_SSID and WIFI_PASSWORD of the WiFi router
#ifdef USE_OFFICE_ROUTER
const char *WIFI_SSID = "code_vivacom";
const char *WIFI_PASSWORD = "codeass123";
#endif // 
#ifdef USE_STEFAN_ROUTER
const char *WIFI_SSID = "code";
const char *WIFI_PASSWORD = "codeass123";
#endif //
#ifdef USE_SIMO_ROUTER
const char *WIFI_SSID = "Simo";
const char *WIFI_PASSWORD = "dolina56";
#endif //
#ifdef USE_VENCI_ROUTER
const char *WIFI_SSID = "...................";
const char *WIFI_PASSWORD = "...............";
#endif //

// * WI-Fi conection setup
// The WI-Fi credentials are defined in Private.h!
const char *deviceName = "poliva4ka";
#ifdef USE_OFFICE_ROUTER
IPAddress staticIP(192, 168, 37, 2); //ESP static ip
IPAddress gateway(192, 168, 37, 1);  //IP Address of your WiFi Router (Gateway)
IPAddress subnet(255, 255, 255, 0);  //Subnet mask
#endif                               //
#ifdef USE_STEFAN_ROUTER
// IPAddress staticIP(192, 168, 1, 2); //ESP static ip
// IPAddress gateway(192, 168, 1, 1);  //IP Address of your WiFi Router (Gateway)
// IPAddress subnet(255, 255, 255, 0); //Subnet mask
#endif                              //
#ifdef USE_SIMO_ROUTER
IPAddress staticIP(192, 168, 0, 4); //! TEMPORARY USING IP 4 AS THE OTHER CONTROLLER IS ON 2!  ESP static ip
IPAddress gateway(192, 168, 0, 1);  //IP Address of your WiFi Router (Gateway)
IPAddress subnet(255, 255, 255, 0); //Subnet mask
#endif
#ifdef USE_VENCI_ROUTER
IPAddress staticIP(192, 168, 0, 4); //ESP static ip
IPAddress gateway(192, 168, 0, 1);  //IP Address of your WiFi Router (Gateway)
IPAddress subnet(255, 255, 255, 0); //Subnet mask
#endif

// IPAddress dns(8, 8, 8, 8);  // If only one DNS is used


// IPAddress primaryDNS(8, 8, 8, 8);   //
// IPAddress secondaryDNS(8, 8, 4, 4); //
