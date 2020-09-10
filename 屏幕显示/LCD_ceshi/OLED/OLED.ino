#include"OLED12864.h"
#include"Arduino.h"
#include "LTimer.h"
#include"font.h"
#include"wifi.h"
#include <LWiFi.h>
#include <string.h>
#include <LHTTPUpdate.h>

LTimer timer0(LTIMER_0);

OLED12864 oled;
WIFI wifi;
WiFiClient client;

char ssid[] = "Xiaomi_204";        // 你的Wi-Fi名称
char pass[] = "asdfghjkl";          // 你的Wi-Fi密码
int keyIndex = 0;                   //您的网络密钥索引号（仅WEP需要）
int status = WL_IDLE_STATUS;
char tcp_server[] = "192.168.31.203";
int prot=5200;

char fotaBinaryURL[] = "http://192.168.31.203:10086/image.bin";//bin包的http地址（必须是压缩之后的）
char version_server[] = "192.168.31.203";

int dianliangceshi=0;
int Time_i=0;
int ShiZhen=12;
int FenZhen=31;
int MiaoZhen=52;
bool NeiRongGengXin=1;
int Menu_1=0;
int Menu_2=0;
int Menu_3=0;
int Menu_4=0;
int Menu_5=0;
String *a;
String wifi_sao[30];
int TCP_IP_1=0;
int TCP_IP_2=0;
int TCP_IP_3=0;
int TCP_IP_4=0;
int TCP_IP_Prot=0;
String Version="v=0.0.1";
String New_Version="No";
long rssi=0;
bool JinCheng1=1;
int XinHaoQiangDu=0;

const int Button_s = 3;
const int Button_x =4;
const int Button_z = 5;
const int Button_y = 14;
const int Button_o = 15;
const int Button_f = 13;

int Button_Value_s;
int Button_Value_x;
int Button_Value_z;
int Button_Value_y;
int Button_Value_o;
int Button_Value_f;


int Button_Value_sj;
int Button_Value_xj;
int Button_Value_zj;
int Button_Value_yj;
int Button_Value_oj;
int Button_Value_fj;

int cengji_1=0;
int cengji_2=0;
int cengji_3=0;
int cengji_4=0;
int cengji_5=0;

long long jiluzhi=0;
int wei1=1;

void setup()
{
  
  status = WiFi.begin(ssid, pass);
  //printWifiStatus();
  //Serial.print("wifi 开始连接");
  //client.connect(tcp_server, prot);
  Serial.begin(115200);
//  pinMode(Button_s, INPUT);
//pinMode(Button_x, INPUT);
//pinMode(Button_z, INPUT);
//pinMode(Button_y, INPUT);
//pinMode(Button_o, INPUT);
//Button_Value_sj=digitalRead(Button_s);
//Button_Value_xj=digitalRead(Button_x);
//Button_Value_zj=digitalRead(Button_z);
//Button_Value_yj=digitalRead(Button_y);
//Button_Value_oj=digitalRead(Button_o);
  timer0.begin();
  timer0.start(990, LTIMER_REPEAT_MODE, Updata_DingLan, NULL);
  oled.Init();
//  Serial.print("初始化完成");
//  oled.ShowPicture(0,0,128,8,heise);
//  delay(1000);
//  Serial.print("图片1显示完成");
//  oled.ShowPicture(0,0,128,8,Init1);
//  delay(1000);
//  oled.ShowPicture(96,0,128,2,DianLiang0);
//  oled.ShowPicture(0,16,128,8,Init1);
//  Serial.print("图片2显示完成");
//  tcp_server = "192.168.31.203";
  Menu();
}

void loop()
{

//Button_Value_s=digitalRead(Button_s);
//Button_Value_x=digitalRead(Button_x);
//Button_Value_z=digitalRead(Button_z);
//Button_Value_y=digitalRead(Button_y);
//Button_Value_o=digitalRead(Button_o);
////Serial.print(Button_Value_s);
////Serial.print(Button_Value_x);
////Serial.print(Button_Value_z);
////Serial.print(Button_Value_y);
////Serial.println(Button_Value_f);
//if(Button_Value_s!=Button_Value_sj)
//{
//  jiluzhi=Button_z_s(wei1,jiluzhi);
//  
//}
//else if(Button_Value_x!=Button_Value_xj)
//{
//  jiluzhi=Button_z_x(wei1,jiluzhi);
//  //Serial.println(Button_Value_x);
//}
//else if(Button_Value_z!=Button_Value_zj)
//{
//  jiluzhi=Button_z_z(wei1,jiluzhi);
//  
//}
//else if(Button_Value_y!=Button_Value_yj)
//{
//  jiluzhi=Button_z_y(wei1,jiluzhi);
//  
//}
//else if(Button_Value_o!=Button_Value_oj)
//{
//  wei1=Button_z_o(wei1,jiluzhi);
//  jiluzhi=zijia(wei1,jiluzhi);
//}
//else if(Button_Value_f!=Button_Value_fj)
//{
//  wei1=Button_z_f(wei1,jiluzhi);
//  jiluzhi=zijian(wei1,jiluzhi);
//  
//}
//  cengji_1=jiluzhi/1000000000000;
//  cengji_2=jiluzhi/1000000000-cengji_1*1000;
//  cengji_3=jiluzhi/1000000-cengji_1*1000000-cengji_2*1000;
//  cengji_4=jiluzhi/1000-cengji_1*1000000000-cengji_2*1000000-cengji_3*1000;
//  cengji_5=jiluzhi-cengji_1*1000000000000-cengji_2*1000000000-cengji_3*1000000-cengji_4*1000;
  Serial.print(cengji_1);
  Serial.print(",");
  Serial.print(cengji_2);
  Serial.print(",");
  Serial.print(cengji_3);
  Serial.print(",");
  Serial.print(cengji_4);
  Serial.print(",");
  Serial.println(cengji_5);

//  if(JinCheng1)
//    printWifiStatus();
  XinHaoQiangDu=Get_XinHaoQiangDu();

  //oled.ShowString(6,52,"Menu",12);
  //oled.ShowString(98,52,"Quit",12);
  
  if((Menu_1!=cengji_1 || Menu_2!=cengji_2 || Menu_3!=cengji_3 || Menu_4!=cengji_4 || Menu_5!=cengji_5))
  {
    qingping();
    Menu_1=cengji_1;
    Menu_2=cengji_2;
    Menu_3=cengji_3;
    Menu_4=cengji_4;
    Menu_5=cengji_5;
    Menu();
  }
}
long printWifiStatus() {
  // 打印你的Wi-Fi名称
  //Serial.print("Wi-Fi名称: ");
  Serial.println(WiFi.SSID());

  // 打印你获取的IP地址
  IPAddress ip = WiFi.localIP();
  //Serial.print("IP 地址: ");
  //Serial.println(ip);

  // 打印接收信号强度：
  //rssi = WiFi.RSSI();
  //Serial.print("信号强度:");
  //Serial.print(rssi);
  //Serial.println(" dBm");
}
void Menu()
{
  NeiRongGengXin=1;
  qingping();
  Serial.println("进入菜单选择");
  switch(Menu_1)
  {
    case 0:
    oled.ShowString(0,52,"                      ",12);
    oled.ShowString(52,52,"Menu",12);
    ///oled.ShowString(98,52,"Quit",12);
    NeiRongGengXin=0;
    oled.ShowPicture(0,2,128,6,MeiXin);
    //oled.ShowString(0,20,"XiKeMeiXin",24);
    break;
    case 1:
    switch(Menu_2)
    {
      oled.ShowString(0,52,"                     ",12);
      oled.ShowString(6,52,"Enter",12);
      oled.ShowString(98,52,"Back",12);
      case 0:
      oled.ShowString(0,52,"                     ",12);
      oled.ShowString(6,52,"Enter",12);
      oled.ShowString(98,52,"Back",12);
      NeiRongGengXin=0;
      oled.ShowPicture(0,2,128,6,SheZhi);
      break;
      case 1:
      qingping();
      oled.ShowString(0,16,"> ",12);
      oled.ShowString(10,16,"Time config",12);
      oled.ShowString(10,28,"Wi-Fi config",12);
      oled.ShowString(10,40,"TCP config",12);

      switch(Menu_3)
      {
        oled.ShowString(0,52,"                     ",12);
        oled.ShowString(6,52,"Enter",12);
        oled.ShowString(98,52,"Back",12);
        case 1:
        qingping();
        oled.ShowString(0,16,"      ",12);
        oled.ShowString(16,16,"Time config",12);
        oled.ShowString(2,28,"H    ",12);
        oled.ShowNum(16,28,ShiZhen,2,12);
        oled.ShowString(28,28,":",12);
        oled.ShowNum(34,28,FenZhen,2,12);
        oled.ShowString(46,28,":",12);
        oled.ShowNum(52,28,MiaoZhen,2,12);
        oled.ShowString(64,28,"          ",12);
        oled.ShowString(0,40,"                     ",12);
        break;
        case 2:
        qingping();
        oled.ShowString(0,16,"      ",12);
        oled.ShowString(16,16,"Time config",12);
        oled.ShowString(2,28,"M    ",12);
        oled.ShowNum(16,28,ShiZhen,2,12);
        oled.ShowString(28,28,":",12);
        oled.ShowNum(34,28,FenZhen,2,12);
        oled.ShowString(46,28,":",12);
        oled.ShowNum(52,28,MiaoZhen,2,12);
        oled.ShowString(64,28,"          ",12);
        oled.ShowString(0,40,"                     ",12);
        break;
        case 3:
        qingping();
        oled.ShowString(0,16,"      ",12);
        oled.ShowString(16,16,"Time config",12);
        oled.ShowString(2,28,"S    ",12);
        oled.ShowNum(16,28,ShiZhen,2,12);
        oled.ShowString(28,28,":",12);
        oled.ShowNum(34,28,FenZhen,2,12);
        oled.ShowString(46,28,":",12);
        oled.ShowNum(52,28,MiaoZhen,2,12);
        oled.ShowString(64,28,"          ",12);
        oled.ShowString(0,40,"                     ",12);
        break;
      }
      break;
      case 2:
      switch(Menu_3)
      {
        case 0:
        qingping();
        oled.ShowString(0,28,"> ",12);
        oled.ShowString(10,16,"Time config",12);
        oled.ShowString(10,28,"Wi-Fi config",12);
        oled.ShowString(10,40,"TCP config",12);
        break;
        case 1:
        qingping();
        a=wifi.listNetworks();
        oled.ShowString(0,28,"    ",12);
        oled.ShowString(0,16,"    ",12);
        oled.ShowString(0,16,"> ",12);
        oled.ShowStringzu(10,16,a[1],12);
        oled.ShowStringzu(10,28,a[5],12);
        oled.ShowStringzu(10,40,a[9],12);
        break;
        case 2:
        qingping();
        oled.ShowString(0,28,"> ",12);
        oled.ShowString(0,16,"    ",12);
        oled.ShowStringzu(10,16,a[1],12);
        oled.ShowStringzu(10,28,a[5],12);
        oled.ShowStringzu(10,40,a[9],12);
        break;
        case 3:
        qingping();
        oled.ShowString(0,40,"> ",12);
        oled.ShowStringzu(10,16,a[1],12);
        oled.ShowStringzu(10,28,a[5],12);
        oled.ShowStringzu(10,40,a[9],12);
        break;
        case 4:
        qingping();
        oled.ShowString(0,40,"> ",12);
        oled.ShowStringzu(10,16,a[5],12);
        oled.ShowStringzu(10,28,a[9],12);
        oled.ShowStringzu(10,40,a[13],12);
        break;
        case 5:
        qingping();
        oled.ShowString(0,40,"> ",12);
        oled.ShowStringzu(10,16,a[9],12);
        oled.ShowStringzu(10,28,a[13],12);
        oled.ShowStringzu(10,40,a[17],12);
        break;
      }
      break;
      case 3:
      switch(Menu_3)
      {
        case 0:
        qingping();
        oled.ShowString(0,40,"> ",12);
        oled.ShowString(10,16,"Time config",12);
        oled.ShowString(10,28,"Wi-Fi config",12);
        oled.ShowString(10,40,"TCP config",12);
        break;
        case 1:
        qingping();
        oled.ShowString(0,16,"      ",12);
        oled.ShowString(16,16,"TCP config",12);
        oled.ShowString(2,28,"1    ",12);
        oled.ShowNum(16,28,TCP_IP_1,3,12);
        oled.ShowString(34,28,".",12);
        oled.ShowNum(40,28,TCP_IP_2,3,12);
        oled.ShowString(58,28,".",12);
        oled.ShowNum(64,28,TCP_IP_3,3,12);
        oled.ShowString(82,28,".",12);
        oled.ShowNum(88,28,TCP_IP_4,3,12);
        oled.ShowString(106,28,"   ",12);
        oled.ShowNum(16,40,TCP_IP_Prot,5,12);
        break;
        case 2:
        qingping();
        oled.ShowString(0,16,"      ",12);
        oled.ShowString(16,16,"TCP config",12);
        oled.ShowString(2,28,"2    ",12);
        oled.ShowNum(16,28,TCP_IP_1,3,12);
        oled.ShowString(34,28,".",12);
        oled.ShowNum(40,28,TCP_IP_2,3,12);
        oled.ShowString(58,28,".",12);
        oled.ShowNum(64,28,TCP_IP_3,3,12);
        oled.ShowString(82,28,".",12);
        oled.ShowNum(88,28,TCP_IP_4,3,12);
        oled.ShowString(106,28,"   ",12);
        oled.ShowNum(16,40,TCP_IP_Prot,5,12);
        break;
        case 3:
        qingping();
        oled.ShowString(0,16,"      ",12);
        oled.ShowString(16,16,"TCP config",12);
        oled.ShowString(2,28,"3    ",12);
        oled.ShowNum(16,28,TCP_IP_1,3,12);
        oled.ShowString(34,28,".",12);
        oled.ShowNum(40,28,TCP_IP_2,3,12);
        oled.ShowString(58,28,".",12);
        oled.ShowNum(64,28,TCP_IP_3,3,12);
        oled.ShowString(82,28,".",12);
        oled.ShowNum(88,28,TCP_IP_4,3,12);
        oled.ShowString(106,28,"   ",12);
        oled.ShowNum(16,40,TCP_IP_Prot,5,12);
        break;
        case 4:
        qingping();
        oled.ShowString(0,16,"      ",12);
        oled.ShowString(16,16,"TCP config",12);
        oled.ShowString(2,28,"4    ",12);
        oled.ShowNum(16,28,TCP_IP_1,3,12);
        oled.ShowString(34,28,".",12);
        oled.ShowNum(40,28,TCP_IP_2,3,12);
        oled.ShowString(58,28,".",12);
        oled.ShowNum(64,28,TCP_IP_3,3,12);
        oled.ShowString(82,28,".",12);
        oled.ShowNum(88,28,TCP_IP_4,3,12);
        oled.ShowString(106,28,"   ",12);
        oled.ShowNum(16,40,TCP_IP_Prot,5,12);
        break;
        case 5:
        qingping();
        oled.ShowString(0,16,"      ",12);
        oled.ShowString(16,16,"TCP config",12);
        oled.ShowString(2,28,"     ",12);
        oled.ShowNum(16,28,TCP_IP_1,3,12);
        oled.ShowString(34,28,".",12);
        oled.ShowNum(40,28,TCP_IP_2,3,12);
        oled.ShowString(58,28,".",12);
        oled.ShowNum(64,28,TCP_IP_3,3,12);
        oled.ShowString(82,28,".",12);
        oled.ShowNum(88,28,TCP_IP_4,3,12);
        oled.ShowString(106,28,"   ",12);
        oled.ShowString(2,40,"P   ",12);
        oled.ShowNum(16,40,TCP_IP_Prot,5,12);
        break;
      }
      break;
      case 4:
     
      switch(Menu_3)
      {
        case 0:
        qingping();
        oled.ShowString(0,40,"> ",12);
        oled.ShowString(10,16,"Wi-Fi config",12);
        oled.ShowString(10,28,"TCP config",12);
        oled.ShowString(10,40,"Update",12);
        break;
        case 1:
        qingping();
        oled.ShowStringzu(16,16,Version,12);
        oled.ShowString(16,28,"Latest version",12);
        oled.ShowStringzu(16,40,New_Version,12);
      }
      break;
    }
    break;
    case 2:
    qingping();
    
    switch(Menu_2)
    {
      case 0:
      NeiRongGengXin=0;
      oled.ShowPicture(0,2,128,6,ChuanGanQi);
      break;
      case 1:
      qingping();
      oled.ShowString(0,16,">",16);
      oled.ShowString(10,16,"Time config",16);
      oled.ShowString(10,32,"Wi-Fi config",16);
      break;
      case 2:
      qingping();
      oled.ShowString(10,16,"Time config",16);
      oled.ShowString(0,32,">",16);
      oled.ShowString(10,32,"Wi-Fi config",16);
      break;
      case 3:
      qingping();
      oled.ShowString(10,16,"Wi-Fi config",16);
      oled.ShowString(0,32,">",16);
      oled.ShowString(10,32,"TCP config",16);
      break;
      case 4:
      qingping();
      oled.ShowString(10,16,"TCP config",16);
      oled.ShowString(0,32,">",16);
      oled.ShowString(10,32,"Update",16);
      break;
    }
    break;
  }
}
long long Button_z_s(int wei ,long long dangqianzhi)
{
  
  long long fhz=dangqianzhi;
  Button_Value_s=digitalRead(Button_s);
  delay(300);
  if(Button_Value_s!=Button_Value_sj)
  {
    switch(wei)
    {
      case 1:
      if(dangqianzhi>=1000000000000)
      fhz=dangqianzhi-1000000000000;
      break;
      case 2:
      if(dangqianzhi>=1000000000)
      fhz=dangqianzhi-1000000000;
      break;
      case 3:
      if(dangqianzhi>=1000000)
      fhz=dangqianzhi-1000000;
      break;
      case 4:
      if(dangqianzhi>=1000)
      fhz=dangqianzhi-1000;
      break;
      case 5:
      if(dangqianzhi>=1)
      fhz=dangqianzhi-1;
      break;
    }
  }
 return fhz; 
}
long long Button_z_x(int wei ,long long dangqianzhi)
{
  Serial.println(wei);
  long long fhz=dangqianzhi;
  Button_Value_x=digitalRead(Button_x);
  delay(300);
  if(Button_Value_x!=Button_Value_xj)
  {
    switch(wei)
    {
      case 1:
      fhz=dangqianzhi+1000000000000;
      break;
      case 2:
      fhz=dangqianzhi+1000000000;
      break;
      case 3:
      fhz=dangqianzhi+1000000;
      break;
      case 4:
      fhz=dangqianzhi+1000;
      break;
      case 5:
      fhz=dangqianzhi+1;
      break;
    }
  }
 return fhz; 
}
long long Button_z_z(int wei ,long long dangqianzhi)
{
  
  long long fhz=dangqianzhi;
  Button_Value_z=digitalRead(Button_z);
  delay(300);
  if(Button_Value_z!=Button_Value_zj)
  {
    if(dangqianzhi/1000000000000>1 && wei==1)
    {
      fhz=dangqianzhi-1000000000000;
    }
    //if(dangqianzhi)
  }
 return fhz; 
}
long long Button_z_y(int wei ,long long dangqianzhi)
{
  
  long long fhz=dangqianzhi;
  Button_Value_y=digitalRead(Button_y);
  delay(300);
  if(Button_Value_y!=Button_Value_yj)
  {
    
    if(dangqianzhi/1000000000000>0 && wei==1)
    {
      fhz=dangqianzhi+1000000000000;
    }
  }
 return fhz; 
}
int Button_z_o(int wei ,long long dangqianzhi)
{
  
  int fhz=wei;
  Button_Value_o=digitalRead(Button_o);
  delay(300);
  if(Button_Value_o!=Button_Value_oj)
  {
    fhz=fhz+1;
    if(fhz>5)
      fhz=1;
    }
 return fhz; 
}
long long zijia(int wei,long long dangqianzhi)
{
  long long fhz=dangqianzhi;
  switch(wei)
    {
      case 1:
      fhz=dangqianzhi+1000000000000;
      break;
      case 2:
      fhz=dangqianzhi+1000000000;
      break;
      case 3:
      fhz=dangqianzhi+1000000;
      break;
      case 4:
      fhz=dangqianzhi+1000;
      break;
      case 5:
      fhz=dangqianzhi+1;
      break;
    }
  return fhz;
}
long long zijian(int wei,long long dangqianzhi)
{
  long long fhz=dangqianzhi;
  switch(wei)
    {
      case 1:
      if(dangqianzhi>=1000000000000)
      fhz=dangqianzhi-1000000000000;
      break;
      case 2:
      if(dangqianzhi>=1000000000)
      fhz=dangqianzhi-1000000000;
      break;
      case 3:
      if(dangqianzhi>=1000000)
      fhz=dangqianzhi-1000000;
      break;
      case 4:
      if(dangqianzhi>=1000)
      fhz=dangqianzhi-1000;
      break;
      case 5:
      if(dangqianzhi>=1)
      fhz=dangqianzhi-1;
      break;
    }
    return fhz;
}
int Button_z_f(int wei ,long long dangqianzhi)
{
  
  int fhz=wei;
  Button_Value_o=digitalRead(Button_o);
  delay(300);
  if(Button_Value_o!=Button_Value_oj)
  {
    fhz=fhz-1;
    if(fhz<1)
      fhz=5;
   }
 return fhz; 
}
void qingping()
{
  oled.ShowString(0,16,"                      ",12);
  oled.ShowString(0,28,"                      ",12);
  oled.ShowString(0,40,"                      ",12);
}
void Updata_Dianliang()
{
  int Value;
  Value=Get_DianLiang();
  switch(Value)
  {
    case 0:oled.ShowPicture(96,0,128,2,DianLiang0);break;
    case 1:oled.ShowPicture(96,0,128,2,DianLiang1);break;
    case 2:oled.ShowPicture(96,0,128,2,DianLiang2);break;
    case 3:oled.ShowPicture(96,0,128,2,DianLiang3);break;
    case 4:oled.ShowPicture(96,0,128,2,DianLiang4);break;
    case 5:oled.ShowPicture(96,0,128,2,DianLiang5);break;
    case 6:oled.ShowPicture(96,0,128,2,DianLiang6);break;
  }
}
int Get_DianLiang()
{
  dianliangceshi++;
  if(dianliangceshi>6)
    dianliangceshi=0;
  return dianliangceshi;
}
void Updata_XinHaoQiangDu()
{
  int Value;
  Value=XinHaoQiangDu;
  switch(Value)
  {
    case 0:oled.ShowPicture(0,0,32,2,XinHaoQiangDu0);break;
    case 1:oled.ShowPicture(0,0,32,2,XinHaoQiangDu1);break;
    case 2:oled.ShowPicture(0,0,32,2,XinHaoQiangDu2);break;
    case 3:oled.ShowPicture(0,0,32,2,XinHaoQiangDu3);break;
    case 4:oled.ShowPicture(0,0,32,2,XinHaoQiangDu4);break;
    case 5:oled.ShowPicture(0,0,32,2,XinHaoQiangDu5);break;
  }
}
int Get_XinHaoQiangDu()
{
  Serial.println("进入获取Wi-Fi信号强度");
  int z=0;

    if(status = WL_CONNECTED)
    {
      rssi=WiFi.RSSI();
      z=100+rssi;
      z=z/10-2;
    }

  Serial.print("获取到Wi-Fi信号强度");
  Serial.println(z);
  return z;
}
void Updata_time()
{
  oled.ShowNum(32,0,ShiZhen,2,16);
  oled.ShowString(48,0,":",16);
  oled.ShowNum(56,0,FenZhen,2,16);
  oled.ShowString(72,0,":",16);
  oled.ShowNum(80,0,MiaoZhen,2,16);
  oled.Update_DiLan();
  delay(1);
  oled.Update_DingLan();
  if(NeiRongGengXin)
    oled.Update_NeiRong();
  
  MiaoZhen++;
  if(MiaoZhen>=60)
  {
    FenZhen++;
    MiaoZhen=0;
  }
  if(FenZhen>=60)
  {
    ShiZhen++;
    FenZhen=0;
  }
  if(ShiZhen>=24)
  {
    ShiZhen=0;
  }
  
}
void Updata_DingLan(void *usr_data)
{
  if(Time_i>=65535)
    Time_i=0;
  Updata_Dianliang();
  Updata_XinHaoQiangDu();
  Updata_time();
  Time_i++;
}
//char* char_String(String str)
//{
//  
//  return *p
//}
