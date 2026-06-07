#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

class Game {

private:
    std::string title;
    std::string shortDescription;
    int popularity;

public:

    Game();
    Game(std::string title, std::string shortDescription, int popularity);
    ~Game();

    std::string getTitle();
    std::string getShortDescription();
    int getPopularity();
    std::string toPrintable();
};

#endif