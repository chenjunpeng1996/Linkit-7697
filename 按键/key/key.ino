#include<arduino.h>
#include"key.h"
int Address_0;
int Address_1;
int Address_2;
int key_volua;

int cengji_1=0;
int cengji_2=0;
int cengji_3=0;
int cengji_4=0;
int cengji_5=0;

int wei=1;
long long jiluzhi=0;
KEY key;
void setup()
{
  Serial.begin(115200);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  //Serial.println("初始化完成");
}
void loop()
{
  Address_0 = digitalRead(10);
  Address_1 = digitalRead(11);
  Address_2 = digitalRead(12);
  //Serial.println("获取按键信息完成");
  key_volua = key.Get_Key_Value(Address_0, Address_1, Address_2);
  //Serial.println("已将按键信息录入系统");
  if(key_volua == 1)
  {
    jiluzhi = key.Button_z_s(wei, jiluzhi);
  }
  else if(key_volua == 2)
  {
    jiluzhi = key.Button_z_x(wei, jiluzhi);
  }
  else if(key_volua == 3)
  {
    if(wei>0 && wei<4)
    {
      wei = wei + 1;
    }
    jiluzhi = key.Button_z_z(wei, jiluzhi);
  }
  else if(key_volua == 4)
  {
    if(wei>1 && wei<5)
    {
      wei = wei - 1;
    }
    jiluzhi = key.Button_z_y(wei, jiluzhi);
  }
  //Serial.println("按键信息判断完成");
  cengji_1=jiluzhi/1000000000000;
  cengji_2=jiluzhi/1000000000-cengji_1*1000;
  cengji_3=jiluzhi/1000000-cengji_1*1000000-cengji_2*1000;
  cengji_4=jiluzhi/1000-cengji_1*1000000000-cengji_2*1000000-cengji_3*1000;
  cengji_5=jiluzhi-cengji_1*1000000000000-cengji_2*1000000000-cengji_3*1000000-cengji_4*1000;
  //Serial.println("按键信息计算成功");
  Serial.print(cengji_1);
  Serial.print(",");
  Serial.print(cengji_2);
  Serial.print(",");
  Serial.print(cengji_3);
  Serial.print(",");
  Serial.print(cengji_4);
  Serial.print(",");
  Serial.println(cengji_5);
}
