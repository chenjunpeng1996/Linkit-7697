#ifndef _OLED12864_H__
#define _OLED12864_H__

#define SCLK_Clr() digitalWrite(8,LOW)//SCL
#define SCLK_Set() digitalWrite(8,HIGH)

#define SDIN_Clr() digitalWrite(9,LOW)//SDA
#define SDIN_Set() digitalWrite(9,HIGH)

#define RST_Clr() digitalWrite(10,LOW)//RES   注：此引脚是为了配合SPI驱动模块改成I2C驱动模块使用的（改装的话必须接），如果买的是I2C模块，请忽略此引脚。
#define RST_Set() digitalWrite(10,HIGH)

#define CMD  0  //写命令
#define DATA 1 //写数据

//导入Arduino核心头文件
#include"Arduino.h"
#include"font.h"
class OLED12864
{
    private:
        byte SCL;
        byte SDA;
        byte pin;
        uint8_t GRAM[128][16];//将要显示的缓存内容
    public:
        OLED12864();
        void I2C_QiShiXinHao();
        void I2C_JieShuXinHao();
        void I2C_WaitAck(); //测数据信号的电平
        void Send_Byte(uint8_t dat);
        void Refresh();
        void Update_DingLan();
        void Update_DiLan();
        void Update_NeiRong();
        void Clear_NeiRong();
        void Clear();
        void DrawPoint(uint8_t x,uint8_t y);
        void ClearPoint(uint8_t x,uint8_t y);
        void DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2);
        void WR_Byte(uint8_t dat,uint8_t mode);
        void Init();
        void ShowChar(uint8_t x,uint8_t y,const char chr,uint8_t size1);
        void ShowStringzu(uint8_t x,uint8_t y,String a,uint8_t size1);
        void ShowString(uint8_t x,uint8_t y,const char *chr,uint8_t size1);
        int Pow(uint8_t m,uint8_t n);
        void ShowNum(uint8_t x,uint8_t y,int num,uint8_t len,uint8_t size1);
        void ShowChinese(uint8_t x,uint8_t y,const uint8_t num,uint8_t size1);
        void WR_BP(uint8_t x,uint8_t y);
        void ShowPicture(uint8_t x0,uint8_t y0,uint8_t x1,uint8_t y1,const uint8_t BMP[]);
    
};
#endif
