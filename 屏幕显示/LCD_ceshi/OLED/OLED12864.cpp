#include"OLED12864.h"
#include"Arduino.h"

//构造函数
OLED12864::OLED12864()
{
  
}
//起始信号
void OLED12864::I2C_QiShiXinHao()
{
  SDIN_Set();
  SCLK_Set();
  SDIN_Clr();
  SCLK_Clr();
}

//结束信号
void OLED12864::I2C_JieShuXinHao()
{
  SCLK_Set();
  SDIN_Clr();
  SDIN_Set();
}

//等待信号响应
void OLED12864::I2C_WaitAck() //测数据信号的电平
{
  SCLK_Set();
  SCLK_Clr();
}

//写入一个字节
void OLED12864::Send_Byte(uint8_t dat)
{
  uint8_t i;
  for(i=0;i<8;i++)
  {
    SCLK_Clr();//将时钟信号设置为低电平
    if(dat&0x80)//将dat的8位从最高位依次写入
    {
      SDIN_Set();
    }
    else
    {
      SDIN_Clr();
    }
    SCLK_Set();//将时钟信号设置为高电平
    SCLK_Clr();//将时钟信号设置为低电平
    dat<<=1;
  }
}
//更新显存到OLED  
void OLED12864::Refresh()
{
  uint8_t i,n;
  for(i=0;i<8;i++)
  {
     WR_Byte(0xb0+i,CMD); //设置行起始地址
     WR_Byte(0x00,CMD);   //设置低列起始地址
     WR_Byte(0x10,CMD);   //设置高列起始地址
     for(n=0;n<128;n++)
     WR_Byte(GRAM[n][i],1);
  }
}
void OLED12864::Update_DingLan()
{
  uint8_t i,n;
  for(i=0;i<2;i++)
  {
     WR_Byte(0xB0+i,CMD); //设置行起始地址
     WR_Byte(0x00,CMD);   //设置低列起始地址
     WR_Byte(0x12,CMD);   //设置高列起始地址
     for(n=32;n<96;n++)
     WR_Byte(GRAM[n][i],1);
  }
}
void OLED12864::Update_DiLan()
{
  uint8_t i,n;
  for(i=6;i<8;i++)
  {
     WR_Byte(0xB0+i,CMD); //设置行起始地址
     WR_Byte(0x00,CMD);   //设置低列起始地址
     WR_Byte(0x10,CMD);   //设置高列起始地址
     for(n=0;n<128;n++)
     WR_Byte(GRAM[n][i],1);
  }
}
void OLED12864::Update_NeiRong()
{
  uint8_t i,n;
  for(i=2;i<6;i++)
  {
     WR_Byte(0xB0+i,CMD); //设置行起始地址
     WR_Byte(0x00,CMD);   //设置低列起始地址
     WR_Byte(0x10,CMD);   //设置高列起始地址
     for(n=0;n<128;n++)
     WR_Byte(GRAM[n][i],1);
  }
}
void OLED12864::Clear_NeiRong()
{
  uint8_t i,n;
  for(i=2;i<6;i++)
  {
     for(n=0;n<128;n++)
     {
       GRAM[n][i]=0;//清除所有数据
      }
  }
  Update_NeiRong();//更新显示
}
//清屏函数
void OLED12864::Clear()
{
  uint8_t i,n;
  for(i=0;i<8;i++)
  {
     for(n=0;n<128;n++)
     {
       GRAM[n][i]=0;//清除所有数据
      }
  }
  Refresh();//更新显示
}

//画点 
//x:0~127
//y:0~63
void OLED12864::DrawPoint(uint8_t x,uint8_t y)
{
  uint8_t i,m,n;
  i=y/8;
  m=y%8;
  n=1<<m;
  GRAM[x][i]|=n;
}

//清除一个点
//x:0~127
//y:0~63
void OLED12864::ClearPoint(uint8_t x,uint8_t y)
{
  uint8_t i,m,n;
  i=y/8;
  m=y%8;
  n=1<<m;
  GRAM[x][i]=~GRAM[x][i];
  GRAM[x][i]|=n;
  GRAM[x][i]=~GRAM[x][i];
}

//画线
//x:0~128
//y:0~64
void OLED12864::DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2)
{
  uint8_t i,k,k1,k2,y0;
  if(x1==x2)    //画竖线
  {
      for(i=0;i<(y2-y1);i++)
      {
        DrawPoint(x1,y1+i);
      }
  }
  else if(y1==y2)   //画横线
  {
      for(i=0;i<(x2-x1);i++)
      {
        DrawPoint(x1+i,y1);
      }
  }
  else      //画斜线
  {
    k1=y2-y1;
    k2=x2-x1;
    k=k1*10/k2;
    for(i=0;i<(x2-x1);i++)
      {
        DrawPoint(x1+i,y1+i*k/10);
      }
  }
}
//发送一个字节
//向SSD1306写入一个字节。
//mode:数据/命令标志 0,表示命令;1,表示数据;
void OLED12864::WR_Byte(uint8_t dat,uint8_t mode)
{
  I2C_QiShiXinHao();
  Send_Byte(0x78);
  I2C_WaitAck();
  if(mode){Send_Byte(0x40);}
  else{Send_Byte(0x00);}
  I2C_WaitAck();
  Send_Byte(dat);
  I2C_WaitAck();
  I2C_JieShuXinHao();
}
//OLED初始化
void OLED12864::Init(void)
{
  pinMode(8,OUTPUT);//设置数字8
  pinMode(9,OUTPUT);//设置数字9
  RST_Set();
  delay(100);
  RST_Clr();//复位
  delay(200);
  RST_Set();
  
  WR_Byte(0xAE,CMD);//--turn off oled panel
  WR_Byte(0x00,CMD);//---set low column address
  WR_Byte(0x10,CMD);//---set high column address
  WR_Byte(0x40,CMD);//--set QiShiXinHao line address  Set Mapping RAM Display QiShiXinHao Line (0x00~0x3F)
  WR_Byte(0x81,CMD);//--set contrast control register
  WR_Byte(0xCF,CMD);// Set SEG Output Current Brightness
  WR_Byte(0xA1,CMD);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
  WR_Byte(0xC8,CMD);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
  WR_Byte(0xA6,CMD);//--set normal display
  WR_Byte(0xA8,CMD);//--set multiplex ratio(1 to 64)
  WR_Byte(0x3f,CMD);//--1/64 duty
  WR_Byte(0xD3,CMD);//-set display offset Shift Mapping RAM Counter (0x00~0x3F)
  WR_Byte(0x00,CMD);//-not offset
  WR_Byte(0xd5,CMD);//--set display clock divide ratio/oscillator frequency
  WR_Byte(0x80,CMD);//--set divide ratio, Set Clock as 100 Frames/Sec
  WR_Byte(0xD9,CMD);//--set pre-charge period
  WR_Byte(0xF1,CMD);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
  WR_Byte(0xDA,CMD);//--set com pins hardware configuration
  WR_Byte(0x12,CMD);
  WR_Byte(0xDB,CMD);//--set vcomh
  WR_Byte(0x40,CMD);//Set VCOM Deselect Level
  WR_Byte(0x20,CMD);//-Set Page Addressing Mode (0x00/0x01/0x02)
  WR_Byte(0x02,CMD);//
  WR_Byte(0x8D,CMD);//--set Charge Pump enable/disable
  WR_Byte(0x14,CMD);//--set(0x10) disable
  WR_Byte(0xA4,CMD);// Disable Entire Display On (0xa4/0xa5)
  WR_Byte(0xA6,CMD);// Disable Inverse Display On (0xa6/a7) 
  WR_Byte(0xAF,CMD);
  Clear();
}
//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//size:选择字体 12/16/24
//取模方式 逐列式
void OLED12864::ShowChar(uint8_t x,uint8_t y,const char chr,uint8_t size1)
{
  uint8_t i,m,temp,size2,chr1;
  uint8_t y0=y;
  size2=(size1/8+((size1%8)?1:0))*(size1/2);  //得到字体一个字符对应点阵集所占的字节数
  chr1=chr-' ';  //计算偏移后的值
  for(i=0;i<size2;i++)
  {
    if(size1==12)
        { 
          temp=pgm_read_byte(&asc2_1206[chr1][i]);
        } //调用1206字体
    else if(size1==16)
        {
          temp=pgm_read_byte(&asc2_1608[chr1][i]);
        } //调用1608字体
    else if(size1==24)
        {
          temp=pgm_read_byte(&asc2_2412[chr1][i]);
        } //调用2412字体
    else return;
        for(m=0;m<8;m++)           //写入数据
        {
          if(temp&0x80)DrawPoint(x,y);
          else ClearPoint(x,y);
          temp<<=1;
          y++;
          if((y-y0)==size1)
          {
            y=y0;
            x++;
            break;
          }
        }
  }
}
void OLED12864::ShowStringzu(uint8_t x,uint8_t y,String a,uint8_t size1)
{
  for(int i=0;i<a.length();i++)
  {
    x+=size1/2;
    ShowChar(x,y,a[i],size1);
    if(x>128-size1/2)  //换行
      return;
  }
}

//显示字符串
//x,y:起点坐标  
//size1:字体大小 
//*chr:字符串起始地址 
void OLED12864::ShowString(uint8_t x,uint8_t y,const char *chr,uint8_t size1)
{
  while((*chr>=' ')&&(*chr<='~'))//判断是不是非法字符!
  {
    ShowChar(x,y,*chr,size1);
    x+=size1/2;
    if(x>128-size1/2)  //换行
    {
      x=0;
      y+=size1;
    }
    chr++;
  }
}

//m^n
int OLED12864::Pow(uint8_t m,uint8_t n)
{
  int result=1;
  while(n--)
  {
    result*=m;
  }
  return result;
}

////显示2个数字
////x,y :起点坐标  
////len :数字的位数
////size:字体大小
void OLED12864::ShowNum(uint8_t x,uint8_t y,int num,uint8_t len,uint8_t size1)
{
  uint8_t t,temp;
  for(t=0;t<len;t++)
  {
    temp=(num/Pow(10,len-t-1))%10;
      if(temp==0)
      {
        ShowChar(x+(size1/2)*t,y,'0',size1);
      }
      else 
      {
        ShowChar(x+(size1/2)*t,y,temp+'0',size1);
      }
  }
}

//显示汉字
//x,y:起点坐标
//num:汉字对应的序号
//取模方式 列行式
void OLED12864::ShowChinese(uint8_t x,uint8_t y,const uint8_t num,uint8_t size1)
{
  uint8_t i,m,n=0,temp,chr1;
  uint8_t x0=x,y0=y;
  uint8_t size3=size1/8;
  while(size3--)
  {
    chr1=num*size1/8+n;
    n++;
      for(i=0;i<size1;i++)
      {
        if(size1==16)
            {temp=pgm_read_byte(&Hzk1[chr1][i]);}//调用16*16字体
        else if(size1==24)
            {temp=pgm_read_byte(&Hzk2[chr1][i]);}//调用24*24字体
        else if(size1==32)       
            {temp=pgm_read_byte(&Hzk3[chr1][i]);}//调用32*32字体
        else if(size1==64)
            {temp=pgm_read_byte(&Hzk4[chr1][i]);}//调用64*64字体
        else return;
              
            for(m=0;m<8;m++)
              {
                if(temp&0x01)DrawPoint(x,y);
                else ClearPoint(x,y);
                temp>>=1;
                y++;
              }
              x++;
              if((x-x0)==size1)
              {x=x0;y0=y0+8;}
              y=y0;
       }
  }
}

//配置写入数据的起始位置
void OLED12864::WR_BP(uint8_t x,uint8_t y)
{
  WR_Byte(0xb0+y,CMD);//设置行起始地址
  WR_Byte(((x&0xf0)>>4)|0x10,CMD);
  WR_Byte((x&0x0f),CMD);
}

//x0,y0：起点坐标
//x1,y1：终点坐标
//BMP[]：要写入的图片数组
void OLED12864::ShowPicture(uint8_t x0,uint8_t y0,uint8_t x1,uint8_t y1,const uint8_t BMP[])
{
  int j=0;
  uint8_t t;
  uint8_t x,y;
  for(y=y0;y<y1;y++)
   {
     WR_BP(x0,y);
     for(x=x0;x<x1;x++)
     {
       t=pgm_read_byte(&BMP[j++]);
       WR_Byte(t,DATA);
     }
   }
}
