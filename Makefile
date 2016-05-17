#This is the makefile 
#Author: Lucas de Jesus B. Gonçalves
 
stochastic:stochastic.o stchlib.o lglib.o
	gcc -o  stochastic stochastic.o stchlib.o lglib.o


stochastic.o: stochastic.c stchlib.h
	gcc -c stochastic.c

stchlib.o: stchlib.c stchlib.h
	gcc -c stchlib.c

lglib.o: lglib.c lglib.h
	gcc -c lglib.c

clean:
	rm stochastic stochastic.o stchlib.o lglib.o
