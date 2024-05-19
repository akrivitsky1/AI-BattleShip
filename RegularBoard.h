//
// Created by Ryan Fouzdar on 5/2/22.
//

#ifndef BATTLESHIP_REGULARBOARD_H
#define BATTLESHIP_REGULARBOARD_H
#include <vector>
#include <map>
#include <string>

namespace BattleShip{
    class RegularBoard {
    public:
        void print_board() const;
        void input_validation(const std::string player1, int num);
        void place_ships(const std::string player1);
        RegularBoard(int num_row, int num_col, std::map <std::string, int> type_of_ships);
        std::string getBoardValue(int row, int col) const;
        void setBoardValue(int rows, int cols, std::string value);
        std::map<std::string, int> getTypesOfShips();
        const int num_rows;
        const int num_cols;


    protected:
        std::vector <std::vector<std::string>> board;
        std::map <std::string, int> types_of_ships;

    };
    std::string get_valid_string(const std::string& prompt);
}


#endif //BATTLESHIP_REGULARBOARD_H
