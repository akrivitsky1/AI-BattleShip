#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <chrono>
#include "Player.h"
#include "HumanPlayer.h"
#include "Cheating_AI.h"
#include "Random_AI.h"
#include "Search_Destroy_AI.h"

std::mt19937 BattleShip::AI_Player::generator;
int main(int argc, char** argv) {
    std::ifstream file(argv[1]); //Getting file input
    int num_rows;
    int num_cols;
    int num_ships;
    file >> num_rows;
    file >> num_cols;
    file >> num_ships;
    std::map <std::string, int> ship_info;
    std::string temp_str;
    int temp_size;
    for(int i = 0; i < num_ships; i++) {
        file >> temp_str;
        file >> temp_size;
        ship_info[temp_str] = temp_size;
    }
    int seed_num = std::chrono::system_clock::now().time_since_epoch().count();
    if(argc >= 3){
        seed_num = atoi(argv[2]);
    }
    int user_choice = -1;
    BattleShip::AI_Player::generator.seed(seed_num);
    while(!(user_choice == 1 || user_choice == 2 || user_choice == 3)){
        std::cout << "What type of game do you want to play?" << std::endl << "1. Human vs Human\n" << "2. Human vs AI\n" << "3. AI vs AI" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> user_choice;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    BattleShip::Player* one = nullptr;
    BattleShip::Player* two = nullptr;

    if(user_choice == 1){
        one = BattleShip::make_player(1,num_rows,num_cols,ship_info); //Instances to the boards and player
        one->place_ships();
        two = BattleShip::make_player(2,num_rows,num_cols,ship_info);
        two->place_ships();
    }else if(user_choice == 2){
        int ai_num = -1;
        one = BattleShip::make_player(1,num_rows,num_cols,ship_info); //Instances to the boards and player
        one->place_ships();
        while(!(ai_num == 1 || ai_num == 2 || ai_num == 3)){
            std::cout << "What AI do you want?\n" << "1. Cheating AI\n" << "2. Random AI\n" << "3. Hunt Destroy AI" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> ai_num;
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        switch(ai_num){
            case 1:
                two = new BattleShip::Cheating_AI(num_rows,num_cols,ship_info);
                break;
            case 2:
                two = new BattleShip::Random_AI(num_rows,num_cols,ship_info);
                break;
            case 3:
                two = new BattleShip::Search_Destroy_AI(num_rows,num_cols,ship_info);
        }
        two->set_player_name("AI 1");
        two->place_ships();

    }else if(user_choice == 3){
        int ai_num = -1;
        while(!(ai_num == 1 || ai_num == 2 || ai_num == 3)){
            std::cout << "What AI do you want?\n" << "1. Cheating AI\n" << "2. Random AI\n" << "3. Hunt Destroy AI" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> ai_num;
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        switch(ai_num){
            case 1:
                one = new BattleShip::Cheating_AI(num_rows,num_cols,ship_info);
                break;
            case 2:
                one = new BattleShip::Random_AI(num_rows,num_cols,ship_info);
                break;
            case 3:
                one = new BattleShip::Search_Destroy_AI(num_rows,num_cols,ship_info);
        }
        one -> set_player_name("AI 1");
        one -> place_ships();
        ai_num = -1;
        while(!(ai_num == 1 || ai_num == 2 || ai_num == 3)){
            std::cout << "What AI do you want?\n" << "1. Cheating AI\n" << "2. Random AI\n" << "3. Hunt Destroy AI" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> ai_num;
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        switch(ai_num){
            case 1:
                two = new BattleShip::Cheating_AI(num_rows,num_cols,ship_info);
                break;
            case 2:
                two = new BattleShip::Random_AI(num_rows,num_cols,ship_info);
                break;
            case 3:
                two = new BattleShip::Search_Destroy_AI(num_rows,num_cols,ship_info);
        }
        two->set_player_name("AI 2");
        two->place_ships();
    }
    //std::cout << "Game Start";
    while(true) {  //win condition
        one->hit_ships(*two);
        if (check_win(*two)) {
            std::cout << "\n";
            std::cout << one->getPlayerName() << " won the game!" << std::endl;
            break;
        }
        two->hit_ships( *one);
        if (check_win( *one)) {
            std::cout << "\n";
            std::cout << two->getPlayerName() << " won the game!" << std::endl;
            break;
        }
    }
    delete one;
    delete two;
    return 0;
}
