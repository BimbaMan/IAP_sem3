#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main()
{
	char inputstr[255];
	gets(inputstr);

	int i = 0;		//delete trash symbols 
	while (i < strlen(inputstr))
	{
		if (!((inputstr[i] > 'A') && (inputstr[i] < 'Z') || ((inputstr[i] > 'a') && (inputstr[i] < 'z')) || (inputstr[i] == ' ')))
		{
			for (int j = i; j < strlen(inputstr); j++)
			{
				inputstr[j] = inputstr[j + 1];
			}
			i--;
		}
		i++;
	}

	i = 0;		//trim left side
	while (i < strlen(inputstr))
	{
		if (inputstr[i] == ' ')
		{
			for (int j = i; j < strlen(inputstr); j++)
			{
				inputstr[j] = inputstr[j + 1];
			}
			//i--;
		}
		
		if (inputstr[i] != ' ')
		{
			break;
		}
		//i++;
	}

	i = strlen(inputstr)-1;		//trim rigth side
	while (i > 0)
	{
		if (inputstr[i] == ' ')
		{
			inputstr[i] = '\0';
			i--;

		}
		if (inputstr[i] != ' ')
		{
			break;
		}
	}

	char checkedstr[255];
	strcpy_s(checkedstr, sizeof checkedstr, inputstr);

	printf("length is %d\n",strlen(checkedstr));
	puts(checkedstr);
	
	char lastword[255];			//last word
	int counter = 0;
	int j = 0;
	for (int i = strlen(checkedstr) - 1; i >= 0; i--) {
		if (ispunct(checkedstr[i]) != NULL || isspace(checkedstr[i]) != NULL) {
			lastword[counter] = '\0';
			break;
		}
		else {
			lastword[counter] = checkedstr[i];
			lastword[counter + 1] = '\0';
			counter++;
		}
	}

	strcpy(lastword, strrev(lastword));
	printf("last word is %s\n", lastword);




}