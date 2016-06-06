#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
int successes, fails;

int checkSmithy(int currentPlayer, struct gameState *state, int handPos){
	int r, handBefore, handAft;
    int deckB, deckA;

	state->hand[currentPlayer][2] = 13;
	//handBefore = state->handCount[currentPlayer];
    deckB = state->deckCount[currentPlayer];
    printf("%d\n",deckB);
	r = cardEffect(13,0,0,0,state,2,0);
	//handAft = state->handCount[currentPlayer];
    deckA = state->deckCount[currentPlayer];
    printf("%d\n",deckA);

    if (deckB != deckA){//((handBefore+2) == handAft){
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

	for (i = 0; i < atoi(argv[2]); i++){
        initializeGame(numPlayers, k, 1, &G);
		currentPlayer = floor((int)Random() % 2);
		checkSmithy(currentPlayer, &G, handPos);
	}

	printf("Successes: %d, Failing cases: %d\n",successes,fails);
	return 0;
}