//
// Created by Ryan Fouzdar on 5/2/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <map>
#include "Player.h"
#include <limits>
#include <sstream>

#include "RegularBoard.h"

void BattleShip::RegularBoard::print_board() const{ //prints the board
    if(num_rows < 11){
        std::cout << "  ";
        for(int i = 0; i < num_cols; i++){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        for(int i = 0; i < num_rows; i++){
            std::cout << i << " ";
            for(int j = 0; j < num_cols; j++){
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "   ";
        for(int i = 0; i < num_cols; i++){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        for(int i = 0; i < num_rows; i++){
            if(i < 10){
                std::cout << " " << i << " ";
            } else {
                std::cout << i << " ";
            }
            for(int j = 0; j < num_cols; j++){
                if(j < 10){
                    std::cout << board[i][j] << " ";
                } else {
                    std::cout << " " << board[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
    }

}

void BattleShip::RegularBoard::input_validation(const std::string player1, int num) { //checks if the input is valid
    bool input = true;
    int row, col;
    std::string user_input;
    auto itr = types_of_ships.begin();
    std::advance(itr,num);
    auto &temp_map = *itr;
    int j = 0;
    int k = 0;
    while(input){
        user_input = get_valid_string( player1 + ", do you want to place " + temp_map.first + " horizontally or vertically?\nEnter h for horizontal or v for vertical\nYour choice: ");
        for(int i = 0; i < user_input.size(); i++){
            user_input.at(i) = std::tolower(user_input.at(i));
        }
        if(user_input == "h"){
            std::cout << player1 << ", enter the row and column you want to place " << temp_map.first
                      << ", which is " << temp_map.second <<" long, at with a space in between row and col: ";
            std::cin >> row >> col;
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if(row > -1 && col > -1 && row < num_rows && col < num_cols){
                if (col + temp_map.second < num_cols +1){
                    for(int i = 0; i < temp_map.second; i++){
                        if(board[row][col+i] != "*"){
                            k = 1;
                        }
                    }
                    if(k != 1){
                        while(j < temp_map.second){
                            board[row][col +j] = temp_map.first;
                            j++;
                        }
                        j = 0;
                        input = false;
                    }
                    k = 0;
                }
            }
        } else if(user_input == "v"){
            std::cout << player1 << ", enter the row and column you want to place " << temp_map.first
                      << ", which is " << temp_map.second <<" long, at with a space in between row and col: ";
            std::cin >> row >> col;
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if((row) > -1 && col > -1 && row < num_rows && col < num_cols){
                if(row + temp_map.second < num_rows +1){
                    for(int i = 0; i < temp_map.second; i++){
                        if(board[row+i][col] != "*"){
                            k = 1;
                        }
                    }
                    if(k != 1){
                        while(j < temp_map.second){
                            board[row+j][col] = temp_map.first;
                            j++;
                        }
                        j = 0;
                        input = false;
                    }
                    k = 0;
                }
            }
        }

    }
    print_board();

}

void BattleShip::RegularBoard::place_ships(const std::string player1) { //places the ships
    for(int i = 0; i < types_of_ships.size(); i++){
        input_validation(player1, i);
    }

}

BattleShip::RegularBoard::RegularBoard(int num_row, int num_col, std::map<std::string, int> type_of_ships):num_rows(num_row),num_cols(num_col) { //constructor
    types_of_ships = type_of_ships;
    for(int i=0; i< num_rows; i++)
    {
        std::vector <std::string> boardRow;
        for(int j=0; j<num_cols; j++)
        {
            boardRow.push_back("*");
        }
        board.push_back(boardRow);
    }

}

std::string BattleShip::RegularBoard::getBoardValue(int row, int col) const { //returns values
    return board[row][col];
}

void BattleShip::RegularBoard::setBoardValue(int rows, int cols, std::string value) { //sets value
    board[rows][cols] = value;
}

std::map<std::string, int> BattleShip::RegularBoard::getTypesOfShips() {
    return types_of_ships;
}


std::string BattleShip::get_valid_string(const std::string& prompt) { //checks the string
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line); //grabs the entire line
        std::stringstream line2parse(line);
        std::string word;
        line2parse >> word;
        if (line2parse) { //if I was able to read the number
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse) { //if there is nothing left we will fail to read it
                return word;
            }
        }
    }
}

