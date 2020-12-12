#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(stack** top, complex new)
{
	if (*top == NULL) // jezeli nie ma w stosie jeszcze zadnego elementu
	{
		*top = (stack*)malloc(sizeof(stack)); // alokuj pamiec na wskaznik top
		(*top)->number = new; // gorny element dostaje nowa wartosc wpisana z konsoli
		(*top)->previous = NULL; // nie ma innego elementu w stosie, wiec wskaznik na NULL
	}
	else
	{
		stack* New;  // nowy element
		New = (stack*)malloc(sizeof(stack)); // alokacja nowego elementu
		New->number = new; // nowy element dostaje wartosc wprowadzona z konsoli
		New->previous = *top; // nowy element wskazuje na ten, ktory byl przed chwila na gorze
		*top = New; // podmiana wskaznika gornego elementu
	}
}

void pop(stack** top)
{
	if (*top == NULL) printf("Stos juz jest pusty!\n"); // warunek, kiedy gorny element wskazuje na NULL
	else
	{
		stack* temp = NULL; // tymczasowy wskaznik
		temp = (*top)->previous; // przypisuje element na gorze stosu do tymczasowej zmiennej
		free(*top); // zwalniam pamiec
		*top = temp; // gorny element jest teraz elementem na ktory wskazywal element gorny wczesniej
	}
}

void empty(stack* top)
{
	(top == NULL) ? printf("Stos jest pusty!\n") : printf("Stos nie jest pusty!\n"); // jezeli wskaznik top jest NULL to wykonaj pierwsza instrukcje, w przeciwnym wypadku druga
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
	if (top == NULL) printf("Stos jest pusty!\n"); // warunek kiedy wskaznik top jest ustawiony na NULL
	else
	{
		stack* temp = top; // tymczasowy wskaznik na gorny element
		do
		{
			printf("%.3lf + %.3lfi\n", temp->number.real, temp->number.imaginary); // wyswietl liczby na ktore wskazuje tymczasowy wskaznik
			temp = temp->previous; // zmiana wskaznika na wartosc poprzednia
		} while (temp != NULL); // dopoki tymczasowy wskaznik nie bedzie wskazywal na NULL, czyli do ostatniego elementu
	}
}