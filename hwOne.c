#include <stdio.h>

//two ways to do constant
#define PI 3.141592654

int main(int argc, char **argv)
{
	int x;
	char y;
	double z;

	x = 2;
	y = 'A';
	z = PI;
	int A = 3;

	x++;
	++x;

	int checkPre = ++x+A; //x = 5
	int checkPost = A+x++; //x = 4

	int prof = 0;
	int pres = 1;

	/*
	if(prof == 1 && pres == 1){
		printf("Go to class.\n");
	}
	else{
		printf("Do not go to class.\n");
	}
	*/

	//(prof == 1) ? printf("Go to class.\n"):printf("Do not go to class.\n");


	//printf("checkPre: %d, checkPost: %d\n",checkPre,checkPost);

    //printf("X = %d, Y = %c, Z = %.2f\n", x, y, z);

	printf("Hello World.");

    return 0;
}
