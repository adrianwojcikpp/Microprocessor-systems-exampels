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
#include <stdint.h>

/* Define --------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef struct 
{
	uint16_t a : 4;
	uint16_t b : 4;
} BitField_Type;

/* Global variables ----------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/* Function definitions ------------------------------------------------------*/

/* Main function -------------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval 0 
  */
int main(void)
{
  printf("BitField_Type size = %llu\n", sizeof(BitField_Type));
  BitField_Type bitField = { .a = 12, .b = 64 };
  printf("bitField.a = %u, bitField.b = %u, ", bitField.a, bitField.b);
  return 0;
}

/* Function definitions ------------------------------------------------------*/
