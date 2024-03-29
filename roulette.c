#include <math.h> // ceil
#include <stdlib.h> // free
#include "roulette.h"
#include "globals.h"


void recalculateRouletteStats(void){
	int i;

	recalculateLengthsSum();

	overall_lengths_weights_sum = 0;
	for(i = 0; i < mi_constant; ++i){
		overall_lengths_weights[i] = overall_lengths_sum/overall_lengths[i];
		overall_lengths_weights_sum += overall_lengths_weights[i];
	}
}

void recalculateLengthsSum(void){
	int i;

	overall_lengths_sum = 0;
	for(i = 0; i < mi_constant; ++i){
		overall_lengths_sum += overall_lengths[i];
	}
}


int getParentRoulette(unsigned *seed){
	int x, i = 0;
	float sum = 0;
	
	x = rand_my(seed) % (int)ceil(overall_lengths_weights_sum);
	
	//TODO jest rozjazd miedzy trzymana suma a faktyczna - tylko czemu?
	// for(y = 0; y < mi_constant; ++y){
	// 	sum += overall_lengths[y];
	// }

	// printf("%d, %f\n",x,overall_lengths_sum - sum);
	// sum = 0;
	
	while(sum < x && i < mi_constant){
		sum += overall_lengths_weights[i];		
		++i;
	}
	
	return i-1<0?0:i-1;
}