#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"

int main(){
	int arrayCard[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
	int arrayLen = 27;
	int i;

	for (i = 0; i < arrayLen; i++){
		if (getCost(i) != arrayCard[i])
			printf("Error! getCard");
	}

	if(getCost(27) != -1){
		printf("Error! getCard");
	}
    printf("SUCCESS (getCost)\n");
    return 0;
}