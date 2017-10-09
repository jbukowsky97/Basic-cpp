#ifndef CONCERT_H
#define CONCERT_H

#include <string>
#include <vector>
#include <ctime>
#include <iostream>

/**********************
 * Class defined by homework for CIS 343
 **********************/
class Concert {
    public:
        /* default constructor */
        Concert();
        
        /* constructor to set all private vars */
        Concert(std::string c, std::vector<std::string> f, int des, std::tm d);

        /* < operator for comparison of Concert objects */
        bool operator<(const Concert & other) const;

        /* definition for printing object as string */
        friend std::ostream& operator<<(std::ostream& os, const Concert& c);
    private:

        /* name of concert */
        std::string concertName;

        /* list of friends attending concert */
        std::vector<std::string> friends;

        /* value 1-10 depicting desire to go */
        int desire;

        /* date and time of concert */
        std::tm date;
};

#endif