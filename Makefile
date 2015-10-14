CFLAGS := -std=c99 -g3

icat: icat.o cpuid.o binprint.o

.PHONY: distclean
distclean:
	rm icat *.o

