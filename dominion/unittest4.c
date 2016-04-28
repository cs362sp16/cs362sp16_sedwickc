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

    //int updateCoins(int player, struct gameState *state, int bonus)
    //printf("Hand coins: %d\n",countHandCoins(0,&G));
    G.hand[0][2] = 6;
    G.hand[0][3] = 5;

	updateCoins(0, &G, 1); 
	//printf("%d\n",G.coins);
	if(G.coins == 4){
		printf("Error! updateCoins\n");
	}else{
        printf("SUCCESS (updateCoins)\n");
    }

    return 0;
    //
}