#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define CRT_SECURE_NO_WARNINGS


struct nodeStruct
{
	int data;
	struct nodeStruct* next;
};
typedef struct nodeStruct node;

struct queueStruct
{
	node* front;
	node* rear;
};
typedef struct queueStruct queue;

bool isEmpty(queue* q);
void Add(queue* q, int data);
int Delete(queue* q, int queueLength);
void Show(queue* q, int queueLength);
void swapFirstAndLast(queue* q, int queueLength);

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	queue* q;
	q = malloc(sizeof(queue));
	q->front = NULL;
	q->rear = NULL;
	node* head = NULL;
	node* tail = NULL;
	int value = 0, key = 0;

	printf("Введите число для помещения в очередь:\n");
	scanf("%d", &value);
	do {
		if (value >= 50 || value <= -50)
		{
			printf("Число должно быть в интервале [-50;50]\n");
			printf("Введите число для помещения в очередь:\n");
			scanf("%d", &value);
		}
	} while (value > 50 || value < -50);
	Add(q, value);
	int queueLength = 1;
	tail = head;

	while (true)
	{
		printf("Menu:\n 1 - add;\n 2 - delete;\n 3 - swap;\n 4 - show;\n 5 - queue length;\n 6 - exit;\n");
		scanf("%d", &key);

		switch (key)
		{
		case 1:
			printf("Enter number:\n");
			scanf("%d", &value);
			do {
				if (value >= 50 || value <= -50)
				{
					printf("Число должно быть в интервале [-50;50]\n");
					printf("Введите число для помещения в очередь:\n");
					scanf("%d", &value);
				}
			} while (value > 50 || value < -50);
			Add(q, value);
			queueLength++;
			break;
		case 2:
			queueLength = Delete(q, queueLength);
			break;
		case 3:
			swapFirstAndLast(q, queueLength);
			break;
		case 4:
			printf("Queue content:\n");
			Show(q, queueLength);
			break;
		case 5:
			printf("Queue length: %d\n", queueLength);
			break;
		case 6:
			exit(0);
		}
	}

}

bool isEmpty(queue* q)
{
	return (q->front == NULL);
}

void Add(queue* q, int value) {
	node* tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp->data = value;
	tmp->next = NULL;
	if (isEmpty(q))
	{
		q->front = q->rear = tmp;
	}
	else
	{
		q->rear->next = tmp;
		q->rear = tmp;
	}
}

int Delete(queue* q, int queueLength) {
	node* tmp;
	tmp = q->front;
	if (queueLength > 0)
	{
		q->front = q->front->next;
		free(tmp);
		queueLength--;
		return queueLength;
	}
	else
	{
		printf("Удалять нечего, очередь пуста\n");
		return queueLength;
	}
}

void Show(queue* q, int queueLength) {
	node* tmp;
	tmp = q->front;
	if (queueLength > 0)
	{
		while (tmp != NULL)
		{
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
		printf("\n");
	}
	else
	{
		printf("Очередь пуста\n");
	}

}

void swapFirstAndLast(queue* q, int queueLength) {
	int counter = -1;
	node* tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp = q->front;
	node* tmp1;
	tmp1 = (node*)malloc(sizeof(node));
	if (queueLength == 1 || queueLength == 0)
	{
		printf("Нечего менять\n");
		return;
	}
	else
	{
		tmp1->data = q->front->data;
		q->front->data = q->rear->data;
		q->rear->data = tmp1->data;
		Show(q, queueLength);

		while (tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}
		printf("Элементов между первым и последним: %d\n", counter-1);
	

	}
}