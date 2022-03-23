$(CC) = gcc

appln: main.o calc_mean.o calc_sub.o
	$(CC) main.o calc_mean.o calc_sub.o -o appln

main.o: main.c calc_mean.h
	$(CC) -c main.c

mean.o: calc_mean.c calc_mean.h
	$(CC) -c calc_mean.c

sub.o: calc_sub.c calc_mean.h
	$(CC) -c calc_sub.c

clean:
	rm -f *.o