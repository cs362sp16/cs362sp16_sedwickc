#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "interface.h"
#include "dominion.h"

int main(){
	struct gameState G;
	int numPlayers, startingHand, endingHand, actionsBefore, actionsAfter;
	numPlayers = 2;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	//Assert fail
	initializeGame(numPlayers, k, 1, &G);
	//printf("Hand 1 size: %d\n", G.handCount[0]);
	//printf("Hand 2 size: %d\n", G.handCount[1]);

	startingHand = G.handCount[0];
	actionsBefore = G.numActions;
	//printf("Actions: %d\n", actionsBefore);


	G.hand[0][3] = 14;
	cardEffect(14, 0, 0, 0, &G, 3, 0);
	//printf("Hand 1 size: %d\n", G.handCount[0]);
	//printf("Hand 2 size: %d\n", G.handCount[1]);
	endingHand = G.handCount[0];
	actionsAfter = G.numActions;
	//printf("Actions: %d\n", actionsAfter);


	if(startingHand != endingHand){
		printf("Error! Village card (cardEffect) not working properly\n");
		exit(0);
	}else{
		printf("SUCCESS (village)\n");
	}
    return 0;
}