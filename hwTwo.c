/*****************************************************
* FILENAME : hwTwo.c
*
* DESCRIPTION :
*       CS 256: Homework Assignment #2 dealing with basic
*				arithmetic functions and loops.
*
* AUTHOR :  Amir Sotoodeh
* START DATE : 4/9/18
*
******************************************************/
#include <stdio.h>

int main(){

	printf("CS256 Homework Assignment #2\n\n");

	//Chapter 2 Problem #4
	printf("Chapter 2 Problem 4: Restaurant Bill\n");
	printf("--------------------------\n");
	float mealCharge = 88.67;
	float tax = mealCharge*0.0675;
	float newAmount = mealCharge + tax;
	float tip = newAmount*0.2;
	printf("Meal Charge: $%.2f\nTax Amount: $%.2f\nTip Amount: $%.2f\nTotal Bill: $%.2f\n",mealCharge,tax,tip,newAmount);
	//END Chapter 2Problem #4

	//Chapter 2 Problem #7
	printf("\nChapter 2 Problem 7: Ocean Levels\n");
	printf("-----------------------\n");
	float risingRate = 1.5;
	int year = 5;
	printf("The ocean level will rise %.2f millimeters in %d years.\n",(float)year*risingRate, year);
	year += 2;
	printf("The ocean level will rise %.2f millimeters in %d years.\n",(float)year*risingRate, year);
	year += 3;
	printf("The ocean level will rise %.2f millimeters in %d years.\n",(float)year*risingRate, year);
	//END Chapter 2 Problem #7

	//Chapter 3 Problem #23
	printf("\nChapter 3 Problem 23: Stock Transaction Program\n");
	printf("---------------------------------------\n");
	int shares = 1000;
	float pricePerShare = 45.50;
	float commission = 0.02;
	float newPricePerShare = 56.90;
	float paid = (float)shares*pricePerShare;
	float received = (float)shares*newPricePerShare;

	printf("Joe paid $%.2f for %d stocks.\n",paid,shares);
	printf("Joe paid $%.2f in commission when buying %d stocks.\n",(float)(shares*pricePerShare)*commission, shares);
	printf("Joe received $%.2f when selling %d stocks.\n",received,shares);
	printf("Joe paid $%.2f in commission when selling %d stocks.\n",(float)(shares*newPricePerShare)*commission,shares);
	float profit = (received - received*commission)-(paid + paid*commission);
	printf("Joe profited $%.2f when trading stocks.\n",profit);
	//END Chapter 3 Problem #23

	//Chapter 5 Problem #23
	printf("\nChapter 5 Problem 23: Pattern Displays\n");
	printf("----------------------------------------");

	for(int i=0;i<11;i++){
		for(int j = 0; j<i;j++){
			printf("+");
		}
		printf("\n");
	}

	printf("\n");

	for(int i=10;i>=1;i--){
		for(int j = 0; j<i;j++){
			printf("+");
		}
		printf("\n");
	}
	//END Chapter 5 Problem #23


}
