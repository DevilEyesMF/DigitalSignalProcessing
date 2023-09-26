// includes
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// defines
#define pi M_PI

// prototype functions
void convolution(double*, int, double*, int, double*);

double seq1[3] = { 1, 2, 3 };
double seq2[2] = { 1, 2 };
double* seqOut;

// main
int main()
{
	return 0;
}

void convolution(double* x, int xlen, double* h, int hlen, double* y)
{
	int n = xlen + hlen - 1; // number of iterations
	y = (double*)calloc(n, sizeof(double));

	for (int i = 0; i < n; i++)
	{

	}

	return;
}