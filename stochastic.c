#include "stchlib.h"
#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[]){
	int x,a;
	bool u[2];

	printf("Creating new word:b\n");
	bool *b=alloc_word();
	printf("Done.\n");

	printf("Filling 'b' with zeroes\n");
	zero_stream(b,WORD_SIZE);
	printf("Done.\n");

	printf("Printing 'b'\n");
	print_stream(b,WORD_SIZE);

	printf("Filling 'b' with random\n");
	fill_with_random(b);

	printf("Printing 'b'\n");
	print_stream(b,WORD_SIZE);


	printf("Converting 9 to binary\n");
	bool *p=number_to_bin(9);
	printf("Done.\n");

	printf("Printing 'p'\n");
	print_stream(p,WORD_SIZE);

	bool *g=alloc_word();
	for(a=0;a<WORD_SIZE;a++){
		u[0]=b[a];
		u[1]=p[a];
		g[a]=g_xor(u,2);
	}

	print_stream(g,WORD_SIZE);
	free(g);
	g=NULL;


	
	printf("stch_ng:\n");
	x=(stch_ng(b,p)==true)?1:0;
	printf("Done: x=%d\n",x);
	

	return(0);
}
