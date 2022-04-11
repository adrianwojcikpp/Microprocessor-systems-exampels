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
typedef enum { a, b, c, d} INPUT;                       //! Input symbols 
typedef enum { alpha = 1, beta = 2, gamma = 4 } OUTPUT; //! Output symbols 
typedef enum { A, B, C } STATE;                         //! State symbols 


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
// OUTPUT STATE_MACHINE_GetOutput(INPUT i, STATE s);

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
  INPUT input[] = {a, b, a, c, b, b, b, d, d, c, c, c, a, d};
  STATE state = A; // Initial state
  
  // Logging table header
  printf(" # | I |   O   | S | \n");
  printf("-------------------- \n");
  
  // Logging table data
  for(int i = 0; i < 14; i++)
  {
    print_state_machine(input[i], STATE_MACHINE_GetOutput(state), state);
    state = STATE_MACHINE_StateTransition(input[i], state);
  }
    
  return 0;
}

/* Function implementations --------------------------------------------------*/

STATE STATE_MACHINE_StateTransition(INPUT i, STATE s)
{
// TODO: implement Next State Truth Table
return A;
}

OUTPUT STATE_MACHINE_GetOutput(STATE s)
{
// TODO: implement Next State Truth Table
return alpha;
}

void print_state_machine(INPUT i, OUTPUT o, STATE s)
{
                                      
  static const char* _input_names[] = {
  /* 00   01   10   11 */
    "a", "b", "c", "d"
  };
  
  static const char* _output_names[] = {
  /*  000      001      010      011      100   */
    "     ", "alpha", "beta ", "     ", "gamma"
  };
  
  static const char* _state_names[] = {
  /* 00   01   10 */ 
    "A", "B", "C"
  };
  
  static int cnt = 0;
  
  printf("%2d | %s | %s | %s | \n", ++cnt, 
    _input_names[i], _output_names[o], _state_names[s]);
}