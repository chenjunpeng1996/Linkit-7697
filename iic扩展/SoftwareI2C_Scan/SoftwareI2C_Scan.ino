// i2c scan
#include "SoftwareI2C.h"

SoftwareI2C softwarei2c;

void setup() {
    Serial.begin(115200);
    Serial.println("串口初始化完成");
    softwarei2c.begin(9, 8);       // sda, scl
    Serial.println("开始扫描...");
}

void loop() {
    for (unsigned char i = 1; i <= 127; i++) {
        if (softwarei2c.beginTransmission(i)) {
            Serial.print("0x");
            Serial.println(i, HEX);

            //while (1);
            softwarei2c.endTransmission();
        }
        
    }

    //Serial.println("没有找到");
    //while (1);

}
