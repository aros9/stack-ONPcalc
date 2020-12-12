#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

complex add(complex a,complex b) // dodawanie liczb zespolonych
{
	complex result;
	result.real = a.real + b.real;
	result.imaginary = a.imaginary + b.imaginary;
	return result;
}

complex subtract(complex a, complex b) // odejmowanie liczb zespolonych
{
	complex result;
	result.real = a.real - b.real;
	result.imaginary = a.imaginary - b.imaginary;
	return result;
}

complex multiply(complex a, complex b) // mnozenie liczb zespolonych
{
	complex result;
	result.real = a.real * b.real - a.imaginary * b.imaginary;
	result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	return result;
}

complex divide(complex a, complex b) // dzielenie liczb zespolonych 
{
	complex result;
	if ((a.imaginary == 0) && (b.imaginary == 0)) // w przypadku, gdy obie liczby nie maja czesci urojonej, mozna je potraktowac jako liczby rzeczywiste
	{
		result.real = a.real / b.real;
		result.imaginary = 0;
		return result;
	}
	else
	{
		result.real = (a.real * b.real + a.imaginary * b.imaginary) / (a.imaginary * a.imaginary + b.imaginary * b.imaginary);
		result.imaginary = (a.imaginary * b.real - a.real * b.imaginary)/(a.imaginary * a.imaginary + b.imaginary * b.imaginary);
		return result;
	}
}