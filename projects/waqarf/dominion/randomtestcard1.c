/*
* Random Test File - One
* Name: Faaiq G Waqar
* Date: November 16th 2019
* Function: Baron
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int baronAssert(int, int);

int baronAssert(int variable1, int variable2){
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
	int baronCheck = 0;
	int functionCheck = 0;
	int baronChoice = 1;
	int currentPlayer = 1;
  int i = 0;

  int coinChecker;
  int buyChecker;
  int discardChecker;
	struct gameState testState;

  srand(time(NULL));

	printf(">>>> RANDOM TESTING: BARON FUNCTION <<<< \n\n");
  printf("Testing for standard process\n");

  for (i = 0; i < 100; i++){
  	testState.numPlayers = 1;
  	testState.numBuys = rand() % 128;
  	testState.coins = rand() % 128;
  	testState.discardCount[1] = rand() % 128;
  	testState.handCount[1] = 5;
  	testState.hand[1][1] = mine;
  	testState.hand[1][2] = estate;
  	testState.hand[1][3] = duchy;
  	testState.hand[1][4] = province;
  	testState.hand[1][5] = estate;

    coinChecker = testState.coins + 1;
    buyChecker = testState.numBuys + 1;
    discardChecker = testState.discardCount[1] + 1;

  	functionCheck = baronCardEffect(baronChoice, &testState, currentPlayer);
  	baronCheck = baronAssert(testState.numBuys, buyChecker);
  	baronCheck = baronAssert(testState.coins, coinChecker);
  	baronCheck = baronAssert(testState.discardCount[1], discardChecker);
  }

  // Only one instance here, not easy to cover at random
	baronChoice = 0;
	functionCheck = baronCardEffect(baronChoice, &testState, currentPlayer);

  baronChoice = -1;
	functionCheck = baronCardEffect(baronChoice, &testState, currentPlayer);

  baronChoice = 1;
	functionCheck = baronCardEffect(baronChoice, &testState, currentPlayer);


  for(i = 0; i < 100; i++){
    testState.numPlayers = 1;
    testState.numBuys = rand() % 128;
  	testState.coins = rand() % 128;
    testState.discardCount[1] = 0;
    testState.handCount[1] = 5;
  	testState.hand[1][1] = mine;
    testState.hand[1][2] = mine;
    testState.hand[1][3] = duchy;
    testState.hand[1][4] = province;
    testState.hand[1][5] = mine;

    coinChecker = testState.coins + 3;
    buyChecker = testState.numBuys;

  	printf("Testing for no estate process\n");
  	baronChoice = 1;
  	functionCheck = baronCardEffect(baronChoice, &testState, currentPlayer);
  	baronCheck = baronAssert(testState.numBuys, 0);
  	baronCheck = baronAssert(testState.coins, 3);
  }

  for(i = 0; i < 100; i++){
    baronChoice = rand() % 1;
  	testState.numPlayers = rand() % 5;
  	testState.numBuys = rand() % 5;
  	testState.coins = rand() % 5;
  	testState.discardCount[1] = 0;
  	testState.handCount[1] = 5;
  	testState.hand[1][1] = mine;
  	testState.hand[1][2] = mine;
  	testState.hand[1][3] = duchy;
  	testState.hand[1][4] = province;
  	testState.hand[1][5] = mine;
  	testState.supplyCount[1] = 2;

  	functionCheck = baronCardEffect(baronChoice, &testState, currentPlayer);
  	baronCheck = baronAssert(testState.supplyCount[estate], 1);
  }

  for(i = 0; i < 100; i++){
    testState.numPlayers = rand() % 5;
    testState.numBuys = rand() % 5;
    testState.coins = rand() % 5;
    testState.discardCount[1] = 0;
    testState.handCount[1] = 5;
    testState.hand[1][1] = mine;
    testState.hand[1][2] = mine;
    testState.hand[1][3] = duchy;
    testState.hand[1][4] = province;
    testState.hand[1][5] = mine;
    testState.supplyCount[estate] = rand() % 128;

    functionCheck = baronCardEffect(baronChoice, &testState, currentPlayer);
  }


	printf(">>>> RANDOM TESTING COMPLETED <<<< \n\n");

	return 0;
}
