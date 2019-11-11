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
 	testState.hand[1][0] = copper;
 	testState.hand[1][1] = copper;
 	testState.hand[1][2] = copper;
 	testState.hand[1][3] = copper;
 	testState.hand[1][4] = copper;

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
  printf(">>>> UNIT TESTING: MINE FUNCTION <<<< \n\n");

  printf("Testing First Exit Case\n");
  functionReturn = mineCardEffect(mineChoice1, mineChoice2, currentPlayer, handPos, &testState);
  mineAssert(functionReturn, -1);

  mineChoice1 = copper;
  mineChoice2 = -1;

  printf("Testing Second Exit Case\n");
  functionReturn = mineCardEffect(mineChoice1, mineChoice2, currentPlayer, handPos, &testState);
  mineAssert(functionReturn, -1);

  mineChoice1 = gold;
  mineChoice2 = curse;

  printf("Testing Third Exit Case\n");
  functionReturn = mineCardEffect(mineChoice1, mineChoice2, currentPlayer, handPos, &testState);
  mineAssert(functionReturn, -1);

  mineChoice1 = copper;
  mineChoice2 = province;

  printf("Testing Standard Usage\n");
  functionReturn = mineCardEffect(mineChoice1, mineChoice2, currentPlayer, handPos, &testState);
  mineAssert(testState.handCount[currentPlayer], 5);

  printf(">>>> UNIT TESTING COMPLETED <<<< \n\n");

   return 0;
 }
