/**
  ******************************************************************************
  * @file    L08_example.c
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 2.0
  * @date    14-Mar-2022
  * @brief   Instruction #08 numeric data types in C
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <float.h>  // FLT constants
#include <stdint.h> // uint32_t
#include <limits.h> // INT_MAX etc.

#include "print_mem.h" 

/* Main function -------------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval 0 
  */
int main(void)
{
  PRINT_INT32(INT_MIN);
  PRINT_INT32(INT_MAX);
  PRINT_INT32(UINT_MAX);
  PRINT_INT32(24);
  PRINT_INT32(-24);
  int a = 2;
  PRINT_INT32(a);
  
  PRINT_Q31(1.0);
  PRINT_Q31(-1.0);
  PRINT_Q31(-0.5);
  float b = -0.5;
  PRINT_Q31(b);
  
  PRINT_FLOAT(FLT_MIN);
  PRINT_FLOAT(FLT_MAX);
  PRINT_FLOAT(FLT_EPSILON);
  PRINT_FLOAT(.1E2f);
  PRINT_FLOAT(0x4048f5c3);

  return 0;
}