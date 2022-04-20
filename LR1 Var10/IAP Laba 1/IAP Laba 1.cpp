﻿// IAP Laba 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
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


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.