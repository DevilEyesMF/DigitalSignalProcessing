// includes
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

// defines
#define NUMBER_OF_SAMPLES 8

// prototype functions
void generate_sinewave(double, double, double, double, int, double*);
void add_waves(double*, double*, int, double*);

int main()
{
	// variables
	double a1 = 1;
	double f1 = 1000;

	// allocate memory
	double* x1 = (double*)calloc(NUMBER_OF_SAMPLES, sizeof(double));
	double* x2 = (double*)calloc(NUMBER_OF_SAMPLES, sizeof(double));
	double* sum = (double*)calloc(NUMBER_OF_SAMPLES, sizeof(double));



	return 0;
}

void generate_sinewave(double a, double f, double fs, double phi, int n, double* x)
{

}

void add_waves(double* x1, double* x2, int N, double* sum)
{

}