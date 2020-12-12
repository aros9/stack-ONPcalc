#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "calculator.h"

int main()
{
    stack* top; // wskaznik na gore stosu
    top = NULL; // na poczatu wskazuje na NULL - nie ma zadnych elementow na stosie

    complex number; // numer czytany z konsoli
    /*
    char operator; // zmienna wczytana z konsoli okreslajaca rodzaj dzialania na liczbach ze stosu

    for (;;)
    {
        number.imaginary = 0; // zerowanie czesci urojonej liczby zespolonej w razie gdyby uzytkownik nie podal takiej wartosci
        operator = '0'; // "zerowanie" operatora
        system("cls");
        printf("======STOS======\n");
        display(top); // wyswietl stos
        printf("================\n");
        printf("KALKULATOR ONP\n");


        while (operator == '0')
        {
            scanf("%lf %lf %c", &number.real, &number.imaginary, &operator);
            push(&top, number);
        }

        if (top->previous == NULL) operator = '0'; // jezeli zostala podana tylko jedna liczba i znak dzialania

        switch (operator)
        {
        case '+': // dodawanie dwoch liczb z gory stosu
        {
            top->previous->number = add(top->previous->number, top->number);
            pop(&top);
        }
            break;
        case '-': // odejmowanie dwoch liczb z gory stosu
        {
            top->previous->number = subtract(top->previous->number, top->number);
            pop(&top);
        }
            break;
        case '*': // mnozenie dwoch liczb z gory stosu
        {
            top->previous->number = multiply(top->previous->number, top->number);
            pop(&top);
        }
            break;
        case '/': // dzielenie dwoch liczb z gory stosu
        {
            top->previous->number = divide(top->number, top->previous->number);
            pop(&top);
        }
            break;
        default:
            break;
        }

    }
    */
    


    int choice;

    for (;;)
    {
        system("cls");
        printf("Aktualny stan stosu: ");
        display(top);

        printf("1. Poloz element na stosie.\n");
        printf("2. Zdejmij element ze stosu.\n");
        printf("3. Sprawdz czy stos jest pusty.\n");
        printf("4. Wyczysc stos.\n");
        printf("5. Zakonczyc program.\n");

        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Wpisz liczbe jaka chcesz dodac: ");
            number.imaginary = 0;
            scanf_s("%lf %lf", &number.real, &number.imaginary);
            push(&top, number);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            empty(top); Sleep(2000);
            break;
        case 4:
            clear(&top);
            break;
        default:
        {
            printf("Zakonczenie programu!\n");
            exit(0);
        }
            break;
        }

    }
    

    return 0;
}