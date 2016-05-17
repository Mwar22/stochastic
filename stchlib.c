#include "stchlib.h"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>





/*
 *This file include some functions/procedures necessari for stochatic computing simulation
 * Author: Lucas de Jesus B. Gonçalves
 */




bool *number_to_bin(int i){	/*integer to digital convertion*/
	
	int divisor, quocient,c,tmp;

	bool converted,temporary;
	bool *word=alloc_word();	/*final word*/

	/*now we fill the word with zeroes*/
	zero_stream(word,WORD_SIZE);


	divisor=i;	
	converted=false; /*initially, the number is not converted*/

	for(c=0;c<=WORD_SIZE;c++){  /*plus one execution (<=), just in case that number ocupe all the WORD_SIZE space*/
		if(converted==false){
			if((quocient!=1)&&(quocient!=0)){ /*if the process is not in the end*/

				quocient=(divisor-(divisor%2))/2;
			
				word[c]=(divisor%2==0)?false:true;
				divisor=quocient;

			
			}else{
				*(word+c)=(quocient==1)?true:false;

				/*this will make the for restart( but now, executing the first else )*/
				converted=true;
				tmp=c;	/*tmp backup the value of c*/

				break;
			}
		}else{	/*this will reverse the order(basic number to digital convertion)*/

				 if(c<=((tmp-(tmp%2))/2)){ /*if its less or equal the middle/last element*/

				 	/*not exchange the value if its impar and reached the middle element,(tmp starts in 0) and then stop*/
					if((tmp%2==0)&&(c==(tmp-(tmp%2))/2)){

						break;
					}else{
					
					/*this exchange the position*/

					temporary=word[c];
					word[c]=word[tmp-c];
					word[tmp-c]=temporary;
					}
				}else{
					break;

				}

		}
	}


	if(tmp!=WORD_SIZE){
		/*now we simply shift the number to the top*/
		for(c=0;c<=tmp;c++){

			word[WORD_SIZE-1-c]=word[tmp-c];
			word[tmp-c]=false;

		
		}
	}

		

	return word;
}


static bool *first_is_greather(bool *stream_a, bool *stream_b){	 /*return true if it is, otherwise return false if it is false*/
	int i;

	for(i=WORD_SIZE;i>0;i--){

		if((*(stream_a+i)==false) && (*(stream_b+i)==true)){
			return stream_b;
		}else if((*(stream_a+i)==true) && (*(stream_b+i)==false)){
			return stream_a;
		}
	}
}


bool *alloc_word(){	/*this will allocate a new word*/
	bool *ptr=(bool *)malloc(WORD_SIZE*sizeof(bool));
	if(ptr==NULL){
		printf("Error, malloc returned Null!(Memory limit reached!)\n");
		exit(EXIT_FAILURE);
	}
	return ptr;
}



bool stch_ng(bool *random_stream, bool *binary_number){
	return (first_is_greather(random_stream,binary_number)==binary_number)? true:false;
}

bool random_bool(){
	return (rand()%2==1)?true:false;
}

void fill_with_random(bool *str){
	int c;
	srand(time(NULL));
	
	for(c=0;c<WORD_SIZE;c++){
		str[c]=random_bool();
	}
}


	


