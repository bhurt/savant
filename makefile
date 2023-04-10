run: savant
	./savant

savant: savant.c
	cc -O2 -o savant savant.c

