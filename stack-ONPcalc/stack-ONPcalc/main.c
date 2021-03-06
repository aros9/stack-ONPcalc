#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "calculator.h"

int main()
{
    stack* top; // wskaznik na gore stosu
    top = NULL; // na poczatu wskazuje na NULL - nie ma zadnych elementow na stosie
    int choice, i; // wybor, zmienna do poprawnego czytania znaku operacji z konsoli
    complex number; // numer czytany z konsoli

    int c;

    char operator; // zmienna wczytana z konsoli okreslajaca rodzaj dzialania na liczbach ze stosu
    char tab[50]; // bufor potrzebny do odczytu z konsoli za pomoca funkcji fgets

    for (;;)
    {
        i = 0;
        operator = '0'; // "zerowanie" operatora
        system("cls");
        printf("======STOS======\n");
        display(top); // wyswietl stos
        printf("================\n");
        printf("\n");


        printf("(1) Poloz element na stosie.\n");
        printf("(2) Zdejmij element ze stosu.\n");
        printf("(3) Sprawdz czy stos jest pusty.\n");
        printf("(4) Wyczysc stos.\n");
        printf("(5) Zakoncz program.\n");

        while (scanf("%d", &choice) != 1 || (choice < 1 || choice > 5))
        {
            printf("Niepoprawna wartosc!\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }

        switch (choice)
        {
        case 1:
        {
            printf("Wpisz element ktory chcesz dodac na stos: ");
            number.imaginary = 0; // zerowanie czesci urojonej liczby zespolonej w razie gdyby uzytkownik nie podal takiej wartosci

            getchar();// getchar uzywany do czyszczenia bufora po wczytywaniu z konsoli wartosci "choice"
            fgets(tab, 50, stdin);

            if ((c = sscanf(tab, "%lf %lf", &number.real, &number.imaginary)) != 0 && c != EOF )
            {
                push(&top, number);
            }
            else
            {
                if (top == NULL || top->previous == NULL) // jezeli jest za malo liczb do dzialania
                {
                    operator = '0';
                    printf("Za malo liczb do dzialania!\n");
                    Sleep(2000);
                }
                else
                {
                    sscanf(tab, "%c", &operator);
                    while (operator == ' ')
                    {
                        operator = tab[i];
                        i++;
                    }
                    if (operator == '+' || operator == '-' || operator == '*' || operator == '/')
                    {
                        printf("Operacja: '%c'\n", operator);
                        Sleep(2000);
                    }
                    else
                    {
                        printf("Niepoprawna operacja!\n");
                        Sleep(2000);
                    }
                }
            }

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
                if ((top->previous->number.real == 0) && (top->number.real == 0)) printf("[0/0] -> symbol nieoznaczony!\n");
                else if ((top->previous->number.imaginary == 0) && (top->number.imaginary == 0) && top->number.real == 0) printf("Dzielenie przez 0!\n");
                else
                {
                    top->previous->number = divide(top->previous->number, top->number);
                    pop(&top);
                }
            }
            break;
            default:
                break;
            }
        }
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
        case 5:
        {
            printf("Zakonczenie programu!\n");
            clear(&top);
            exit(0);
        }
        break;
        }
    }
        return 0;
    }
