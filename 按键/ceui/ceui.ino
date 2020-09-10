const int Button_s = 3;
const int Button_x =4;
const int Button_z = 5;
const int Button_y = 14;
const int Button_o = 15;

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

int cengji_1=0;
int cengji_2=0;
int cengji_3=0;
int cengji_4=0;
int cengji_5=0;

long long jiluzhi=0;
int wei1=1;
void setup() {

Serial.begin(115200);
pinMode(Button_s, INPUT);
pinMode(Button_x, INPUT);
pinMode(Button_z, INPUT);
pinMode(Button_y, INPUT);
pinMode(Button_o, INPUT);
Button_Value_sj=digitalRead(Button_s);
Button_Value_xj=digitalRead(Button_x);
Button_Value_zj=digitalRead(Button_z);
Button_Value_yj=digitalRead(Button_y);
Button_Value_oj=digitalRead(Button_o);
}
              
void loop() {
Button_Value_s=digitalRead(Button_s);
Button_Value_x=digitalRead(Button_x);
Button_Value_z=digitalRead(Button_z);
Button_Value_y=digitalRead(Button_y);
Button_Value_o=digitalRead(Button_o);
//Serial.print(Button_Value_s);
//Serial.print(Button_Value_x);
//Serial.print(Button_Value_z);
//Serial.print(Button_Value_y);
//Serial.println(Button_Value_o);
if(Button_Value_s!=Button_Value_sj)
{
  jiluzhi=Button_z_s(wei1,jiluzhi);
  
}
if(Button_Value_x!=Button_Value_xj)
{
  jiluzhi=Button_z_x(wei1,jiluzhi);
  //Serial.println(Button_Value_x);
}
if(Button_Value_z!=Button_Value_zj)
{
  jiluzhi=Button_z_z(wei1,jiluzhi);
  
}
if(Button_Value_y!=Button_Value_yj)
{
  jiluzhi=Button_z_y(wei1,jiluzhi);
  
}
if(Button_Value_o!=Button_Value_oj)
{
  wei1=Button_z_o(wei1,jiluzhi);
  
}
  cengji_1=jiluzhi/1000000000000;
  cengji_2=jiluzhi/1000000000-cengji_1*1000;
  cengji_3=jiluzhi/1000000-cengji_1*1000000-cengji_2*1000;
  cengji_4=jiluzhi/1000-cengji_1*1000000000-cengji_2*1000000-cengji_3*1000;
  cengji_5=jiluzhi-cengji_1*1000000000000-cengji_2*1000000000-cengji_3*1000000-cengji_4*1000;
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

long long Button_z_s(int wei ,long long dangqianzhi)
{
  
  long long fhz=dangqianzhi;
  Button_Value_s=digitalRead(Button_s)s
  delay(300);
  if(Button_Value_s!=Button_Value_sj)
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
