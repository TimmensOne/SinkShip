#include <stdio.h>
#include <stdbool.h>

//Version: 0.1
//Owner: TimmensOne
//Supporter: cyd3r

bool checkForWinner = false;
bool hitChecker;

int board[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int ownBoardPlayer1[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int ownBoardPlayer2[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int enemyBoardPlayer1[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int enemyBoardPlayer2[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int boardStatistics[5][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

char shipStart[2];
char shipEnd[2];

char fireField[2];

const char rowTitles[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
const char colTitles[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

const char rowTitlesStatistics[] = {'t', '2', '3', '4', '5'};

int player = 1;

int totalPlayer1 = 0;
int totalPlayer2 = 0;

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
            switch (board[row][col])
            {
            case 0:
                printf("   ");
                break;
            case 1:
                printf(" x ");
                break;
            case 6:
                printf(" S ");
                break;
            default:
                printf(" %d ", board[row][col]);
                break;
            }
            printf("|");
        }
        printf("\n  -----------------------------------------\n");
    }
}

int getStartRowInput()
{
    for (int i = 0; i < 10; i++)
    {
        if (rowTitles[i] == shipStart[0])
        {
            return i;
        }
    }
    return 0;
}

int getEndRowInput()
{
    for (int i = 0; i < 10; i++)
    {
        if (rowTitles[i] == shipEnd[0])
        {
            return i;
        }
    }
    return 0;
}

int getStartColInput()
{
    for (int i = 0; i < 10; i++)
    {
        if (colTitles[i] == shipStart[1])
        {
            return i;
        }
    }
    return 0;
}

int getEndColInput()
{
    for (int i = 0; i < 10; i++)
    {
        if (colTitles[i] == shipEnd[1])
        {
            return i;
        }
    }
    return 0;
}

int getFireRowInput()
{
    for (int i = 0; i < 10; i++)
    {
        if (rowTitles[i] == fireField[0])
        {
            return i;
        }
    }
    return 0;
}

int getFireColInput()
{
    for (int i = 0; i < 10; i++)
    {
        if (colTitles[i] == fireField[1])
        {
            return i;
        }
    }
    return 0;
}

void checkBlockedField()
{
    do
    {
        printf("Enter Startposition (e.g. A1):\n");
        scanf("%s", &shipStart);
        if (board[getStartRowInput()][getStartColInput()] != 0)
        {
            printf("Pleas try Again. This Field is blocked\n");
        }
        else
        {
            printf("Perfect\n");
        }
    } while (board[getStartRowInput()][getStartColInput()] != 0);
}

void checkShipDirections(int rowStart, int colStart, int shiplength, bool directionLeft, bool directionRight, bool directionTop, bool directionBottom)
{
    bool position;

    int positionLeft = board[rowStart - shiplength][colStart];
    int positionRight = board[rowStart + shiplength][colStart];
    int positionTop = board[rowStart][colStart - shiplength];
    int positionBottom = board[rowStart][colStart + shiplength];

    if (positionLeft == 0)
    {
        for (int i = 0; i < shiplength; i++)
        {
            if (board[positionLeft + i][colStart] == 0)
            {
                position = true;
                directionLeft = true;
            }
            else
            {
                position = false;
                directionLeft = false;
            }
        }
    } else {
        directionLeft = false;
    }
    if (positionRight == 0)
    {
        for (int i = 0; i < shiplength; i++)
        {
            if (board[rowStart][colStart] == 0)
            {
                position = true;
                directionRight = true;
            }
            else
            {
                position = false;
                directionRight = false;
            }
        }
    } else {
        directionRight = false;
    }
    if (positionTop == 0)
    {
        for (int i = 0; i < shiplength; i++)
        {
            if (board[rowStart][positionTop + i] == 0)
            {
                position = true;
                directionTop = true;
            }
            else
            {
                position = false;
                directionTop = true;
            }
        }
    } else {
        directionTop = false;
    }
    if (positionBottom == 0)
    {
        for (int i = 0; i < shiplength; i++)
        {
            if (board[rowStart][colStart] == 0)
            {
                position = true;
                directionBottom = true;
            }
            else
            {
                position = false;
                directionBottom = false;
            }
        }
    }
    else
    {
        directionBottom = false;
    }
}

void enterSelectedDirection(int direction, int shipLength, bool directionLeft, bool directionRight, bool directionTop, bool directionBottom)
{
    int shipStartXPos;
    int shipStartYPos;
    switch (direction)
    {

    //right
    case 0:
        if (!directionRight)
        {
            printf("This direction isn't possible");
            break;
        }
        printf("right enterDirection\n");
        shipStartXPos = getStartRowInput();
        shipStartYPos = getStartColInput();
        for (int i = shipStartXPos - 1; i <= shipStartXPos + 1; i++)
        {
            for (int j = shipStartYPos - 1; j <= shipStartYPos + shipLength + 1; j++)
            {
                board[i][j] = 1;
            }
        }
        for (int i = shipStartXPos; i <= shipStartXPos; i++)
        {
            for (int j = shipStartYPos; j <= shipStartYPos + shipLength; j++)
            {
                board[i][j] = shipLength;
            }
        }
        break;
    //bottom
    case 1:
        if (!directionBottom)
        {
            printf("This direction isn't possible");
            break;
        }
        printf("bottom enterDirection\n");
        shipStartXPos = getStartRowInput();
        shipStartYPos = getStartColInput();
        for (int i = shipStartXPos - 1; i <= shipStartXPos + shipLength + 1; i++)
        {
            for (int j = shipStartYPos - 1; j <= shipStartYPos + 1; j++)
            {
                board[i][j] = 1;
            }
        }
        for (int i = shipStartXPos; i <= shipStartXPos + shipLength; i++)
        {
            for (int j = shipStartYPos; j <= shipStartYPos; j++)
            {
                board[i][j] = shipLength;
            }
        }
        break;
    //left
    case 2:
        if (!directionLeft)
        {
            printf("This direction isn't possible");
            break;
        }
        printf("left enterDirection\n");
        shipStartXPos = getStartRowInput();
        shipStartYPos = getStartColInput() - shipLength;
        for (int i = shipStartXPos - 1; i <= shipStartXPos + 1; i++)
        {
            for (int j = shipStartYPos - 1; j <= shipStartYPos + shipLength + 1; j++)
            {
                board[i][j] = 1;
            }
        }
        for (int i = shipStartXPos; i <= shipStartXPos; i++)
        {
            for (int j = shipStartYPos; j <= shipStartYPos + shipLength; j++)
            {
                board[i][j] = shipLength;
            }
        }
        break;
    default:
        printf("Something went wrong\n");
        break;
    //top
    case 3:
        if (!directionTop)
        {
            printf("This direction isn't possible");
            break;
        }
        printf("top enterDirection\n");
        shipStartXPos = getStartRowInput() - shipLength;
        shipStartYPos = getStartColInput();
        for (int i = shipStartXPos - 1; i <= shipStartXPos + shipLength + 1; i++)
        {
            for (int j = shipStartYPos - 1; j <= shipStartYPos + 1; j++)
            {
                board[i][j] = 1;
            }
        }
        for (int i = shipStartXPos; i <= shipStartXPos + shipLength; i++)
        {
            for (int j = shipStartYPos; j <= shipStartYPos; j++)
            {
                board[i][j] = shipLength;
            }
        }
        break;
    }
}

//update version 2
void drawShip(int shipLenth)
{
    //1.
    //2.
    //3. player choose direction
    //4. block around the ship
    //5. place down the ship
    //6. print the updated Board

    //1. check if entered Field is blocked
    checkBlockedField();
    int rowStart = getStartRowInput();
    int colStart = getStartColInput();

    //2. check if it can be placed
    bool directionLeft;
    bool directionRight;
    bool directionTop;
    bool directionBottom;
    checkShipDirections(rowStart, colStart, shipLenth, directionLeft, directionRight, directionTop, directionBottom);

    //3. + 4. + 5.
    int direction;
    printf("Please enter your Direction \n0=right, 1=bottom, 2=left, 3=top\n");
    scanf("%d", &direction);
    enterSelectedDirection(direction, shipLenth, directionLeft, directionRight, directionTop, directionBottom);
    //6.
    printBoard();
}

//issue 2
void drawShips()
{
    // convert i from 3 to 4
    //for (int i = 3; i > 0; i--){
    //    printf("\nShiplength: 2\n");
    //    drawShip(2);
    //}
    // convert i from 2 to 3
    for (int i = 2; i > 0; i--)
    {
        printf("\nShiplength: 3\n");
        drawShip(3);
    }
    /*
    for (int i = 2; i > 0; i--){
        printf("\nShiplength: 4\n");
        drawShip(4);
    }
    printf("\nShiplength: 5\n");
    drawShip(5);
    */
}

void resetBoard()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = 0;
        }
    }
}

void saveBoardPlayer1()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ownBoardPlayer1[i][j] = board[i][j];
        }
    }
    resetBoard();
}

void saveBoardPlayer2()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ownBoardPlayer2[i][j] = board[i][j];
        }
    }
    resetBoard();
}

void firstPlayer()
{
    printf("\nPlayer 1 is on the line.\n");
    printf("\n - Please enter Startposition and Endpoisition of your Ships.\n");
    printf(" - Every player has the same amount of ships:\n    4x 2-ship, 3x 3-ship, 2x 4-ship, 1x 5-ship\n");
    printBoard();
    drawShips();
    saveBoardPlayer1();
}

void secondPlayer()
{
    printf("\nPlayer 2 is on the line.\n");
    printf("\n - Please enter Startposition and Endpoisition of your Ships.\n");
    printf(" - Every player has the same amount of ships:\n    4x 2-ship, 3x 3-ship, 2x 4-ship, 1x 5-ship\n");
    printBoard();
    drawShips();
    saveBoardPlayer2();
}

void checkPlayer()
{
    if (player == 1)
    {
        printf("\n --- Player 1 is tuned in ---\n");
    }
    else if (player == 2)
    {
        printf("\n --- Player 2 is tuned in ---\n");
    }
}

void printEnemy()
{
    if (player == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                board[i][j] = enemyBoardPlayer1[i][j];
            }
        }
        printBoard();
        resetBoard();
    }
    else if (player == 2)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                board[i][j] = enemyBoardPlayer2[i][j];
            }
        }
        printBoard();
        resetBoard();
    }
}

void playerFires()
{
    printf("Enter Field:\n");
    scanf("%s", &fireField);
}

void blockAround(int row, int col)
{
    if (player == 1)
    {
        for (int i = row - 1; i <= row + 1; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                enemyBoardPlayer1[i][j] = ownBoardPlayer2[i][j];
            }
        }
    }
    else if (player == 2)
    {
        for (int i = row - 1; i <= row + 1; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                enemyBoardPlayer2[i][j] = ownBoardPlayer1[i][j];
            }
        }
    }
}

void blockAroundShip(int shipLength)
{
    if (player == 1)
    {
        int rowCount = 0;
        int colCount = 0;
        //checkRow
        while (rowCount < shipLength)
        {
            //left
            int i = 0;
            while (enemyBoardPlayer1[getFireRowInput() - i][getFireColInput()] == shipLength)
            {
                rowCount++;
                printf("left %d", rowCount);
                blockAround(getFireRowInput() - i, getFireColInput());
                i++;
            }
            if (rowCount == shipLength)
            {
                break;
            }
            //right
            int j = 1;
            while (enemyBoardPlayer1[getFireRowInput() + j][getFireColInput()] == shipLength)
            {
                rowCount++;
                printf("right %d", rowCount);
                blockAround(getFireRowInput() + j, getFireColInput());
                j++;
            }
        }
        //checkCol
        while (colCount < shipLength)
        {
            //left
            int i = 0;
            while (enemyBoardPlayer1[getFireRowInput()][getFireColInput() - i] == shipLength)
            {
                colCount++;
                printf("left %d", colCount);
                blockAround(getFireRowInput(), getFireColInput() - i);
                i++;
            }
            if (colCount == shipLength)
            {
                break;
            }
            //right
            int j = 1;
            while (enemyBoardPlayer1[getFireRowInput()][getFireColInput() + j] == shipLength)
            {
                colCount++;
                printf("right %d", colCount);
                blockAround(getFireRowInput(), getFireColInput() + j);
                j++;
            }
        }
    }
    else if (player == 2)
    {
        int rowCount = 0;
        int colCount = 0;
        //checkRow
        while (rowCount < shipLength)
        {
            //left
            int i = 0;
            while (enemyBoardPlayer2[getFireRowInput() - i][getFireColInput()] == shipLength)
            {
                rowCount++;
                printf("left %d", rowCount);
                blockAround(getFireRowInput() - i, getFireColInput());
                i++;
            }
            if (rowCount == shipLength)
            {
                break;
            }
            //right
            int j = 1;
            while (enemyBoardPlayer2[getFireRowInput() + j][getFireColInput()] == shipLength)
            {
                rowCount++;
                printf("right %d", rowCount);
                blockAround(getFireRowInput() + j, getFireColInput());
                j++;
            }
        }
        //checkCol
        while (colCount < shipLength)
        {
            //left
            int i = 0;
            while (enemyBoardPlayer2[getFireRowInput()][getFireColInput() - i] == shipLength)
            {
                colCount++;
                printf("left %d", colCount);
                blockAround(getFireRowInput(), getFireColInput() - i);
                i++;
            }
            if (colCount == shipLength)
            {
                break;
            }
            //right
            int j = 1;
            while (enemyBoardPlayer2[getFireRowInput()][getFireColInput() + j] == shipLength)
            {
                colCount++;
                printf("right %d", colCount);
                blockAround(getFireRowInput(), getFireColInput() + j);
                j++;
            }
        }
    }
}

//issue 4
void checkSunkenShip()
{
    int shipLength = 0;
    int count = 0;
    if (player == 1)
    {
        shipLength = enemyBoardPlayer1[getFireRowInput()][getFireColInput()];
        for (int i = getFireRowInput() - shipLength + 1; i < getFireRowInput() + shipLength; i++)
        {
            if (enemyBoardPlayer1[i][getFireColInput()] == shipLength)
            {
                count++;
            }
        }
        if (count == shipLength)
        {
            blockAroundShip(shipLength);
            printf("Ship has sunk\n");
            totalPlayer1++;
        }
        else
        {
            count = 0;
        }
        for (int j = getFireColInput() - shipLength + 1; j < getFireColInput() + shipLength; j++)
        {
            if (enemyBoardPlayer1[getFireRowInput()][j] == shipLength)
            {
                count++;
            }
        }
        if (count == shipLength)
        {
            blockAroundShip(shipLength);
            printf("Ship has sunk\n");
            totalPlayer1++;
        }
        else
        {
            count = 0;
        }
    }
    else if (player == 2)
    {
        shipLength = enemyBoardPlayer2[getFireRowInput()][getFireColInput()];
        for (int i = getFireRowInput() - shipLength + 1; i < getFireRowInput() + shipLength; i++)
        {
            if (enemyBoardPlayer2[i][getFireColInput()] == shipLength)
            {
                count++;
            }
        }
        if (count == shipLength)
        {
            blockAroundShip(shipLength);
            printf("Ship has sunk\n");
            totalPlayer2++;
        }
        else
        {
            count = 0;
        }
        for (int j = getFireColInput() - shipLength + 1; j < getFireColInput() + shipLength; j++)
        {
            if (enemyBoardPlayer2[getFireRowInput()][j] == shipLength)
            {
                count++;
            }
        }
        if (count == shipLength)
        {
            blockAroundShip(shipLength);
            printf("Ship has sunk\n");
            totalPlayer2++;
        }
        else
        {
            count = 0;
        }
    }
    //need update!
    //boardStatistics[player-1][shipLength] += 1;
}

void enterHit()
{
    printf("Hit Ship\n");
    if (player == 1)
    {
        enemyBoardPlayer1[getFireRowInput()][getFireColInput()] = ownBoardPlayer2[getFireRowInput()][getFireColInput()];
        checkSunkenShip();
    }
    else if (player == 2)
    {
        enemyBoardPlayer2[getFireRowInput()][getFireColInput()] = ownBoardPlayer1[getFireRowInput()][getFireColInput()];
        checkSunkenShip();
    }
}

void enterNoHit()
{
    printf("Missed Ship\n");
    if (player == 1)
    {
        enemyBoardPlayer1[getFireRowInput()][getFireColInput()] = 1;
    }
    else if (player == 2)
    {
        enemyBoardPlayer2[getFireRowInput()][getFireColInput()] = 1;
    }
    printEnemy();
}

void checkHit()
{
    if (player == 1)
    {
        if (ownBoardPlayer2[getFireRowInput()][getFireColInput()] == 0)
        {
            hitChecker = false;
            enterNoHit();
        }
        else if (ownBoardPlayer2[getFireRowInput()][getFireColInput()] == 1)
        {
            hitChecker = false;
            enterNoHit();
        }
        else
        {
            hitChecker = true;
            enterHit();
        }
    }
    else if (player == 2)
    {
        if (ownBoardPlayer1[getFireRowInput()][getFireColInput()] == 0)
        {
            hitChecker = false;
            enterNoHit();
        }
        else if (ownBoardPlayer1[getFireRowInput()][getFireColInput()] == 1)
        {
            hitChecker = false;
            enterNoHit();
        }
        else
        {
            hitChecker = true;
            enterHit();
        }
    }
}

void changePlayer()
{
    if (player == 1)
    {
        player = 2;
        printf("Changed Player to 2\n");
    }
    else if (player == 2)
    {
        player = 1;
        printf("Changed Player to 1\n");
    }
}

//issue 1
void printStatistics()
{
    printf("   P1   P2");

    printf("\n   ----------\n");
    for (int row = 0; row < 5; row++)
    {
        printf("%c ", rowTitlesStatistics[row]);
        printf("|");
        for (int col = 0; col < 2; col++)
        {
            printf(" %d |", boardStatistics[row][col]);
        }
        printf("\n  -----------\n");
    }
}

//issue 4
void play()
{
    do
    {
        checkPlayer();
        do
        {
            printEnemy();
            playerFires();
            checkHit();
            // convert 2 to 10 if more ships
            if (totalPlayer1 == 2 || totalPlayer2 == 2)
            {
                break;
            }
        } while (hitChecker);
        // convert 2 to 10 if more ships
        if (totalPlayer1 == 2 || totalPlayer2 == 2)
        {
            break;
        }
        //printStatistics();
        changePlayer();
        // convert 2 to 10 if more ships
    } while (totalPlayer1 != 2 || totalPlayer2 != 2);
    printEnemy();
    printf("Winner is Player %d", player);
    //Print Boards
}

void printAllBords()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", ownBoardPlayer1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", ownBoardPlayer2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", enemyBoardPlayer1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", enemyBoardPlayer2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//issue 3
int main()
{
    printf(" --- Welcom to sink ships --- \n");
    firstPlayer();
    secondPlayer();
    play();
    //printAllBords();
}

/*
    issues:
    1- print statistics
    2- darw ships --> convert 2 to 10 if more ships
                  --> add undo
                  --> can place up or left
    3- winner --> print bord
    4- play --> convert 1 to 10 if more ships
*/