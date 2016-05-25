#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "interface.h"
#include <stdlib.h>

int moneyCounter(struct gameState *state){
    int money = 0;
    int i=0;
    while(i<numHandCards(state)){
        if (handCard(i, state) == copper){
            playCard(i, -1, -1, -1, state);
            money++;
        }
        else if (handCard(i, state) == silver){
            playCard(i, -1, -1, -1, state);
            money += 2;
        }
        else if (handCard(i, state) == gold){
            playCard(i, -1, -1, -1, state);
            money += 3;
        }
        i++;
    }
    return money;
}
int main (int argc, char** argv) {
    struct gameState G;
    struct gameState *p = &G;
    int numPlay = (rand() % 4) + 1;
    int k[10] = {adventurer, gardens, embargo, minion, baron, mine, council_room,
	       sea_hag, tribute, smithy};
    
    printf ("Starting game.\n");
    
    initializeGame(numPlay, k, atoi(argv[1]), p);
    printf ("Starting game.\n");
    int money = 0;
    int smithyPos = -1;
    int adventurerPos = -1;
    int sea_hagPos = -1;
    int baronPos = -1;
    int minionPos = -1;
    int tributePos = -1;
    int council_roomPos = -1;
    int i=0;
    
    int numSmithies = 0;
    int numtributes = 0;
    int numAdventurers = 0;
    int numBarons = 0;
    int numSeaHags = 0;
    int numMinions = 0;
    int numcouncil_rooms = 0;


    while (!isGameOver(p)) {
        money = 0;
        smithyPos = -1;
        adventurerPos = -1;
        sea_hagPos = -1;
        baronPos = -1;
        tributePos = -1;
        council_roomPos = -1;
        minionPos = -1;

        for (i = 0; i < numHandCards(p); i++) {
            if (handCard(i, p) == copper)
                money++;
            else if (handCard(i, p) == silver)
                money += 2;
            else if (handCard(i, p) == gold)
                money += 3;
            else if (handCard(i, p) == smithy)
                smithyPos = i;
            else if (handCard(i, p) == adventurer)
                adventurerPos = i;
            else if (handCard(i, p) == baron)
                baronPos = i;
            else if (handCard(i, p) == sea_hag)
                sea_hagPos = i;
            else if (handCard(i, p) == tribute)
                tributePos = i;
            else if (handCard(i, p) == minion)
                minionPos = i;
            else if (handCard(i, p) == council_room)
                council_roomPos = i;
        }
        
        if (whoseTurn(p) == 0) {
            //printHand(whoseTurn(p), p);

            if (smithyPos != -1) {
                printf("0: smithy played from position %d\n", smithyPos);
                playCard(smithyPos, -1, -1, -1, p);
                printf("smithy played.\n");
                money = moneyCounter(p);
            }
            if(tributePos != -1){
                printf("0: tribute played from position %d\n", tributePos);
                playCard(tributePos, -1, -1, -1, p);
                printf("tribute played.\n");
                money = moneyCounter(p);
            }

            if (money >= 8) {
                printf("%d: bought province\n", whoseTurn(p));
                buyCard(province, p);
            }
            else if (money >= 6) {
                printf("%d: bought gold\n", whoseTurn(p));
                buyCard(gold, p);
            }
            else if ((money >= 5) && (numtributes < 2)) {
                printf("%d: bought tribute\n", whoseTurn(p));
                buyCard(tribute, p);
                numtributes++;
            }
            else if ((money >= 4) && (numSmithies < 2)) {
                printf("%d: bought smithy\n", whoseTurn(p));
                buyCard(smithy, p);
                numSmithies++;
            }
            else if (money >= 3) {
                printf("%d: bought silver\n", whoseTurn(p));
                buyCard(silver, p);
            }
            
            printf("%d: end turn\n", whoseTurn(p));
            endTurn(p);
        }else if (whoseTurn(p) == 1){
            //printHand(whoseTurn(p), p);

            if (adventurerPos != -1) {
                printf("%d: adventurer played from position %d\n", whoseTurn(p),adventurerPos);
                playCard(adventurerPos, -1, -1, -1, p);
                money = moneyCounter(p);
            }
            if (minionPos != -1) {
                printf("%d: minion played from position %d\n", whoseTurn(p),minionPos);
                playCard(minionPos, rand() % 2, rand() % 2, rand() % 2, p);
                money = moneyCounter(p);
            }

            if (money >= 8) {
                printf("%d: bought province\n", whoseTurn(p));
                buyCard(province, p);
            }
            else if ((money >= 6) && (numAdventurers < 2)) {
                printf("%d: bought adventurer\n",whoseTurn(p));
                buyCard(adventurer, p);
                numAdventurers++;
            }else if (money >= 6){
                printf("%d: bought gold\n", whoseTurn(p));
                buyCard(gold, p);
            }else if ((money >= 5) && (numtributes < 2)) {
                printf("%d: bought minion\n", whoseTurn(p));
                buyCard(minion, p);
                numMinions++;
            }else if (money >= 3){
                printf("%d: bought silver\n", whoseTurn(p));
                buyCard(silver, p);
            }
            printf("%d: end turn\n", whoseTurn(p));
            
            endTurn(p);      
        }
        else if (whoseTurn(p) == 2){
            printHand(whoseTurn(p), p);
            if (baronPos != -1) {
                printf("%d: baron played from position %d\n", whoseTurn(p),baronPos);
                playCard(baronPos, 1, -1, -1, p);
                money = moneyCounter(p);
            }
            if (council_roomPos != -1) {
                printf("%d: council_room played from position %d\n", whoseTurn(p),council_roomPos);
                playCard(council_roomPos, 1, -1, -1, p);
                money = moneyCounter(p);
            }
            
            if (money >= 8) {
                printf("%d: bought province\n", whoseTurn(p));
                buyCard(province, p);
            }
            if (money >= 6){
                printf("%d: bought gold\n", whoseTurn(p));
                buyCard(gold, p);
            }else if (money >= 5){
                printf("%d: bought council_room\n", whoseTurn(p));
                buyCard(council_room, p);
                numcouncil_rooms++;
            }else if (money >= 4) {
                printf("%d: bought baron\n",whoseTurn(p));
                buyCard(baron, p);
                numBarons++;
            }
            else if (money >= 3){
                printf("%d: bought silver\n", whoseTurn(p));
                buyCard(silver, p);
            }
            printf("%d: end turn\n", whoseTurn(p));
            
            endTurn(p);     
        }
        else if (whoseTurn(p) == 3){
            //printHand(whoseTurn(p), p);

            if (sea_hagPos != -1) {
                printf("%d: sea_hag played from position %d\n", whoseTurn(p),sea_hagPos);
                playCard(sea_hagPos, -1, -1, -1, p);
                money = moneyCounter(p);
            }
            
            if (money >= 8) {
                printf("%d: bought province\n", whoseTurn(p));
                buyCard(province, p);
            }
            else if ((money >= 4) && (numSeaHags < 2)) {
                printf("%d: bought sea_hag\n",whoseTurn(p));
                buyCard(sea_hag, p);
                numSeaHags++;
            }else if (money >= 6){
                printf("%d: bought gold\n", whoseTurn(p));
                buyCard(gold, p);
            }else if (money >= 3){
                printf("%d: bought silver\n", whoseTurn(p));
                buyCard(silver, p);
            }
            printf("%d: end turn\n", whoseTurn(p));
            
            endTurn(p);     
        }
        
        for(i = 0; i < numPlay; i++){
            printf ("Player %d: %d\n", i, scoreFor(i, p));
        }
        
    } // end of While
    
    printf ("Finished game.\n");
    for(i = 0; i < numPlay; i++){
        printf ("Player %d: %d\n", i, scoreFor(i, p));
    }
    
    return 0;
}

