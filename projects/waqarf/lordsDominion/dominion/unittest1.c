/*
* Unit Test File - One
* Name: Faaiq G Waqar
* Date: November 10th 2019
* Function: Baron
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
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
  int bonus = 0;
	struct gameState testState;

	testState.numPlayers = 1;
	testState.numBuys = 0;
	testState.coins = 0;
	testState.discardCount[1] = 0;
	testState.handCount[1] = 5;
	testState.hand[1][1] = mine;
	testState.hand[1][2] = estate;
	testState.hand[1][3] = duchy;
	testState.hand[1][4] = province;
	testState.hand[1][5] = estate;

	printf(">>>> UNIT TESTING: BARON FUNCTION <<<< \n\n");

	printf("Testing for standard process\n");
	functionCheck = playBaron(baronChoice, &testState, currentPlayer, &bonus);
	baronCheck = baronAssert(testState.numBuys, 1);
	baronCheck = baronAssert(testState.coins, 4);
	baronCheck = baronAssert(testState.discardCount[1], 1);

	baronChoice = 0;
  functionCheck = playBaron(baronChoice, &testState, currentPlayer, &bonus);

  testState.numPlayers = 1;
  testState.numBuys = 0;
	testState.coins = 0;
  testState.discardCount[1] = 0;
  testState.handCount[1] = 5;
	testState.hand[1][1] = mine;
  testState.hand[1][2] = mine;
  testState.hand[1][3] = duchy;
  testState.hand[1][4] = province;
  testState.hand[1][5] = mine;

	printf("Testing for no estate process\n");
	baronChoice = 1;
	functionCheck = playBaron(baronChoice, &testState, currentPlayer, &bonus);
	baronCheck = baronAssert(testState.numBuys, 0);
	baronCheck = baronAssert(testState.coins, 3);

	testState.numPlayers = 1;
	testState.numBuys = 0;
	testState.coins = 0;
	testState.discardCount[1] = 0;
	testState.handCount[1] = 5;
	testState.hand[1][1] = mine;
	testState.hand[1][2] = mine;
	testState.hand[1][3] = duchy;
	testState.hand[1][4] = province;
	testState.hand[1][5] = mine;
	testState.supplyCount[1] = 2;

	functionCheck = playBaron(baronChoice, &testState, currentPlayer, &bonus);
	baronCheck = baronAssert(testState.supplyCount[estate], 1);

	printf(">>>> UNIT TESTING COMPLETED <<<< \n\n");

	return 0;
}
