CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1: unittest1.c dominion.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	#gcov unittest1.o
	
	#./playdom 3 >> unittestresults.out
	#gcov dominion.c >> unittestresults.out

unittest2: unittest2.c dominion.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	#gcov unittest2.o

unittest3: unittest3.c dominion.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	#gcov unittest3.o

unittest4: unittest4.c dominion.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	#gcov unittest4.o

cardtest1: cardtest1.c dominion.o interface.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	#gcov cardtest1.o

cardtest2: cardtest2.c dominion.o interface.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	#gcov cardtest2.o
	#gcov cardtest2.c >> unittestresults.out

cardtest3: cardtest3.c dominion.o interface.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	#gcov cardtest3.o

cardtest4: cardtest4.c dominion.o interface.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)
	#gcov cardtest4.o

unittestresults.out: dominion.o unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 > unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out


	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out


	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out


all: playdom player 

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
