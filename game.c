#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

void initializeBoard() {
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
board[i][j] = ' ';
}

void displayBoard() {
printf("\n");
for(int i=0;i<3;i++) {
printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
if(i!=2) printf("\n-----------\n");
}
printf("\n\n");
}

int checkWin(char player) {
for(int i=0;i<3;i++) {
if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
return 1;
if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
return 1;
}

if(board[0][0]==player && board[1][1]==player && board[2][2]==player)  
    return 1;  

if(board[0][2]==player && board[1][1]==player && board[2][0]==player)  
    return 1;  

return 0;

}

int isDraw() {
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
if(board[i][j]==' ')
return 0;
return 1;
}

void playerMove() {
int r,c;

printf("Enter row and column (1-3): ");  
scanf("%d %d",&r,&c);  

r--; c--;  

if(board[r][c]==' ')  
    board[r][c]='X';  
else {  
    printf("Invalid move! Try again.\n");  
    playerMove();  
}

}

void computerMove() {
int r,c;

do {  
    r = rand()%3;  
    c = rand()%3;  
} while(board[r][c] != ' ');  

board[r][c]='O';  

printf("Computer played at %d %d\n",r+1,c+1);

}

int main() {

srand(time(0));  
initializeBoard();  

printf("===== TIC TAC TOE =====\n");  
printf("You: X  Computer: O\n");  

while(1) {  

    displayBoard();  
    playerMove();  

    if(checkWin('X')) {  
        displayBoard();  
        printf("🎉 You Win!\n");  
        break;  
    }  

    if(isDraw()) {  
        displayBoard();  
        printf("Game Draw!\n");  
        break;  
    }  

    computerMove();  

    if(checkWin('O')) {  
        displayBoard();  
        printf("Computer Wins!\n");  
        break;  
    }  

    if(isDraw()) {  
        displayBoard();  
        printf("Game Draw!\n");  
        break;  
    }  
}  

return 0;

}
