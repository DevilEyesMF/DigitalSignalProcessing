// includes
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// defines
#define pi M_PI

// typedefs
typedef struct
{
	double amplitude;
	double frequency;
	double phase;
}Wave;

// prototype functions
void generate_sinewave(double, double, double, double, int, double*);
void add_waves(double*, double*, int, double*);

// main
int main()
{
	// constants
	const int NUMBER_OF_SAMPLES = 8;
	const double SAMPLING_FREQ = 8000;

	// variables
	Wave wave1 = {
	.amplitude = 1,
	.frequency = 1000,
	.phase = 0
	};

	Wave wave2 = {
	.amplitude = 0.5,
	.frequency = 2000,
	.phase = 3 / 4 * pi
	};

	// allocate memory
	double* x1 = (double*)calloc(NUMBER_OF_SAMPLES, sizeof(double));
	double* x2 = (double*)calloc(NUMBER_OF_SAMPLES, sizeof(double));
	double* sum = (double*)calloc(NUMBER_OF_SAMPLES, sizeof(double));

	generate_sinewave(wave1.amplitude, wave1.frequency, SAMPLING_FREQ, wave1.phase, NUMBER_OF_SAMPLES, x1);

	for (int i = 0; i < NUMBER_OF_SAMPLES; i++)
	{
		printf("point %d: %lf\n", i, x1[i]);
	}

	return 0;
}

// generate_sinewave
void generate_sinewave(double a, double f, double fs, double p, int n, double* x)
{
	for (int i = 0; i < n; i++)
	{
		x[i] = sin(2 * pi * (f / fs) * i + p);
	}

	return;
}

// add_waves
void add_waves(double* x1, double* x2, int n, double* sum)
{

}
