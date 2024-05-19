#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <map>
#include "Player.h"
#include "RegularBoard.h"
#include "FiringBoard.h"
#include <limits>

void BattleShip::FiringBoard::print_board() const { //prints board
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

void BattleShip::FiringBoard::hit_ship(Player const& player1, RegularBoard const& Board1, RegularBoard& Board2, Player const& player2) {
    //check to see if it hits a ship
    //updates ship with character based on if it hits ship or not
    //prints board
    int row_selected;
    int col_selected;
    std::cout << player1.getPlayerName() << "'s Firing Board" << std::endl;
    print_board();
    std::cout << player1.getPlayerName() << "'s Placement Board" << std::endl;
    Board1.print_board();
    std::vector<int> values = FiringBoard::input_validation(player1, Board1);
    row_selected = values.at(0);
    col_selected = values.at(1);
    if(Board2.getBoardValue(row_selected, col_selected) !=  "*"){
        board[row_selected][col_selected] = "X";
        std::cout << player1.getPlayerName() << "'s Firing Board" << std::endl;
        print_board();
        std::cout << player1.getPlayerName() << "'s Placement Board" << std::endl;
        Board1.print_board();
        std::cout << player1.getPlayerName() << " hit " << player2.getPlayerName() << "'s "
                  << Board2.getBoardValue(row_selected, col_selected) << "!" <<std::endl;
        std::string ship_name = Board2.getBoardValue(row_selected, col_selected);
        Board2.setBoardValue(row_selected, col_selected, "X");
        bool destroyed = true;
        for(int i = 0; i  < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(Board2.getBoardValue(i,j) == ship_name){
                    destroyed = false;
                }
            }
        }
        if(destroyed){
            std::cout << player1.getPlayerName() << " destroyed " << player2.getPlayerName() << "'s " << ship_name << "!" << std::endl;
        }
    } else {
        Board2.setBoardValue(row_selected, col_selected, "O");
        board[row_selected][col_selected] = "O";
        std::cout << player1.getPlayerName() << "'s Firing Board" << std::endl;
        print_board();
        std::cout << player1.getPlayerName() << "'s Placement Board" << std::endl;
        Board1.print_board();
        std::cout << "Missed." << std::endl;
    }
}

BattleShip::FiringBoard::FiringBoard(int num_row, int num_col) { //constructor
    num_rows = num_row;
    num_cols = num_col;
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

std::vector<int> BattleShip::FiringBoard::input_validation(Player const& player1,RegularBoard const& Board1) { //valid input of firing coordinates
    bool input = true;
    int row, col;
    std::vector<int> values;
    while(input){
        std::cout << player1.getPlayerName() << ", where would you like to fire?\nEnter your attack coordinate in the form row col: ";
        std::cin >> row >> col;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if((row) > -1 && col > -1 && row < num_rows && col < num_cols){
            if(board[row][col] == "*"){
                values.push_back(row);
                values.push_back(col);
                input = false;
            }else{
                std::cout << player1.getPlayerName() << "'s Firing Board" << std::endl;
                print_board();

                std::cout << player1.getPlayerName() << "'s Placement Board" << std::endl;
                Board1.print_board();
            }
        }else{
            std::cout << player1.getPlayerName() << "'s Firing Board" << std::endl;
            print_board();

            std::cout << player1.getPlayerName() << "'s Placement Board" << std::endl;
            Board1.print_board();
        }
    }
    return values;
}

std::string BattleShip::FiringBoard::getBoardValue(int i, int j) {
    return board[i][j];
}

void BattleShip::FiringBoard::setBoardValue(int i, int j, std::string board_str) {
    board[i][j] = board_str;
}
