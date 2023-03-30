#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int first;
int second;
bool check = false;

int userInput(int coordNum);

int main(int argc, char* argv[]) {
	do {
		first = userInput(1);
		second = userInput(2);
		board[first][second] = 'X';
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++) {
				printf("[%c]", board[i][j]);
			}
			printf("\n");
		}

		//if the board is filled up, check = false and game ends
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!isalpha(board[i][j])) {
					check = true;
					j = 3;
					i = 3;
				} else {
					check = false;
				}
			}
		}
	} while (check == true);
	return EXIT_SUCCESS;
}

int userInput(int coordNum) {
	int input = -1;
	do {
		printf("please enter coordinate %i: ", coordNum);
		scanf("%i", &input);
	} while ((input < 0) || (input > 2));
	return input;
}
