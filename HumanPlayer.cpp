//
// Created by Ryan Fouzdar on 5/14/22.
//

#include "HumanPlayer.h"
void BattleShip::HumanPlayer::hit_ships(Player& Enemy) {
    fb.hit_ship(*this, this->Board, Enemy.Board, Enemy);

}
void BattleShip::HumanPlayer::place_ships() {
    Board.print_board();
    Board.place_ships(this->getPlayerName());
}
BattleShip::HumanPlayer *BattleShip::make_player(int player_num,int row, int col,std::map <std::string, int> type_of_ships) {  //creates player instances
    std::string player_name;
    player_name = BattleShip::get_valid_string("Player " + std::to_string(player_num) + " please enter your name: ");
    return new BattleShip::HumanPlayer (row,col,type_of_ships, player_name);
}
