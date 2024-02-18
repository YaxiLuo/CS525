a.out: main.c insertion.c utils.c 
	gcc -o a.out main.c insertion.c utils.c	
# CC=gcc
# CFLAGS=-I.
# DEPS = utils.h insertion.h

# %.o: %.c $(DEPS)
#     $(CC) -c -o $@ 
# for .o file
# 	$(CC) -c -o $

# sort : utils.c insertion.c
# 	$(CC) -o sort main.c utils.c insertion.c
