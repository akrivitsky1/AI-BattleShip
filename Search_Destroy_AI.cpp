//
// Created by Ryan Fouzdar on 5/15/22.
//

#include "Search_Destroy_AI.h"
#include <algorithm>
#include <iostream>
void BattleShip::Search_Destroy_AI::hit_ships(Player &Enemy) {
    //Add the arguments for hit_AI_ship, going to need the other AI_board and whatever human board
    int firing_position;
    int row_fired = -1;
    int col_fired = -1;
    if(firing_coordinates.empty()){
        for(int i = 0; i < Enemy.Board.num_rows; i++){
            for(int j = 0; j < Enemy.Board.num_cols; j++){
                firing_coordinates.push_back(Coordinate(i,j));
            }
        }
    }
    if(destroy_ai.empty()) {
        firing_position = BattleShip::AI_Player::minstd_get_random_int(0, firing_coordinates.size() - 1);
        row_fired = firing_coordinates.at(firing_position).x;
        col_fired = firing_coordinates.at(firing_position).y;
    }else {

        Coordinate remove_cord = destroy_ai.front();
        destroy_ai.pop();
        row_fired = remove_cord.x;
        col_fired = remove_cord.y;
    }
    if (Enemy.Board.getBoardValue(row_fired, col_fired) != "*") {
        std::string value = Enemy.Board.getBoardValue(row_fired, col_fired);
        AI_Firing_Board.setBoardValue(row_fired, col_fired, "X");
        Enemy.Board.setBoardValue(row_fired, col_fired, "X");
        std::cout << this->getPlayerName() << "'s Firing Board" << std::endl;
        AI_Firing_Board.print_board();
        std::cout << "\n\n";
        std::cout << this->getPlayerName() << "'s Placement Board" << std::endl;
        this->Board.print_board();
        std::cout << this->getPlayerName() << " hit " << Enemy.getPlayerName() << "'s " << value << "!" << std::endl;
        Coordinate cords[4] = {Coordinate(row_fired, col_fired-1), Coordinate(row_fired-1, col_fired ),
                               Coordinate(row_fired , col_fired+1), Coordinate(row_fired+1, col_fired)};
        int j;
        for (int i = 0; i < 4; i++) {
            for (j = 0; j < firing_coordinates.size(); j++) {
                if (cords[i].x == firing_coordinates[j].x && cords[i].y == firing_coordinates[j].y) {
                    destroy_ai.push(cords[i]);
                    break;
                }
            }
            if(cords[i].x == firing_coordinates[j].x && cords[i].y == firing_coordinates[j].y){
                firing_coordinates.erase(firing_coordinates.begin() + j);
            }
        }
        Enemy.Board.setBoardValue(row_fired, col_fired, "X");
        bool destroyed = true;
        for (int i = 0; i < Enemy.Board.num_rows; i++) {
            for (int j = 0; j < Enemy.Board.num_cols; j++) {
                if (Enemy.Board.getBoardValue(i, j) == value) {
                    destroyed = false;
                }
            }
        }
        if (destroyed) {
            std::cout << this->getPlayerName() << " destroyed " << Enemy.getPlayerName() << "'s "
                      << value << "!" << std::endl;
        }
    } else {
        AI_Firing_Board.setBoardValue(row_fired, col_fired, "O");
        Enemy.Board.setBoardValue(row_fired, col_fired, "O");
        std::cout << this->getPlayerName() << "'s Firing Board" << std::endl;
        AI_Firing_Board.print_board();
        std::cout << "\n\n";
        std::cout << this->getPlayerName() << "'s Placement Board" << std::endl;
        this->Board.print_board();
        std::cout << "Missed." << std::endl;
    }

}

