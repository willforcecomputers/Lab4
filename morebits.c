/*
 * morebits.c
 *
 *  Created on: Oct 19, 2016
 *      Author: William
 */

#include <stdio.h>

int getbits(unsigned int num, int lsb, int msb) { //return value of bits between the lsb and msb values.

	unsigned int bitnum = 0; //accumulator for ON bits
	unsigned int i = 0; //bit to be tested

	for (i = (1 << msb); i >= (1 << lsb); i = (i >> 1)) { //for each bitwise value in the range of bits

		if((num & i) > 0) { //if specified bit exists in given number, add to accumulator

			bitnum += i;
		}
	}

	return (bitnum >> lsb);
}

int main() {

	//varibales for run 1
	int x = 752;
	int y = 3;
	int z = 6;

	//variable for run 2
	int a = 4223;
	int b = 6;
	int c = 12;

	//variables for run 3
	int j = 90675;
	int k = 1;
	int l = 13;

	printf("getbits(%x,%d,%d) = [%x] Expecting [e]\n", x, y, z, getbits(x, y, z));
	printf("getbits(%x,%d,%d) = [%x] Expecting [41]\n", a, b, c, getbits(a, b, c));
	printf("getbits(%x,%d,%d) = [%x] Expecting [1119]\n", j, k, l, getbits(j, k, l));

	return 1;
}
