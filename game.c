#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int first;
int second;
bool check = false;
int turn = 0;

int userInput(int coordNum);
bool winCondition(char board[3][3]);

int main(int argc, char* argv[]) {
	do {
		//get coordinates
		do {
			first = userInput(1);
			second = userInput(2);
		} while (isalpha(board[second][first]));


		if ((turn % 2) == 0) {
			board[second][first] = 'X';
		} else {
			board[second][first] = 'O';
		}
		printf("  0, 1, 2\n");
		for (int i = 0; i < 3; i++){
			printf("%i", i);
			for (int j = 0; j < 3; j++) {
				printf("[%c]", board[i][j]);
			}
			printf("\n");
		}
		if (winCondition(board) == true) {
			turn = 9;
		}

		turn = turn + 1;
	} while (turn < 9);
	return EXIT_SUCCESS;
}

bool winCondition(char board[3][3]) {
	char player = ' ';
	for (int i = 0; i < 2; i++ ) {
		player = (i == 0 ? 'X' : 'O');

		//horizontal conditions
		if ((board[0][0] == player) && (board[0][1] == player) && (board[0][2] == player)) {
			printf("%c has won!\n", player);
			return true;
		} else if ((board[1][0] == player) && (board[1][1] == player) && (board[1][2] == player)){
			printf("%c has won!\n", player);
			return true;
		} else if ((board[2][0] == player) && (board[2][1] == player) && (board[2][2] == player)){
                	printf("%c has won!\n", player);
			return true;

		//vertical conditions
		} else if ((board[0][0] == player) && (board[1][0] == player) && (board[2][0] == player)){
                	printf("%c has won!\n", player);
                	return true;
		} else if ((board[0][1] == player) && (board[1][1] == player) && (board[2][1] == player)){
                	printf("%c has won!\n", player);
                	return true;
        	} else if ((board[0][2] == player) && (board[1][2] == player) && (board[2][2] == player)){
                	printf("%c has won!\n", player);
                	return true;

		//diagonal conditions
		} else if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)){
                	printf("%c has won!\n", player);
                	return true;
		} else if ((board[0][2] == player) && (board[1][1] == player) && (board[2][0] == player)){
                	printf("%c has won!\n", player);
                	return true;
        	}
	}
	return false;
}

int userInput(int coordNum) {
	int input = -1;
	do {
		printf("please enter coordinate %i: ", coordNum);
		scanf("%i", &input);
	} while ((input < 0) || (input > 2));
	return input;
}
