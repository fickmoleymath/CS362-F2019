/*
 * Unit Test File - Five
 * Name: Faaiq G Waqar
 * Date: November 10th 2019
 * Function: Mine
 */

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include "rngs.h"
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>

 int mineAssert(int, int);

 int mineAssert(int variable1, int variable2){
 	if(variable1 == variable2)
 		return 0;
 	if(variable1 > variable2)
 		return -1;
 	if(variable1 < variable2)
 		return 1;

  	return -1;
 }

 int main(){
  int mineChoice1 = curse;
  int mineChoice2 = 0;
  int currentPlayer = 1;
  int handPos = 0;
  int functionReturn = 0;
  struct gameState testState;

  testState.numPlayers = 2;
 	testState.numBuys = 0;
 	testState.coins = 0;
 	testState.discardCount[1] = 0;
 	testState.handCount[1] = 5;
 	testState.hand[1][0] = ambassador;
 	testState.hand[1][1] = estate;
 	testState.hand[1][2] = estate;
 	testState.hand[1][3] = estate;
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

  functionReturn = mineCardEffect(mineChoice1, mineChoice2, currentPlayer, handPos, &testState);

  mineChoice1 = copper;
  mineChoice2 = -1;

  functionReturn = mineCardEffect(mineChoice1, mineChoice2, currentPlayer, handPos, &testState);

  mineChoice1 = gold;
  mineChoice2 = curse;

  functionReturn = mineCardEffect(mineChoice1, mineChoice2, currentPlayer, handPos, &testState);

  mineChoice1 = copper;
  mineChoice2 = curse;

  functionReturn = mineCardEffect(mineChoice1, mineChoice2, currentPlayer, handPos, &testState);

   return 0;
 }
