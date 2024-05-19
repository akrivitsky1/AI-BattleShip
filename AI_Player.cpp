//
// Created by Ryan Fouzdar on 5/14/22.
//
#include <iostream>
#include <random>
#include <map>
#include <string>
#include <chrono>
#include "AI_Player.h"
#include "RegularBoard.h"
#include "Player.h"

void BattleShip::AI_Player::place_AI_ships_once(const std::map<std::string, int> &temp_map, int num) {
    std::uniform_int_distribution<int> distribution(0,1);
    bool input = true;
    int AI_num_row;
    int AI_num_col;
    int AI_direction;
    auto itr = temp_map.begin();
    std::advance(itr,num);
    auto &temp_map2 = *itr;
    int j = 0;
    int k = 0;
    std::cout << this->getPlayerName() <<  "'s Board\n";
    while(input){
        AI_direction = distribution(BattleShip::AI_Player::generator);
        if(AI_direction == 0){
            AI_num_row = minstd_get_random_int(0, Board.num_rows - 1);
            AI_num_col = minstd_get_random_int(0, Board.num_cols - temp_map2.second);
            for(int i = 0; i < temp_map2.second; i++){
                if(Board.getBoardValue(AI_num_row, AI_num_col + i) != "*"){
                    k = 1;
                }
            }
            if(k != 1){
                for(j = 0; j < temp_map2.second; j++) {
                    Board.setBoardValue(AI_num_row, AI_num_col + j, temp_map2.first);
                }
                j = 0;
                input = false;
            }
            k = 0;
        }
        else{
            AI_num_row = minstd_get_random_int(0, Board.num_rows - temp_map2.second );
            AI_num_col = minstd_get_random_int(0, Board.num_cols - 1);
            for(int i = 0; i < temp_map2.second; i++){
                if(Board.getBoardValue(AI_num_row + i, AI_num_col) != "*"){
                    k = 1;
                }
            }
            if(k != 1){
                for(j = 0; j < temp_map2.second; j++){
                    Board.setBoardValue(AI_num_row + j, AI_num_col, temp_map2.first);
                }
                j = 0;
                input = false;
            }
            k = 0;
        }
    }
    Board.print_board();
    std::cout << "\n";
}



int BattleShip::AI_Player::minstd_get_random_int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    int random_num = dist(BattleShip::AI_Player::generator);
    return random_num;
}

void BattleShip::AI_Player::place_ships() {
    std::map<std::string, int> temp_map;
    temp_map = Board.getTypesOfShips();
    for(int i = 0; i < temp_map.size(); i++){
        place_AI_ships_once(temp_map, i);
    }
}
