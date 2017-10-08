#include "Concert.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stdlib.h>

int main() {
    //std::time_t t = 0;
    //std::time(&t);
    //std::tm date = *std::localtime(&t);
    srand(time(NULL));
    std::string first[] {"Tomato", "Dog", "Cat", "Fruity", "Squad", "Roll", "Apple", "Frog", "Yellow", "Curved"};
    std::string last[] {"Pickles", "Fish", "Laundry", "Pencils", "Pictures", "Tissues", "Lights", "Umbrella", "Fire", "Oranges"};
    std::string people[] {"Jonah", "Jon", "Sarah", "Joey", "Patrick", "Emily", "Megan", "Michaela", "Jenna", "Alex", "Bob", "Frank", "Wesley", "Jessica", "Allison", "Taylor"};
    std::vector<Concert> concerts(100);
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 10; k++) {
            std::time_t t = rand() % 1000000000 + 500000000;
            int friendCount = rand() % 11;
            std::vector<std::string> f(friendCount);
            for (int j = 0; j < friendCount; j++) {
                f[j] = people[rand() % 16];
            }
            concerts[i * 10 + k] = Concert(first[i] + " " + last[k], f, rand() % 10 + 1, *std::localtime(&t));
        }
    }
    std::sort(concerts.begin(), concerts.end());
    std::cout << "Concert Name\t\tMM/DD/YYYY\tHH:MM:SS\tDesire\tFriends" << std::endl << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << concerts[i] << std::endl;
    }
    return 0;
}