/*****************************************************
* FILENAME : hwThree.c
*
* DESCRIPTION :
*       Homework Assignment #3
*
* AUTHOR :  Amir Sotoodeh
* START DATE : 4/15/18
*
******************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159

	float newPopulation(int P, float B, float D){
		float new = (P + B*P - D*P);
		return new;
	}

	int* reverseArray(int a[], int size){
	    int *array;
	    array= malloc(size*sizeof(int));


		int j = 0;

		for(int i = size;i>=0;i--){
			array[j] = a[i];
			j++;
		}


		return array;
	}

	int checkgameBoard(char gameBoard[3][3])
	{
	    int x;
	    for(x = 0; x < 3; x++)
	    {

	      if ((gameBoard[x][0] != '*') &&
	          (gameBoard[x][0] == gameBoard[x][1]) &&
	          (gameBoard[x][0] == gameBoard[x][2]))
	         return(gameBoard[x][0] == 'O' ? -1 : 1);


	      if ((gameBoard[0][x] != '*') &&
	          (gameBoard[0][x] == gameBoard[1][x]) &&
	          (gameBoard[0][x] == gameBoard[2][x]))
	         return(gameBoard[0][x] == 'O' ? -1 : 1);
	    };


	    if ((gameBoard[0][0] != '*') &&
	       (gameBoard[0][0] == gameBoard[1][1]) &&
	       (gameBoard[0][0] == gameBoard[2][2]))
	      return(gameBoard[0][0] == 'O' ? -1 : 1);


	    if ((gameBoard[2][0] != '*') &&
	       (gameBoard[2][0] == gameBoard[1][1]) &&
	       (gameBoard[0][0] == gameBoard[0][2]))
	      return(gameBoard[2][0] == 'O' ? -1 : 1);


	    return 0;
	}

int main(){

	printf("CS256 Homework Assignment #3\n\n");

	//Chapter 4 Problem #23
	printf("Chapter 4 Problem 23: Geometry Calculator\n");

	printf("1. Calculate the Area of a Circle\n");
	printf("2. Calculate the Area of a Rectangle\n");
	printf("3. Calculate the Area of a Triangle\n");
	printf("4. Quit\n");
	printf("Enter your choice (1-4):\n");

	int choice;
	scanf("%d", &choice);


	if(choice == 1){
		printf("Enter the radius of the circle:\n");
		double radius;
		scanf("%le",&radius);
		if(radius<0){
			printf("Error: Invalid entry.\n");
		}
		else{
			printf("The area of the circle is: %.2f\n",pow(radius,2)*PI);
		}
	}
	else if(choice == 2){
		printf("Enter the length and width of the rectangle:\n");
		double length;
		double width;
		scanf("%le%lf",&length,&width);

		if(length<0 || width<0){
					printf("Error: Invalid entry.\n");
		}
		else{
		printf("The area of the rectangle is: %.2f\n", length*width);
		}
	}
	else if(choice == 3){
		printf("Enter the base and height of the triangle:\n");
		double base;
		double height;
		scanf("%le%lf",&base,&height);

		if(base<0 || height<0){
					printf("Error: Invalid entry.\n");
		}
		else{
		printf("The area of the triangle is: %.2f\n", 0.5*base*height);
		}
	}
	else if(choice == 4){
		exit(0);
	}
	else{
		printf("Error: Invalid choice.\n");
	}


	//Chapter 6 Problem 16: Population
	printf("\nChapter 6 Problem 16: Population\n");
	int startingSize;
	float birthRate;
	float deathRate;
	int years;
	printf("Please enter starting population size:\n");
	scanf("%d",&startingSize);
	if(startingSize<2){
		exit(0);
	}
	printf("Please enter the annual birth rate:\n");
	scanf("%f",&birthRate);
	printf("Please enter the annual death rate:\n");
	scanf("%f",&deathRate);
	if(birthRate<0 || deathRate<0){
		exit(0);
	}
	printf("Please enter the amount of years to display:\n");
	scanf("%d",&years);
	if(years<1){
		exit(0);
	}

	if(years <2){
		exit(0);
	}
	else{
		float newPop = (float)newPopulation(startingSize,birthRate,deathRate);
		printf("Year 1: %.0f\n",newPop);

		for(int i = 0; i<years-1; i++){
			newPop = newPopulation(newPop,birthRate,deathRate);
			printf("Year %d: %.0f\n",i+2,newPop);
		}
	}

	printf("\nChapter 7 Problem 18 Tic-Tac-Toe Game");

	int player = 0;
	int winner = 0;
	int row = 0;
	int column = 0;
	int line = 0;
	char gameBoard [3][3] = {
					{'*','*','*'},
					{'*','*','*'},
					{'*','*','*'}
	};
		for (int i = 0; i<9 && winner==0; i++)
		{
			printf("\n\n");
			printf(" %c | %c | %c\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
			printf("---|---|---\n");
			printf(" %c | %c | %c\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
			printf("---|---|---\n");
			printf(" %c | %c | %c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
			player = i%2 + 1;

			do
			{
					printf("\nPlayer %d, please enter the row and column of where you want to place your %c: ", player,(player==1)?'X':'O');
					scanf("%d%d", &row,&column);
			}while((row > 2 || column > 2 || row<0 || column <0) || (gameBoard[row][column] == 'X' || gameBoard[row][column] == 'O'));

			gameBoard[row][column] = (player == 1) ? 'X' : 'O';

			winner = checkgameBoard(gameBoard);

		}

		if(winner==0)
			printf("The game is a draw\n");
		else
			printf("\nPlayer %d has won\n", winner);

		printf("\n\n");
		printf(" %c | %c | %c\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
		printf("---|---|---\n");
		printf(" %c | %c | %c\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
		printf("---|---|---\n");
		printf(" %c | %c | %c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);


	printf("Chapter 9 Problem 10: Reverse Array\n");

	int array[] = {10, 20, 30, 40, 50};

	int *reversedArray = reverseArray(array, 5);

	printf("Original array: ");
	for(int i = 0;i<5;i++){
		printf("%d ",array[i]);
	}
	printf("\n");

	printf("Reversed array: ");
	for(int i = 1;i<6;i++){
		printf("%d ",reversedArray[i]);
	}


	return 0;

}
