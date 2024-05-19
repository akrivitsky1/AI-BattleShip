//
// Created by Ryan Fouzdar on 5/14/22.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include "Player.h"
#include "FiringBoard.h"

namespace BattleShip{
    class HumanPlayer : public BattleShip::Player {
    public:
        void hit_ships(Player& Enemy) override;
        HumanPlayer(int row, int col,std::map <std::string, int> type_of_ships, std::string name) : Player(row, col, type_of_ships), fb(row,col) {
            set_player_name(name);
        }
        void place_ships();
    private:
        FiringBoard fb;

    };
     HumanPlayer* make_player(int player_num,int row, int col,std::map <std::string, int> type_of_ships);
}



#endif //BATTLESHIP_HUMANPLAYER_H
