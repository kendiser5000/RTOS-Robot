// IR.c
// Created On:  04/10/19
// Modified On: 04/10/19
// Created By:  Richard Li
#include "ADC.h"
#include "IR.h"
#include <stdio.h>
#include <stdlib.h>

#define FILTERSIZE	5
#define skewRate	0
#define fs 			0
uint16_t medianFilter[FILTERSIZE];
int middle;

void IR_Init(uint32_t channelNum){
	ADC_Open();
	ADC_Collect(channelNum, fs, medianFilter, FILTERSIZE);
	middle = FILTERSIZE / 2;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

//get IR filtered value
int IR_getValue(void){
	qsort(medianFilter, FILTERSIZE, sizeof(int), cmpfunc);
	return medianFilter[middle];
}