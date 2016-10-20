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

int rotate_left(unsigned int num, int width, int howmany) { //rotate given amount of leading bits to end of an int

	unsigned int rotanum = num; //rotated number variable
	unsigned int accunum = 0; //accumulator for value to be rotated
	unsigned int i = 0;

	for (i = (width - 1); i >= (width - howmany); i -= 1) { //for loop iterating through bitwise positions within original number

		unsigned int checknum = (1 << i); //number to check for and add/subtract if bit is ON
		if((num & checknum) > 0) { //if bit is on add bitshifted number to accumulator and subtract from rotated number

			accunum = (accunum << 1);
			accunum += (checknum >> (i));
			rotanum -= checknum;

		}

		else { //otherwise just shift the accumulator
			accunum = (accunum << 1);
		}
	}

	rotanum = rotanum << (howmany); //shift rotated number over to make room for accumulator
	rotanum += accunum; //add accumulator to rotated number
	return rotanum;
}

int main() {

	//varibales for getbits run 1
	int x = 752;
	int y = 3;
	int z = 6;

	//variable for getbits run 2
	int a = 4223;
	int b = 6;
	int c = 12;

	//variables for getbits run 3
	int j = 90675;
	int k = 1;
	int l = 13;

	//varibales for rotateleft run 1
	int q = 752;
	int w = 10;
	int e = 4;

	//variable for rotateleft run 2
	int r = 4223;
	int t = 13;
	int g = 5;

	//variables for rotateleft run 3
	int s = 90675;
	int d = 17;
	int f = 13;

	//runs for getbits
	printf("getbits(%x,%d,%d) = [%x] Expecting [e]\n", x, y, z, getbits(x, y, z));
	printf("getbits(%x,%d,%d) = [%x] Expecting [41]\n", a, b, c, getbits(a, b, c));
	printf("getbits(%x,%d,%d) = [%x] Expecting [1119]\n", j, k, l, getbits(j, k, l));

	//runs for rotateleft
	printf("rotate_left(%x,%d,%d) = [%x] Expecting [30b]\n", q, w, e, rotate_left(q, w, e));
	printf("rotate_left(%x,%d,%d) = [%x] Expecting [ff0]\n", r, t, g, rotate_left(r, t, g));
	printf("rotate_left(%x,%d,%d) = [%x] Expecting [7623]\n", s, d, f, rotate_left(s, d, f));

	return 1;
}
