#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "interface.h"
#include "dominion.h"

int main(){
	struct gameState G;
	int numPlayers, startingHand, endingHand;
	numPlayers = 2;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	//Assert fail
	initializeGame(numPlayers, k, 1, &G);
	//printf("Hand size: %d\n", G.handCount[0]);
	startingHand = G.handCount[0];
	G.hand[0][3] = 13;
	f_smithy(0, &G, 3);
	//printf("Hand size: %d\n", G.handCount[0]);
	endingHand = G.handCount[0];
	if( startingHand >= endingHand ){
		printf("Error! Smithy card (f_smithy) not working properly\n");
		exit(0);
	}else{
		printf("SUCCESS (smithy)\n");
	}
    return 0;
}
