/*
 * Unit Test File - Two
 * Name: Faaiq G Waqar
 * Date: November 10th 2019
 * Function: Minion
 */

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include "rngs.h"
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>

 int minionAssert(int, int);

 int minionAssert(int variable1, int variable2){
   if(variable1 == variable2)
 		return 0;
 	if(variable1 > variable2)
 		return -1;
 	if(variable1 < variable2)
 		return 1;

  return -1;
 }

int main(){
  int minionChoice1 = 1;
  int minionChoice2 = 0;
  int defaultHandPos = 1;
  int defaultCurrentPlayer = 1;
  int functionResult = 0;
  struct gameState testState;

  testState.numPlayers = 2;
	testState.numBuys = 0;
	testState.coins = 0;
	testState.discardCount[0] = 0;
	testState.handCount[0] = 5;
	testState.hand[0][0] = minion;
	testState.hand[0][1] = estate;
	testState.hand[0][2] = duchy;
	testState.hand[0][3] = province;
	testState.hand[0][4] = estate;

  testState.discardCount[1] = 0;
  testState.handCount[1] = 5;
  testState.hand[1][0] = mine;
  testState.hand[1][1] = estate;
  testState.hand[1][2] = duchy;
  testState.hand[1][3] = province;
  testState.hand[1][4] = estate;
  testState.whoseTurn = 1;
  testState.numActions = 0;
  testState.playedCardCount = 0;

  printf(">>>> UNIT TESTING: MINION FUNCTION <<<< \n\n");

  printf("Testing First Choice Case\n");
  functionResult = minionCardEffect(defaultHandPos, defaultCurrentPlayer, minionChoice1, minionChoice2, &testState);
  minionAssert(testState.coins, 2);

  testState.coins = 0;
  minionChoice1 = 0;
  minionChoice2 = 1;

  printf("Testing Second Choice Case\n");
  functionResult = minionCardEffect(defaultHandPos, defaultCurrentPlayer, minionChoice1, minionChoice2, &testState);
  minionAssert(testState.handCount[1], 4);

  printf(">>>> UNIT TESTING COMPLETED <<<< \n\n");

  return 0;
}
