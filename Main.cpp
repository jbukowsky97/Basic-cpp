#include "Concert.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stdlib.h>

/**********************
 * Main method to create vector of
 * Concert objects and sort them
 **********************/
int main() {
    //seed random with time
    srand(time(NULL));
    //list of 10 random words for first words of concert names
    std::string first[] {"Tomato", "Dog", "Cat", "Fruity", "Squad", "Roll", "Apple", "Frog", "Yellow", "Curved"};
    //list of 10 random words for last words of concert names
    std::string last[] {"Pickles", "Fish", "Laundry", "Pencils", "Pictures", "Tissues", "Lights", "Umbrella", "Fire", "Oranges"};
    //list of random names for random friend list creation
    std::string people[] {"Jonah", "Jon", "Sarah", "Joey", "Patrick", "Emily", "Megan", "Michaela", "Jenna", "Alex", "Bob", "Frank", "Wesley", "Jessica", "Allison", "Taylor"};
    std::vector<Concert> concerts(100);
    //loop thru first words
    for (int i = 0; i < 10; i++) {
        //loop thru last words for each first word
        for (int k = 0; k < 10; k++) {
            //create a time for concert randomly
            std::time_t t = rand() % 1000000000 + 500000000;
            //create random friend count (0 - 10)
            int friendCount = rand() % 11;
            //create vector with desired friendCount size
            std::vector<std::string> f(friendCount);
            //loop thru friends vector
            for (int j = 0; j < friendCount; j++) {
                //assign friend as random name from people list
                f[j] = people[rand() % 16];
            }
            //create Concert object at desired index in concerts
            //with parameters required for desired constructor
            concerts[i * 10 + k] = Concert(first[i] + " " + last[k], f, rand() % 10 + 1, *std::localtime(&t));
        }
    }
    //sort the concerts
    std::sort(concerts.begin(), concerts.end());
    //print out line defining each column
    std::cout << "Concert Name\t\tMM/DD/YYYY\tHH:MM:SS\tDesire\tFriends" << std::endl << std::endl;
    //loop thru Concert objects in concerts and print them
    for (int i = 0; i < 100; i++) {
        std::cout << concerts[i] << std::endl;
    }
    //successfully terminate program
    return 0;
}