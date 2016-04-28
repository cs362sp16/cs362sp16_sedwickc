#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "interface.h"
#include "dominion.h"

int main(){
	struct gameState G;
	int numPlayers, startingHand, endingHand, coinsB, coinsA;
	numPlayers = 2;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	//Assert fail
	initializeGame(numPlayers, k, 1, &G);
	//printf("Hand 1 size: %d\n", G.handCount[0]);
	//printf("Coins Before: %d\n", G.coins);

	startingHand = G.handCount[0];
	coinsB = G.coins;


	G.hand[0][3] = 18;
	cardEffect(18, 1, 0, 0, &G, 3, 0);
	//printf("Hand 1 size: %d\n", G.handCount[0]);
	endingHand = G.handCount[0];


	if(startingHand == endingHand){
		printf("Error! Steward card (cardEffect) not working properly\n");
		exit(0);
	}

	G.hand[0][3] = 18;
	cardEffect(18, 2, 0, 0, &G, 3, 0);
	//printf("Coins After: %d\n", G.coins);
	startingHand = G.handCount[0];
	coinsA = G.coins;

	if(coinsB == coinsA){
		printf("Error! Steward card (cardEffect) not working properly\n");
		exit(0);
	}

	G.hand[0][3] = 18;
	cardEffect(18, 0, 0, 0, &G, 3, 0);
	endingHand = G.handCount[0];
	//printf("Hand 1 size: %d\n", G.handCount[0]);


	if(startingHand == endingHand){
		printf("Error! Steward card (cardEffect) not working properly\n");
		exit(0);
	}else{
		printf("SUCCESS (steward)\n");
	}
    
    return 0;

}