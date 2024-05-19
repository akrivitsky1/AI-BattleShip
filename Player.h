//
// Created by Ryan Fouzdar on 5/2/22.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H
#include "RegularBoard.h"
namespace BattleShip{
    class Player {
    public:
        std::string getPlayerName() const;
        void set_player_name(std::string name);
        Player(int row, int col,std::map <std::string, int> type_of_ships):Board(row,col, type_of_ships) {}
        RegularBoard Board;
        virtual void hit_ships(Player& Enemy) = 0;
        virtual void place_ships() = 0;
    private:
        std::string player_name;
    };
    bool check_win(const Player& Enemy);
}



#endif //BATTLESHIP_PLAYER_H
