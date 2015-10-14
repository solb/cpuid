#include "binprint.h"

void binprint(FILE *stream, unsigned num) {
	for (int place = 31; place >= 0; --place) {
		printf("%d", !!(num & (1 << place)));
		if (place && place % 4 == 0)
			putchar(' ');
		num %= 1 << place;
	}
	putchar('\n');
}
