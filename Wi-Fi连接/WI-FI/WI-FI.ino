#include"wifi.h"
WIFI wifi;
void setup() {
	//Initialize serial and wait for port to open:
	Serial.begin(115200);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
   wifi.Init();
	}

	
}

void loop() {
	// scan for existing networks:
	
	String *a;
  a=wifi.listNetworks();
 
  Serial.println(a[1]);
  Serial.println(a[5]);
  Serial.println(a[9]);
  
	delay(10000);
}
