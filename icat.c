#include "binprint.h"
#include "cpuid.h"

#include <stdbool.h>

int main(void) {
	cpuid_feat_flags_t flags;

	printf("%s: ", "Leaf 7 EBX");
	cpuid_query(&flags, 0x7, 0x0);
	binprint(stdout, flags.b);
	bool pqe = flags.b & (1 << 15);
	printf("\t%s: %d\n", "PQE (bit 15)", pqe);
	if(!pqe)
		return 1;

	printf("%s: ", "Leaf 10 EBX");
	cpuid_query(&flags, 0x10, 0x0);
	binprint(stdout, flags.b);
	bool l3 = flags.b & (1 << 1);
	printf("\t%s: %d\n", "L3 (bit 1)", l3);
	if (!l3)
		return 2;

	return 0;
}
