// includes
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// defines
#define pi M_PI
#define SIZE(a) sizeof(a)/sizeof(a[0])

// prototype functions
void convolution(double*, int, double*, int, double**);

double seq1[] = { 1,7,7,0,1,3};
double seq2[] = { 48,293,27,6887,9888};
double* seqOut;

// main
int main()
{
	double* y;

	convolution(seq2, SIZE(seq2), seq1, SIZE(seq1), &y);

	return 0;
}

void convolution(double* x, int xlen, double* h, int hlen, double** y)
{
	int i = xlen + hlen - 1; // number of iterations
	*y = (double*)calloc(i, sizeof(double));

	int kmin;
	int kmax;

	for (int n = 0; n < i; n++)
	{
		// kmin
		if (n >= (xlen < hlen ? xlen : hlen))
		{
			kmin = n - (xlen < hlen ? xlen : hlen) + 1;
		}
		else
		{
			kmin = 0;
		}

		// kmax
		if (n >= (xlen > hlen ? xlen : hlen))
		{
			kmax = (xlen > hlen ? xlen : hlen) - 1;
		}
		else
		{
			kmax = n;
		}

		for (int k = kmin; k <= kmax; k++)
		{
			if(xlen > hlen)
			{
				(*y)[n] += x[k] * h[n - k];
			}
			else
			{
				(*y)[n] += h[k] * x[n - k];
			}
		}
	}

	return;
}