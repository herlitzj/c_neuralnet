#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "gates.c"

void main() {
	srand((unsigned)time(NULL));
	double tweak_amount = 0.01;
	double best_out = -10000.0;
	double best_x = -2.0;
	double best_y = 3.0;
	int i;

	for(i = 0; i < 10000; i++) {
		double rand_x = ((double)rand()/(double)RAND_MAX);
		double rand_y = ((double)rand()/(double)RAND_MAX);
		double x_try = best_x + tweak_amount * (rand_x * 2 - 1);
		double y_try = best_y + tweak_amount * (rand_y * 2 - 1);
		double output = forwardMultiplyGate(x_try, y_try);
		if(output > best_out) {
			best_out = output;
			best_x = x_try;
			best_y = y_try;
		}
	}

	printf("BEST X: %f\n", best_x);
	printf("BEST Y: %f\n", best_y);
	printf("BEST OUT: %f\n", best_out);
}