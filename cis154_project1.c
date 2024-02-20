/*
Victor Van
2/11/2024, Due: 2/26/2024
C - Professor Penta
Project 1
*/

#include <stdio.h>
#include <math.h>

void run_interface(void);
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
	scanf("%d", &user_input);
	switch (user_input)
	{
	case 0:
		printf("Terminal Termination!\n");
		return;
	case 1:
		printf("Quantum Code Translator\n");
		quantum_code_translator('f');
		break;
	case 2:
		printf("Intergalactic Signal Identifier\n");
		intergalactic_signal_identifier('v');
		break;
	case 3:
		printf("Energy Pulse Analyzer\n");
		energy_pulse_analyzer('4');
		break;
	case 4:
		printf("Nanorefractor Predictor\n");
		nano_refractor_predictor(9.72);
		break;
	case 5:
		printf("Astronavigation Averager\n");
		astro_navigation_averager(617, 978, 603, 404, 318);
		break;
	case 6:
		printf("Gravity Wave Synchronizer\n");
		gravity_wave_synchronizer(510, 411);
		break;
	default:
		printf("Error: Invalid Input!\n");
		break;
	}
	run_interface();
}

void quantum_code_translator(char quantumCode)
{
	printf("%d\n", quantumCode);
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

void nano_refractor_predictor(double cosmicElement)
{
	double test_decimal_place = cosmicElement + 0.5;
	if ((int)test_decimal_place == (int)cosmicElement + 1)
	{
		int round_up = (int)cosmicElement + 1;
		printf("%d", round_up);
	}
	else
	{
		int round_down = (int)cosmicElement;
		printf("%d", round_down);
	}
}

void astro_navigation_averager(int d1, int d2, int d3, int d4, int d5)
{
	double average_dimension = (d1 + d2 + d3 + d4 + d5)/5;
	printf("%lf", average_dimension);
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