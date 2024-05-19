//
// Created by Ryan Fouzdar on 5/15/22.
//
#include <iostream>
#include <vector>
#include <string>
#include "Random_AI.h"
#include "FiringBoard.h"
#include "AI_Player.h"


void BattleShip::Random_AI::hit_ships(Player& Enemy) {
    //Add the arguments for hit_AI_ship, going to need the other Board and whatever human board
    int firing_position;
    if(firing_coordinates.empty()){
        for(int i = 0; i < Enemy.Board.num_rows; i++){
            for(int j = 0; j < Enemy.Board.num_cols; j++){
                firing_coordinates.push_back(Coordinate(i,j));
            }
        }
    }
    firing_position = BattleShip::AI_Player::minstd_get_random_int(0, firing_coordinates.size() - 1);
    int row_fired = firing_coordinates.at(firing_position).x;
    int col_fired = firing_coordinates.at(firing_position).y;
    firing_coordinates.erase(firing_coordinates.begin() + firing_position);
    if(Enemy.Board.getBoardValue(row_fired, col_fired) != "*"){
        std::string value = Enemy.Board.getBoardValue(row_fired, col_fired);
        AI_Firing_Board.setBoardValue(row_fired, col_fired, "X");
        Enemy.Board.setBoardValue(row_fired,col_fired, "X");
        std::cout << this->getPlayerName() << "'s Firing Board" << std::endl;
        AI_Firing_Board.print_board();
        std::cout << "\n\n";
        std::cout << this->getPlayerName() << "'s Placement Board" << std::endl;
        this->Board.print_board();
        std::cout << this->getPlayerName() << " hit " << Enemy.getPlayerName() << "'s " << value << "!" << std::endl;
        Enemy.Board.setBoardValue(row_fired,col_fired, "X");
        bool destroyed = true;
        for(int i = 0; i  < Board.num_rows; i++) {
            for(int j = 0; j < Board.num_cols; j++) {
                if(Enemy.Board.getBoardValue(i,j) == value){
                    destroyed = false;
                }
            }
        }
        if(destroyed){
            std::cout << this->getPlayerName() << " destroyed " << Enemy.getPlayerName() << "'s " << value << "!" << std::endl;
        }

    } else {
        AI_Firing_Board.setBoardValue(row_fired, col_fired, "O");
        Enemy.Board.setBoardValue(row_fired,col_fired, "O");
        std::cout << this->getPlayerName() << "'s Firing Board" << std::endl;
        AI_Firing_Board.print_board();
        std::cout << "\n\n";
        std::cout << this->getPlayerName() << "'s Placement Board" << std::endl;
        this->Board.print_board();
        std::cout << "Missed." << std::endl;

    }
}

