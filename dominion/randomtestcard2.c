#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
int successes, fails;

int checkSmithy(int currentPlayer, struct gameState *state, int handPos){
	int r;

	r = f_great_hall(currentPlayer, state, handPos);

	if (r == 0){
		return successes++;
	}else{
		return fails++;
	}
}

int main(int argc, char* argv[]){
	struct gameState G;
	int numPlayers, i, currentPlayer, handPos = 0;
	numPlayers = 2;
	SelectStream(1);
  	PutSeed(atoi(argv[1]));
  	if (argc < 3){
  		printf("Incorrect implementation. Should be '.exe seedNum numRuns'");
  	}
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	initializeGame(numPlayers, k, 1, &G);

	for (i = 0; i < atoi(argv[2]); i++){
		currentPlayer = floor((int)Random() % 2);
		checkSmithy(currentPlayer, &G, handPos);
	}

	printf("Successes: %d, Failing cases: %d\n",successes,fails);
	return 0;
}