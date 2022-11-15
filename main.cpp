#include <iostream>

class Grid{
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

        // Compute movement
        void moveGrid(int input){
            if((input > 0) && (input < 10)){
                crossPos[input - 1] = true;
                drawGrid();
            }else{
                std::cout << "Invalid move - please enter a number between 1 and 9" << std::endl;
                getGridMovement();
            }
        }

        // Get grid movement
        void getGridMovement(){
            static int move;
            std::cout << "X plays" << std::endl;
            std::cin >> move;
            moveGrid(move);
        }

        // Winning condition
        bool isRunning(){
            if(crossPos[0] == true && crossPos[1] == true && crossPos[2] == true){
                return false;
            }
            if(crossPos[0] == true && crossPos[3] == true && crossPos[6] == true){
                return false;
            }
            if(crossPos[0] == true && crossPos[4] == true && crossPos[8] == true){
                return false;
            }
            if(crossPos[1] == true && crossPos[4] == true && crossPos[7] == true){
                return false;
            }
            if(crossPos[2] == true && crossPos[4] == true && crossPos[6] == true){
                return false;
            }
            if(crossPos[3] == true && crossPos[4] == true && crossPos[5] == true){
                return false;
            }
            if(crossPos[2] == true && crossPos[5] == true && crossPos[8] == true){
                return false;
            }
            return true;
        }
};

int main(){
    Grid grid;
    grid.drawGrid();
    while(grid.isRunning()){
        grid.getGridMovement();
    }
    std::cout << "Cross wins!" << std::endl;
    return 0;
}