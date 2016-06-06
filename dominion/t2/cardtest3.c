#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "interface.h"
#include "dominion.h"

int checkVillage(int currentPlayer, struct gameState *state, int handPos){
    int r, startingHand, endingHand, actionsBefore, actionsAfter;
    int deckB, deckA;
    
    startingHand = state->handCount[currentPlayer];
    actionsBefore = state->numActions;
    
    state->hand[currentPlayer][2] = 14;
    
    printf("handCount: %d, Actions: %d\n",startingHand,actionsBefore);
    
    r = cardEffect(14,0,0,0,state,2,0);
    
    endingHand = state->handCount[currentPlayer];
    actionsAfter = state->numActions;
    
    printf("handCount: %d, Actions: %d\n",endingHand,actionsAfter);
    
    if((startingHand != endingHand) || (actionsAfter != (actionsBefore+2))){
        printf("Error! Village card (cardEffect) not working properly\n");
        exit(0);
    }else{
        printf("SUCCESS (village)\n");
    }
}


int main(){
	struct gameState G;
    int numPlayers;
	numPlayers = 2;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	//Assert fail
	initializeGame(numPlayers, k, 1, &G);
	//printf("Hand 1 size: %d\n", G.handCount[0]);
	//printf("Hand 2 size: %d\n", G.handCount[1]);

	
	//printf("Actions: %d\n", actionsBefore);
    checkVillage(floor((int)Random() % 2), &G, 2);

    return 0;
}