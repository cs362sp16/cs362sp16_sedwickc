#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"

int main(){
	struct gameState G;
	int numPlayers;
	numPlayers = 2;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	//Assert fail
	if (initializeGame(numPlayers, k, 1, &G) == -1){
		printf("Error in initialization! Number of players\n");
    }else if(G.handCount[0] < 5){
        printf("Error in initialization! Number of starting cards\n");
    }
    printf("SUCCESS (initializeGame)\n");
	return 0;
}