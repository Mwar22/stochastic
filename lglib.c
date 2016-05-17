
#include "lglib.h"
#include <stdio.h>
#include <stdlib.h>


/*
 *   Bare simple CLI logic gate simulator library.
 *
 *   Author: Lucas de Jesus B. Gonçalves
 */


void zero_stream(bool *stream, int n_inputs){/*this fills a word with zeroes*/
	int i;
	for(i=0;i<n_inputs;i++){
		stream[i]=false;
	}
}

void print_stream(bool *str, int n_inputs){
	int c;
	for(c=0;c<n_inputs;c++){
		if(str[c]==true){
			printf("1");
		}else{
			printf("0");
		}
	}
	printf("\n");
}


/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

bool g_xor(bool *inputs, int n_inputs){		 /*this calculates a multiple xor gate, giving the inputs as well the quantity of them*/

	
	int counter;
	bool tmp;

	for(counter=0;counter<n_inputs-1;counter++){ /*xor operation with all, using the output of the previous calc, as an input for the next*/

		if(counter==0){
			tmp=inputs[counter]^inputs[counter+1];
		}else{
			tmp=tmp^inputs[counter+1];
		}
	}
	return tmp;
}

bool g_nor(bool *inputs, int n_inputs){ 	/*this calculates a multiple nor gate, similar to the g_xor*/

	int counter;
	bool tmp;

	for(counter=0;counter<n_inputs-1;counter++){ /*nor operation with all, using the output of the previous calc, as an input for the next*/

		if(counter==0){
			tmp=!(inputs[counter]||inputs[counter+1]); /*just trying some bool logic :) */
		
		}else{
			tmp=!(tmp||inputs[counter+1]);
		}
	}
	return tmp;
}



bool g_or(bool *inputs, int n_inputs){ 	/*this calculates a multiple or gate, similar to the g_nor*/

	int counter;
	bool tmp;

	for(counter=0;counter<n_inputs-1;counter++){ /*or operation with all, using the output of the previous calc, as an input for the next*/

		if(counter==0){
			tmp=(inputs[counter]||inputs[counter+1]); /*just trying some bool logic :) */

		}else{
			tmp=(tmp||inputs[counter+1]);
		}
	}
	return tmp;
}

bool g_and(bool *inputs, int n_inputs){ 	/*this calculates a multiple and gate, similar to the g_xor*/

	int counter;
	bool tmp;

	for(counter=0;counter<n_inputs-1;counter++){ /*and operation with all, using the output of the previous calc, as an input for the next*/

		if(counter==0){
			tmp=inputs[counter]&&inputs[counter+1]; /*just trying some bool logic :) */

		}else{
			tmp=tmp&&inputs[counter+1];
		}
	}
	return tmp;
}

bool g_nand(bool *inputs, int n_inputs){ 	/*this calculates a multiple nand gate, similar to the g_xor*/

	int counter;
	bool tmp;

	for(counter=0;counter<n_inputs-1;counter++){ /*nand operation with all, using the output of the previous calc, as an input for the next*/

		if(counter==0){
			tmp=!(inputs[counter]&&inputs[counter+1]); /*just trying some bool logic :) */

		}else{
			tmp=!(tmp&&inputs[counter+1]);
		}
	}
	return tmp;
}

void g_not(bool *inputs, int n_inputs){		/*this inverts all the inputs*/
	int counter;
	for(counter=0;counter<n_inputs;counter++){
		*(inputs+counter)=!inputs[counter];
	}
}


/*#####################################################*/
bool calc_out(gate *l_gate){

	bool out;

	switch(l_gate->type){

		case G_XOR:								/*In case of being a xor gate ...*/
			out=g_xor(l_gate->port,l_gate->inputs);			
		break;	

		case G_NOR:
			out=g_nor(l_gate->port,l_gate->inputs);
		break;

		case G_NAND:
			out=g_nand(l_gate->port,l_gate->inputs);
		break;
		
		case G_OR:
			out=g_or(l_gate->port,l_gate->inputs);
		break;
		
		case G_AND:
			out=g_and(l_gate->port,l_gate->inputs);
		break;
		
		case G_NOT:						/*as an special case, the not gate doesn't have multi-inputs*/
			g_not(l_gate->port,l_gate->inputs);
		break;
	}
	return out;
}

