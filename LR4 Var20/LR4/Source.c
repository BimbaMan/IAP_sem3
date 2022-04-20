#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS
#define NEW_LINE_CODE 10
#define DELIM_CODE '\0'
#define ARR_LEN 20
#define MAX_PH_LEN 100
#define MAX_NAME_LEN 50

typedef struct lib
{
	unsigned int number;
	char *name;
	char *PubHouse;
	struct tm date;
} book;

void Add(book *arr, int Amount)
{
	printf("Number: ");
	scanf_s("%d", &arr[Amount].number);

	char temp[MAX_NAME_LEN];
	printf("Name: ");
	while (getchar() != '\n');
	fgets(temp, MAX_NAME_LEN, stdin);
	int i = strlen(temp) - 1;
	if (temp[i] == NEW_LINE_CODE)
	{
		temp[i] = DELIM_CODE;
	}
	arr[Amount].name = (char*)malloc(sizeof(char) * (MAX_NAME_LEN + 1));
	strcpy(arr[Amount].name, temp);

	
	char temp1[MAX_PH_LEN];
	printf("Publishing house: ");
	fgets(temp1, MAX_PH_LEN, stdin);
	i = strlen(temp1) - 1;
	if (temp1[i] == NEW_LINE_CODE)
	{
		temp1[i] = DELIM_CODE;
	}
	arr[Amount].PubHouse = (char*)malloc(sizeof(char) * (MAX_PH_LEN + 1));
	strcpy(arr[Amount].PubHouse, temp1);

	printf("Date (day month year): ");
	scanf_s("%d%d%d", &arr[Amount].date.tm_mday, &arr[Amount].date.tm_mon, &arr[Amount].date.tm_year);
}

int Delete(book *arr, int n, bool f)
{ 
	f = 0;
	unsigned int num = sizeof(unsigned int);
	for (unsigned int i = 0; i < ARR_LEN; i++)
	{
		if (arr[i].number == n)
		{
			num = i;	f = 1;
			while (num < (ARR_LEN - 1))
			{
				arr[num] = arr[num+ 1];
				num++;
			}
			return f;
			break;
		}
	}
	return f;


}

void ShowStruct(book *b)
{
	printf("Number  : %d\n", (*b).number);
	printf("Name: %s\n", (*b).name);
	printf("Publishing house : %s\n", (*b).PubHouse);
	printf("Date  : %02d.%02d.%04d\n", (*b).date.tm_mday, (*b).date.tm_mon, (*b).date.tm_year);
}

void main()
{
	book bookArr[ARR_LEN];
	
	int ArrAmount = 0; bool f;
	int swchoice = -1;
	do
	{
		printf("Choice:\n1 - Add element\n2 - Delete element\n3 - Show all elements\n4 - Choise publishing house\n5 - Exit\n");
		swchoice = -1;
		scanf_s("%d", &swchoice);

		switch (swchoice)
		{
			case 1: {
			Add(bookArr, ArrAmount);
			ArrAmount++;
			system("cls"); //clean console
			break;
			}

			case 2: {
				int num;
				printf("Enter the number: ");
				while (getchar() != '\n');
				scanf_s("%d", &num);
				if (num >= 0)
				{
					f = 0;
					f = Delete(bookArr, num, f);
					if (f == 1)
					{
						ArrAmount--;
					}
					
				}
				system("cls"); //clean console
				break;
			}

			case 3: {
				system("cls");
				if (ArrAmount>0)
				{
					for (int i = 0; i < ArrAmount; i++)
					{
						ShowStruct(bookArr + i);
						printf("\n");
					}
				}
				else
				{
					printf("No elements found\n");
				}
				break;

			}
			case 4: {
				system("cls");
				char inputstr[MAX_PH_LEN];
				printf("Enter the name of the publishing house: ");
				while (getchar() != '\n');
				 gets(inputstr);
				printf("\n");
				
				for (int i = 0; i < ArrAmount; i++)
				{
					if (strcmp(bookArr[i].PubHouse, inputstr) == 0)
					{
						ShowStruct(bookArr + i);
						printf("\n");
					}
				}
				break;
			}
			
			case 5: {
				break;
			}

			default: printf("Selection error\n");
		}

	} while (swchoice!=5);

}