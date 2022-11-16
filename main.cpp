#include <SFML/Graphics.hpp>
#include "GUI/GUI.hpp"
#include <iostream>
#include <conio.h>

class Grid{
    bool crossPlayed = false;

    public:
        bool crossPos[9] = {false, false, false,
                            false, false, false,
                            false, false, false};
        
        bool circlePos[9] = {false, false, false,
                             false, false, false,
                             false, false, false};

        // Draw grid
        void drawGrid(){
            for(int i = 0; i < 9; i++){
                if(crossPos[i] ==  true)
                    std::cout << " X ";
                if(circlePos[i] == true)
                    std::cout << " O ";
                if((crossPos[i] == false) && (circlePos[i] == false))
                    std::cout << " # ";
                if(((i+1) % 3) == 0)
                    std::cout << std::endl;
            }
        }

        // Compute movement for X
        void moveXGrid(int input){
            if((circlePos[input - 1] == true) || (crossPos[input - 1] == true)){
                std::cout << "Invalid move - already played" << std::endl;
                getGridMovement();
            }else if((input > 0) && (input < 10)){
                crossPos[input - 1] = true;
                crossPlayed = true;
                drawGrid();
            }else{
                std::cout << "Invalid move - please enter a number between 1 and 9" << std::endl;
                getGridMovement();
            }
        }

        // Compute movement for X
        void moveOGrid(int input){
            if((circlePos[input - 1] == true) || (crossPos[input - 1] == true)){
                std::cout << "Invalid move - already played" << std::endl;
                getGridMovement();
            }else if((input > 0) && (input < 10)){
                circlePos[input - 1] = true;
                crossPlayed = false;
                drawGrid();
            }else{
                std::cout << "Invalid move - please enter a number between 1 and 9" << std::endl;
                getGridMovement();
            }
        }

        // Get grid movement for X
        void getGridMovement(){
            static int move;
            if(crossPlayed){
                std::cout << " O plays" << std::endl;
                std::cin >> move;
                moveOGrid(move);
            }
            else{
            std::cout << "X plays" << std::endl;
            std::cin >> move;
            moveXGrid(move);
            }
        }

        // Winning condition for X
        bool isCrossWin(){
            if(crossPos[0] == true && crossPos[1] == true && crossPos[2] == true){
                return true;
            }
            if(crossPos[0] == true && crossPos[3] == true && crossPos[6] == true){
                return true;
            }
            if(crossPos[0] == true && crossPos[4] == true && crossPos[8] == true){
                return true;
            }
            if(crossPos[1] == true && crossPos[4] == true && crossPos[7] == true){
                return true;
            }
            if(crossPos[2] == true && crossPos[4] == true && crossPos[6] == true){
                return true;
            }
            if(crossPos[3] == true && crossPos[4] == true && crossPos[5] == true){
                return true;
            }
            if(crossPos[2] == true && crossPos[5] == true && crossPos[8] == true){
                return true;
            }
            return false;
        }

        // Winning condition for O
        bool isCircleWin(){
            if(circlePos[0] == true && circlePos[1] == true && circlePos[2] == true){
                return true;
            }
            if(circlePos[0] == true && circlePos[3] == true && circlePos[6] == true){
                return true;
            }
            if(circlePos[0] == true && circlePos[4] == true && circlePos[8] == true){
                return true;
            }
            if(circlePos[1] == true && circlePos[4] == true && circlePos[7] == true){
                return true;
            }
            if(circlePos[2] == true && circlePos[4] == true && circlePos[6] == true){
                return true;
            }
            if(circlePos[3] == true && circlePos[4] == true && circlePos[5] == true){
                return true;
            }
            if(circlePos[2] == true && circlePos[5] == true && circlePos[8] == true){
                return true;
            }
            return false;
        }
};

int main(){
    GUI gui;
    gui.drawGui(300, 300);

    Grid grid;
    grid.drawGrid();

    while((grid.isCrossWin() == false) && (grid.isCircleWin() == false)){
        grid.getGridMovement();
    }
    if(grid.isCrossWin())
        std::cout << "Cross wins!" << std::endl << "Press any key to exit..." << std::endl;
    if(grid.isCircleWin())
        std::cout << "Circle wins!" << std::endl << "Press any key to exit..." << std::endl;
    _getch();
    return 0;
}