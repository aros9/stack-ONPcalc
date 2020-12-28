#include <stdio.h>
#include <stdlib.h>

typedef struct complex // struktura liczby zespolonej
{
	double real;
	double imaginary;
}complex;

typedef struct stack // struktura stosu
{
	complex number;
	struct stack *previous;
}stack;

void push(stack** top, complex new); // poloz element na stosie
void pop(stack** top); // zdejmij element ze stosu
void empty(stack* top); // czy stos jest pusty?
void clear(stack** top); // wyczysc stos
void display(stack* top); // wyswietl stos