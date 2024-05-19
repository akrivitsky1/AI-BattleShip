//void BattleShip::AI_Player::place_AI_ships_once(std::minstd_rand& generator1,std::default_random_engine generator2, std::map<std::string, int> temp_map, int num)
// Created by Ryan Fouzdar on 5/14/22.
//

#ifndef BATTLESHIP_AI_PLAYER_H
#define BATTLESHIP_AI_PLAYER_H
#include "RegularBoard.h"
#include "Player.h"
#include "FiringBoard.h"
#include <random>

namespace BattleShip{
    class AI_Player : public BattleShip::Player {
    public:
        /*virtual*/ void place_AI_ships_once(const std::map<std::string, int> &temp_map, int num);
        /*virtual*/ int minstd_get_random_int(int min, int max);
        /*virtual*/ void place_ships() override;
        static std::mt19937 generator;
        AI_Player(int row, int col,std::map <std::string, int> type_of_ships) : Player(row, col,type_of_ships),AI_Firing_Board(row,col) {}
        virtual void hit_ships(Player &Enemy) = 0;
        FiringBoard AI_Firing_Board;
    };

}



#endif //BATTLESHIP_AI_PLAYER_H
