#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

int calculate_bid(int player, int pos, int* first_moves, int* second_moves) {
	int pBalance = 100, pPos = 0, draw = 1;
	int bid;

	// To check if bot is player 1 or 2
	if (player != 1){
		swap(first_moves, second_moves);
		pPos = 10;
		draw = 2;
	}
	
	// Calculate how much money left
	for (int i = 0; i < 200; i++){
		if (first_moves[i] == 0) break;//the bid can't be zero so if we got zero as a move we are out of input range (Optimization)
		if (first_moves[i] > second_moves[i]){
			pBalance -= first_moves[i];
		}else if (first_moves[i] == second_moves[i]){
			if (draw == 1){
				pBalance -= *(first_moves + i);
				draw = 2;
			}
			else{
				draw = 1;
			}
		}

	}

	//Calculating the amount of bid the bot places in this current state
	if (pBalance > 0){
		int rPos;

		rPos = 10 - abs(pPos - pos);  //Calcaulating the dividing factor based on the distance between the bot's position and the scotch position. If the distance is low, then bid less.
		bid = pBalance / rPos; //Bidding an amount based on remaining balance and the position factor.
		if(bid <= 0){
			bid = rand() % pBalance + 1;
		}
	}
	else{
		bid = 0;
	}
	return bid;
}

int main(void) {
	int player;                                 //1 if first player 2 if second
	int scotch_pos;                             //position of the scotch 
	int bid, iter = 0;                                    //Amount bid by the player
	size_t buf_limit = 500;
	char *first_move = (char *)malloc(buf_limit);      //previous bids of the first player
	char *second_move = (char *)malloc(buf_limit);     //prevous bids of the second player
	char remove_new_line[2];
	int first_moves[200] = { 0 };
	int second_moves[200] = { 0 };
	char *tok_1, *tok_2;

	srand(time(NULL));
	cin >> player;
	cin >> scotch_pos;
	cin.getline(remove_new_line, 2);           //removes a new line from the buffer
	cin.getline(first_move, 200);
	cin.getline(second_move, 200);
	tok_1 = strtok(first_move, " ");
	for (int i = 0; tok_1; i++) {
		first_moves[i] = atoi(tok_1);
		tok_1 = strtok(NULL, " ");
	}
	tok_2 = strtok(second_move, " ");
	for (int i = 0; tok_2; i++) {
		second_moves[i] = atoi(tok_2);
		tok_2 = strtok(NULL, " ");
	}
	bid = calculate_bid(player, scotch_pos, first_moves, second_moves);
	cout << bid;
	return 0;
}