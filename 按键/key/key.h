#ifndef _KEY_H__
#define _KEY_H__
//导入Arduino核心头文件
#include"Arduino.h"
class KEY
{
    private:
    public:
        int Get_Key_Value(int address0, int address1, int address2);
        long long Button_z_s(int wei, long long dangqianzhi);
        long long Button_z_x(int wei, long long dangqianzhi);
        long long Button_z_z(int wei, long long dangqianzhi);
        long long Button_z_y(int wei, long long dangqianzhi);
};
#endif