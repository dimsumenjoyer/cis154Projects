/*
Victor Van
2/11/2024, Due: 2/26/2024
C - Professor Penta
Project 1
*/

#include <stdio.h>
#include <math.h>

typedef struct
{
	int d1, d2, d3, d4, d5;
} Distance;

typedef struct
{
	double h1, h2;
} Height;

int main(void);
void run_interface(void);

char enter_quantum_code(void);
double enter_cosmic_element(void);
Distance enter_distances(void);
Height enter_heights(void);

void quantum_code_translator(char quantumCode);
void intergalactic_signal_identifier(char quantumCode);
void energy_pulse_analyzer(char quantumCode);
void nano_refractor_predictor(double cosmicElement);
void astro_navigation_averager(int d1, int d2, int d3, int d4, int d5);
void gravity_wave_synchronizer(double h1, double h2);

int main(void)
{
	run_interface();
	return 0;
}

void run_interface(void)
{
	int user_input;
	printf("What do you want to do?\n");
	scanf(" %d", &user_input);
	Distance distance;
	Height height;
	switch (user_input)
	{
	case 0:
		printf("Terminal Termination!\n");
		return;
	case 1:
		printf("Quantum Code Translator\n");
		char quantumCode = enter_quantum_code();
		quantum_code_translator(quantumCode);
		break;
	case 2:
		printf("Intergalactic Signal Identifier\n");
		intergalactic_signal_identifier(enter_quantum_code());
		break;
	case 3:
		energy_pulse_analyzer(enter_quantum_code());
		break;
	case 4:
		nano_refractor_predictor(enter_cosmic_element());
		break;
	case 5:
		distance = enter_distances();
		astro_navigation_averager(distance.d1, distance.d2, distance.d3, distance.d4, distance.d5);
		break;
	case 6:
		height = enter_heights();
		gravity_wave_synchronizer(height.h1, height.h2);
		break;
	default:
		printf("Error: Invalid Input!\n");
		break;
	}
	run_interface();
}

char enter_quantum_code()
{
	char quantumCode;
	printf("Enter a quantum code: ");
	scanf(" %d", &quantumCode);
	return quantumCode;
}

void quantum_code_translator(char quantumCode)
{
	printf(" %d\n", quantumCode);
}

void intergalactic_signal_identifier(char quantumCode)
{
	if ((quantumCode > 64 && quantumCode < 90 ) || (quantumCode > 96 && quantumCode < 123))
	{
		printf("Signal Detected: UPF\n");
	}
	else
	{
		printf("Signal Detected: Unknown\n");
	}
}

void energy_pulse_analyzer(char quantumCode)
{
	char checkForEvenOrOdd = quantumCode % 2;
	if (checkForEvenOrOdd == 0)
	{
		printf("Signal Strength: Strong\n");
	}
	else if (checkForEvenOrOdd < 0)
	{
		printf("Error: Unknown Signal Strength\n");
	}
	else
	{
		printf("Signal Strength: Weak\n");
	}
}

double enter_cosmic_element(void)
{
	double cosmicElement;
	printf("Enter a value for cosmic element: ");
	scanf(" %lf", &cosmicElement);
	return cosmicElement;
}

void nano_refractor_predictor(double cosmicElement)
{
	// int(number + 0.5) == int(number + 1)
	double test_decimal_place = cosmicElement + 0.5;
	if ((int)test_decimal_place == (int)cosmicElement + 1)
	{
		int round_up = (int)cosmicElement + 1;
		printf(" %d", round_up);
	}
	else
	{
		int round_down = (int)cosmicElement;
		printf(" %d", round_down);
	}
}

Distance enter_distances(void)
{
	Distance distance;
	printf("Enter 5 Distances: ");
	scanf(" %d", &distance.d1);
	scanf(" %d", &distance.d2);
	scanf(" %d", &distance.d3);
	scanf(" %d", &distance.d4);
	scanf(" %d", &distance.d5);
	return distance;
}

void astro_navigation_averager(int d1, int d2, int d3, int d4, int d5)
{
	double average_dimension = (d1 + d2 + d3 + d4 + d5)/5;
	printf(" %lf", average_dimension);
}

Height enter_heights(void)
{
	Height height;
	printf("Enter 2 Heights: ");
	scanf(" %lf", &height.h1);
	scanf(" %lf", &height.h2);
	return height;
}

void gravity_wave_synchronizer(double h1, double h2)
{
	double differenceOfHeight = abs(h1 - h2);
	if (differenceOfHeight < 0.001)
	{
		printf("Compatible.\n");
	}
	else
	{
		printf("Uncompatible.\n");
	}
}