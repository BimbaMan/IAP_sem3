#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define CRT_SECURE_NO_WARNINGS

struct node
{
	int data;
	int max, min;
	struct node* next;
};

typedef struct node node;

node* CreateStack(int data) {
	node* top;
	top = (node*)malloc(sizeof(node));

	top->data = data;
	top->max = data;
	top->next = NULL;

	return top;
}

node* Push(node* head, int data) {
	node* tmp;

	tmp = (node*)malloc(sizeof(node));

	tmp->data = data;
	if (head == NULL) {
		tmp->max = data;
		tmp->min = data;
		tmp->next = NULL;
		return tmp;
	}
	else {
		if (data > head->max) {
			tmp->max = data;
		}
		else
		{
			tmp->max = head->max;
		}
		if (data < head->min)
		{
			tmp->min = data;
		}
		else
		{
			tmp->min = head->min;
		}
	}
	tmp->next = head;
	return tmp;
}

node* Pop(node* head) {
	if (head == NULL) {
		return NULL;
	}
	node* tmp = head->next;
	free(head);
	return tmp;
}

void ViewStack(node* head) {
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void Max(node* head) {
	int pos = 1;
	while (head != NULL)
	{
		if (head->data == head->max) {
			printf("max %d\n", head->data);
			
			break;
		}
		pos++;
		head = head->next;
	}
	printf("pos: %d\n", pos);
}

void Min(node *head) {
	while (head != NULL)
	{
		if (head->data == head->min)
		{
			printf("min %d\n", head->data);
			break;
		}
		head = head->next;
	}
}

void main() {
	node* head = NULL;
	int value = 0, k, c;
	bool flag = true, fv = true;

	printf("Enter number to push in stack:\n");
	scanf("%d", &value);
	while (fv)
	{
		if (value >= -50 && value <= 50)
		{
			fv = false;
			head = Push(head, value);
		}
		else
		{
			printf("Enter number in -50..+50\n");
		}
	}

	while (flag == true)
	{
		printf("Menu: 1-Push; 2-Show; 3-Max and min; 4-Pop; 5-Exit\n");
		scanf("%d", &k);
		switch (k)
		{
		case 1:
			printf("\nEnter number:\n");
			scanf("%d", &value);
			if (value >= -50 && value <= 50)
			{
				head = Push(head, value);
			}
			else
			{
				printf("Enter number in -50..+50\n");
			}
			
			printf("\n");
			break;
		case 2:
			printf("\nStack content:\n");
			ViewStack(head);
			break;
		case 3:
			printf("\n");
			Max(head);
			Min(head);
			printf("\n");
			break;
		case 4:
			head = Pop(head);
			break;
		case 5:
			while (head != NULL)
			{
				head = Pop(head);
			}
			printf("\nStack content:\n");
			ViewStack(head);
			flag = false;
			break;
		}
	}

}
