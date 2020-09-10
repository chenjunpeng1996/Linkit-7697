#include "ntime.h"
#include <LWiFi.h>
#include <WiFiUdp.h>
#include <ctime>
#include <LRTC.h>


NTIME NetTime;


String Network_Time="";

char _lwifi_ssid[] = "204";
char _lwifi_pass[] = "asdfghjkl";

void setup()
{
  LRTC.begin();
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Network_Time = NetTime.getNetworkTime();
  int a = NetTime.get_field_from_time_string(Network_Time, 0);
  int b = NetTime.get_field_from_time_string(Network_Time, 1);
  int c = NetTime.get_field_from_time_string(Network_Time, 2);
  int d= NetTime.get_field_from_time_string(Network_Time, 3);
  int e = NetTime.get_field_from_time_string(Network_Time, 4);
  int f = NetTime.get_field_from_time_string(Network_Time, 5);
 LRTC.set(a,b,c,d,e,f);
  Serial.begin(115200);
}


void loop()
{
  Serial.print(NetTime.get_field_from_time_string(NetTime.get_time_from_RTC(), 0));
  Serial.print("-");
  Serial.print(NetTime.get_field_from_time_string(NetTime.get_time_from_RTC(), 1));
  Serial.print("-");
  Serial.print(NetTime.get_field_from_time_string(NetTime.get_time_from_RTC(), 2));
  Serial.print(" ");
  Serial.print(NetTime.get_field_from_time_string(NetTime.get_time_from_RTC(), 3));
  Serial.print(":");
  Serial.print(NetTime.get_field_from_time_string(NetTime.get_time_from_RTC(), 4));
  Serial.print(":");
  Serial.println(NetTime.get_field_from_time_string(NetTime.get_time_from_RTC(), 5));
  delay(1000);
}
