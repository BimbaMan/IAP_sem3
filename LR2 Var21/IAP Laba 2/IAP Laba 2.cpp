// IAP Laba 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
int main()
{

	int mat[6][6];
	for (int i = 0; i < 6; i++) {	//input matrix
		for (int j = 0; j < 6; j++) {
			printf("(%d;%d)=", i, j);
			scanf_s("%d", &mat[i][j]);
		}
	}

	for (int i = 0; i < 6; i++) {		//output matrix
		for (int j = 0; j < 6; j++) {
			printf("%d \t", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int min = 0, sumodd = 0;
	for (int i = 0; i < 6; i += 2) {				//finding min elem's in odd str's & sum it
		min = mat[i][0];
		for (int j = 0; j < 6; j++) {
			if (mat[i][j] < min) {
				min = mat[i][j];
			}
		}
		sumodd += min;
	}

	int sumeven = 0, max=0;
	for (int i = 1; i < 6; i += 2) {			//finding max elem's in even str's & sum it
		max = mat[i][0];
		for (int j = 0; j < 6; j++) {
			if (mat[i][j] > max) {
				max = mat[i][j];
			}
		}
		sumeven += max;
	}

	printf("\n"); 
	printf("sum odd num's = %d", sumodd);
	printf("\n");
	printf("sum even num's = %d", sumeven);


	return 0;
}

