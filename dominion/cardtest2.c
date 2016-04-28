#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "interface.h"
#include "dominion.h"

int main(){
	struct gameState G;
	int numPlayers, startingHand, startingHand2, endingHand, endingHand2;
	numPlayers = 2;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	//Assert fail
	initializeGame(numPlayers, k, 1, &G);
	//printf("Hand 1 size: %d\n", G.handCount[0]);
	//printf("Hand 2 size: %d\n", G.handCount[1]);

	startingHand = G.handCount[0];
	G.hand[0][3] = 8;
	f_council_room(0, &G, 3);
	//printf("Hand 1 size: %d\n", G.handCount[0]);
	//printf("Hand 2 size: %d\n", G.handCount[1]);


	endingHand = G.handCount[0];
	endingHand2 = G.handCount[1];

	if(startingHand == endingHand && startingHand2 == endingHand2){
		printf("Error! Council Room card (f_council_room) not working properly\n");
		exit(0);
	}else{
		printf("SUCCESS (council_room)\n");
	}
    return 0;
}