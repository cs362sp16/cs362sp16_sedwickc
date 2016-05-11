#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
int successes, fails;

int checkAdventurer(int z, int currentPlayer, int drawntreasure, struct gameState *state, int cardDrawn){
	int r;

	r = f_adventurer(z, currentPlayer, drawntreasure, state, cardDrawn);

	if (r == 0){
		return successes++;
	}else{
		return fails++;
	}
}

int main(int argc, char* argv[]){
	struct gameState G;
	int numPlayers, z, i, currentPlayer, drawntreasure, cardDrawn = 0;
	numPlayers = 2;
	z = 0;
	SelectStream(1);
  	PutSeed(atoi(argv[1]));
  	if (argc < 3){
  		printf("Incorrect implementation. Should be '.exe seedNum numRuns'");
  	}
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	       //printf("initializeGame\n");
	initializeGame(numPlayers, k, 1, &G);
	//printf("entering loop\n");
	for (i = 0; i < atoi(argv[2]); i++){
		currentPlayer = floor((int)Random() % 2);
		drawntreasure = floor((int)Random() % 3);
		G.deckCount[0] = floor((int)Random() * MAX_DECK);
		checkAdventurer(z, currentPlayer, drawntreasure, &G, cardDrawn);
	}

	printf("Successes: %d, Failing cases: %d\n",successes,fails);
	return 0;
}
