#include"wifi.h"
#include"Arduino.h"
#include<iostream>
#include<string>
#include <LWiFi.h>
 using namespace std;
 #define max 100
void WIFI::printMacAddress() {
	// the MAC address of your Wifi shield
	byte mac[6];

	// print your MAC address:
	WiFi.macAddress(mac);
	Serial.print("MAC: ");
	Serial.print(mac[5], HEX);
	Serial.print(":");
	Serial.print(mac[4], HEX);
	Serial.print(":");
	Serial.print(mac[3], HEX);
	Serial.print(":");
	Serial.print(mac[2], HEX);
	Serial.print(":");
	Serial.print(mac[1], HEX);
	Serial.print(":");
	Serial.println(mac[0], HEX);
}
void WIFI::Init()
{
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }

  // Print WiFi MAC address:
  printMacAddress();
}
String* WIFI::listNetworks() {
  String SaoMiao_Wifi[100];
	// scan for nearby networks:
	Serial.println("** Scan Networks **");
	int numSsid = WiFi.scanNetworks();
	if (numSsid == -1) {
		Serial.println("Couldn't get a wifi connection");
	}

	// print the list of networks seen:
	Serial.print("number of available networks:");
	Serial.println(numSsid);
  
	// print the network number and name for each network found:
	for (int thisNet = 0; thisNet < numSsid; thisNet++) {
		Serial.print(thisNet);
    SaoMiao_Wifi[thisNet*4]=to_String(thisNet);
		Serial.print(") ");
		Serial.print(WiFi.SSID(thisNet));
    SaoMiao_Wifi[thisNet*4+1]=WiFi.SSID(thisNet);
		Serial.print("\tSignal: ");
    SaoMiao_Wifi[thisNet*4+2]=to_String(WiFi.RSSI(thisNet));
    Serial.print(WiFi.RSSI(thisNet));

		Serial.print(" dBm");
		Serial.print("\tEncryption: ");
		SaoMiao_Wifi[thisNet*4+3]=printEncryptionType(WiFi.encryptionType(thisNet));
	}
 return SaoMiao_Wifi;
}

String WIFI::printEncryptionType(int thisType) {
	// read the encryption type and print out the name:
 String a;
	switch (thisType) {
		case ENC_TYPE_WEP:
			Serial.println("WEP");
      a="WEP";
			break;
		case ENC_TYPE_TKIP:
			Serial.println("WPA");
      a="WPA";
			break;
		case ENC_TYPE_CCMP:
			Serial.println("WPA2");
     a="WPA2";
			break;
		case ENC_TYPE_NONE:
			Serial.println("None");
     a="None";
			break;
		case ENC_TYPE_AUTO:
			Serial.println("Auto");
     a="Auto";
			break;
		default :
			Serial.println("WPA-PSK/WPA2-PSK");
     a="WPA-PSK/WPA2-PSK";
			break;
	}
 return a;
}

String WIFI::to_String(int n)
 {
     int m = n;
     char s[max];
     char ss[max];
     int i=0,j=0;
     if (n < 0)// 处理负数
     {
         m = 0 - m;
         j = 1;
         ss[0] = '-';
     }    
     while (m>0)
     {
         s[i++] = m % 10 + '0';
         m /= 10;
     }
     s[i] = '\0';
     i = i - 1;
     while (i >= 0)
    {
         ss[j++] = s[i--];
     }    
     ss[j] = '\0';    
    return ss;
}
