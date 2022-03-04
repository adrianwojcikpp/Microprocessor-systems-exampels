/**
  ******************************************************************************
  * @file    L02_example.c
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 1.0
  * @date    04-Mar-2022
  * @brief   Intruction #02 tasks solution template
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

/* Define --------------------------------------------------------------------*/
#define T '1' /**< True symbol (T / H / 1) */
#define F '0' /**< False symbol (F / L / 0) */

/* Macro ---------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef _Bool (*logic_function)(unsigned int); /**< Logic function */

/* Global variables ----------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/* Function definitions ------------------------------------------------------*/

/**
 * @brief Logic function truth table printing procedure
 * @param[in] fcn    Logic function 
 * @param[in] bits   Input size (number of bits)
 * @return None
 */
void print_truth_table(logic_function fcn, unsigned int bits)
{
  unsigned int j;
  
  printf("    |");
  for(j = 0; j < bits; j++)
    printf(" %c |", j + 'a');
  printf(" %s |\n", "fcn");
    
  unsigned int i;
  for(i = 0; i < (1 << bits); i++)
  {
    printf("%3d |",i);
    for(j = bits; j > 0; j--)
      printf(" %c |", (i & (1 << (j-1))) ? T : F);
    printf("  %c  |\n", fcn(i) ? T : F);
  }
}

/**
 * @brief Logic function <<TODO>>
 * @param[in] x Integer input
 * @return <<TODO>>
 */
_Bool my_fcn(unsigned int x) // <<TODO>> CHANGE NAME FUNCTION!
{
  // USER CODE BEGIN
  return ((x % 3) == 0);
  // USER CODE END
}

/* Main function -------------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval 0 
  */
int main(void)
{
  // call example
  print_truth_table(my_fcn, 5 /* number of bits */); 
  
  return 0;
}

/* Function definitions ------------------------------------------------------*/
