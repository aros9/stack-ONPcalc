#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(stack** top, complex new)
{
	if (*top == NULL)
	{
		*top = (stack*)malloc(sizeof(stack));
		(*top)->number = new;
		(*top)->previous = NULL;
	}
	else
	{
		stack* New;
		New = (stack*)malloc(sizeof(stack));
		New->number = new;
		New->previous = *top;
		*top = New;
	}
}

void pop(stack** top)
{
	if (*top == NULL) printf("Stos juz jest pusty!\n");
	else
	{
		stack* temp = NULL;
		temp = (*top)->previous;
		free(*top);
		*top = temp;
	}
}

void empty(stack* top)
{
	(top == NULL) ? printf("Stos jest pusty!\n") : printf("Stos nie jest pusty!\n"); // jezeli wskaznik top jest NULL to wykonaj 1 instrukcje, w przeciwnym wypadku druga
}

void clear(stack** top)
{
	while (*top != NULL)
	{
		pop(top);
	}
}

void display(stack* top)
{
	printf("\n");
	if (top == NULL) printf("Stos jest pusty!\n");
	else
	{
		stack* temp = top;
		do
		{
			printf("%.3lf + %.3lfi\n", temp->number.real, temp->number.imaginary);
			temp = temp->previous;
		} while (temp != NULL);
	}
}
