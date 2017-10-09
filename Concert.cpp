#include "Concert.h"

#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>

/**********************
 * default constructor
 **********************/
Concert::Concert()
{
    concertName = "";
    friends = std::vector<std::string>(10);
    desire = 0;
    std::time_t t = 0;
    date = *std::localtime(&t);
}

/**********************
 * desired constructor
 * 
 * @param c - concert name
 * @param f - list of friends
 * @param des - desire
 * @param d - date
 **********************/
Concert::Concert(std::string c, std::vector<std::string> f, int des, std::tm d)
{
    concertName = c;
    friends = f;
    desire = des;
    date = d;
}

/**********************
 * < operator for comparison of Concert objects
 * 
 * @param &other - const reference to Concert object
 * 
 * @return boolean - true if this object is less than other
 **********************/
bool Concert::operator<(const Concert & other) const
{
    if (date.tm_year != other.date.tm_year) {
        //years aren't equal, determine if less than
        return (date.tm_year < other.date.tm_year);
    }else if (date.tm_yday != other.date.tm_yday) {
        //days aren't equal, determine if less than
        return (date.tm_yday < other.date.tm_yday);
    }else {
        //add up hours, minutes, seconds into seconds to compare
        long seconds = date.tm_hour * 3600 + date.tm_min * 60 + date.tm_sec;
        long otherSeconds = other.date.tm_hour * 3600 + other.date.tm_min * 60 + other.date.tm_sec;
        if (seconds != otherSeconds) {
            //seconds aren't equal, determine if less than
            return (seconds < otherSeconds);
        }else {
            //times are exactly equal, use desire to
            //determine if less than
            return (desire < other.desire);
        }
    }
}

/**********************
 * define how Concert objects will be printed as strings
 *
 * Desired Format:
 *   Concert Name   MM/DD/YYYY  HH:MM:SS    Desire    Friends (list)
 * 
 * @return std::ostream - information of how to print object
 **********************/
std::ostream& operator<<(std::ostream& os, const Concert& c) {
    std::string friendStr = "[";
    //loop thru friends and add friend to friendStr
    for (int i = 0; i < c.friends.size(); i++) {
        friendStr += c.friends[i];
        //add ", " only when friend is not the last
        //friend in the list
        if (i < c.friends.size() - 1) {
            friendStr += ", ";
        }
    }
    friendStr += "]";
    //produce desired format from Concert object c
    os << c.concertName << "\t\t" << std::setfill('0') << std::setw(2) << c.date.tm_mon + 1 << "/" << std::setw(2) << c.date.tm_mday << "/" << c.date.tm_year + 1900 << "\t" << std::setw(2) << c.date.tm_hour << ":" << std::setw(2) << c.date.tm_min << ":" << std::setw(2) << c.date.tm_sec << "\t" << c.desire << "\t" << friendStr;
    return os;
}
