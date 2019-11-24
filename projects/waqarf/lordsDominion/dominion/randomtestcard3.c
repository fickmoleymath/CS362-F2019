/*
 * Random Test File - THree
 * Name: Faaiq G Waqar
 * Date: November 16th 2019
 * Function: Tribute
 */

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include "rngs.h"
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>

 int tributeAssert(int, int);

 int tributeAssert(int variable1, int variable2){
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
   int nextPlayer = 0;
   int currentPlayer = 1;
   int functionReturn = 0;
   int handPos = 0;
   int bonus = 0;
  int tributeRevealedCards[MAX_HAND];
   struct gameState testState;

   int i = 0;

   srand(time(NULL));

  printf(">>>> RANDOM TESTING: TRIBUTE FUNCTION <<<< \n\n");

  for(i = 0; i < 100; i++){

   	testState.numPlayers = 2;
   	testState.numBuys = rand() % 128;
   	testState.coins = rand() % 128;
   	testState.discardCount[1] = 0;
   	testState.handCount[1] = 5;
   	testState.hand[1][0] = ambassador;
   	testState.hand[1][1] = estate;
   	testState.hand[1][2] = duchy;
   	testState.hand[1][3] = province;
   	testState.hand[1][4] = estate;
    testState.deckCount[1] = 3;
    testState.deck[1][0] = duchy;
    testState.deck[1][1] = province;
    testState.deck[1][2] = estate;

   	testState.discardCount[0] = 0;
   	testState.handCount[0] = 5;
   	testState.hand[0][0] = mine;
   	testState.hand[0][1] = estate;
   	testState.hand[0][2] = duchy;
   	testState.hand[0][3] = province;
   	testState.hand[0][4] = estate;
    testState.deckCount[0] = 1;
    testState.deck[0][0] = duchy;
   	testState.whoseTurn = 1;
   	testState.numActions = rand() % 128;
   	testState.playedCardCount = rand() % 128;

    tributeRevealedCards[0] = copper;
    tributeRevealedCards[1] = estate;
    tributeRevealedCards[2] = silver;
    tributeRevealedCards[3] = duchy;

    printf("Testing for Small Count, high Deck\n");
    functionReturn = playTribute(handPos, &testState, currentPlayer, nextPlayer, tributeRevealedCards, &bonus);
    tributeAssert(testState.deckCount[0], 0);

    testState.deckCount[0] = 0;
    testState.discardCount[0] = 1;
    testState.discard[0][0] = tribute;

    printf("Testing for Small Count, high Discard\n");
    functionReturn = playTribute(handPos, &testState, currentPlayer, nextPlayer, tributeRevealedCards, &bonus);
    tributeAssert(testState.discardCount[0], -1);

    testState.discardCount[0] = 0;

    printf("Testing for no revealable\n");
    functionReturn = playTribute(handPos, &testState, currentPlayer, nextPlayer, tributeRevealedCards, &bonus);
    tributeAssert(testState.deckCount[0], 1);
    tributeAssert(testState.discardCount[0], 0);

    testState.deckCount[0] = 1;
    testState.discardCount[0] = 1;
    testState.discard[0][0] = tribute;

    printf("Testing for standard process\n");
    functionReturn = playTribute(handPos, &testState, currentPlayer, nextPlayer, tributeRevealedCards, &bonus);
    tributeAssert(testState.deckCount[1], 4);

  }

  printf(">>>> UNIT TESTING COMPLETED <<<< \n\n");
  return 0;
 }
