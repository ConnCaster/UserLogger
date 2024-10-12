#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>

struct Date{
    std::string m_month;
    unsigned short m_day;
    unsigned short m_hour;
    unsigned short m_minutes;
    struct Duration{
        unsigned short m_day;
        unsigned short m_hour;
        unsigned short m_minutes;
        Duration(const std::string &str);
        Duration()=default;
    } duration;
    Date(const std::string &str);
    Date()=default;

};

class LogSession{
private:
    std::string m_username;
    std::string m_tty_name;
    std::string m_hostname;
    Date m_date_params;

public:
    LogSession(const std::string &str);

};