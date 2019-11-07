#include <stdio.h>
#include <stdbool.h>

bool checkForWinner = false;
bool hitChecker;

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

int ownBoardPlayer1[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0}};

int ownBoardPlayer2[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0}};

int enemyBoardPlayer1[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0}};

int enemyBoardPlayer2[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0}};

int boardStatistics[5][2] = {{0,0},{0,0},{0,0},{0,0},{0,0}};

char shipStart[2];
char shipEnd[2];

char fireField[2];

const char rowTitles[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
const char colTitles[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

const char rowTitlesStatistics[] = {'t','2','3','4','5'};

int player = 1;

int totalPlayer1 = 0;
int totalPlayer2 = 0;

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
            else if (board[row][col] == 6){
                printf(" S ");
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

int getFireRowInput() {
    for (int i = 0; i < 10; i++){
        if (rowTitles[i] == fireField[0]){
            return i;
        }
    }
    return 0;
}

int getFireColInput() {
    for (int i = 0; i < 10; i++){
        if (colTitles[i] == fireField[1]){
            return i;
        }  
    }
    return 0;
}

void drawShip(int shipLength){
    //BlockChecker
    do{      
    printf("Enter Startposition (e.g. A1):\n");
    scanf("%s", & shipStart);
    } while (board[getStartRowInput()][getStartColInput()] != 0);
    int rowStart = getStartRowInput();
    int colStart = getStartColInput();
    //BlockChecker
    //LengthChecker
    bool boolean;
    do{
        printf("Enter Endposition (e.g. A2):\n");
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
    //    printf("\nShiplength: 2\n");
    //    drawShip(2);
    //}
    //for (int i = 3; i > 0; i--){
        printf("\nShiplength: 3\n");
        drawShip(3);
    /*}
    for (int i = 2; i > 0; i--){
        printf("\nShiplength: 4\n");
        drawShip(4);
    }
    printf("\nShiplength: 5\n");
    drawShip(5);
    */
}

void resetBoard(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            board[i][j] = 0;
        }
    }
}

void saveBoardPlayer1(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            ownBoardPlayer1[i][j] = board[i][j];
        }
    }
    resetBoard();
}

void saveBoardPlayer2(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            ownBoardPlayer2[i][j] = board[i][j];
        }
    }
    resetBoard();
}

void firstPlayer(){
    printf("\nPlayer 1 is on the line.\n");
    printf("\n - Please enter Startposition and Endpoisition of your Ships.\n");
    printf(" - Every player has the same amount of ships:\n    4x 2-ship, 3x 3-ship, 2x 4-ship, 1x 5-ship\n");
    printBoard();
    drawShips();
    saveBoardPlayer1();
}

void secondPlayer(){
    printf("\nPlayer 2 is on the line.\n");
    printf("\n - Please enter Startposition and Endpoisition of your Ships.\n");
    printf(" - Every player has the same amount of ships:\n    4x 2-ship, 3x 3-ship, 2x 4-ship, 1x 5-ship\n");
    printBoard();
    drawShips();
    saveBoardPlayer2();
}

void checkPlayer(){
    if (player == 1){
        printf("\n --- Player 1 is tuned in ---\n");
    } else if (player == 2){
        printf("\n --- Player 2 is tuned in ---\n");
    }
}

void printEnemy(){
    if (player == 1){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                board[i][j] = enemyBoardPlayer1[i][j];
            }
        }
        printBoard();
        resetBoard();
    }else if (player == 2){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                board[i][j] = enemyBoardPlayer2[i][j];
            }
        }
        printBoard();
        resetBoard();
    }
}

void playerFires(){
    printf("Enter Field:\n");
    scanf("%s", & fireField);
}

void blockAround(){
    for (int i = getFireRowInput()-1; i <= getFireRowInput()+1; i++){
        for (int j = getFireColInput()-1; j <= getFireColInput()+1; j++){
            enemyBoardPlayer1[i][j] = ownBoardPlayer2[i][j];
        }
    }
}

//need update!
void blockAroundShip(int shipLength){
    if (player == 1){
    int rowCount = 0;
    int colCount = 0;
        //checkRow
        while (rowCount < shipLength){
            //left
            int i = 0;
            while (enemyBoardPlayer1[getFireRowInput()-i][getFireColInput()] == shipLength){
                rowCount++;
                printf("left %d", rowCount);
                blockAround();
                i++;
            }
            if (rowCount == shipLength){
                break;
            }          
            //right
            int j = 1;
            while (enemyBoardPlayer1[getFireRowInput()+j][getFireColInput()] == shipLength){
                rowCount++;
                printf("right %d", rowCount);
                blockAround();
                j++;
            }
        }
        //checkCol
        while (colCount < shipLength){
            //left
            int i = 0;
            while (enemyBoardPlayer1[getFireRowInput()][getFireColInput()-i] == shipLength){
                colCount++;
                printf("left %d", colCount);
                blockAround();
                i++;
            }
            if (colCount == shipLength){
                break;
            }          
            //right
            int j = 1;
            while (enemyBoardPlayer1[getFireRowInput()][getFireColInput()+j] == shipLength){
                colCount++;
                printf("right %d", colCount);
                blockAround();
                j++;
            }
        }
    }else if(player == 2){
        int rowCount = 0;
        int colCount = 0;
        //checkRow
        while (rowCount < shipLength){
            //left
            int i = 0;
            while (enemyBoardPlayer2[getFireRowInput()-i][getFireColInput()] == shipLength){
                rowCount++;
                printf("left %d", rowCount);
                blockAround();
                i++;
            }
            if (rowCount == shipLength){
                break;
            }          
            //right
            int j = 1;
            while (enemyBoardPlayer2[getFireRowInput()+j][getFireColInput()] == shipLength){
                rowCount++;
                printf("right %d", rowCount);
                blockAround();
                j++;
            }
        }
        //checkCol
        while (colCount < shipLength){
            //left
            int i = 0;
            while (enemyBoardPlayer2[getFireRowInput()][getFireColInput()-i] == shipLength){
                colCount++;
                printf("left %d", colCount);
                blockAround();
                i++;
            }
            if (colCount == shipLength){
                break;
            }          
            //right
            int j = 1;
            while (enemyBoardPlayer2[getFireRowInput()][getFireColInput()+j] == shipLength){
                colCount++;
                printf("right %d", colCount);
                blockAround();
                j++;
            }
        }
    }    
}

void checkSunkenShip(){
    int shipLength = 0;
    int count = 0;
    if (player == 1){
        shipLength = enemyBoardPlayer1[getFireRowInput()][getFireColInput()];
        for (int i = getFireRowInput() - shipLength + 1; i < getFireRowInput() + shipLength; i++){
            if (enemyBoardPlayer1[i][getFireColInput()] == shipLength){
                count++;
            }
        }
        if (count == shipLength){
            //need update!
            blockAroundShip(shipLength);
            printf("Ship has sunk\n");
            totalPlayer1++;
        } else{
            count = 0;
        }
        for (int j = getFireColInput()-shipLength + 1; j < getFireColInput() + shipLength; j++){
            if (enemyBoardPlayer1[getFireRowInput()][j] == shipLength){
                count++;
            }
        }
        if (count == shipLength){
            //need update!
            blockAroundShip(shipLength);
            printf("Ship has sunk\n");
            totalPlayer1++;
        } else{
            count = 0;
        }
    }else if (player == 2){
        shipLength = enemyBoardPlayer2[getFireRowInput()][getFireColInput()];
        for (int i = getFireRowInput() - shipLength + 1; i < getFireRowInput() + shipLength; i++){
            if (enemyBoardPlayer2[i][getFireColInput()] == shipLength){
                count++;
            }
        }
        if (count == shipLength){
            //need update!
            blockAroundShip(shipLength);
            printf("Ship has sunk\n");
            totalPlayer2++;
        } else{
            count = 0;
        }
        for (int j = getFireColInput()-shipLength + 1; j < getFireColInput() + shipLength; j++){
            if (enemyBoardPlayer2[getFireRowInput()][j] == shipLength){
                count++;
            }
        }
        if (count == shipLength){
            //need update!
            blockAroundShip(shipLength);
            printf("Ship has sunk\n");
            totalPlayer2++;
        } else{
            count = 0;
        }
    }
    //need update!
    //boardStatistics[player-1][shipLength] += 1;
}

void enterHit(){
    printf("Hit Ship\n");
    if (player == 1){
        enemyBoardPlayer1[getFireRowInput()][getFireColInput()] = ownBoardPlayer2[getFireRowInput()][getFireColInput()];
        checkSunkenShip();
    }else if (player == 2){
        enemyBoardPlayer2[getFireRowInput()][getFireColInput()] = ownBoardPlayer1[getFireRowInput()][getFireColInput()];
        checkSunkenShip();
    }
}

void enterNoHit(){
    printf("Missed Ship\n");
    if (player == 1){
        enemyBoardPlayer1[getFireRowInput()][getFireColInput()] = 1;
    }else if (player == 2){
        enemyBoardPlayer2[getFireRowInput()][getFireColInput()] = 1;
    }
    printEnemy();
}

void checkHit(){
    if (player == 1){
        if (ownBoardPlayer2[getFireRowInput()][getFireColInput()] == 0){
            hitChecker = false;
            enterNoHit();
        } else if(ownBoardPlayer2[getFireRowInput()][getFireColInput()] == 1){
            hitChecker = false;
            enterNoHit();
        } else{
            hitChecker = true;
            enterHit();
        }
    } else if (player ==2){
        if (ownBoardPlayer1[getFireRowInput()][getFireColInput()] == 0){
            hitChecker = false;
            enterNoHit();
        } else if(ownBoardPlayer1[getFireRowInput()][getFireColInput()] == 1){
            hitChecker = false;
            enterNoHit();
        } else{
            hitChecker = true;
            enterHit();
        }
    }
}

void changePlayer(){
    if (player == 1){
        player = 2;
        printf("Changed Player to 2\n");
    }else if (player  == 2){
        player = 1;
        printf("Changed Player to 1\n");
    }
}

void printStatistics(){
    printf("   P1   P2");

    printf("\n   ----------\n");
    for (int row = 0; row < 5; row++){
        printf("%c ", rowTitlesStatistics[row]);
        printf("|");
        for (int col = 0; col < 2; col++){
            if (boardStatistics[row][col] == 0){
                printf(" 0 ");
            }else if (boardStatistics[row][col] == 1){
                printf(" 1 ");
            }else if (boardStatistics[row][col] == 2){
                printf(" 2 ");
            }else if (boardStatistics[row][col] == 3){
                printf(" 3 ");
            }else if (boardStatistics[row][col] == 4){
                printf(" 4 ");
            }else if (boardStatistics[row][col] == 5){
                printf(" 5 ");
            }else if (boardStatistics[row][col] == 6){
                printf(" 6 ");
            }else if (boardStatistics[row][col] == 7){
                printf(" 7 ");
            }else if (boardStatistics[row][col] == 8){
                printf(" 8 ");
            }else if (boardStatistics[row][col] == 9){
                printf(" 9 ");
            }else if (boardStatistics[row][col] == 10){
                printf(" 10");
            }
            printf("|");
        }
    printf("\n  -----------\n");
    }
}

void play(){
    do{
        checkPlayer();
        do{
            printEnemy();
            playerFires();
            checkHit();
            // convert 1 to 10 if more ships
            if (totalPlayer1 == 1 || totalPlayer2 == 1){
                break;
            }
        } while (hitChecker);
        if (totalPlayer1 == 1 || totalPlayer2 == 1){
            break;
        }
        //printStatistics();
        changePlayer();
        // convert 1 to 10 if more ships
    } while (totalPlayer1 != 1 || totalPlayer2 != 1);
    printf("Winner");
    //Print Boards
}

void printAllBords(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d", ownBoardPlayer1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d", ownBoardPlayer2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d", enemyBoardPlayer1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d", enemyBoardPlayer2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//need update!
//In play --> checkHit --> enterHit --> checkSunkenShip --> blockAround!!!
int main (){
    printf(" --- Welcom to sink ships --- \n");
    firstPlayer();
    secondPlayer();
    play();
    //printAllBords();
}