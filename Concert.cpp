#include "Concert.h"
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>

Concert::Concert()
{
    concertName = "";
    friends = std::vector<std::string>(10);
    desire = 0;
    std::time_t t = 0;
    date = *std::localtime(&t);
}

Concert::Concert(std::string c, std::vector<std::string> f, int des, std::tm d)
{
    concertName = c;
    friends = f;
    desire = des;
    date = d;
}

bool Concert::operator<(const Concert & other) const
{
    //return (date.tm_year < other.date.tm_year);
    if (date.tm_year != other.date.tm_year) {
        return (date.tm_year < other.date.tm_year);
    }else if (date.tm_yday != other.date.tm_yday) {
        return (date.tm_yday < other.date.tm_yday);
    }else {
        long seconds = date.tm_hour * 3600 + date.tm_min * 60 + date.tm_sec;
        long otherSeconds = other.date.tm_hour * 3600 + other.date.tm_min * 60 + other.date.tm_sec;
        if (seconds != otherSeconds) {
            return (seconds < otherSeconds);
        }else {
            return (desire < other.desire);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Concert& c) {
    std::string friendStr = "[";
    for (int i = 0; i < c.friends.size(); i++) {
        friendStr += c.friends[i];
        if (i < c.friends.size() - 1) {
            friendStr += ", ";
        }
    }
    friendStr += "]";
    os << c.concertName << "\t\t" << std::setfill('0') << std::setw(2) << c.date.tm_mon + 1 << "/" << std::setw(2) << c.date.tm_mday << "/" << c.date.tm_year + 1900 << "\t" << std::setw(2) << c.date.tm_hour << ":" << std::setw(2) << c.date.tm_min << ":" << std::setw(2) << c.date.tm_sec << "\t" << c.desire << "\t" << friendStr;
    return os;
}
