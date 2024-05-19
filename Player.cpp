//
// Created by Ryan Fouzdar on 5/2/22.
//
#include <string>
#include "Player.h"



std::string BattleShip::Player::getPlayerName() const  {
    return player_name;
}
void BattleShip::Player::set_player_name(std::string name){
    player_name = name;
}
bool BattleShip::check_win(const Player& Enemy) { //checks who wins
    for(int i = 0; i  < Enemy.Board.num_rows; i++) {
        for(int j = 0; j < Enemy.Board.num_cols; j++) {
            if(Enemy.Board.getBoardValue(i,j) != "*" && Enemy.Board.getBoardValue(i,j)!= "X" && Enemy.Board.getBoardValue(i,j)!= "O"){
               return false;
            }
        }
    }
    return true;
}
