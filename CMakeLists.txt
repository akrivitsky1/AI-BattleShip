cmake_minimum_required(VERSION 3.5)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp FiringBoard.cpp FiringBoard.h RegularBoard.cpp RegularBoard.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h AI_Player.cpp AI_Player.h Cheating_AI.cpp Cheating_AI.h Random_AI.cpp Random_AI.h Search_Destroy_AI.cpp Search_Destroy_AI.h)
