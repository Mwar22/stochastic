

#ifndef STCHLIB_H
#define STCHLIB_H

#define WORD_SIZE 8 	/*Word stream size(128 bits)*/
#include "lglib.h"
#include <stdbool.h>

bool *number_to_bin(int i); /*this will convert an integer to its binary representation*/
bool *alloc_word(); /*this will allocate and return a word with WORD_SIZE elements*/
bool stch_ng(bool *random_stream,bool *binary_word);	/*stochastic number generator*/
void fill_with_random(bool *str); /*this fills a word with random 0 or 1*/
bool random_bool();	/*this generate a random bool*/

#endif

