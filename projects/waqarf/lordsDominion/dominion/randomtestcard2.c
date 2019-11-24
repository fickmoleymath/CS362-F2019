/*
 * Random Test File - Two
 * Name: Faaiq G Waqar
 * Date: November 16th 2019
 * Function: Minion
 */

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include "rngs.h"
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>

 int minionAssert(int, int);

 int minionAssert(int variable1, int variable2){
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
  int minionChoice1 = 1;
  int minionChoice2 = 0;
  int defaultHandPos = 1;
  int defaultCurrentPlayer = 1;
  int functionResult = 0;
  int bonus = 0;

  int coinChecker;
  int handChecker;
  int i;

  struct gameState testState;
  srand(time(NULL));

  printf(">>>> RANDOM TESTING: MINION FUNCTION <<<< \n\n");

  printf("Testing First Choice Case\n");

  for(i = 0; i < 100; i++){

    testState.numPlayers = 2;
  	testState.numBuys = rand() % 128;
  	testState.coins = rand() % 128;
  	testState.discardCount[0] = 0;
  	testState.handCount[0] = 5;
  	testState.hand[0][0] = minion;
  	testState.hand[0][1] = estate;
  	testState.hand[0][2] = duchy;
  	testState.hand[0][3] = province;
  	testState.hand[0][4] = estate;

    testState.discardCount[1] = 0;
    testState.handCount[1] = rand() % 128;
    testState.hand[1][0] = mine;
    testState.hand[1][1] = estate;
    testState.hand[1][2] = duchy;
    testState.hand[1][3] = province;
    testState.hand[1][4] = estate;
    testState.whoseTurn = 1;
    testState.numActions = 0;
    testState.playedCardCount = 0;

    coinChecker = testState.coins + 2;
    handChecker = testState.handCount[1] - 1;


    printf(">>>> RANDOM TESTING: MINION FUNCTION <<<< \n\n");

    printf("Testing First Choice Case\n");
    functionResult = playMinion(minionChoice1, minionChoice2, &testState, defaultHandPos, defaultCurrentPlayer, &bonus);
    minionAssert(testState.coins, coinChecker);

    testState.coins = 0;
    minionChoice1 = 0;
    minionChoice2 = 1;

    printf("Testing Second Choice Case\n");
    functionResult = playMinion(minionChoice1, minionChoice2, &testState, defaultHandPos, defaultCurrentPlayer, &bonus);
    minionAssert(testState.handCount[1], handChecker);

  }

  printf(">>>> RANDOM TESTING COMPLETED <<<< \n\n");

  return 0;
}
