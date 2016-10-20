/*
 * getbits.c
 *
 *  Created on: Oct 18, 2016
 *      Author: William
 */
#include <stdio.h>

int getbits(unsigned int num, int lsb, int msb) {

	unsigned int bitnum = 0;
	unsigned int i = 0;

	for (i = (1 << msb); i >= (1 << lsb); i = (i >> 1)) {

		if((num & i) > 0) {

			bitnum += i;
		}
	}

	return (bitnum >> lsb);
}

int main() {

	int x = 752;
	int y = 3;
	int z = 6;

	int a = 4223;
	int b = 6;
	int c = 12;

	int j = 90675;
	int k = 1;
	int l = 13;

	printf("getbits(%d,%d,%d) = [%d] Expecting [14]\n", x, y, z, getbits(x, y, z));
	printf("getbits(%d,%d,%d) = [%d] Expecting [65]\n", a, b, c, getbits(a, b, c));
	printf("getbits(%d,%d,%d) = [%d] Expecting [4377]\n", j, k, l, getbits(j, k, l));

	return 1;
}
