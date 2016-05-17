#ifndef STDBOOL
#define STDBOOL
#include <stdbool.h>
#endif

#ifndef LOGIC_SIM
#define LOGIC_SIM


/*CURRENT TYPES OF LOGIC GATES*/
#define G_NOT 1
#define G_AND 2
#define G_NAND 3

#define G_OR 4
#define G_NOR 5
#define G_XOR 6


typedef struct{

	int type;	/*type of the gate*/
	int inputs;	/*Number of input ports*/
	bool *port;	/*an pointer to an array of inputs(wich has boolean values) */	

}gate;
	
/*there are basic boolean operations(all as multi input gates))*/
bool g_xor(bool *inputs, int n_inputs);
bool g_nor(bool *inputs, int n_inputs);
bool g_or(bool *inputs, int n_inputs);
bool g_and(bool *inputs, int n_inputs);
bool g_nand(bool *inputs, int n_inputs);
void g_not(bool *inputs, int n_inputs);

/*this performs the action of an gate (and gives you the output)*/
bool calc_out(gate *l_gate);

/*other functions*/
void zero_stream(bool *stream, int n_inputs);	/*this fills a word with zeroes*/
void print_stream(bool *str, int n_inputs);	/*this prints a word(0 or 1, since the words are bool)*/



#endif
