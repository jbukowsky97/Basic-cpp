#ifndef CONCERT_H
#define CONCERT_H

#include <string>
#include <vector>
#include <ctime>
#include <iostream>

class Concert {
    public:
        Concert();
        
        Concert(std::string c, std::vector<std::string> f, int des, std::tm d);

        bool operator<(const Concert & other) const;

        friend std::ostream& operator<<(std::ostream& os, const Concert& c);
    private:

        std::string concertName;

        std::vector<std::string> friends;

        int desire;

        std::tm date;
};

#endif