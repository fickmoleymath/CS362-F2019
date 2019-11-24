/*
 * Unit Test File - Three
 * Name: Faaiq G Waqar
 * Date: November 10th 2019
 * Function: Ambassador
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ambassadorAssert(int, int);

int ambassadorAssert(int variable1, int variable2){
	if(variable1 == variable2){
		printf("PASSED: Equivalent\n");
		return 0;
	}
	if(variable1 > variable2){
		printf("FAILED: Greater Than\n");
		return -1;
	}
	if(variable1 < variable2){
		printf("FAILED: Less Than\n");
		return 1;
	}

 	return -1;
}

int main(){
  int ambassadorChoice1 = 0;
  int ambassadorChoice2 = 3;
  int defaultCurrent = 1;
  int defaultHand = 0;
	int functionReturn = 0;
  struct gameState testState;

	testState.numPlayers = 2;
	testState.numBuys = 0;
	testState.coins = 0;
	testState.discardCount[1] = 0;
	testState.handCount[1] = 5;
	testState.hand[1][0] = ambassador;
	testState.hand[1][1] = estate;
	testState.hand[1][2] = duchy;
	testState.hand[1][3] = province;
	testState.hand[1][4] = estate;

	testState.discardCount[0] = 0;
	testState.handCount[0] = 5;
	testState.hand[0][0] = mine;
	testState.hand[0][1] = estate;
	testState.hand[0][2] = duchy;
	testState.hand[0][3] = province;
	testState.hand[0][4] = estate;
	testState.whoseTurn = 1;
	testState.numActions = 0;
	testState.playedCardCount = 0;

	printf(">>>> UNIT TESTING: AMBASSADOR FUNCTION <<<< \n\n");

	printf("Testing First Exit Case\n");
	functionReturn = playAmbassador(ambassadorChoice1, ambassadorChoice2, &testState, defaultCurrent, defaultHand);
	ambassadorAssert(functionReturn, -1);

	ambassadorChoice1 = 0;
	ambassadorChoice2 = 1;

	printf("Testing Second Exit Case\n");
	functionReturn = playAmbassador(ambassadorChoice1, ambassadorChoice2, &testState, defaultCurrent, defaultHand);
	ambassadorAssert(functionReturn, -1);

	ambassadorChoice1 = 1;
	ambassadorChoice2 = 1;

	printf("Testing Third Exit Case\n");
	functionReturn = playAmbassador(ambassadorChoice1, ambassadorChoice2, &testState, defaultCurrent, defaultHand);
	ambassadorAssert(functionReturn, -1);

	ambassadorChoice1 = 4;
	ambassadorChoice2 = 0;

	printf("Testing Primary Base Case\n");
	functionReturn = playAmbassador(ambassadorChoice1, ambassadorChoice2, &testState, defaultCurrent, defaultHand);
	ambassadorAssert(testState.supplyCount[1], 0);
	ambassadorAssert(testState.handCount[0], 6);

	printf(">>>> UNIT TESTING COMPLETED <<<< \n\n");

  return 0;
}
