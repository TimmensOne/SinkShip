#include <stdio.h>
#include <stdbool.h>

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

void getShipPoints()
{
    printf("Enter Startpoint:");
    scanf("%s", &shipStart);
    printf("Enter Endpoint:");
    scanf("%s", &shipEnd);
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

void drawShip2()
{
    getShipPoints();
    int row = getStartRowInput();
    int col = getStartColInput();
    board[row][col] = 1;
    row = getEndRowInput();
    col = getEndColInput();
    board[row][col] = 1;
}

void drawShip3()
{
    bool boolean;
    printf("Enter Startposition:");
    scanf("%s", & shipStart);
    int rowStart = getStartRowInput();
    int colStart = getStartColInput();
    do{
        printf("Enter Endposition:");
        scanf("%s", & shipEnd);
        if (getStartRowInput() == getEndRowInput()){
            if (getEndColInput() - getStartColInput() == 2){
                boolean = false;
            } else{
                boolean = true;
            }
        } else if(getStartColInput() == getEndColInput()){
            if (getEndRowInput() - getStartRowInput() == 2){
                boolean = false;
            } else{
                boolean = true;
            }
        } else{
            boolean = true;
        }
    } while (boolean);
    int rowEnd = getEndRowInput();
    int colEnd = getEndColInput();
    for (int i = rowStart; i <= rowEnd; i++)
    {
        for (int j = colStart; j <= colEnd; j++)
        {
            board[i][j] = 2;
        }        
    }
}

void drawShip4()
{
    getShipPoints();
    int row = getStartRowInput();
    int col = getStartColInput();
    board[row][col] = 3;
    row = getEndRowInput();
    col = getEndColInput();
    board[row][col] = 3;
}

void drawShip5()
{
    getShipPoints();
    int row = getStartRowInput();
    int col = getStartColInput();
    board[row][col] = 4;
    row = getEndRowInput();
    col = getEndColInput();
    board[row][col] = 4;
}

void drawShips()
{
    //for (int i = 4; i > 0; i--){
    //    drawShip2();
    //}
    //for (int i = 3; i > 0; i--){
        drawShip3();
    //}
    //for (int i = 2; i > 0; i--){
    //    drawShip4();
    //}
    //drawShip5();
}

void printBoard()
{
    printf("\n    %c   %c   %c   %c   %c   %c   %c   %c   %c   %c", colTitles[0], colTitles[1], colTitles[2], colTitles[3], colTitles[4], colTitles[5], colTitles[6], colTitles[7], colTitles[8], colTitles[9]);

    printf("\n  -----------------------------------------\n");
    for (int row = 0; row < 10; row++)
    {
        printf("%c ", rowTitles[row]);
        printf("|");
        for (int col = 0; col < 10; col++)
        {
            if (board[row][col] == 0)
            {
                printf("   ");
            }
            else if (board[row][col] == 1)
            {
                printf(" 2 ");
            }
            else if (board[row][col] == 2)
            {
                printf(" 3 ");
            }
            else if (board[row][col] == 3)
            {
                printf(" 4 ");
            }
            printf("|");
        }
    printf("\n  -----------------------------------------\n");
}
}
int main ()
{
    drawShips();
    //printBoard();
}