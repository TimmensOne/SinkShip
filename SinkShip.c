#include <stdio.h>
#include <stdbool.h>

//Version: 1.0.6. (Open Beta)
//Owner: TimmensOne

//boolean
bool hitChecker;
bool directionLeft;
bool directionRight;
bool directionTop;
bool directionBottom;
bool boolShipDirection;

//int [][]
int board[10][10];
int ownBoardPlayer1[10][10];
int ownBoardPlayer2[10][10];
int enemyBoardPlayer1[10][10];
int enemyBoardPlayer2[10][10];
int boardStatistics[5][2];

//char []
char shipStart[3];
char fireField[2];

//const char []
const char rowTitles[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
const char colTitles[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
const char directionsTitels[] = {'r', 'b', 'l', 't'};
const char rowTitlesStatistics[] = {'t', '2', '3', '4', '5'};

//int
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

int getShipDirection()
{
    for (int i = 0; i <= 3; i++)
    {
        if (directionsTitels[i] == shipStart[2])
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

bool checkTop(int shipLength)
{
    if (getStartRowInput() - shipLength + 1 >= 0)
    {
        for (int i = 0; i < shipLength; i++)
        {
            if (board[getStartRowInput() - shipLength + i][getStartColInput()] == 0)
            {
                directionLeft = true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return directionLeft;
}

bool checkBottom(int shipLength)
{
    if (getStartRowInput() + shipLength - 1 <= 9)
    {
        for (int i = 0; i < shipLength; i++)
        {
            if (board[getStartRowInput() + i][getStartColInput()] == 0)
            {
                directionRight = true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return directionRight;
}

bool checkLeft(int shipLength)
{
    if (getStartColInput() - shipLength + 1 >= 0)
    {
        for (int i = 0; i < shipLength; i++)
        {
            if (board[getStartRowInput()][getStartColInput() - shipLength + i] == 0)
            {
                directionTop = true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return directionTop;
}

bool checkRight(int shipLength)
{
    if (getStartColInput() + shipLength - 1 <= 9)
    {
        for (int i = 0; i < shipLength; i++)
        {
            if (board[getStartRowInput()][getStartColInput() + i] == 0)
            {
                directionBottom = true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return directionBottom;
}

bool checkShipDirection(int shipLength)
{
    switch (getShipDirection())
    {
    case 0:
        boolShipDirection = checkRight(shipLength);
        break;

    case 1:
        boolShipDirection = checkBottom(shipLength);
        break;

    case 2:
        boolShipDirection = checkLeft(shipLength);
        break;
    case 3:
        boolShipDirection = checkTop(shipLength);
        break;
    }
    return boolShipDirection;
}

void enterSelectedDirection(int direction, int shipLength)
{
    int shipStartYPos = getStartRowInput();
    int shipStartXPos = getStartColInput();
    switch (direction)
    {
    //right
    case 0:
        for (int i = shipStartYPos - 1; i <= shipStartYPos + 1; i++)
        {
            for (int j = shipStartXPos - 1; j <= shipStartXPos + shipLength; j++)
            {
                if (i >= 0 && i <= 9)
                {
                    if (j >= 0 && j <= 9)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }
        for (int i = shipStartYPos; i <= shipStartYPos; i++)
        {
            for (int j = shipStartXPos; j <= shipStartXPos + shipLength - 1; j++)
            {
                board[i][j] = shipLength;
            }
        }
        break;
    //bottom
    case 1:
        for (int i = shipStartYPos - 1; i <= shipStartYPos + shipLength; i++)
        {
            for (int j = shipStartXPos - 1; j <= shipStartXPos + 1; j++)
            {
                if (i >= 0 && i <= 9)
                {
                    if (j >= 0 && j <= 9)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }
        for (int i = shipStartYPos; i <= shipStartYPos + shipLength - 1; i++)
        {
            for (int j = shipStartXPos; j <= shipStartXPos; j++)
            {
                board[i][j] = shipLength;
            }
        }
        break;
    //left
    case 2:
        shipStartXPos -= shipLength + 1;
        for (int i = shipStartYPos - 1; i <= shipStartYPos + 1; i++)
        {
            for (int j = shipStartXPos - 1; j <= shipStartXPos + shipLength + 1; j++)
            {
                if (i >= 0 && i <= 9)
                {
                    if (j >= 0 && j <= 9)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }
        for (int i = shipStartYPos; i <= shipStartYPos; i++)
        {
            for (int j = shipStartXPos; j <= shipStartXPos + shipLength - 1; j++)
            {
                board[i][j] = shipLength;
            }
        }
        break;
    //top
    case 3:
        shipStartYPos -= shipLength + 1;
        for (int i = shipStartYPos - 1; i <= shipStartYPos + shipLength + 1; i++)
        {
            for (int j = shipStartXPos - 1; j <= shipStartXPos + 1; j++)
            {
                if (i >= 0 && i <= 9)
                {
                    if (j >= 0 && j <= 9)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }
        for (int i = shipStartYPos; i <= shipStartYPos + shipLength - 1; i++)
        {
            for (int j = shipStartXPos; j <= shipStartXPos; j++)
            {
                board[i][j] = shipLength;
            }
        }
        break;
    default:
        printf("Something went wrong\n");
        break;
    }
}

void drawSingleShip(int shipLength)
{
    do
    {
        do
        {
            printf("Enter Startposition (e.g. A1r):\n");
            scanf("%s", &shipStart);
            if (board[getStartRowInput()][getStartColInput()] != 0)
            {
                printf("Pleas try Again. This Field is blocked\n");
            }
        } while (board[getStartRowInput()][getStartColInput()] != 0);
        if (!checkShipDirection(shipLength))
        {
            printf("Some Fields are blocked. Try Again!");
        }
    } while (!checkShipDirection(shipLength));
    enterSelectedDirection(getShipDirection(), shipLength);
    printBoard();
}

void drawShips()
{
    for (int i = 4; i > 0; i--)
    {
        printf("\nShiplength: 2\n");
        drawSingleShip(2);
    }
    for (int i = 3; i > 0; i--)
    {
        printf("\nShiplength: 3\n");
        drawSingleShip(3);
    }
    for (int i = 2; i > 0; i--)
    {
        printf("\nShiplength: 4\n");
        drawSingleShip(4);
    }
    printf("\nShiplength: 5\n");
    drawSingleShip(5);
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
                if (player == 1)
                {
                    enemyBoardPlayer1[i][j] = ownBoardPlayer2[i][j];
                }
                else if (player == 2)
                {
                    enemyBoardPlayer2[i][j] = ownBoardPlayer1[i][j];
                }
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
                blockAround(getFireRowInput(), getFireColInput() + j);
                j++;
            }
        }
    }
}

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
    //is subject to changes
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
        if (ownBoardPlayer2[getFireRowInput()][getFireColInput()] == 0 || ownBoardPlayer2[getFireRowInput()][getFireColInput()] == 1)
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
        if (ownBoardPlayer1[getFireRowInput()][getFireColInput()] == 0 || ownBoardPlayer1[getFireRowInput()][getFireColInput()] == 1)
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

//is subject to changes
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
            if (totalPlayer1 == 10 || totalPlayer2 == 10)
            {
                break;
            }
        } while (hitChecker);
        if (totalPlayer1 == 10 || totalPlayer2 == 10)
        {
            break;
        }
        changePlayer();
    } while (totalPlayer1 != 10 || totalPlayer2 != 10);
    printEnemy();
    printf("Winner is Player %d\n", player);
}

int main()
{
    printf(" --- Welcom to sink ships --- \n");
    firstPlayer();
    secondPlayer();
    play();
}

/*
    issues sort by priority:
        1- Fixing Bugs      --> currently nothing known
        2- Print Statistics --> printStatistics(); is subject to changes
*/