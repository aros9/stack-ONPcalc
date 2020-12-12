#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main()
{
    stack* top;
    top = NULL;

    complex number;

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
            empty(top);
            break;
        case 4:
            clear(top);
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