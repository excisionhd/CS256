/*****************************************************
* FILENAME : project1.c
*
* DESCRIPTION :
*       Project #1, a theater sales system that prints
*       and allows the user to buy tickets as well
*       as see overall statistics of sales.
*
* AUTHOR :  Amir Sotoodeh
* START DATE : 4/22/18
*
******************************************************/
#include <stdio.h>
	char seatingChart[15][30];
	int choosing = 1;
	int choice = 0;
	float price;
	float seatingPrice[15];
	float totalSales=0;
	int seatsSold=0;
	int available=0;

	void updateSeating(int row, int col, char seating[15][30]){
		seating[row][col]= '*';
	}

	void printChart(char seating[15][30]){
		printf("\t\t    Seats\n\t");
		for(int i=0;i<30;i++){
			printf("%d",(i+1)%10);
		}
		printf("\n");
		for (int row = 0;row <15;row++){
			printf("Row %d\t",row+1);
			for(int col = 0; col <30;col++){
				printf("%c",seating[row][col]);
			}
			printf(" Price: $%.2f\n", seatingPrice[row]);
		}
	}

	void userIntro(){
		for(int i=0;i<15;i++){
			printf("Enter the price of a seat in Row %d\n",i+1);
		    scanf("%f", &price);
		    seatingPrice[i] = price;

		}

		for (int row = 0;row <15;row++){
			for(int col = 0; col <30;col++){
				seatingChart[row][col] = '#';
			}
		}
	}

	int main(){

		printf("CS256 Project #1: Theater Seating\n\n");

		userIntro();
		printChart(seatingChart);

		do{
			int done = 0;
			printf("\nPlease select an option:\n");
			printf("1. Buy tickets.\n");
			printf("2. See seating chart.\n");
			printf("3. See total sales.\n");
			printf("4. See available seating.\n");
			printf("5. Quit.\n");
			scanf("%d", &choice);

			switch(choice) {

			   case 1:
			   	   	do{
						int row, col;

						printf("Enter the row and seat to purchase.  Type 0 for either to quit. ");
						scanf("%d%d",&row,&col);


						if(row == 0 || col == 0){
							break;
						}
						if(row < 16 && row>0 && col > 0 && col <31 && seatingChart[row-1][col-1] != '*'){
							updateSeating(row-1,col-1,seatingChart);
							seatsSold++;
							totalSales += seatingPrice[row-1];
							printChart(seatingChart);
						}
						else{
							printf("Error: Seat taken or invalid entry.\n");
						}

			   	   	}while(done == 0);

			   	   	break;

			   case 2:
				   printChart(seatingChart);
				   break;

			   case 3:
				   printf("Total Sales: $%.2f\n",totalSales);
				   break;
			   case 4:


				   printf("Seats sold: %d\n",seatsSold);
				   for(int i=0;i<15;i++){
					   for(int j=0;j<30;j++){
						   if (seatingChart[i][j] == '#'){
							   available++;
						   };
					   }
					   printf("Seats available in Row %d: %d\n",i+1,available);
					   available=0;
				   }
				   printf("Seats available in Auditorium: %d\n", 450-seatsSold);
				   break;

			   case 5:
				   choosing=0;
				   break;

			   default:
				   break;

			}
		}
		while(choosing == 1);

		printf("Thank you for using this program.");

		return 0;

	}
