//
// Created by Ryan Fouzdar on 5/15/22.
//

#ifndef BATTLESHIP_RANDOM_AI_H
#define BATTLESHIP_RANDOM_AI_H
#include "AI_Player.h"
#include "FiringBoard.h"

namespace BattleShip{
    class Random_AI: public AI_Player {
    public:
        struct Coordinate
        {
            double x, y;
            Coordinate(double x1, double y1) : x(x1), y(y1) {}
        };
        void hit_ships(Player &Enemy) override;
        Random_AI (int row, int col,std::map <std::string, int> type_of_ships) : AI_Player(row, col,type_of_ships){}
    protected:
        std::vector<Coordinate> firing_coordinates;
    };
}



#endif //BATTLESHIP_RANDOM_AI_H
