#include <stdio.h>
#include <stdbool.h>

bool checkForWinner = false;

int board[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0}};

int enemyBoard[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0}};

char shipStart[2];
char shipEnd[2];
char possibleRowEnd[2];
char possibleColEnd[2];

const char rowTitles[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
const char colTitles[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

void printBoard(){
    printf("\n    %c   %c   %c   %c   %c   %c   %c   %c   %c   %c", colTitles[0], colTitles[1], colTitles[2], colTitles[3], colTitles[4], colTitles[5], colTitles[6], colTitles[7], colTitles[8], colTitles[9]);

    printf("\n  -----------------------------------------\n");
    for (int row = 0; row < 10; row++){
        printf("%c ", rowTitles[row]);
        printf("|");
        for (int col = 0; col < 10; col++){
            if (board[row][col] == 0){
                printf("   ");
            }
            else if (board[row][col] == 1){
                printf(" x ");
            }
            else if (board[row][col] == 2){
                printf(" 2 ");
            }
            else if (board[row][col] == 3){
                printf(" 3 ");
            }
            else if (board[row][col] == 4){
                printf(" 4 ");
            }
            else if (board[row][col] == 5){
                printf(" 5 ");
            }
            printf("|");
        }
    printf("\n  -----------------------------------------\n");
    }
}

int getStartRowInput() {
    for (int i = 0; i < 10; i++){
        if (rowTitles[i] == shipStart[0]){
            return i;
        }
    }
    return 0;
}

int getEndRowInput() {
    for (int i = 0; i < 10; i++){
        if (rowTitles[i] == shipEnd[0]){
            return i;
        }
    }
    return 0;
}

int getStartColInput() {
    for (int i = 0; i < 10; i++){
        if (colTitles[i] == shipStart[1]){
            return i;
        }
    }
    return 0;
}

int getEndColInput() {
    for (int i = 0; i < 10; i++){
        if (colTitles[i] == shipEnd[1]){
            return i;
        }  
    }
    return 0;
}

void drawShip(int shipLength){
    //BlockChecker
    do{      
    printf("Enter Startposition:");
    scanf("%s", & shipStart);
    } while (board[getStartRowInput()][getStartColInput()] != 0);
    int rowStart = getStartRowInput();
    int colStart = getStartColInput();
    //BlockChecker
    //LengthChecker
    bool boolean;
    do{
        printf("Enter Endposition:");
        scanf("%s", & shipEnd);
        if (getStartRowInput() == getEndRowInput()){
            if (getEndColInput() - getStartColInput() + 1 == shipLength){
                boolean = false;
            } else{
                boolean = true;
            }
        } else if(getStartColInput() == getEndColInput()){
            if (getEndRowInput() - getStartRowInput() + 1 == shipLength){
                boolean = false;
            } else{
                boolean = true;
            }
        } else{
            boolean = true;
        }
    } while (boolean);
    //LengthChecker
    int rowEnd = getEndRowInput();
    int colEnd = getEndColInput();
    //Blocker
    for (int i = rowStart-1; i <= rowEnd+1; i++){
        if (i < 0){
            continue;
        }else if(i > 9){
            continue;
        }
        for (int j = colStart-1; j <= colEnd+1; j++){
            if (j < 0){
            continue;
        }else if(j > 9){
            continue;
        }
            board[i][j] = 1;
        } 
    }//Blocker
    //Ship
    for (int i = rowStart; i <= rowEnd; i++){
        for (int j = colStart; j <= colEnd; j++){
            board[i][j] = shipLength;
        }        
    }//Ship
    printBoard();
}

void drawShips(){
    //for (int i = 4; i > 0; i--){
        drawShip(2);
    //}
    //for (int i = 3; i > 0; i--){
        drawShip(3);
    //}
    //for (int i = 2; i > 0; i--){
    //    drawShip(4);
    //}
    //drawShip(5);
}

void firstPlayer(){
    drawShips();
}

void secondPlayer(){
    drawShips();
}

void startGame(){
    printBoard();
}

int main (){
    do{
    firstPlayer();
    secondPlayer();
    startGame();
    } while (checkForWinner);
}