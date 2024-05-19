//
// Created by Ryan Fouzdar on 5/2/22.
//

#ifndef BATTLESHIP_FIRINGBOARD_H
#define BATTLESHIP_FIRINGBOARD_H
#include "RegularBoard.h"
namespace BattleShip{
    class FiringBoard {
    public:
        void print_board() const;
        void hit_ship(Player const& player1, RegularBoard const& Board1, RegularBoard& Board2, Player const& player2);
        std::vector<int> input_validation(Player const& player1,RegularBoard const& Board1 );
        FiringBoard(int num_row, int num_col);
        std::string getBoardValue(int i, int j);
        void setBoardValue(int i, int j, std::string value);


    protected:
        std::vector <std::vector<std::string>> board;
        int num_rows;
        int num_cols;

    };
}



#endif //BATTLESHIP_FIRINGBOARD_H
