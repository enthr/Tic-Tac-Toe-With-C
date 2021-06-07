#include <stdio.h>
#include <stdlib.h>

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Global

int choice, player; // Global

int checkForWin();
void displayBoard();
void markBoard(char mark);


int main() {
    int gameStatus;
    char mark;
    player = 1;
    do {
        displayBoard();

        //Change Turns
        player = (player % 2) ? 1 : 2;

        //Get Input
        printf("Player %d, Enter A Number: ",player);
        scanf("%d", &choice);

        //Set The Correct Character Based on PLayer Turn
        mark = (player == 1) ? 'X' : 'O';

        //Set THe Board Based On User Choice or Invalid Choice
        markBoard(mark);

        gameStatus = checkForWin();
        player++;
    } while (gameStatus == -1);

    if(gameStatus == 1) {
        printf("==> Player %d Win \n\n", --player);
    }
    else {
        printf("==> Game Draw \n\n");
    }

    return 0;
}

/*
 * Function To Return Game Status
 * 1 for game over with result
 * -1 for game in progress
 * 0 game over with no result
 */
int checkForWin() {
    int returnValue = 0;

    if(square[1] == square[2] && square[2] == square[3]) {
        returnValue = 1;
    }
    else if(square[4] == square[5] && square[5] == square[6]) {
        returnValue = 1;
    }
    else if(square[7] == square[8] && square[8] == square[9]) {
        returnValue = 1;
    }
    else if(square[1] == square[4] && square[4] == square[7]) {
        returnValue = 1;
    }
    else if(square[2] == square[5] && square[5] == square[8]) {
        returnValue = 1;
    }
    else if(square[3] == square[6] && square[6] == square[9]) {
        returnValue = 1;
    }
    else if(square[1] == square[5] && square[5] == square[9]) {
        returnValue = 1;
    }
    else if(square[3] == square[5] && square[5] == square[7]) {
        returnValue = 1;
    }
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9') {
        returnValue = 0;
    }
    else {
        returnValue = -1;
    }

    return returnValue;
}


/*
 * Function To Draw Tic-Tac-Toe Board With Players Mark
 */
void displayBoard() {
    system("cls");

    printf("\n\tTic Tac Toe\n\n");
    printf("Player1 (X) - Player2 (O)\n\n");
    printf("    |    |   \n");
    printf(" %c  | %c  | %c\n",square[1], square[2], square[3]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c\n",square[4], square[5], square[6]);
    printf("____|____|____\n");
    printf("    |    |   \n");
    printf(" %c  | %c  | %c\n",square[7], square[8], square[9]);
    printf("    |    |   \n\n");
}

/*
 *Set The Board With Correct Character X or O in the correct spot in the array
*/
void markBoard(char mark) {
    if(choice == 1 && square[1] == '1') {
        square[1] = mark;
    }
    else if(choice == 2 && square[2] == '2') {
        square[2] = mark;
    }else if(choice == 3 && square[3] == '3') {
        square[3] = mark;
    }else if(choice == 4 && square[4] == '4') {
        square[4] = mark;
    }else if(choice == 5 && square[5] == '5') {
        square[5] = mark;
    }else if(choice == 6 && square[6] == '6') {
        square[6] = mark;
    }else if(choice == 7 && square[7] == '7') {
        square[7] = mark;
    }else if(choice == 8 && square[8] == '8') {
        square[8] = mark;
    }else if(choice == 9 && square[9] == '9') {
        square[9] = mark;
    }
    else {
        printf("Invalid Move");
        player--;
    }
}
