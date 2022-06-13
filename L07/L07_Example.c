/**
  ******************************************************************************
  * @file    L07_example.c
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 2.0
  * @date    14-Mar-2022
  * @brief   Instruction #07 state machine implementation in C
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

/* Typedef -------------------------------------------------------------------*/
typedef _Bool INPUT;   //! Input symbols 
typedef _Bool OUTPUT;  //! Output symbols 
typedef enum { NONE = -1, START = 0, FIRST = 1, SUCCESS = 2, SECOND = 3, SUCCESSD = 6, DELAY = 7 } STATE; //! STATE symbols 

/* Function prototypes ------------------------------------------------------*/

/**
 * @brief State machine state transition function: next state truth table
 * @param[in] i - Input symbol 
 * @param[in] s - State symbol 
 * @return Next state
 */
STATE STATE_MACHINE_StateTransition(INPUT i, STATE s);

/** 
  * @brief State machine output function: output truth table
  * @param[in] s - State symbol 
  * @return Output
  */
OUTPUT STATE_MACHINE_GetOutput(STATE s); 

/**
 * @brief State machine output function: output truth table
 * @param[in] i - an input symbol
 * @param[in] s - a current state symbol
 * @return Current output symbol
 */
OUTPUT STATE_MACHINE_GetOutput2(INPUT i, STATE s);

/**
 * @brief Prints table row with names of input, output and state
 * @param[in] i - Input symbol 
 * @param[in] o - Output symbol 
 * @param[in] s - State symbol 
 */
void print_state_machine(INPUT i, OUTPUT o, STATE s);

/* Entry point: main function -----------------------------------------------*/
int main(void)
{
  INPUT input[] = {1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1,0};
  STATE state_moore = START; // Initial state
  
  // Logging table header
  printf(" Input size: %llu \n\n", sizeof(input) / sizeof(input[0]));
  printf("Moore machine\n");
  printf(" # | I | O |     S    | \n");
  printf("----------------------- \n");
  
  // Logging table data
  for(int i = 0; i < (sizeof(input) / sizeof(input[0])); i++)
  {
    print_state_machine(input[i], STATE_MACHINE_GetOutput(state_moore), state_moore);
    state_moore = STATE_MACHINE_StateTransition(input[i], state_moore);
  }
    
  STATE state_mealy = START; // Initial state
	
  printf("\nMealy machine\n");
  printf(" # | I | O |     S    | \n");
  printf("----------------------- \n");
  
  // Logging table data
  for(int i = 0; i < (sizeof(input) / sizeof(input[0])); i++)
  {
    print_state_machine(input[i], STATE_MACHINE_GetOutput2(input[i], state_mealy), state_mealy);
    state_mealy = STATE_MACHINE_StateTransition(input[i], state_mealy);
  }	
	
  return 0;
}

/* Function implementations --------------------------------------------------*/

STATE STATE_MACHINE_StateTransition(INPUT i, STATE s)
{
	switch(s)
	{
		case START:
		{
			if(i == 1)
				return START;
			else
				return FIRST;
		}
		case FIRST:
		{
			if(i == 1)
				return SECOND;
			else
				return FIRST;
		}
		case SECOND:
		{
			if(i == 1)
				return SUCCESS;
			else
				return DELAY;
		}
		case DELAY:
		{
			if(i == 1)
				return SUCCESSD;
			else
				return DELAY;
		}
		case SUCCESSD:
		{
			if(i == 1)
				return SUCCESS;
			else
				return DELAY;
		}
		case SUCCESS:
		{
			if(i == 1)
				return START;
			else
				return FIRST;
		}
		default:
			return NONE;
	}
}

OUTPUT STATE_MACHINE_GetOutput2(INPUT i, STATE s)
{
	switch(s)
	{
		case START:
		{
			if(i == 1)
				return 0;
			else
				return 0;
		}
		case FIRST:
		{
			if(i == 1)
				return 0;
			else
				return 0;
		}
		case SECOND:
		{
			if(i == 1)
				return 1;
			else
				return 0;
		}
		case DELAY:
		{
			if(i == 1)
				return 1;
			else
				return 0;
		}
		case SUCCESSD:
		{
			if(i == 1)
				return 1;
			else
				return 0;
		}
		case SUCCESS:
		{
			if(i == 1)
				return 0;
			else
				return 0;
		}
		default:
			return 0;
	}
}

OUTPUT STATE_MACHINE_GetOutput(STATE s)
{

if(s == SUCCESSD || s == SUCCESS)
	return 1;
else
	return 0;
}

void print_state_machine(INPUT i, OUTPUT o, STATE s)
{
                                      
  static const char* _input_names[] = {
    "0", "1"
  };
  
  static const char* _output_names[] = {
    "0", "1"
  };
  
  static const char* _state_names[] = {
  /*  000          001          010         011         100         101         110         111    */
    "START   ",  "FIRST   ",  "SUCCESS ", "SECOND  ", "        ", "        ", "SUCCESSD", "DELAY   "
  };
  
  static int cnt = 0;
  
  printf("%2d | %s | %s | %s | \n", ++cnt, 
    _input_names[i], _output_names[o], _state_names[s]);
}