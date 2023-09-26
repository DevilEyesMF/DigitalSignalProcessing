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
	.phase = 3.0 / 4.0 * pi
	};

	// allocate memory
	double* x1 = (double*)calloc(NUMBER_OF_SAMPLES, sizeof(double));
	double* x2 = (double*)calloc(NUMBER_OF_SAMPLES, sizeof(double));
	double* sum = (double*)calloc(NUMBER_OF_SAMPLES, sizeof(double));

	generate_sinewave(wave1.amplitude, wave1.frequency, SAMPLING_FREQ, wave1.phase, NUMBER_OF_SAMPLES, x1);
	generate_sinewave(wave2.amplitude, wave2.frequency, SAMPLING_FREQ, wave2.phase, NUMBER_OF_SAMPLES, x2);

	add_waves(x1, x2, NUMBER_OF_SAMPLES, sum);

	for (int i = 0; i < NUMBER_OF_SAMPLES; i++)
	{
		printf("point %d:\twave 1: %lf\t\twave 2: %lf\t\tsum: %lf\n", i, x1[i], x2[i], sum[i]);
	}

	return 0;
}

// generate_sinewave
void generate_sinewave(double a, double f, double fs, double p, int n, double* x)
{
	for (int i = 0; i < n; i++)
	{
		x[i] = a * sin(2 * pi * (f / fs) * i + p);
	}

	return;
}

// add_waves
void add_waves(double* x1, double* x2, int n, double* sum)
{
	for (int i = 0; i < n; i++)
	{
		sum[i] = x1[i] + x2[i];
	}

	return;
}
