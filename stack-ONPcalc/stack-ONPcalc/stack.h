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


void push();
void pop();
int empty();
void clear();
void display();

