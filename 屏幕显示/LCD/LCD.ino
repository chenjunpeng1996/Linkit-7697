#include "font.h"
#include"Arduino.h"
#include"OLED12864.h"
#include"Arduino.h"
#include "SoftwareI2C.h"
#include "ClosedCube_TCA9546A.h"
int scl=8;//定义数字接口8
int sda=9;//定义数字接口9
int res=10;//定义数字接口10

#define OLED_SCLK_Clr() digitalWrite(scl,LOW)//SCL
#define OLED_SCLK_Set() digitalWrite(scl,HIGH)

#define OLED_SDIN_Clr() digitalWrite(sda,LOW)//SDA
#define OLED_SDIN_Set() digitalWrite(sda,HIGH)

#define OLED_RST_Clr() digitalWrite(res,LOW)//RES   注：此引脚是为了配合SPI驱动模块改成I2C驱动模块使用的（改装的话必须接），如果买的是I2C模块，请忽略此引脚。
#define OLED_RST_Set() digitalWrite(res,HIGH)


#define OLED_CMD  0  //写命令
#define OLED_DATA 1 //写数据
OLED12864 oled;
ClosedCube_TCA9546A tca9546a;
SoftwareI2C softwarei2c;
uint8_t OLED_GRAM[128][16];//将要显示的缓存内容
char toChar[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
String str1,str2,str3,str4,str5;
bool PanDuan = false; 
bool user=false ;
String bsf="#";
int fanse=0;
int fanzhuan=1;
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int address=0x74;
void setup()
{
  delay(1000);
  Serial.println("开始执行");
  Serial.begin(115200);
  delay(1000);
  // reserve 200 bytes for the inputString:
  //inputString.reserve(200);
  Serial.println("设置iic");
  softwarei2c.begin(9, 8);
  delay(1000);
  Serial.println("设置iic");
  softwarei2c.beginTransmission(address);
   delay(100);
   Serial.println("设置iic");
  softwarei2c.write(0x08);
  Serial.println("设置iic");
  //softwarei2c.endTransmission();
  delay(1000);
  Serial.println("初始化lcd");
  oled.Init();
  
   Serial.println("显示lcd");
}

void loop()
{
  oled.ShowPicture(0,0,128,8,Init1);
    delay(1000);
    oled.ShowPicture(0,0,128,8,Init2);
    delay(1000);
}
