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

    initializeGame(numPlayers, k, 1, &G);
    
    G.coins = 99;
    if(buyCard(3, &G) != 0){
        printf("Error! buyCard not working properly\n");
    }
    
    G.numBuys = 0;
    if(buyCard(3, &G) != -1){
        printf("Error! buyCard not working properly\n");
    }
    
    G.numBuys = 1;
    G.supplyCount[0] = 0;
    if(buyCard(0, &G) != -1){
        printf("Error! buyCard not working properly\n");
    }
    
    G.coins = 2;
    if(buyCard(3, &G) != -1){
        printf("Error! buyCard not working properly\n");
    }
    printf("SUCCESS (buyCard)\n");
    return 0;
    //G.numBuys = 1;
    
}