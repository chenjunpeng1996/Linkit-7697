#include"Arduino.h"
#include "key.h"
int Button_Value_s;
int Button_Value_x;
int Button_Value_z;
int Button_Value_y;
int Button_Value_o;

int Button_Value_sj;
int Button_Value_xj;
int Button_Value_zj;
int Button_Value_yj;
int Button_Value_oj;



int KEY::Get_Key_Value(int address0 ,int address1 ,int address2 )
{
    if (address0 == 1 && address1 == 0 && address2 == 0) {
        return 1;
  } else if (address0 == 0 && address1 == 1  && address2 == 0) {
        return 2;
  } else if ( address0 == 1 && address1 == 1 &&  address2 == 0) {
        return 3;
  } else if (  address0  == 0 &&  address1== 0 &&   address2  == 1) {
        return 4;
  } else {
        return 0;
  }
}
long long KEY::Button_z_s(int wei ,long long dangqianzhi)
{
    long long fhz = dangqianzhi;
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
long long KEY::Button_z_x(int wei ,long long dangqianzhi)
{
    long long fhz = dangqianzhi;
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
long long KEY::Button_z_z(int wei ,long long dangqianzhi)
{
    long long fhz = dangqianzhi;
    if(wei==1)
    {
      fhz=dangqianzhi+1000000000;
    }else if(wei==2)
    {
      fhz=dangqianzhi+1000000;
    }
    else if(wei==3)
    {
      fhz=dangqianzhi+1000;
    }
    //if(dangqianzhi)
 return fhz; 
}
long long KEY::Button_z_y(int wei ,long long dangqianzhi)
{
    long long fhz = dangqianzhi;
    if(wei==2)
    {
      fhz=dangqianzhi/1000000000*1000000000;
    }
    else if(wei==3)
    {
      fhz=dangqianzhi/1000000*1000000;
    }
    else if(wei==4)
    {
      fhz=dangqianzhi/1000*1000;
    }
 return fhz; 
}
