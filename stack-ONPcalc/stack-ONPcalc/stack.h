#include <stdio.h>
#include <stdlib.h>

struct complex
{
	double real;
	double imaginary;
};
typedef struct complex complex;

struct stack
{
	complex number;
	struct stack *previous;
}; 
typedef struct stack stack;


void push(stack** top, complex new);
void pop(stack** top);
void empty(stack* top);
void clear(stack** top);
void display(stack* top);

