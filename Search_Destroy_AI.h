//
// Created by Ryan Fouzdar on 5/15/22.
//

#ifndef BATTLESHIP_SEARCH_DESTROY_AI_H
#define BATTLESHIP_SEARCH_DESTROY_AI_H
#include "Random_AI.h"
#include <queue>
namespace BattleShip{
    class Search_Destroy_AI : public BattleShip::Random_AI {

    public:
        Search_Destroy_AI(int row, int col,std::map <std::string, int> type_of_ships) : BattleShip::Random_AI(row, col,type_of_ships){}
        void hit_ships(Player &Enemy) override;
    private:
        std::queue <Random_AI::Coordinate> destroy_ai;
    };

}



#endif //BATTLESHIP_SEARCH_DESTROY_AI_H
