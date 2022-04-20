#include <stdlib.h>
#include <stdio.h>
int main()
{
	int mat[4][4];
	for (int i = 0; i <= 3; i++) {	//input matrix
		for (int j = 0; j <= 3; j++) {
			printf("(%d;%d)=", i, j);
			scanf_s("%d", &mat[i][j]);
		}
	}
	int max = mat[0][0], col = 0, row = 0;
	for (int i = 0; i <= 3; i++) {		//output matrix and count max
		for (int j = 0; j <= 3; j++) {
			printf("%d \t", mat[i][j]);
			if (max < mat[i][j]) {
				max = mat[i][j]; col = j; row = i;
			}
		}
		printf("\n");
	}
	printf("\n");

	if (col==0 && row==0){
		printf("Na svoem meste!");
		return 0;
	}

	int temp = 0;
	for (int i = row; i >= 1; i--) {			//change rows
		for (int j = 0; j <= 3; j++) {
			temp = mat[i][j];
			mat[i][j] = mat[i - 1][j];
			mat[i - 1][j] = temp;
		}
	}

	temp = 0;
	for (int j = col; j >= 1; j--) {			//change columns
		for (int i = 0; i <= 3; i++) {
			temp = mat[i][j];
			mat[i][j] = mat[i][j - 1];
			mat[i][j - 1] = temp;
		}
	}

	for (int i = 0; i <= 3; i++) {		//output matrix
		for (int j = 0; j <= 3; j++) {
			printf("%d \t", mat[i][j]);
		}
		printf("\n");
	}



	return 0;
}

