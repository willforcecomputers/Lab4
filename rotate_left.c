/*
 * rotate_left.c
 *
 *  Created on: Oct 18, 2016
 *      Author: William
 */


#include <stdio.h>

int rotateleft(unsigned int num, int width, int howmany) {

	unsigned int rotanum = num;
	unsigned int accunum = 0;
	unsigned int i = 0;

	for (i = (width - 1); i >= (width - howmany); i -= 1) {

		unsigned int checknum = (1 << i);
		if((num & checknum) > 0) {

			accunum = (accunum << 1);
			accunum += (checknum >> (i));
			rotanum -= checknum;

		}

		else {
			accunum = (accunum << 1);
		}
	}

	rotanum = rotanum << (howmany);
	rotanum += accunum;
	return rotanum;
}

int main() {

	int x = 752;
	int y = 10;
	int z = 4;

	int a = 154;
	int b = 8;
	int c = 3;

	int j = 90675;
	int k = 17;
	int l = 13;

	printf("rotateleft(%d,%d,%d) = [%d] Expecting [779]\n", x, y, z, rotateleft(x, y, z));
	printf("rotateleft(%d,%d,%d) = [%d] Expecting [212]\n", a, b, c, rotateleft(a, b, c));
	printf("rotateleft(%d,%d,%d) = [%d] Expecting [30243]\n", j, k, l, rotateleft(j, k, l));

	return 1;
}
