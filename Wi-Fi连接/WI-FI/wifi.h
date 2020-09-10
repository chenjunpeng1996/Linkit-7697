#ifndef _WIFI_H__
#define _WIFI_H__
//导入Arduino核心头文件
#include"Arduino.h"
class WIFI
{
    private:
    public:
        String printEncryptionType(int thisType);
        String* listNetworks();
        void printMacAddress();
        void Init();
        String to_String(int n);
};
#endif
