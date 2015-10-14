#ifndef CPUID_H_
#define CPUID_H_

typedef struct {
	unsigned a;
	unsigned c;
	unsigned b;
	unsigned d;
} cpuid_feat_flags_t;

void cpuid_query(cpuid_feat_flags_t *buf, unsigned leaf, unsigned subleaf);

#endif
