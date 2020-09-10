#ifndef _NTIME_H__
#define _NTIME_H__
//导入Arduino核心头文件
#include <LWiFi.h>
#include <WiFiUdp.h>
#include <ctime>
#include <LRTC.h>
#include <arduino.h>
class NTIME
{
    private:
    public:
        String getNetworkTime();
        unsigned long sendNTPpacket(const char *host);
       // int get_field_from_time_string(const String &time_str, int field_index);
        int get_field_from_time_string(const String &time_str, int field_index);
        String get_time_from_RTC();
};
#endif
